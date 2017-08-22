// 我借的书标签.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "我借的书标签.h"


// 我借的书标签 对话框

IMPLEMENT_DYNAMIC(我借的书标签, CDialog)

我借的书标签::我借的书标签(CWnd* pParent /*=NULL*/)
	: CDialog(我借的书标签::IDD, pParent)
{

}

我借的书标签::~我借的书标签()
{
}

void 我借的书标签::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MYLEND, MyLendList);
}


BEGIN_MESSAGE_MAP(我借的书标签, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LIST_REFLASH, &我借的书标签::OnBnClickedButtonListReflash)
END_MESSAGE_MAP()


// 重载类的初始化函数

BOOL 我借的书标签::OnInitDialog(void)
{
	CDialog::OnInitDialog();
	MyLendList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	MyLendList.InsertColumn(0,"唯一图书码",0,110);//设置列的编号、名字、格式、宽度
	/*MyLendList.SetColumnWidth(0,100);*///设置编号为0的列列宽为100 （上面的函数已经设置，这里只是多写一种写法）
	MyLendList.InsertColumn(1,"图书号",0,100);
	MyLendList.InsertColumn(2,"书名",0,100);
	MyLendList.InsertColumn(3,"作者",0,100);
	MyLendList.InsertColumn(4,"出版商",0,150);
	MyLendList.InsertColumn(5,"出版时间",0,100);
	MyLendList.InsertColumn(6,"单价",0,95);
	SetData();
    return TRUE;
}



void 我借的书标签::SetData(void)
{
	MyLendList.DeleteAllItems();   //删除所有行中的数据
	sql_connect();
	SQL.Format("select * from booknum where lenduser='%s' order by bookid ",theApp.Username);
	SQLtosql();
	mysql_query(conn,sql);
    res=mysql_store_result(conn);
	int i=0;
	
	while(row=mysql_fetch_row(res))
	{   CString Item;
	    Item.Format("第%d行",i);
		MyLendList.InsertItem(i,Item);
		MyLendList.SetItemText(i,0,row[0]);
        MyLendList.SetItemText(i,1,row[1]);
		SQL.Format("select * from booktype where id='%s'",row[1]);
		SQLtosql();
		mysql_query(conn,sql);
		bres=mysql_store_result(conn);
		brow=mysql_fetch_row(bres);
        MyLendList.SetItemText(i,2,brow[1]);
        MyLendList.SetItemText(i,3,brow[2]);
		MyLendList.SetItemText(i,4,brow[3]);
		MyLendList.SetItemText(i,5,brow[4]);
		CString price;
		double show ;
		show=atof(brow[5]);
		price.Format("%.2lf",show);
        MyLendList.SetItemText(i,6,price);
		i++;

    }


}

void 我借的书标签::sql_connect(void)
{
    conn= mysql_init((MYSQL*) 0);//初始化mysql结构
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql结构，数据库服务器地址，数据库用户名，数据库密码，数据库名，端口号，（下面两个参数是mysql连接配置，一般不需更改）
	{MessageBox("数据库连接失败！");exit(0);}//数据库连接失败退出程序
	else{ mysql_query(conn, "set names gbk"); }//设置MYSQL返回的编码为gbk，与项目使用的多字符编码相兼容。
}

void 我借的书标签::SQLtosql(void)
{
    sql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
}

void 我借的书标签::OnBnClickedButtonListReflash()
{
	// TODO: 在此添加控件通知处理程序代码
	SetData();

}
