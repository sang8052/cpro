// ��¼����.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "��¼����.h"


// ��¼���� �Ի���




��¼����::��¼����(CWnd* pParent /*=NULL*/)
	: CDialog(��¼����::IDD, pParent)
	, Username(_T(""))
	, Password(_T(""))
	, strVERSION(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void ��¼����::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, Username);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, Password);
	DDX_Text(pDX, IDC_STATIC_VER, strVERSION);
}

BEGIN_MESSAGE_MAP(��¼����, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &��¼����::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &��¼����::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// C��¼���� ��Ϣ�������

BOOL ��¼����::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	
   
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
   {
      pSysMenu->EnableMenuItem(SC_CLOSE, MF_GRAYED); 
   }
	

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó����¼���ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    Getready();   //ִ���Զ����ʼ������
	
    return TRUE;
}



// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void ��¼����::OnPaint()
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
HCURSOR ��¼����::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//���ػس���Ϣ
 BOOL   ��¼����::PreTranslateMessage(MSG*   pMsg)    
  {  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_ESCAPE)     return   TRUE;  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_RETURN)   return   TRUE;    
    else    
          return   CDialog::PreTranslateMessage(pMsg);  
  }

// ��¼���� ��Ϣ�������


void ��¼����::OnBnClickedButtonCancel()//ȡ����ť����Ϣ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

// ���ݿ��������ӵĺ���
void ��¼����::SQL_connect(void)
{
	conn= mysql_init((MYSQL*) 0);//��ʼ��mysql�ṹ
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql�ṹ�����ݿ��������ַ�����ݿ��û��������ݿ����룬���ݿ������˿ںţ�����������������mysql�������ã�һ�㲻����ģ�
	{MessageBox("���ݿ�����ʧ�ܣ�");exit(0);}//���ݿ�����ʧ���˳�����
	else{ mysql_query(conn, "set names gbk"); }//����MYSQL���صı���Ϊgbk������Ŀʹ�õĶ��ַ���������ݡ�
}
//��¼��ť�ĺ���
void ��¼����::OnBnClickedButtonLogin()
{
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
    //��������û������������MD5����
	//ע�����MD5���ܵĺ���ֻ������Ӣ�ĺ����֡�
    MD5 md5; 
	USES_CONVERSION;
	UpdateData(true);//��edit���л��Ŀǰ������
	md5.update(Password.GetBuffer());    //��Ϊupdate����ֻ����string���ͣ�����ʹ��getbuffer()����ת��CStringΪstring
    Password.ReleaseBuffer();
	Password=md5.toString().c_str();     //toString()������ü����ַ�����c_str();��������ת����CString����
	Password.MakeUpper();//�Ѽ���֮���������ַ���ȫ����д
	SQL.Format("select * from user where username='%s' and password='%s'",Username,Password);
	SQLtosql();
    mysql_query(conn,sql);
    res=mysql_store_result(conn);
	if(mysql_num_rows(res)==0){MessageBox("�û������������");}
	else{
		if(mysql_num_rows(res)==1){
            SQL.Format("UPDATE user SET lastlogintime='%s', lastloginip='%s' where username= '%s'",strDateTime,ip,Username);
	        SQLtosql();
            mysql_query(conn,sql);
			MessageBox("��¼�ɹ���");
		    OnOK();
			theApp.Username=Username;
			theApp.Logintime=strDateTime;
			theApp.LimitTime=strlimittime;
			

		}
		if(mysql_num_rows(res)!=1){MessageBox("���˻���Ч��");}
        }


}

// CString ��SQL ת���� char* sql
void ��¼����::SQLtosql(void)
{
	
	sql=SQL.GetBuffer();  //��GCstr ת����str��ȥ 
	SQL.ReleaseBuffer();  //�ͷŻ�����
}
	
	
// �Զ����ʼ������
void ��¼����::Getready(void)
{
    MessageBox("ϵͳ���ڳ�ʼ�������������Ҫ����ӣ�����������������������Ժ򡣡���");
	//��������ݿ������������
	SQL_connect();

	//������ݿ��й���ϵͳ����״̬������
	SQL.Format("select * from sys where setname='sysonoff'");
    SQLtosql();
    mysql_query(conn,sql);res=mysql_store_result(conn);row = mysql_fetch_row(res);
    CString sysoff;sysoff.Format("off");
    if(row[2]==sysoff){SQL.Format("select * from sys where setname='sysoffres'");
    SQLtosql();mysql_query(conn,sql);
    res=mysql_store_result(conn);row = mysql_fetch_row(res);
	CString echotext;
	echotext.Format("����%s���ʳ�����ʱ�޷�����",row[2]);
	MessageBox(echotext);
	if($DEBUG=="false"){exit(0);}
	}
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
	for(unsigned int i=0; i < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); i++ )
	{char SubBlock[200];wsprintf( SubBlock,TEXT("\\StringFileInfo\\%04x%04x\\FileVersion"),lpTranslate[i].wLanguage,lpTranslate[i].wCodePage);
	void *lpBuffer=NULL;unsigned int dwBytes=0;VerQueryValue(InfoBuf,SubBlock,&lpBuffer,&dwBytes);
	CString strTemp=( char *)lpBuffer;strVERSION=strTemp;UpdateData(false);}
	delete InfoBuf;

	//������ݿ����Ƿ�����ǰ�汾����ʹ��
	SQL.Format("select * from sys where setvalue='%s'",strVERSION);
    SQLtosql();
    mysql_query(conn,sql);
    res=mysql_store_result(conn);
	if(mysql_num_rows(res)==0)
	{
		SQL.Format("select * from sys where setname='urltodown'");
		SQLtosql();
		mysql_query(conn,sql);
		res=mysql_store_result(conn);
		row = mysql_fetch_row(res);
		CString echotext;
		echotext.Format("����ǰ�İ汾���ͣ��Ѿ�ֹ֧ͣ�֡������\t%s  ��ȡ���°汾��",row[2]);
		MessageBox(echotext);
		if($DEBUG=="false"){exit(0);}
	}
    
	//��ñ�������ip��ַ
	if($DEBUG=="false"){Getip();}
	
   
	MessageBox("��ʼ���ɹ���");
}



// ��ñ�����������ip��ַ
void ��¼����::Getip(void)
{
	char buffer[]="LibTempIp.txt";//���ó�������ʱ������ip�ļ�Ŀ¼
	if(PathFileExists("LibTempIp.txt")){DeleteFile("LibTempIp.txt ");}//��黺���ļ��Ƿ���ڣ����ڼ�ɾ��
	char* Tempfile=buffer;
	//���γ��Ի��ip��ַ
	URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);
	if(PathFileExists(Tempfile)){}else{MessageBox("��ʼ������ip��ַʧ�ܣ��������ԡ�����");
	URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);
	if(PathFileExists(Tempfile)){}else {MessageBox("��ʼ������ip��ַʧ�ܣ��������ԡ�����");
    URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);
    if(PathFileExists(Tempfile)){}else{MessageBox("��ʼ������ip��ַʧ��!");exit(0);}}}
}
