// 登录窗口.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "登录窗口.h"


// 登录窗口 对话框




登录窗口::登录窗口(CWnd* pParent /*=NULL*/)
	: CDialog(登录窗口::IDD, pParent)
	, Username(_T(""))
	, Password(_T(""))
	, strVERSION(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void 登录窗口::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, Username);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, Password);
	DDX_Text(pDX, IDC_STATIC_VER, strVERSION);
}

BEGIN_MESSAGE_MAP(登录窗口, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &登录窗口::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &登录窗口::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// C登录窗口 消息处理程序

BOOL 登录窗口::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	
   
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
   {
      pSysMenu->EnableMenuItem(SC_CLOSE, MF_GRAYED); 
   }
	

	// 设置此对话框的图标。当应用程序登录窗口不是对话框时，框架将自动
	//  执行此操作

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    Getready();   //执行自定义初始化函数
	
    return TRUE;
}



// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void 登录窗口::OnPaint()
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
HCURSOR 登录窗口::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//重载回车消息
 BOOL   登录窗口::PreTranslateMessage(MSG*   pMsg)    
  {  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_ESCAPE)     return   TRUE;  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_RETURN)   return   TRUE;    
    else    
          return   CDialog::PreTranslateMessage(pMsg);  
  }

// 登录窗口 消息处理程序


void 登录窗口::OnBnClickedButtonCancel()//取消按钮的消息处理函数
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

// 数据库用来连接的函数
void 登录窗口::SQL_connect(void)
{
	conn= mysql_init((MYSQL*) 0);//初始化mysql结构
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql结构，数据库服务器地址，数据库用户名，数据库密码，数据库名，端口号，（下面两个参数是mysql连接配置，一般不需更改）
	{MessageBox("数据库连接失败！");exit(0);}//数据库连接失败退出程序
	else{ mysql_query(conn, "set names gbk"); }//设置MYSQL返回的编码为gbk，与项目使用的多字符编码相兼容。
}
//登录按钮的函数
void 登录窗口::OnBnClickedButtonLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	int  result=0;
	 // 获取当前ip地址;
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

    //获得当前时间
	CString strDateTime,Tday,Thour,Tmin,Tsec,Tyear,Tmo,strlimittime;
	CTime time;  
    time=CTime::GetCurrentTime(); 
	//获取当前时间日期 
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
    //对输入的用户名和密码进行MD5加密
	//注意这个MD5加密的函数只适用于英文和数字。
    MD5 md5; 
	USES_CONVERSION;
	UpdateData(true);//从edit框中获得目前的数据
	md5.update(Password.GetBuffer());    //因为update函数只接收string类型，所以使用getbuffer()函数转换CString为string
    Password.ReleaseBuffer();
	Password=md5.toString().c_str();     //toString()函数获得加密字符串，c_str();函数重新转换成CString类型
	Password.MakeUpper();//把加密之后的密码的字符串全部大写
	SQL.Format("select * from user where username='%s' and password='%s'",Username,Password);
	SQLtosql();
    mysql_query(conn,sql);
    res=mysql_store_result(conn);
	if(mysql_num_rows(res)==0){MessageBox("用户名或密码错误！");}
	else{
		if(mysql_num_rows(res)==1){
            SQL.Format("UPDATE user SET lastlogintime='%s', lastloginip='%s' where username= '%s'",strDateTime,ip,Username);
	        SQLtosql();
            mysql_query(conn,sql);
			MessageBox("登录成功！");
		    OnOK();
			theApp.Username=Username;
			theApp.Logintime=strDateTime;
			theApp.LimitTime=strlimittime;
			

		}
		if(mysql_num_rows(res)!=1){MessageBox("此账户无效！");}
        }


}

// CString 的SQL 转换到 char* sql
void 登录窗口::SQLtosql(void)
{
	
	sql=SQL.GetBuffer();  //把GCstr 转换到str中去 
	SQL.ReleaseBuffer();  //释放缓冲区
}
	
	
// 自定义初始化函数
void 登录窗口::Getready(void)
{
    MessageBox("系统正在初始化程序，这可能需要半分钟（根据网络情况而定），请稍候。。。");
	//检查与数据库服务器的链接
	SQL_connect();

	//检查数据库中关于系统运行状态的设置
	SQL.Format("select * from sys where setname='sysonoff'");
    SQLtosql();
    mysql_query(conn,sql);res=mysql_store_result(conn);row = mysql_fetch_row(res);
    CString sysoff;sysoff.Format("off");
    if(row[2]==sysoff){SQL.Format("select * from sys where setname='sysoffres'");
    SQLtosql();mysql_query(conn,sql);
    res=mysql_store_result(conn);row = mysql_fetch_row(res);
	CString echotext;
	echotext.Format("由于%s，故程序暂时无法运行",row[2]);
	MessageBox(echotext);
	if($DEBUG=="false"){exit(0);}
	}
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
	for(unsigned int i=0; i < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); i++ )
	{char SubBlock[200];wsprintf( SubBlock,TEXT("\\StringFileInfo\\%04x%04x\\FileVersion"),lpTranslate[i].wLanguage,lpTranslate[i].wCodePage);
	void *lpBuffer=NULL;unsigned int dwBytes=0;VerQueryValue(InfoBuf,SubBlock,&lpBuffer,&dwBytes);
	CString strTemp=( char *)lpBuffer;strVERSION=strTemp;UpdateData(false);}
	delete InfoBuf;

	//检查数据库中是否允许当前版本继续使用
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
		echotext.Format("您当前的版本过低，已经停止支持。请访问\t%s  获取最新版本。",row[2]);
		MessageBox(echotext);
		if($DEBUG=="false"){exit(0);}
	}
    
	//获得本机外网ip地址
	if($DEBUG=="false"){Getip();}
	
   
	MessageBox("初始化成功！");
}



// 获得本机本机外网ip地址
void 登录窗口::Getip(void)
{
	char buffer[]="LibTempIp.txt";//设置程序运行时缓存获得ip文件目录
	if(PathFileExists("LibTempIp.txt")){DeleteFile("LibTempIp.txt ");}//检查缓存文件是否存在，存在即删除
	char* Tempfile=buffer;
	//三次尝试获得ip地址
	URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);
	if(PathFileExists(Tempfile)){}else{MessageBox("初始化本机ip地址失败，正在重试。。。");
	URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);
	if(PathFileExists(Tempfile)){}else {MessageBox("初始化本机ip地址失败，正在重试。。。");
    URLDownloadToFile(0,"http://www.ip138.com/ip2city.asp","LibTempIp.txt",0,NULL);
    if(PathFileExists(Tempfile)){}else{MessageBox("初始化本机ip地址失败!");exit(0);}}}
}
