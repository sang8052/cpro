// 修改图书信息弹窗.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "修改图书信息弹窗.h"


// 修改图书信息弹窗 对话框

IMPLEMENT_DYNAMIC(修改图书信息弹窗, CDialog)

修改图书信息弹窗::修改图书信息弹窗(CWnd* pParent /*=NULL*/)
	: CDialog(修改图书信息弹窗::IDD, pParent)
	, RESET_PRICE(_T(""))
	, RESET_TIME(_T(""))
	, RESET_PRINT(_T(""))
	, SETWRITTER(_T(""))
	, RESET_NAME(_T(""))
	, RESET_ID(_T(""))
{

}

修改图书信息弹窗::~修改图书信息弹窗()
{
}

void 修改图书信息弹窗::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESET_PRICE, RESET_PRICE);
	DDX_Text(pDX, IDC_ERESET_TIME, RESET_TIME);
	DDX_Text(pDX, IDC_RESET_PRINT, RESET_PRINT);
	DDX_Text(pDX, IDC_RESET_WRITTER, SETWRITTER);
	DDX_Text(pDX, IDC_RESET_NAME, RESET_NAME);
	DDX_Text(pDX, IDC_RESET_ID, RESET_ID);
}


BEGIN_MESSAGE_MAP(修改图书信息弹窗, CDialog)
	ON_BN_CLICKED(IDCANCEL, &修改图书信息弹窗::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &修改图书信息弹窗::OnBnClickedOk)
END_MESSAGE_MAP()


// 重载类的初始化函数

BOOL 修改图书信息弹窗::OnInitDialog()
{
	CDialog::OnInitDialog();
    sql_connect();
    SetData();
	return TRUE;
}

void 修改图书信息弹窗::SQLtosql(void)
{
	sql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
}

void 修改图书信息弹窗::sql_connect(void)
{
		conn= mysql_init((MYSQL*) 0);//初始化mysql结构
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql结构，数据库服务器地址，数据库用户名，数据库密码，数据库名，端口号，（下面两个参数是mysql连接配置，一般不需更改）
	{MessageBox("数据库连接失败！");exit(0);}//数据库连接失败退出程序
	else{ mysql_query(conn, "set names gbk"); }//设置MYSQL返回的编码为gbk，与项目使用的多字符编码相兼容
}

void 修改图书信息弹窗::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}

void 修改图书信息弹窗::SetData()
{
	ResetBookid=theApp.data;
	SQL.Format("select * from booktype where id='%s'",ResetBookid);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	RESET_ID=ResetBookid;
	RESET_NAME=row[1];
	SETWRITTER=row[2];
	RESET_PRINT=row[3];
	RESET_TIME=row[4];
	RESET_PRICE=row[5];
	UpdateData(false);


}

void 修改图书信息弹窗::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(true);
	SQL.Format("update booktype set bookname='%s', bookwritter='%s', bookprint='%s', bookprinttime='%s', bookprice='%s' where id='%s'",RESET_NAME,SETWRITTER,RESET_PRINT,RESET_TIME,RESET_PRICE,RESET_ID);
	SQLtosql();
	mysql_query(conn,sql);
	OnCancel();
}
