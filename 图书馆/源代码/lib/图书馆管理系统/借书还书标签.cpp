// ���黹���ǩ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "���黹���ǩ.h"


// ���黹���ǩ �Ի���

IMPLEMENT_DYNAMIC(���黹���ǩ, CDialog)

���黹���ǩ::���黹���ǩ(CWnd* pParent /*=NULL*/)
	: CDialog(���黹���ǩ::IDD, pParent)
	, EDIT_BOOKNUM(_T(""))
	, EDIT_BOOKNAME(_T(""))
	, EDIT_WRITTER(_T(""))
	, EDIT_STATE(_T(""))
{

}

���黹���ǩ::~���黹���ǩ()
{
}

void ���黹���ǩ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BOOKNUM, EDIT_BOOKNUM);
	DDX_Text(pDX, IDC_EDIT_BOOKNAME, EDIT_BOOKNAME);
	DDX_Text(pDX, IDC_EDIT_BOOKWRITER, EDIT_WRITTER);
	DDX_Text(pDX, IDC_EDIT_BOOKSTATE, EDIT_STATE);

	DDX_Control(pDX, IDC_EXPLORER_QR, PIC_QR);
}


BEGIN_MESSAGE_MAP(���黹���ǩ, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_REFALSH, &���黹���ǩ::OnBnClickedButtonRefalsh)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &���黹���ǩ::OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_LEND, &���黹���ǩ::OnBnClickedButtonLend)
	ON_BN_CLICKED(IDC_BUTTON_RETURN, &���黹���ǩ::OnBnClickedButtonReturn)
END_MESSAGE_MAP()



// ������ĳ�ʼ������
BOOL ���黹���ǩ::OnInitDialog()
{
	CDialog::OnInitDialog();
	Username=theApp.Username;
	LoginTime=theApp.Logintime;
	LimitTime=theApp.LimitTime;
	MD5 LeTurn;
	LeTurn.update(LoginTime.GetBuffer());    //��Ϊupdate����ֻ����string���ͣ�����ʹ��getbuffer()����ת��CStringΪstring
    LoginTime.ReleaseBuffer();
	LoginTime=LeTurn.toString().c_str();     //toString()������ü����ַ�����c_str();��������ת����CString����
	LoginTime.MakeUpper();//�Ѽ���֮���������ַ���ȫ����д
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


void ���黹���ǩ::	SQL_server(void)
{
	conn= mysql_init((MYSQL*) 0);//��ʼ��mysql�ṹ
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql�ṹ�����ݿ��������ַ�����ݿ��û��������ݿ����룬���ݿ������˿ںţ�����������������mysql�������ã�һ�㲻����ģ�
	{MessageBox("���ݿ�����ʧ�ܣ�");exit(0);}//���ݿ�����ʧ���˳�����
	else{ mysql_query(conn, "set names gbk"); }//����MYSQL���صı���Ϊgbk������Ŀʹ�õĶ��ַ���������ݡ�
}

void ���黹���ǩ::SQLtosql(void)
{
    sql=SQL.GetBuffer();  //��GCstr ת����str��ȥ 
	SQL.ReleaseBuffer();  //�ͷŻ�����
}

BEGIN_EVENTSINK_MAP(���黹���ǩ, CDialog)
	ON_EVENT(���黹���ǩ, IDC_EXPLORER_QR, 259, ���黹���ǩ::DocumentCompleteExplorerQr, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

void ���黹���ǩ::DocumentCompleteExplorerQr(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO: �ڴ˴������Ϣ����������
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

void ���黹���ǩ::OnBnClickedButtonRefalsh()
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

void ���黹���ǩ::OnBnClickedButtonSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	my_ulonglong SQLchanges;
	UpdateData(true);
	SQL.Format("select * from booknum where booknum='%s'",EDIT_BOOKNUM);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	SQLchanges=mysql_num_rows(res);
	if(SQLchanges==0){
		MessageBox("�������Ψһͼ�����������֤���������룡");
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
			if(bookstate==0){EDIT_STATE.Format("��δ���");}
			else{EDIT_STATE.Format("�ѽ��");}
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

void ���黹���ǩ::OnBnClickedButtonLend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	my_ulonglong SQLchanges;
	UpdateData(true);
	SQL.Format("select * from booknum where booknum='%s'",EDIT_BOOKNUM);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	SQLchanges=mysql_num_rows(res);
	if(SQLchanges==0){
		MessageBox("�������Ψһͼ�����������֤���������룡");
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
			if(bookstate!=0){MessageBox("���󣺴����Ѿ��������");}
			else
			{   
                CTime time;  
                time=CTime::GetCurrentTime();
				CString strDateTime;
				strDateTime=time.Format(_T("%Y-%m-%d %H:%M:%S"));
				SQL.Format("update booknum set bookstate=1, lendtime='%s', lenduser='%s' where booknum='%s'",strDateTime,theApp.Username,EDIT_BOOKNUM);
				SQLtosql();
				mysql_query(conn,sql);
				MessageBox("����ɹ���");
                OnBnClickedButtonSelect();
				
			}
	   } 
}

void ���黹���ǩ::OnBnClickedButtonReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	my_ulonglong SQLchanges;
	UpdateData(true);
	SQL.Format("select * from booknum where booknum='%s'",EDIT_BOOKNUM);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	SQLchanges=mysql_num_rows(res);
	if(SQLchanges==0)
	{
		MessageBox("�������Ψһͼ�����������֤���������룡");
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
			if(bookstate!=1){MessageBox("���󣺴�����δ�������");}
			else
			{   
                CTime time;  
                time=CTime::GetCurrentTime();
				CString strDateTime;
				strDateTime=time.Format(_T("%Y-%m-%d %H:%M:%S"));
				SQL.Format("update booknum set bookstate=0, lendtime='', lenduser='' where booknum='%s'",EDIT_BOOKNUM);
				SQLtosql();
				mysql_query(conn,sql);
				MessageBox("����ɹ���");
                OnBnClickedButtonSelect();
				
			}
	   } 
}


BOOL   ���黹���ǩ::PreTranslateMessage(MSG*   pMsg)    
  {  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_ESCAPE)     return   TRUE;  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_RETURN)   return  	TRUE;    
    else    
          return   CDialog::PreTranslateMessage(pMsg);  
  }
