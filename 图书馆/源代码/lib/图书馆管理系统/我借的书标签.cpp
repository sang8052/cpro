// �ҽ�����ǩ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "�ҽ�����ǩ.h"


// �ҽ�����ǩ �Ի���

IMPLEMENT_DYNAMIC(�ҽ�����ǩ, CDialog)

�ҽ�����ǩ::�ҽ�����ǩ(CWnd* pParent /*=NULL*/)
	: CDialog(�ҽ�����ǩ::IDD, pParent)
{

}

�ҽ�����ǩ::~�ҽ�����ǩ()
{
}

void �ҽ�����ǩ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MYLEND, MyLendList);
}


BEGIN_MESSAGE_MAP(�ҽ�����ǩ, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LIST_REFLASH, &�ҽ�����ǩ::OnBnClickedButtonListReflash)
END_MESSAGE_MAP()


// ������ĳ�ʼ������

BOOL �ҽ�����ǩ::OnInitDialog(void)
{
	CDialog::OnInitDialog();
	MyLendList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	MyLendList.InsertColumn(0,"Ψһͼ����",0,110);//�����еı�š����֡���ʽ�����
	/*MyLendList.SetColumnWidth(0,100);*///���ñ��Ϊ0�����п�Ϊ100 ������ĺ����Ѿ����ã�����ֻ�Ƕ�дһ��д����
	MyLendList.InsertColumn(1,"ͼ���",0,100);
	MyLendList.InsertColumn(2,"����",0,100);
	MyLendList.InsertColumn(3,"����",0,100);
	MyLendList.InsertColumn(4,"������",0,150);
	MyLendList.InsertColumn(5,"����ʱ��",0,100);
	MyLendList.InsertColumn(6,"����",0,95);
	SetData();
    return TRUE;
}



void �ҽ�����ǩ::SetData(void)
{
	MyLendList.DeleteAllItems();   //ɾ���������е�����
	sql_connect();
	SQL.Format("select * from booknum where lenduser='%s' order by bookid ",theApp.Username);
	SQLtosql();
	mysql_query(conn,sql);
    res=mysql_store_result(conn);
	int i=0;
	
	while(row=mysql_fetch_row(res))
	{   CString Item;
	    Item.Format("��%d��",i);
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

void �ҽ�����ǩ::sql_connect(void)
{
    conn= mysql_init((MYSQL*) 0);//��ʼ��mysql�ṹ
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql�ṹ�����ݿ��������ַ�����ݿ��û��������ݿ����룬���ݿ������˿ںţ�����������������mysql�������ã�һ�㲻����ģ�
	{MessageBox("���ݿ�����ʧ�ܣ�");exit(0);}//���ݿ�����ʧ���˳�����
	else{ mysql_query(conn, "set names gbk"); }//����MYSQL���صı���Ϊgbk������Ŀʹ�õĶ��ַ���������ݡ�
}

void �ҽ�����ǩ::SQLtosql(void)
{
    sql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
}

void �ҽ�����ǩ::OnBnClickedButtonListReflash()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetData();

}
