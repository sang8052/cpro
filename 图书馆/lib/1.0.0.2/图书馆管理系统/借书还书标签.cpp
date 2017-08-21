// 借书还书标签.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "借书还书标签.h"


// 借书还书标签 对话框

IMPLEMENT_DYNAMIC(借书还书标签, CDialog)

借书还书标签::借书还书标签(CWnd* pParent /*=NULL*/)
	: CDialog(借书还书标签::IDD, pParent)
	, EDIT_BOOKNUM(_T(""))
	, EDITBOOKNAME(_T(""))
	, EDIT_WRITTER(_T(""))
	, EDIT_STATE(_T(""))
{

}

借书还书标签::~借书还书标签()
{
}

void 借书还书标签::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BOOKNUM, EDIT_BOOKNUM);
	DDX_Text(pDX, IDC_EDIT_BOOKNAME, EDITBOOKNAME);
	DDX_Text(pDX, IDC_EDIT_BOOKWRITER, EDIT_WRITTER);
	DDX_Text(pDX, IDC_EDIT_BOOKSTATE, EDIT_STATE);

	DDX_Control(pDX, IDC_EXPLORER_QR, PIC_QR);
}


BEGIN_MESSAGE_MAP(借书还书标签, CDialog)
END_MESSAGE_MAP()



// 重载类的初始化函数
BOOL 借书还书标签::OnInitDialog()
{
	CDialog::OnInitDialog();
	Username=theApp.Username;
	LoginTime=theApp.Logintime;
	LimitTime=theApp.LimitTime;
	MD5 LeTurn;
	LeTurn.update(LoginTime.GetBuffer());    //因为update函数只接收string类型，所以使用getbuffer()函数转换CString为string
    LoginTime.ReleaseBuffer();
	LoginTime=LeTurn.toString().c_str();     //toString()函数获得加密字符串，c_str();函数重新转换成CString类型
	LoginTime.MakeUpper();//把加密之后的密码的字符串全部大写
	CString Appkey = LoginTime.Right(10);
	CString Apppass= LoginTime.Left(10);
	SQL_server();
   SQL.Format("select * from user where username='%s'",Username);
   SQLtosql();
   mysql_query(conn,sql);
   res=mysql_store_result(conn);
   row=mysql_fetch_row(res);
   CString oldAppkey=row[5];
   SQL.Format("update appkey set keystate=0 where keyvaule ='%s'",oldAppkey);
   SQLtosql();
   mysql_query(conn,sql);;
   SQL.Format("update user set keyvalue='%s' where username ='%s'",Appkey,Username);
   SQLtosql();
   mysql_query(conn,sql);
   SQL.Format("insert into appkey(keypass,keyvalue,limittime,keystate) value('%s','%s','%s',1)",Apppass,Appkey,LimitTime);
   SQLtosql();
   mysql_query(conn,sql);
   
	CString Url_Qr_string;
	Url_Qr_string.Format("http://mysscloud.xyz/qr/showpic.php?keyvalue=%s&keypass=%s",Appkey,Apppass);
    
	PIC_QR.Navigate(Url_Qr_string,NULL,NULL,NULL,NULL);
	return TRUE;
}


void 借书还书标签::	SQL_server(void)
{
	conn= mysql_init((MYSQL*) 0);//初始化mysql结构
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql结构，数据库服务器地址，数据库用户名，数据库密码，数据库名，端口号，（下面两个参数是mysql连接配置，一般不需更改）
	{MessageBox("数据库连接失败！");exit(0);}//数据库连接失败退出程序
	else{ mysql_query(conn, "set names gbk"); }//设置MYSQL返回的编码为gbk，与项目使用的多字符编码相兼容。
}

void 借书还书标签::SQLtosql(void)
{
    sql=SQL.GetBuffer();  //把GCstr 转换到str中去 
	SQL.ReleaseBuffer();  //释放缓冲区
}

