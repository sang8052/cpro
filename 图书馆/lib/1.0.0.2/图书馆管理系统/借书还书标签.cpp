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
	, EDITBOOKNAME(_T(""))
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
	DDX_Text(pDX, IDC_EDIT_BOOKNAME, EDITBOOKNAME);
	DDX_Text(pDX, IDC_EDIT_BOOKWRITER, EDIT_WRITTER);
	DDX_Text(pDX, IDC_EDIT_BOOKSTATE, EDIT_STATE);

	DDX_Control(pDX, IDC_EXPLORER_QR, PIC_QR);
}


BEGIN_MESSAGE_MAP(���黹���ǩ, CDialog)
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

