// FunIndex.cpp : 实现文件
//

#include "stdafx.h"
#include "lib.h"
#include "FunIndex.h"


// FunIndex 对话框

IMPLEMENT_DYNAMIC(FunIndex, CDialog)

FunIndex::FunIndex(CWnd* pParent /*=NULL*/)
	: CDialog(FunIndex::IDD, pParent)
	, Messagein(_T(""))
	, Messageout01(_T(""))
	, Messageout02(_T(""))
{

}

FunIndex::~FunIndex()
{
}

void FunIndex::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER_QR, Url_Qr);
	DDX_Text(pDX, IDC_EDIT1, Messagein);
	DDX_Text(pDX, IDC_EDIT3, Messageout01);
	DDX_Text(pDX, IDC_EDIT4, Messageout02);
}


BEGIN_MESSAGE_MAP(FunIndex, CDialog)
	ON_COMMAND(ID_32785, &FunIndex::Menu_About)
	ON_COMMAND(ID_32794, &FunIndex::Menu_Thanks)
	ON_COMMAND(ID_32790, &FunIndex::Menu_Select)
	ON_COMMAND(ID_32795, &FunIndex::Menu_MyLend)
	ON_COMMAND(ID_32792, &FunIndex::Menu_AddTbook)
	ON_COMMAND(ID_32793, &FunIndex::Menu_AddNbook)
	ON_BN_CLICKED(IDC_BUTTON3_search, &FunIndex::OnBnClickedButton3search)
	ON_EN_CHANGE(IDC_EDIT3, &FunIndex::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &FunIndex::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT1, &FunIndex::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1_lend, &FunIndex::OnBnClickedButton1lend)
	ON_BN_CLICKED(IDC_BUTTON2_return, &FunIndex::OnBnClickedButton2return)
	ON_BN_CLICKED(IDC_BUTTON4_reflash, &FunIndex::OnBnClickedButton4reflash)
END_MESSAGE_MAP()


