// libDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lib.h"
#include "libDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClibDlg 对话框




ClibDlg::ClibDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ClibDlg::IDD, pParent)
	, username(_T(""))
	, password(_T(""))
	, strVERSION(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void ClibDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, username);
	DDX_Text(pDX, IDC_EDIT2, password);
	DDX_Text(pDX, IDC_STATIC_VERSION, strVERSION);
}

BEGIN_MESSAGE_MAP(ClibDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &ClibDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ClibDlg::OnBnClickedCancel)
	ON_COMMAND(ID_32779, &ClibDlg::Ontip)
	
END_MESSAGE_MAP()


// ClibDlg 消息处理程序

BOOL ClibDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString echo;
	echo.Format("系统正在初始化程序，这可能需要半分钟（根据网路情况而定），请稍候。。。");
    MessageBox(echo);
	char buffer[]="C:\\LibTempIp.txt";//设置程序运行时缓存获得ip文件目录

	//获得程序目前的版本号

	char cPath[200];
 DWORD dwHandle,InfoSize;
 ::GetModuleFileName(NULL,cPath,sizeof(cPath)); //首先获得版本信息资源的长度
 InfoSize = GetFileVersionInfoSize(cPath,&dwHandle); //将版本信息资源读入缓冲区

 char *InfoBuf = new char[InfoSize];
 GetFileVersionInfo(cPath,0,InfoSize,InfoBuf); //获得生成文件使用的代码页及文件版本
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
	

	char * Tempfile=buffer;
	
  //  
		//URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","C:\\LibTempIp.txt",0,NULL);//更新缓存文件
		//if(PathFileExists(Tempfile)){}
	 //  else {
		//     MessageBox("初始化本机ip地址失败，正在重试。。。");
	 //        URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","C:\\LibTempIp.txt",0,NULL);//更新缓存文件
		//	 if(PathFileExists(Tempfile)){}
  //           else {
		//		 MessageBox("初始化本机ip地址失败，正在重试。。。");
	 //            URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","C:\\LibTempIp.txt",0,NULL);//更新缓存文件
		//	     if(PathFileExists(Tempfile)){}
		//		 else{MessageBox("初始化本机ip地址失败!");exit(0);}
		//	      }
	 //      }/*---------------------------------------------------------------------------------------------------方便调试临时注释掉*/
	 
	
	
	
	//检出与数据库服务器的连接
   int connect_state;connect_state=Server_connect();
   if(connect_state==0){MessageBox("数据库连接失败，清检查您的互联网连接!");exit(0);}//退出程序---------------------------------------------------------------------------------------------------方便调试临时注释掉
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
		echotext.Format("您当前的版本过低，已经停止支持。请访问\t%s\t获取最新版本。",row[2]);
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
	    echotext.Format("由于%s，故程序暂时无法运行",row[2]);MessageBox(echotext);exit(0);}
	}

	
		
   MessageBox("初始化成功！");
  
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClibDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ClibDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 连接服务器的数据库
int ClibDlg::Server_connect(void)
{
    conn= mysql_init((MYSQL*) 0);//初始化mysql结构
	
	if(!mysql_real_connect(conn,"116.196.81.185","cpro","98766789","cpro",3306,NULL,0)) //mysql结构，数据库服务器地址，数据库用户名，数据库密码，数据库名，端口号，（下面两个参数是mysql连接配置，一般不需更改）
	{return 0;}//数据库连接失败
	else{ mysql_query(conn, "set names gbk"); return 1;}
}

DIALOG1 win_inquire;
void ClibDlg::OnBnClickedOk()
{
	HWND m=this->m_hWnd;
	// TODO: 在此添加控件通知处理程序代码
	int  result=0;
	 // 获取当前ip地址;
    ifstream IPfile("C:\\LibTempIp.txt");
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

    //获得当前时间
	CString strDate,strTime,strDateTime;
	CTime time;  
    time=CTime::GetCurrentTime();             //获取当前时间日期  
    strDate=time.Format(_T("%x"));          //格式化日期  
    strTime=time.Format(_T("%X"));          //格式化时间  
    strDateTime=time.Format(_T("%Y-%m-%d %H:%M:%S"));
    //对输入的用户名和密码进行加密
    MD5 md5; 
	USES_CONVERSION;
	UpdateData(true);//从edit框中获得目前的数据
	md5.update(password.GetBuffer());    //因为update函数只接收string类型，所以使用getbuffer()函数转换CString为string
    password.ReleaseBuffer();
	password=md5.toString().c_str();     //toString()函数获得加密字符串，c_str();函数重新转换成CString类型
	password.MakeUpper();//把加密之后的密码的字符串全部大写
	Server_connect();
	SQL.Format("select * from user where username='%s' and password='%s'",username,password);
	char *SQLW;
    SQLW=SQL.GetBuffer(SQL.GetLength());
    SQL.ReleaseBuffer();
    mysql_query(conn,SQLW);
    res=mysql_store_result(conn);
	if(mysql_num_rows(res)==0){MessageBox("用户名或密码错误！");}
	else{
		if(mysql_num_rows(res)==1){
            SQL.Format("UPDATE user SET lastlogintime='%s', lastloginip='%s' where username= '%s'",strDateTime,ip,username);
	        SQLW=SQL.GetBuffer(SQL.GetLength());
            SQL.ReleaseBuffer();
            mysql_query(conn,SQLW);
			
			MessageBox("登录成功！");
			if(win_inquire.m_hWnd==0){
 win_inquire.Create(IDD_DIALOG1);
	}
	win_inquire.ShowWindow(SW_SHOW);

		}
		if(mysql_num_rows(res)!=1){MessageBox("此账户无效！");}
        }

	
}

void ClibDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}







void ClibDlg::Ontip()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("调用了LIB窗口");
}

