// �޸�ͼ����Ϣ����.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "�޸�ͼ����Ϣ����.h"


// �޸�ͼ����Ϣ���� �Ի���

IMPLEMENT_DYNAMIC(�޸�ͼ����Ϣ����, CDialog)

�޸�ͼ����Ϣ����::�޸�ͼ����Ϣ����(CWnd* pParent /*=NULL*/)
	: CDialog(�޸�ͼ����Ϣ����::IDD, pParent)
	, RESET_PRICE(_T(""))
	, RESET_TIME(_T(""))
	, RESET_PRINT(_T(""))
	, SETWRITTER(_T(""))
	, RESET_NAME(_T(""))
	, RESET_ID(_T(""))
{

}

�޸�ͼ����Ϣ����::~�޸�ͼ����Ϣ����()
{
}

void �޸�ͼ����Ϣ����::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESET_PRICE, RESET_PRICE);
	DDX_Text(pDX, IDC_ERESET_TIME, RESET_TIME);
	DDX_Text(pDX, IDC_RESET_PRINT, RESET_PRINT);
	DDX_Text(pDX, IDC_RESET_WRITTER, SETWRITTER);
	DDX_Text(pDX, IDC_RESET_NAME, RESET_NAME);
	DDX_Text(pDX, IDC_RESET_ID, RESET_ID);
}


BEGIN_MESSAGE_MAP(�޸�ͼ����Ϣ����, CDialog)
	ON_BN_CLICKED(IDCANCEL, &�޸�ͼ����Ϣ����::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &�޸�ͼ����Ϣ����::OnBnClickedOk)
END_MESSAGE_MAP()


// ������ĳ�ʼ������

BOOL �޸�ͼ����Ϣ����::OnInitDialog()
{
	CDialog::OnInitDialog();
    sql_connect();
    SetData();
	return TRUE;
}

void �޸�ͼ����Ϣ����::SQLtosql(void)
{
	sql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
}

void �޸�ͼ����Ϣ����::sql_connect(void)
{
		conn= mysql_init((MYSQL*) 0);//��ʼ��mysql�ṹ
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql�ṹ�����ݿ��������ַ�����ݿ��û��������ݿ����룬���ݿ������˿ںţ�����������������mysql�������ã�һ�㲻����ģ�
	{MessageBox("���ݿ�����ʧ�ܣ�");exit(0);}//���ݿ�����ʧ���˳�����
	else{ mysql_query(conn, "set names gbk"); }//����MYSQL���صı���Ϊgbk������Ŀʹ�õĶ��ַ����������
}

void �޸�ͼ����Ϣ����::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}

void �޸�ͼ����Ϣ����::SetData()
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

void �޸�ͼ����Ϣ����::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData(true);
	SQL.Format("update booktype set bookname='%s', bookwritter='%s', bookprint='%s', bookprinttime='%s', bookprice='%s' where id='%s'",RESET_NAME,SETWRITTER,RESET_PRINT,RESET_TIME,RESET_PRICE,RESET_ID);
	SQLtosql();
	mysql_query(conn,sql);
	OnCancel();
}