BOOL FunIndex::OnInitDialog()
{
	CDialog::OnInitDialog();
    // TODO: 在此添加额外的初始化代码
	MD5 LeTurn;
	LeTurn.update(LoginTime.GetBuffer());    //因为update函数只接收string类型，所以使用getbuffer()函数转换CString为string
    LoginTime.ReleaseBuffer();
	LoginTime=LeTurn.toString().c_str();     //toString()函数获得加密字符串，c_str();函数重新转换成CString类型
	LoginTime.MakeUpper();//把加密之后的密码的字符串全部大写
	CString Appkey = LoginTime.Right(10);
	CString Apppass= LoginTime.Left(10);
    Server_Connect();
    SQL.Format("select * from user where username='%s'",username);
	TempSql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,TempSql);
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	CString oldAppkey=row[5];
    SQL.Format("update appkey set keystate=0 where keyvaule ='%s'",oldAppkey);
	TempSql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,TempSql);
	SQL.Format("update user set keyvalue='%s' where username ='%s'",Appkey,username);
	TempSql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,TempSql);
	SQL.Format("insert into appkey(keypass,keyvalue,limittime,keystate) value('%s','%s','%s',1)",Apppass,Appkey,LimitTime);
	TempSql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,TempSql);
	CString Url_Qr_string;
	Url_Qr_string.Format("http://mysscloud.xyz/qr/showpic.php?keyvalue=%s&keypass=%s",Appkey,Apppass);
	Url_Qr.Navigate(Url_Qr_string,NULL,NULL,NULL,NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


// 连接数据库服务器

int FunIndex::Server_Connect(void)
{
	 conn= mysql_init((MYSQL*) 0);//初始化mysql结构
	if(!mysql_real_connect(conn,"116.196.81.185","cpro","98766789","cpro",3306,NULL,0)) //mysql结构，数据库服务器地址，数据库用户名，数据库密码，数据库名，端口号，（下面两个参数是mysql连接配置，一般不需更改）
	{return 0;}//数据库连接失败
	else{ mysql_query(conn, "set names gbk"); return 1;}
}

void FunIndex::SetData(CString getname,CString getlogintime,CString getlimittime)
{
      username=getname;
	  LoginTime=getlogintime;
	  LimitTime=getlimittime;
}



BEGIN_EVENTSINK_MAP(FunIndex, CDialog)
	ON_EVENT(FunIndex, IDC_EXPLORER_QR, 259, FunIndex::DocumentCompleteExplorerQr, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

void FunIndex::DocumentCompleteExplorerQr(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO: 在此处添加消息处理程序代码
	HRESULT hr;  
pDisp = this->Url_Qr.get_Document();              
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

void FunIndex::Menu_About()
{
	// TODO: 在此添加命令处理程序代码
	if(DlgAbout.m_hWnd==0)
	{
		DlgAbout.Create(IDD_FUN_ABOUT,this);
	}
	DlgAbout.GetVersion();
	DlgAbout.ShowWindow(SW_SHOW);
}

void FunIndex::Menu_Thanks()
{
	// TODO: 在此添加命令处理程序代码
	if(DlgThank.m_hWnd==0)
	{
		DlgThank.Create(IDD_FUN_THANKS,this);
	}
	DlgThank.SetData();
	DlgThank.ShowWindow(SW_SHOW);

}

void FunIndex::Menu_Select()
{
	// TODO: 在此添加命令处理程序代码
}

void FunIndex::Menu_MyLend()
{
	// TODO: 在此添加命令处理程序代码
}

void FunIndex::Menu_AddTbook()
{
	// TODO: 在此添加命令处理程序代码
}

void FunIndex::Menu_AddNbook()
{
	// TODO: 在此添加命令处理程序代码
}


void FunIndex::OnBnClickedButton3search()
{
	// TODO: 在此添加控件通知处理程序代码
CString stringSQL01,stringSQL02;
CString ID,NAME;
CString state;
int MessageNum,x;
string zhouyang,shangyihui;

OnEnChangeEdit1();

SQL.Format("select * from booknum where booknum='%s'",Messagein);

stringSQL01=SQL.GetBuffer();
SQL.ReleaseBuffer();
mysql_query(conn,stringSQL01);
res= mysql_store_result(conn);
row=mysql_fetch_row(res);//把结果集变成数组
MessageNum=mysql_num_rows(res);
if(MessageNum==1)
{
ID.Format("%s",row[1]);
state.Format("%s",row[2]);
SQL.Format("select * from booktype where ID='%s'",ID);
stringSQL02=SQL.GetBuffer();
ID.ReleaseBuffer();
mysql_query(conn,stringSQL02);
res=mysql_store_result(conn);
row=mysql_fetch_row(res);
NAME.Format("%s",row[1]);
Messageout01=NAME;
x=atoi(state);
if(x==0)
{
	Messageout02.Format("未借出");
}else{
	Messageout02.Format("已借出");
}
OnEnChangeEdit3();OnEnChangeEdit4();
}
else{
	MessageBox("请输入正确的ID！");
}
}

void FunIndex::OnEnChangeEdit3()
{
	UpdateData(false);
}

void FunIndex::OnEnChangeEdit4()
{
	UpdateData(false);	
}

void FunIndex::OnEnChangeEdit1()
{
	UpdateData(true);
}

void FunIndex::OnBnClickedButton1lend()
{
	CTime time;  
    time=CTime::GetCurrentTime();
	CString strDateTime;
	strDateTime=time.Format(_T("%Y-%m-%d %H:%M:%S"));
	CString stringSQL01,stringSQL02;
	int MessageNum;
	CString state;
	int x;//
OnEnChangeEdit1();
SQL.Format("select * from booknum where booknum='%s'",Messagein);
stringSQL01=SQL.GetBuffer();
SQL.ReleaseBuffer();
mysql_query(conn,stringSQL01);
res= mysql_store_result(conn);
row=mysql_fetch_row(res);//把结果集变成数组
MessageNum=mysql_num_rows(res);
if(MessageNum==1)//借书
{
	state.Format("%s",row[2]);
	x=atoi(state);
	if(x==0){
	SQL.Format("update booknum  set bookstate=1,lendtime='%s',lenduser='%s' where booknum='%s'",strDateTime,username,Messagein);
	stringSQL02=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,stringSQL02);
	OnBnClickedButton3search();
	MessageBox("借书成功！");
	}else
	{
		MessageBox("此书已经借出！");
	}
}else{
	MessageBox("请输入正确的ID号！");}     
}

void FunIndex::OnBnClickedButton2return()
{
	// TODO: 在此添加控件通知处理程序代码
	CString stringSQL01,stringSQL02;
	int MessageNum,x;
	CString state;
OnEnChangeEdit1();
SQL.Format("select * from booknum where booknum='%s'",Messagein);
stringSQL01=SQL.GetBuffer();
SQL.ReleaseBuffer();
mysql_query(conn,stringSQL01);
res= mysql_store_result(conn);
row=mysql_fetch_row(res);//把结果集变成数组
MessageNum=mysql_num_rows(res);
if(MessageNum==1)//还书
{
	state.Format("%s",row[2]);
	x=atoi(state);
	if(x==1){
	SQL.Format("update booknum  set bookstate=0 ,lendtime='', lenduser='' where booknum='%s'",Messagein);
	stringSQL02=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,stringSQL02);
	OnBnClickedButton3search();
    MessageBox("还书成功！");
	}else
	{
		MessageBox("此书已经归还！");
	}

}else{
	MessageBox("请输入正确的ID号！");} 
}

BOOL FunIndex::PreTranslateMessage(MSG* pMsg)
{
    // TODO:  在此添加专用代码和/或调用基类
    if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
    {
        // 如果消息是键盘按下事件，且是Esc键，执行以下代码（什么都不做，你可以自己添加想要的代码）
        return TRUE;
    }
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        // 如果消息是键盘按下事件，且是Entert键，执行以下代码（什么都不做，你可以自己添加想要的代码）
        return TRUE;
    }
    return CDialog::PreTranslateMessage(pMsg);
}
void FunIndex::OnBnClickedButton4reflash()
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
    Server_Connect();
	SQL.Format("select * from user where username='%s'",username);
	TempSql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,TempSql);
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	CString oldAppkey=row[5];
    SQL.Format("update appkey set keystate=0 where keyvaule ='%s'",oldAppkey);
	TempSql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,TempSql);
	SQL.Format("update user set keyvalue='%s' where username ='%s'",Appkey,username);
	TempSql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,TempSql);
	SQL.Format("insert into appkey(keypass,keyvalue,limittime,keystate) value('%s','%s','%s',1)",Apppass,Appkey,strlimittime);
	TempSql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,TempSql);
	CString Url_Qr_string;
	Url_Qr_string.Format("http://mysscloud.xyz/qr/showpic.php?keyvalue=%s&keypass=%s",Appkey,Apppass);
	Url_Qr.Navigate(Url_Qr_string,NULL,NULL,NULL,NULL);

}
