// libDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lib.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgLogin �Ի���




CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
	, username(_T(""))
	, password(_T(""))
	, strVERSION(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, username);
	DDX_Text(pDX, IDC_EDIT2, password);
	DDX_Text(pDX, IDC_STATIC_VERSION, strVERSION);
}

BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CDlgLogin::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgLogin::OnBnClickedCancel)

	
END_MESSAGE_MAP()


// CDlgLogin ��Ϣ�������

BOOL CDlgLogin::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CString echo;
	echo.Format("ϵͳ���ڳ�ʼ�������������Ҫ����ӣ�������·��������������Ժ򡣡���");
    MessageBox(echo);
	char buffer[]="LibTempIp.txt";//���ó�������ʱ������ip�ļ�Ŀ¼

	//��ó���Ŀǰ�İ汾��

 char cPath[200];
 DWORD dwHandle,InfoSize;
 ::GetModuleFileName(NULL,cPath,sizeof(cPath)); //���Ȼ�ð汾��Ϣ��Դ�ĳ���
 InfoSize = GetFileVersionInfoSize(cPath,&dwHandle); //���汾��Ϣ��Դ���뻺����

 char *InfoBuf = new char[InfoSize];
 GetFileVersionInfo(cPath,0,InfoSize,InfoBuf); //��������ļ�ʹ�õĴ���ҳ���ļ��汾
 unsigned int  cbTranslate = 0;
 struct LANGANDCODEPAGE {WORD wLanguage; WORD wCodePage; } *lpTranslate;
 VerQueryValue(InfoBuf, TEXT("\\VarFileInfo\\Translation"),(LPVOID*)&lpTranslate,&cbTranslate);
 // Read the file description for each language and code page.
 for(unsigned int i=0; i < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); i++ )
 { char SubBlock[200];wsprintf( SubBlock,TEXT("\\StringFileInfo\\%04x%04x\\FileVersion"),lpTranslate[i].wLanguage,lpTranslate[i].wCodePage);
  void *lpBuffer=NULL;unsigned int dwBytes=0;VerQueryValue(InfoBuf,SubBlock,&lpBuffer,&dwBytes);
  CString strTemp=( char *)lpBuffer;
  strVERSION=strTemp;UpdateData(false);}
  delete InfoBuf;
	
  //��������ݿ������������
   int connect_state;connect_state=Server_connect();
   if(connect_state==0){MessageBox("���ݿ�����ʧ�ܣ��������Ļ���������!");exit(0);}//�˳�����---------------------------------------------------------------------------------------------------���������ʱע�͵�
    SQL.Format("select * from sys where setvalue='%s'",strVERSION);
	char *SQLW;
    SQLW=SQL.GetBuffer(SQL.GetLength());
    SQL.ReleaseBuffer();
    mysql_query(conn,SQLW);
    res=mysql_store_result(conn);
	if(mysql_num_rows(res)==0)
	{
		SQL.Format("select * from sys where setname='urltodown'");
		char *SQLW;
		SQLW=SQL.GetBuffer(SQL.GetLength());
		SQL.ReleaseBuffer();
		mysql_query(conn,SQLW);
		res=mysql_store_result(conn);
		row = mysql_fetch_row(res);
		CString echotext;
		echotext.Format("����ǰ�İ汾���ͣ��Ѿ�ֹ֧ͣ�֡������\t%s\t��ȡ���°汾��",row[2]);
		MessageBox(echotext);
		exit(0);
	}
	else
	{
		SQL.Format("select * from sys where setname='sysonoff'");
	    char *SQLW;SQLW=SQL.GetBuffer(SQL.GetLength());SQL.ReleaseBuffer();
        mysql_query(conn,SQLW);res=mysql_store_result(conn);row = mysql_fetch_row(res);
	    CString sysoff;sysoff.Format("off");
	    if(row[2]==sysoff){SQL.Format("select * from sys where setname='sysoffres'");
	    char *SQLW;SQLW=SQL.GetBuffer(SQL.GetLength());SQL.ReleaseBuffer();mysql_query(conn,SQLW);
        res=mysql_store_result(conn);row = mysql_fetch_row(res);CString echotext;
	    echotext.Format("����%s���ʳ�����ʱ�޷�����",row[2]);MessageBox(echotext);exit(0);}
	}

	char * Tempfile=buffer;
	URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);//���»����ļ�
		if(PathFileExists(Tempfile)){}
	   else {
		     MessageBox("��ʼ������ip��ַʧ�ܣ��������ԡ�����");
	         URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);//���»����ļ�
			 if(PathFileExists(Tempfile)){}
             else {
				 MessageBox("��ʼ������ip��ַʧ�ܣ��������ԡ�����");
	             URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);//���»����ļ�
			     if(PathFileExists(Tempfile)){}
				 else{MessageBox("��ʼ������ip��ַʧ��!");exit(0);}
			      }
	       }
	MessageBox("��ʼ���ɹ���");
    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDlgLogin::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDlgLogin::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���ӷ����������ݿ�
