// ��������ǩ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "��������ǩ.h"


// ��������ǩ �Ի���

IMPLEMENT_DYNAMIC(��������ǩ, CDialog)

��������ǩ::��������ǩ(CWnd* pParent /*=NULL*/)
	: CDialog(��������ǩ::IDD, pParent)
	, AddNum(_T(""))
	, AddName(_T(""))
	, AddWritter(_T(""))
	, AddPrint(_T(""))
	, AddPrinttime(_T(""))
	, AddPrice(_T(""))
	, Addamount(_T(""))
{

}

��������ǩ::~��������ǩ()
{
}

void ��������ǩ::DoDataExchange(CDataExchange* pDX)
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


BEGIN_MESSAGE_MAP(��������ǩ, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON_ADD, &��������ǩ::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &��������ǩ::OnBnClickedButtonReset)
END_MESSAGE_MAP()


// ������ĳ�ʼ������

BOOL ��������ǩ::OnInitDialog(void)
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

void ��������ǩ::SQLtosql(void)
{
	sql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
}

void ��������ǩ::sql_connect(void)
{
	conn= mysql_init((MYSQL*) 0);//��ʼ��mysql�ṹ
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql�ṹ�����ݿ��������ַ�����ݿ��û��������ݿ����룬���ݿ������˿ںţ�����������������mysql�������ã�һ�㲻����ģ�
	{MessageBox("���ݿ�����ʧ�ܣ�");exit(0);}//���ݿ�����ʧ���˳�����
	else{ mysql_query(conn, "set names gbk"); }//����MYSQL���صı���Ϊgbk������Ŀʹ�õĶ��ַ���������ݡ�
}



bool ��������ǩ::CheckAdd(void)
{
	
	if(AddName==""){MessageBox("����������ͼ������ƣ�");return false;}
	if(AddWritter==""){MessageBox("����������ͼ������ߣ�");return false;}
	if(AddPrint==""){MessageBox("����������ͼ��ĳ����̣�");return false;}
	if(AddPrinttime==""){MessageBox("����������ͼ��ĳ���ʱ�䣡");return false;}
	if(Addamount==""){MessageBox("����������ͼ���������");return false;}
	if(AddPrice==""){MessageBox("����������ͼ��ĵ��ۣ�");return false;}
	double price=atof(AddPrice);
	double amount=atof(Addamount);
	if(price>0)
	{
		if(ChectInt(amount)&&amount<=99999){return true;}
		else{MessageBox("��������ȷ��ͼ������");return false;}
	}
	else {
     MessageBox("��������ȷ��ͼ�鵥��");return false;
	}

}


bool ��������ǩ::ChectInt(double a)
{
	int b;
	double temp;
	temp=a;
	b=(int)a;
	if(temp-b==0)
	{return true;}
	else{return false;}
}

void ��������ǩ::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
     MessageBox("��ӳɹ���");
	}
}

void ��������ǩ::OnBnClickedButtonReset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Addamount.Format("");
	AddName.Format("");
	AddPrice.Format("");
	AddPrint.Format("");
	AddPrinttime.Format("");
	AddWritter.Format("");
	UpdateData(false);
		
}
