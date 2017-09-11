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
	, EDIT_BOOKNAME(_T(""))
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
	DDX_Text(pDX, IDC_EDIT_BOOKNAME, EDIT_BOOKNAME);
	DDX_Text(pDX, IDC_EDIT_BOOKWRITER, EDIT_WRITTER);
	DDX_Text(pDX, IDC_EDIT_BOOKSTATE, EDIT_STATE);

	DDX_Control(pDX, IDC_EXPLORER_QR, PIC_QR);
}


BEGIN_MESSAGE_MAP(借书还书标签, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_REFALSH, &借书还书标签::OnBnClickedButtonRefalsh)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &借书还书标签::OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_LEND, &借书还书标签::OnBnClickedButtonLend)
	ON_BN_CLICKED(IDC_BUTTON_RETURN, &借书还书标签::OnBnClickedButtonReturn)
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
   SQL.Format("update appkey set keystate=0 where keyvalue ='%s'",oldAppkey);
   SQLtosql();
   mysql_query(conn,sql);;
   SQL.Format("update user set keyvalue='%s' where username ='%s'",Appkey,Username);
   SQLtosql();
   mysql_query(conn,sql);
   SQL.Format("insert into appkey(keypass,keyvalue,limittime,keystate) value('%s','%s','%s',1)",Apppass,Appkey,LimitTime);
   SQLtosql();
   mysql_query(conn,sql);
   
	CString Url_Qr_string;
	Url_Qr_string.Format("http://www.mysscloud.xyz/qr/showpic.php?keyvalue=%s&keypass=%s",Appkey,Apppass);
    
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

BEGIN_EVENTSINK_MAP(借书还书标签, CDialog)
	ON_EVENT(借书还书标签, IDC_EXPLORER_QR, 259, 借书还书标签::DocumentCompleteExplorerQr, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

void 借书还书标签::DocumentCompleteExplorerQr(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO: 在此处添加消息处理程序代码
		HRESULT hr;  
pDisp = this->PIC_QR.get_Document();              
IHTMLDocument2 *pDocument1 = NULL;  
IHTMLElement*   pE2;    
IHTMLBodyElement * pBodyE2;    
hr = pDisp->QueryInterface(IID_IHTMLDocument2, (void**)&pDocument1);  
if(SUCCEEDED(pDocument1->get_body(&pE2)))    
{    
    if(SUCCEEDED(pE2->QueryInterface(IID_IHTMLBodyElement,   (void**)&pBodyE2)))    
    {    
        pBodyE2->put_scroll(L"no");//去滚动条  
    }    
    IHTMLStyle   *phtmlStyle2;    
    pE2->get_style(&phtmlStyle2);    
   
    if(phtmlStyle2 != NULL)    
    {    
        phtmlStyle2->put_overflow(L"hidden");    
        phtmlStyle2->put_border(L"none");//   去除边框       
        phtmlStyle2->Release();    
        pE2->Release();    
    }    
}
}

void 借书还书标签::OnBnClickedButtonRefalsh()
{
	// TODO: 在此添加控件通知处理程序代码
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
    MD5 LeTurn;
	LeTurn.update(strDateTime.GetBuffer());    //因为update函数只接收string类型，所以使用getbuffer()函数转换CString为string
    strDateTime.ReleaseBuffer();
	strDateTime=LeTurn.toString().c_str();     //toString()函数获得加密字符串，c_str();函数重新转换成CString类型
	strDateTime.MakeUpper();//把加密之后的密码的字符串全部大写
	CString Appkey = strDateTime.Right(10);
	CString Apppass= strDateTime.Left(10);
	SQL.Format("select * from user where username='%s'",Username);
   SQLtosql();
   mysql_query(conn,sql);
   res=mysql_store_result(conn);
   row=mysql_fetch_row(res);
   CString oldAppkey=row[5];
   SQL.Format("update appkey set keystate=0 where keyvalue ='%s'",oldAppkey);
   SQLtosql();
   mysql_query(conn,sql);;
   SQL.Format("update user set keyvalue='%s' where username ='%s'",Appkey,Username);
   SQLtosql();
   mysql_query(conn,sql);
   SQL.Format("insert into appkey(keypass,keyvalue,limittime,keystate) value('%s','%s','%s',1)",Apppass,Appkey,strlimittime);
   SQLtosql();
   mysql_query(conn,sql);
   
	CString Url_Qr_string;
	Url_Qr_string.Format("http://www.mysscloud.xyz/qr/showpic.php?keyvalue=%s&keypass=%s",Appkey,Apppass);
    
	PIC_QR.Navigate(Url_Qr_string,NULL,NULL,NULL,NULL);
    
}

void 借书还书标签::OnBnClickedButtonSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	my_ulonglong SQLchanges;
	UpdateData(true);
	SQL.Format("select * from booknum where booknum='%s'",EDIT_BOOKNUM);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	SQLchanges=mysql_num_rows(res);
	if(SQLchanges==0){
		MessageBox("您输入的唯一图书码有误，请查证后重新输入！");
		EDIT_BOOKNAME.Format("");
		EDIT_STATE.Format("");
		EDIT_WRITTER.Format("");
		UpdateData(false);
	}
	else{
		    row=mysql_fetch_row(res);
	        CString BOOKID;
			BOOKID=row[1];
			bookstate=atoi(row[2]);
			if(bookstate==0){EDIT_STATE.Format("尚未借出");}
			else{EDIT_STATE.Format("已借出");}
			SQL.Format("select * from booktype where id='%s'",BOOKID);
			SQLtosql();
			mysql_query(conn,sql);
			res=mysql_store_result(conn);
			row=mysql_fetch_row(res);
			EDIT_BOOKNAME=row[1];
			EDIT_WRITTER=row[2];
			UpdateData(false);
	   } 
}