int CDlgLogin::Server_connect(void)
{
    conn= mysql_init((MYSQL*) 0);//��ʼ��mysql�ṹ
	
	if(!mysql_real_connect(conn,"116.196.81.185","cpro","98766789","cpro",3306,NULL,0)) //mysql�ṹ�����ݿ��������ַ�����ݿ��û��������ݿ����룬���ݿ������˿ںţ�����������������mysql�������ã�һ�㲻����ģ�
	{return 0;}//���ݿ�����ʧ��
	else{ mysql_query(conn, "set names gbk"); return 1;}
}


void CDlgLogin::OnBnClickedOk()
{
	HWND m=this->m_hWnd;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int  result=0;
	 // ��ȡ��ǰip��ַ;
    ifstream IPfile("LibTempIp.txt");
    string str,strtmp;
    while ( getline(IPfile,strtmp) )
    {   
        str+=strtmp;
    }
    string::size_type posEnd1 = str.find("[");
    string::size_type posEnd2 = str.find("]");
    str = str.substr(posEnd1+1,posEnd2-posEnd1-1);
	CString ip,ipprint;
	ip=str.c_str();

    //��õ�ǰʱ��
	CString strDateTime,Tday,Thour,Tmin,Tsec,Tyear,Tmo,strlimittime;
	CTime time;  
    time=CTime::GetCurrentTime(); 
	//��ȡ��ǰʱ������ 
	Tyear=time.Format("%Y");
	Tmo=time.Format("%m");
	Tday=time.Format("%d");int iTday= atoi(Tday);
	Thour=time.Format("%H");int iThour= atoi(Thour);
	Tmin=time.Format("%M");
	Tsec=time.Format("%S");
	if(iThour+2>=24){iThour=iThour-22;iTday=iTday+1;}
	else{iThour=iThour+2;}
	Tday.Format("%d",iTday);if(iThour<10){Thour.Format("0%d",iThour);}else{Thour.Format("%d",iThour);}
	strlimittime.Format("%s-%s-%s %s:%s:%s",Tyear,Tmo,Tday,Thour,Tmin,Tsec);
    strDateTime=time.Format(_T("%Y-%m-%d %H:%M:%S"));
    //��������û�����������м���
    MD5 md5; 
	USES_CONVERSION;
	UpdateData(true);//��edit���л��Ŀǰ������
	md5.update(password.GetBuffer());    //��Ϊupdate����ֻ����string���ͣ�����ʹ��getbuffer()����ת��CStringΪstring
    password.ReleaseBuffer();
	password=md5.toString().c_str();     //toString()������ü����ַ�����c_str();��������ת����CString����
	password.MakeUpper();//�Ѽ���֮���������ַ���ȫ����д
	Server_connect();
	SQL.Format("select * from user where username='%s' and password='%s'",username,password);
	char *SQLW;
    SQLW=SQL.GetBuffer(SQL.GetLength());
    SQL.ReleaseBuffer();
    mysql_query(conn,SQLW);
    res=mysql_store_result(conn);
	if(mysql_num_rows(res)==0){MessageBox("�û������������");}
	else{
		if(mysql_num_rows(res)==1){
            SQL.Format("UPDATE user SET lastlogintime='%s', lastloginip='%s' where username= '%s'",strDateTime,ip,username);
	        SQLW=SQL.GetBuffer(SQL.GetLength());
            SQL.ReleaseBuffer();
            mysql_query(conn,SQLW);
			MessageBox("��¼�ɹ���");
			DestroyWindow( );
			LeTurn.SetData(username,strDateTime,strlimittime);
			if(LeTurn.m_hWnd==0)
			{LeTurn.Create(IDD_FUN_INDEX,this);}   
		    LeTurn.ShowWindow(SW_SHOW);	

		}
		if(mysql_num_rows(res)!=1){MessageBox("���˻���Ч��");}
        }

	
}

void CDlgLogin::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}



