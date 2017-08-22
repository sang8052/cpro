// 新书入库标签.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "新书入库标签.h"


// 新书入库标签 对话框

IMPLEMENT_DYNAMIC(新书入库标签, CDialog)

新书入库标签::新书入库标签(CWnd* pParent /*=NULL*/)
	: CDialog(新书入库标签::IDD, pParent)
	, AddNum(_T(""))
	, AddName(_T(""))
	, AddWritter(_T(""))
	, AddPrint(_T(""))
	, AddPrinttime(_T(""))
	, AddPrice(_T(""))
	, Addamount(_T(""))
{

}

新书入库标签::~新书入库标签()
{
}

void 新书入库标签::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADD_NUM, AddNum);
	DDX_Text(pDX, IDC_ADD_BOOKNAME, AddName);
	DDX_Text(pDX, IDC_ADD_BOOKWRITTER, AddWritter);
	DDX_Text(pDX, IDC_ADD_PRINT, AddPrint);
	DDX_Text(pDX, IDC_ADD_PRINTTIME, AddPrinttime);
	DDX_Text(pDX, IDC_ADD_BOOKPRICE, AddPrice);
	DDX_Text(pDX, IDC_ADD_AMOUNT, Addamount);
}


BEGIN_MESSAGE_MAP(新书入库标签, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON_ADD, &新书入库标签::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &新书入库标签::OnBnClickedButtonReset)
END_MESSAGE_MAP()


// 重载类的初始化函数

BOOL 新书入库标签::OnInitDialog(void)
{
	CDialog::OnInitDialog();
    sql_connect();
	SQL.Format("select * from booktype where id = (select max(id) from booktype)");
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	int temp=atoi(row[0]);
	temp=temp+1;
	AddNum.Format("%d",temp);
	UpdateData(false);
	return TRUE;
}

void 新书入库标签::SQLtosql(void)
{
	sql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
}

void 新书入库标签::sql_connect(void)
{
	conn= mysql_init((MYSQL*) 0);//初始化mysql结构
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql结构，数据库服务器地址，数据库用户名，数据库密码，数据库名，端口号，（下面两个参数是mysql连接配置，一般不需更改）
	{MessageBox("数据库连接失败！");exit(0);}//数据库连接失败退出程序
	else{ mysql_query(conn, "set names gbk"); }//设置MYSQL返回的编码为gbk，与项目使用的多字符编码相兼容。
}



bool 新书入库标签::CheckAdd(void)
{
	
	if(AddName==""){MessageBox("请输入新增图书的名称！");return false;}
	if(AddWritter==""){MessageBox("请输入新增图书的作者！");return false;}
	if(AddPrint==""){MessageBox("请输入新增图书的出版商！");return false;}
	if(AddPrinttime==""){MessageBox("请输入新增图书的出版时间！");return false;}
	if(Addamount==""){MessageBox("请输入新增图书的数量！");return false;}
	if(AddPrice==""){MessageBox("请输入新增图书的单价！");return false;}
	double price=atof(AddPrice);
	double amount=atof(Addamount);
	if(price>0)
	{
		if(ChectInt(amount)&&amount<=99999){return true;}
		else{MessageBox("请输入正确的图书数量");return false;}
	}
	else {
     MessageBox("请输入正确的图书单价");return false;
	}

}


bool 新书入库标签::ChectInt(double a)
{
	int b;
	double temp;
	temp=a;
	b=(int)a;
	if(temp-b==0)
	{return true;}
	else{return false;}
}

void 新书入库标签::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(CheckAdd())
	{
		double AddPrice_double=atof(AddPrice);
		SQL.Format("insert into booktype (id,bookname,bookwritter,bookprint,bookprinttime,bookprice) value ('%s','%s','%s','%s','%s',%lf)",AddNum,AddName,AddWritter,AddPrint,AddPrinttime,AddPrice_double);
		SQLtosql();
		mysql_query(conn,sql);
		int Addamount_int=atoi(Addamount);
		for(int i=1;i<=Addamount_int;i++)
		{
             if(Addamount_int<=9)
			 {
				 SQL.Format("insert into booknum (booknum,bookid,bookstate,lendtime,lenduser) value ('%s0000%d','%s',0,'','')",AddNum,i,AddNum);
		         SQLtosql();
		         mysql_query(conn,sql);
			 }
			 if(Addamount_int>9&&Addamount_int<=99)
			 {
                 SQL.Format("insert into booknum (booknum,bookid,bookstate,lendtime,lenduser) value ('%s000%d','%s',0,'','')",AddNum,i,AddNum);
		         SQLtosql();
		         mysql_query(conn,sql);
			 }
			 if(Addamount_int>99&&Addamount_int<=999)
			 {
                   SQL.Format("insert into booknum (booknum,bookid,bookstate,lendtime,lenduser) value ('%s00%d','%s',0,'','')",AddNum,i,AddNum);
		         SQLtosql();
		         mysql_query(conn,sql);
			 }
			 if(Addamount_int>999&&Addamount_int<=9999)
			 {
                    SQL.Format("insert into booknum (booknum,bookid,bookstate,lendtime,lenduser) value ('%s0%d','%s',0,'','')",AddNum,i,AddNum);
		         SQLtosql();
		         mysql_query(conn,sql);
			 }
			 if(Addamount_int>9999&&Addamount_int<=99999)
			 {
                  SQL.Format("insert into booknum (booknum,bookid,bookstate,lendtime,lenduser) value ('%s%d','%s',0,'','')",AddNum,i,AddNum);
		         SQLtosql();
		         mysql_query(conn,sql);
			 }
		}
     MessageBox("添加成功！");
	}
}

void 新书入库标签::OnBnClickedButtonReset()
{
	// TODO: 在此添加控件通知处理程序代码
	Addamount.Format("");
	AddName.Format("");
	AddPrice.Format("");
	AddPrint.Format("");
	AddPrinttime.Format("");
	AddWritter.Format("");
	UpdateData(false);
		
}
