#pragma once
#include "afxcmn.h"
#include "winsock.h"
#include "mysql.h"

#pragma comment(lib,"libmysql.lib")


// �ҽ�����ǩ �Ի���

class �ҽ�����ǩ : public CDialog
{
	DECLARE_DYNAMIC(�ҽ�����ǩ)

public:
	�ҽ�����ǩ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~�ҽ�����ǩ();

// �Ի�������
	enum { IDD = IDD_FUN_MYLEND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	virtual BOOL OnInitDialog();
	CListCtrl MyLendList;
	CString SQL;
	char* sql;
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;

	MYSQL_RES* bres;
	MYSQL_ROW brow;

	void SetData(void);
	void sql_connect(void);
	void SQLtosql(void);
	afx_msg void OnBnClickedButtonListReflash();
};
