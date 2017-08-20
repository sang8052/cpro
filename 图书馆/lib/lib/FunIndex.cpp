// FunIndex.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lib.h"
#include "FunIndex.h"


// FunIndex �Ի���

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
    // TODO: �ڴ���Ӷ���ĳ�ʼ������
	MD5 LeTurn;
	LeTurn.update(LoginTime.GetBuffer());    //��Ϊupdate����ֻ����string���ͣ�����ʹ��getbuffer()����ת��CStringΪstring
    LoginTime.ReleaseBuffer();
	LoginTime=LeTurn.toString().c_str();     //toString()������ü����ַ�����c_str();��������ת����CString����
	LoginTime.MakeUpper();//�Ѽ���֮���������ַ���ȫ����д
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


// �������ݿ������

int FunIndex::Server_Connect(void)
{
	 conn= mysql_init((MYSQL*) 0);//��ʼ��mysql�ṹ
	if(!mysql_real_connect(conn,"116.196.81.185","cpro","98766789","cpro",3306,NULL,0)) //mysql�ṹ�����ݿ��������ַ�����ݿ��û��������ݿ����룬���ݿ������˿ںţ�����������������mysql�������ã�һ�㲻����ģ�
	{return 0;}//���ݿ�����ʧ��
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
	// TODO: �ڴ˴������Ϣ����������
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
        pBodyE2->put_scroll(L"no");//ȥ������  
    }    
    IHTMLStyle   *phtmlStyle2;    
    pE2->get_style(&phtmlStyle2);    
   
    if(phtmlStyle2 != NULL)    
    {    
        phtmlStyle2->put_overflow(L"hidden");    
        phtmlStyle2->put_border(L"none");//   ȥ���߿�       
        phtmlStyle2->Release();    
        pE2->Release();    
    }    
}  
}

void FunIndex::Menu_About()
{
	// TODO: �ڴ���������������
	if(DlgAbout.m_hWnd==0)
	{
		DlgAbout.Create(IDD_FUN_ABOUT,this);
	}
	DlgAbout.GetVersion();
	DlgAbout.ShowWindow(SW_SHOW);
}

void FunIndex::Menu_Thanks()
{
	// TODO: �ڴ���������������
	if(DlgThank.m_hWnd==0)
	{
		DlgThank.Create(IDD_FUN_THANKS,this);
	}
	DlgThank.SetData();
	DlgThank.ShowWindow(SW_SHOW);

}

void FunIndex::Menu_Select()
{
	// TODO: �ڴ���������������
}

void FunIndex::Menu_MyLend()
{
	// TODO: �ڴ���������������
}

void FunIndex::Menu_AddTbook()
{
	// TODO: �ڴ���������������
}

void FunIndex::Menu_AddNbook()
{
	// TODO: �ڴ���������������
}


void FunIndex::OnBnClickedButton3search()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
row=mysql_fetch_row(res);//�ѽ�����������
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
	Messageout02.Format("δ���");
}else{
	Messageout02.Format("�ѽ��");
}
OnEnChangeEdit3();OnEnChangeEdit4();
}
else{
	MessageBox("��������ȷ��ID��");
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
row=mysql_fetch_row(res);//�ѽ�����������
MessageNum=mysql_num_rows(res);
if(MessageNum==1)//����
{
	state.Format("%s",row[2]);
	x=atoi(state);
	if(x==0){
	SQL.Format("update booknum  set bookstate=1,lendtime='%s',lenduser='%s' where booknum='%s'",strDateTime,username,Messagein);
	stringSQL02=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,stringSQL02);
	OnBnClickedButton3search();
	MessageBox("����ɹ���");
	}else
	{
		MessageBox("�����Ѿ������");
	}
}else{
	MessageBox("��������ȷ��ID�ţ�");}     
}

void FunIndex::OnBnClickedButton2return()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString stringSQL01,stringSQL02;
	int MessageNum,x;
	CString state;
OnEnChangeEdit1();
SQL.Format("select * from booknum where booknum='%s'",Messagein);
stringSQL01=SQL.GetBuffer();
SQL.ReleaseBuffer();
mysql_query(conn,stringSQL01);
res= mysql_store_result(conn);
row=mysql_fetch_row(res);//�ѽ�����������
MessageNum=mysql_num_rows(res);
if(MessageNum==1)//����
{
	state.Format("%s",row[2]);
	x=atoi(state);
	if(x==1){
	SQL.Format("update booknum  set bookstate=0 ,lendtime='', lenduser='' where booknum='%s'",Messagein);
	stringSQL02=SQL.GetBuffer();
	SQL.ReleaseBuffer();
	mysql_query(conn,stringSQL02);
	OnBnClickedButton3search();
    MessageBox("����ɹ���");
	}else
	{
		MessageBox("�����Ѿ��黹��");
	}

}else{
	MessageBox("��������ȷ��ID�ţ�");} 
}

BOOL FunIndex::PreTranslateMessage(MSG* pMsg)
{
    // TODO:  �ڴ����ר�ô����/����û���
    if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
    {
        // �����Ϣ�Ǽ��̰����¼�������Esc����ִ�����´��루ʲô��������������Լ������Ҫ�Ĵ��룩
        return TRUE;
    }
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        // �����Ϣ�Ǽ��̰����¼�������Entert����ִ�����´��루ʲô��������������Լ������Ҫ�Ĵ��룩
        return TRUE;
    }
    return CDialog::PreTranslateMessage(pMsg);
}
void FunIndex::OnBnClickedButton4reflash()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
    MD5 LeTurn;
	LeTurn.update(strDateTime.GetBuffer());    //��Ϊupdate����ֻ����string���ͣ�����ʹ��getbuffer()����ת��CStringΪstring
    strDateTime.ReleaseBuffer();
	strDateTime=LeTurn.toString().c_str();     //toString()������ü����ַ�����c_str();��������ת����CString����
	strDateTime.MakeUpper();//�Ѽ���֮���������ַ���ȫ����д
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
