#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "mysql.h"
#include "winsock.h"
#include "�޸�ͼ����Ϣ����.h"

#pragma comment (lib,"libmysql.lib")

// ͼ���ѯ��ǩ �Ի���

class ͼ���ѯ��ǩ : public CDialog
{
	DECLARE_DYNAMIC(ͼ���ѯ��ǩ)

public:
	ͼ���ѯ��ǩ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ͼ���ѯ��ǩ();

// �Ի�������
	enum { IDD = IDD_FUN_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	virtual BOOL OnInitDialog();
	CListCtrl SelectList;
	CString	SQL;
	char *sql;
	MYSQL *conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
    
	void sql_connect(void);
	void SQLtosql(void);
	
	afx_msg void OnBnClickedSelect();
	CString SBookName;
	CString SbookWritter;
	CString SbookPrint;
	afx_msg void OnBnClickedSelectReset();
	afx_msg void OnBnClickedSelectDel();
	bool CheckPower(void);
	
//���ػس���Ϣ
	BOOL  PreTranslateMessage(MSG*   pMsg) ;
};