void 借书还书标签::OnBnClickedButtonLend()
{
	// TODO: 在此添加控件通知处理程序代码
	my_ulonglong SQLchanges;
	UpdateData(true);
	SQL.Format("select * from booknum where booknum='%s'",EDIT_BOOKNUM);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	SQLchanges=mysql_num_rows(res);
	if(SQLchanges==0){
		MessageBox("您输入的唯一图书码有误，请查证后重新输入！");
		EDIT_BOOKNAME.Format("");
		EDIT_STATE.Format("");
		EDIT_WRITTER.Format("");
		UpdateData(false);
	}
	else{
		    row=mysql_fetch_row(res);
	        CString BOOKID;
			BOOKID=row[1];
			bookstate=atoi(row[2]);
			if(bookstate!=0){MessageBox("错误：此书已经被借出！");}
			else
			{   
                CTime time;  
                time=CTime::GetCurrentTime();
				CString strDateTime;
				strDateTime=time.Format(_T("%Y-%m-%d %H:%M:%S"));
				SQL.Format("update booknum set bookstate=1, lendtime='%s', lenduser='%s' where booknum='%s'",strDateTime,theApp.Username,EDIT_BOOKNUM);
				SQLtosql();
				mysql_query(conn,sql);
				MessageBox("借书成功！");
                OnBnClickedButtonSelect();
				
			}
	   } 
}

void 借书还书标签::OnBnClickedButtonReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	my_ulonglong SQLchanges;
	UpdateData(true);
	SQL.Format("select * from booknum where booknum='%s'",EDIT_BOOKNUM);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	SQLchanges=mysql_num_rows(res);
	if(SQLchanges==0)
	{
		MessageBox("您输入的唯一图书码有误，请查证后重新输入！");
		EDIT_BOOKNAME.Format("");
		EDIT_STATE.Format("");
		EDIT_WRITTER.Format("");
		UpdateData(false);
	}
	else{
		    row=mysql_fetch_row(res);
	        CString BOOKID;
			BOOKID=row[1];
			bookstate=atoi(row[2]);
			if(bookstate!=1){MessageBox("错误：此书尚未被借出！");}
			else
			{   
                CTime time;  
                time=CTime::GetCurrentTime();
				CString strDateTime;
				strDateTime=time.Format(_T("%Y-%m-%d %H:%M:%S"));
				SQL.Format("update booknum set bookstate=0, lendtime='', lenduser='' where booknum='%s'",EDIT_BOOKNUM);
				SQLtosql();
				mysql_query(conn,sql);
				MessageBox("还书成功！");
                OnBnClickedButtonSelect();
				
			}
	   } 
}


BOOL   借书还书标签::PreTranslateMessage(MSG*   pMsg)    
  {  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_ESCAPE)     return   TRUE;  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_RETURN)   return  	TRUE;    
    else    
          return   CDialog::PreTranslateMessage(pMsg);  
  }
