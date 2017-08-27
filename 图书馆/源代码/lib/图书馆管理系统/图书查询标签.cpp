// ͼ���ѯ��ǩ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "ͼ���ѯ��ǩ.h"


// ͼ���ѯ��ǩ �Ի���

IMPLEMENT_DYNAMIC(ͼ���ѯ��ǩ, CDialog)

ͼ���ѯ��ǩ::ͼ���ѯ��ǩ(CWnd* pParent /*=NULL*/)
	: CDialog(ͼ���ѯ��ǩ::IDD, pParent)
	, SBookName(_T(""))
	, SbookPrint(_T(""))
{

}

ͼ���ѯ��ǩ::~ͼ���ѯ��ǩ()
{
}

void ͼ���ѯ��ǩ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SELECT, SelectList);
	DDX_Text(pDX, IDC_EDIT_NAME, SBookName);
	DDX_Text(pDX, IDC_EDIT_WRITTER, SbookWritter);
	DDX_Text(pDX, IDC_EDIT_PRINT, SbookPrint);
}


BEGIN_MESSAGE_MAP(ͼ���ѯ��ǩ, CDialog)
	ON_BN_CLICKED(IDC_SELECT, &ͼ���ѯ��ǩ::OnBnClickedSelect)
	ON_BN_CLICKED(IDC_SELECT_RESET, &ͼ���ѯ��ǩ::OnBnClickedSelectReset)
	ON_BN_CLICKED(IDC_SELECT_DEL, &ͼ���ѯ��ǩ::OnBnClickedSelectDel)
END_MESSAGE_MAP()


// ������ĳ�ʼ������

BOOL ͼ���ѯ��ǩ::OnInitDialog(void)
{
	CDialog::OnInitDialog();
	SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	/*SelectList.SetColumnWidth(0,100);*///���ñ��Ϊ0�����п�Ϊ100 ������ĺ����Ѿ����ã�����ֻ�Ƕ�дһ��д����
	SelectList.InsertColumn(0,"ͼ���",0,118);
	SelectList.InsertColumn(1,"����",0,118);
	SelectList.InsertColumn(2,"����",0,118);
	SelectList.InsertColumn(3,"������",0,168);
	SelectList.InsertColumn(4,"����ʱ��",0,118);
	SelectList.InsertColumn(5,"����",0,115);
	sql_connect();
    OnBnClickedSelect();
	return TRUE;
}

void ͼ���ѯ��ǩ::sql_connect(void)
{
	conn= mysql_init((MYSQL*) 0);//��ʼ��mysql�ṹ
	if(!mysql_real_connect(conn,$MYSQLSERVER,$MYSQLUSER,$MYSQLPASS,$MYSQLDATA,3306,NULL,0)) //mysql�ṹ�����ݿ��������ַ�����ݿ��û��������ݿ����룬���ݿ������˿ںţ�����������������mysql�������ã�һ�㲻����ģ�
	{MessageBox("���ݿ�����ʧ�ܣ�");exit(0);}//���ݿ�����ʧ���˳�����
	else{ mysql_query(conn, "set names gbk"); }//����MYSQL���صı���Ϊgbk������Ŀʹ�õĶ��ַ���������ݡ�
}

void ͼ���ѯ��ǩ::SQLtosql(void)
{
	sql=SQL.GetBuffer();
	SQL.ReleaseBuffer();
}



void ͼ���ѯ��ǩ::OnBnClickedSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	SQL.Format("");
	SelectList.DeleteAllItems();   //ɾ���������е�����
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
		    MessageBox("ϵͳ�ݲ�֧�������Ĳ�ѯ��ʽ��");
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
			Item.Format("��%d��",i);
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

void ͼ���ѯ��ǩ::OnBnClickedSelectReset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(CheckPower())
	{
	int Item;
	Item=SelectList.GetSelectionMark();
	CString showdata;
	showdata=SelectList.GetItemText(Item,0);
    theApp.data=showdata;
	�޸�ͼ����Ϣ���� RESET;
	RESET.DoModal();
	
	MessageBox("�޸ĳɹ���");
    OnBnClickedSelect();
	}
    else
	{
	MessageBox("��û���㹻��Ȩ�ޣ�����ϵ����Ա����");
	}
 
}

void ͼ���ѯ��ǩ::OnBnClickedSelectDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	MessageBox("ɾ���ɹ���");
    OnBnClickedSelect();
	}
	else
	{
	MessageBox("��û���㹻��Ȩ�ޣ�����ϵ����Ա����");
	}
}

bool ͼ���ѯ��ǩ::CheckPower(void)
{
	SQL.Format("select * from user where username='%s'",theApp.Username);
	SQLtosql();
	mysql_query(conn,sql);
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	if(atoi(row[6])==0){return true;}
	else{return false;}
}


	BOOL   ͼ���ѯ��ǩ::PreTranslateMessage(MSG*   pMsg)    
  {  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_ESCAPE)     return   TRUE;  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_RETURN)   return  	TRUE;    
    else    
          return   CDialog::PreTranslateMessage(pMsg);  
  }



