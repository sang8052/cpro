// 图书查询标签.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "图书查询标签.h"


// 图书查询标签 对话框

IMPLEMENT_DYNAMIC(图书查询标签, CDialog)

图书查询标签::图书查询标签(CWnd* pParent /*=NULL*/)
	: CDialog(图书查询标签::IDD, pParent)
	, SBookName(_T(""))
	, SbookPrint(_T(""))
{

}

图书查询标签::~图书查询标签()
{
}

void 图书查询标签::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SELECT, SelectList);
	DDX_Text(pDX, IDC_EDIT_NAME, SBookName);
	DDX_Text(pDX, IDC_EDIT_WRITTER, SbookWritter);
	DDX_Text(pDX, IDC_EDIT_PRINT, SbookPrint);
}


BEGIN_MESSAGE_MAP(图书查询标签, CDialog)
	ON_BN_CLICKED(IDC_SELECT, &图书查询标签::OnBnClickedSelect)
	ON_BN_CLICKED(IDC_SELECT_RESET, &图书查询标签::OnBnClickedSelectReset)
	ON_BN_CLICKED(IDC_SELECT_DEL, &图书查询标签::OnBnClickedSelectDel)
END_MESSAGE_MAP()


// 重载类的初始化函数

BOOL 图书查询标签::OnInitDialog(void)
{
	CDialog::OnInitDialog();
	SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	/*SelectList.SetColumnWidth(0,100);*///设置编号为0的列列宽为100 （上面的函数已经设置，这里只是多写一种写法）
	SelectList.InsertColumn(0,"图书号",0,118);
	SelectList.InsertColumn(1,"书名",0,118);
	SelectList.InsertColumn(2,"作者",0,118);
	SelectList.InsertColumn(3,"出版商",0,168);
	SelectList.InsertColumn(4,"出版时间",0,118);
	SelectList.InsertColumn(5,"单价",0,115);
	sql_connect();
    OnBnClickedSelect();
	return TRUE;
}

void 图书查询标签::sql_connect(void)
{
	conn= mysql_init((MYSQL*) 0);//初始化mysql结构
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql结构，数据库服务器地址，数据库用户名，数据库密码，数据库名，端口号，（下面两个参数是mysql连接配置，一般不需更改）
	{MessageBox("数据库连接失败！");exit(0);}//数据库连接失败退出程序
	else{ mysql_query(conn, "set names gbk"); }//设置MYSQL返回的编码为gbk，与项目使用的多字符编码相兼容。
}

void 图书查询标签::SQLtosql(void)
{
	sql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
}



void 图书查询标签::OnBnClickedSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	SQL.Format("");
	SelectList.DeleteAllItems();   //删除所有行中的数据
	if(SBookName=="")
	{
		if(SbookWritter=="")
		{
			if(SbookPrint=="")
			{
				SQL.Format("select * from booktype");
			}
			else{SQL.Format("select * from booktype where bookprint='%s'",SbookPrint);}
		}
		else
		{
			if(SbookPrint=="")
			{SQL.Format("select * from booktype where bookwritter='%s'",SbookWritter);}
			else{SQL.Format("select * from booktype where bookwritter='%s' and bookprint='%s'",SbookWritter,SbookPrint);}
		 }
	}
	else
	{
		if(SbookWritter==""&&SbookPrint=="")
		{
			SQL.Format("select * from booktype where bookname='%s'",SBookName);
		}
		else
		{
		    MessageBox("系统暂不支持这样的查询方式！");
		}
	
	}
	if(SQL!="")
	{
		SQLtosql();
		mysql_query(conn,sql);
		res=mysql_store_result(conn);
		int i=0;
		while(row=mysql_fetch_row(res))
		{
			CString Item;
			Item.Format("第%d行",i);
			SelectList.InsertItem(i,Item);
			SelectList.SetItemText(i,0,row[0]);
			SelectList.SetItemText(i,1,row[1]);
			SelectList.SetItemText(i,2,row[2]);
			SelectList.SetItemText(i,3,row[3]);
			SelectList.SetItemText(i,4,row[4]);
			CString price;
		    double show ;
		   show=atof(row[5]);
		    price.Format("%.2lf",show);
			SelectList.SetItemText(i,5,price);
			i++;
			
		}

	}
}

void 图书查询标签::OnBnClickedSelectReset()
{
	// TODO: 在此添加控件通知处理程序代码
	if(CheckPower())
	{
	int Item;
	Item=SelectList.GetSelectionMark();
	CString showdata;
	showdata=SelectList.GetItemText(Item,0);
    theApp.data=showdata;
	修改图书信息弹窗 RESET;
	RESET.DoModal();
	
	MessageBox("修改成功！");
    OnBnClickedSelect();
	}
    else
	{
	MessageBox("您没有足够的权限！请联系管理员处理！");
	}
 
}

void 图书查询标签::OnBnClickedSelectDel()
{
	// TODO: 在此添加控件通知处理程序代码
	if(CheckPower())
	{
	int Item;
	Item=SelectList.GetSelectionMark();
	CString showdata;
	showdata=SelectList.GetItemText(Item,0);
	SQL.Format("delete from booktype where id='%s'",showdata);
	SQLtosql();
	mysql_query(conn,sql);
	SQL.Format("delete from booknum where bookid='%s'",showdata);
	SQLtosql();
	mysql_query(conn,sql);
	MessageBox("删除成功！");
    OnBnClickedSelect();
	}
	else
	{
	MessageBox("您没有足够的权限！请联系管理员处理！");
	}
}

bool 图书查询标签::CheckPower(void)
{
	SQL.Format("select * from user where username='%s'",theApp.Username);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	if(atoi(row[6])==0){return true;}
	else{return false;}
}


	BOOL   图书查询标签::PreTranslateMessage(MSG*   pMsg)    
  {  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_ESCAPE)     return   TRUE;  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_RETURN)   return  	TRUE;    
    else    
          return   CDialog::PreTranslateMessage(pMsg);  
  }



