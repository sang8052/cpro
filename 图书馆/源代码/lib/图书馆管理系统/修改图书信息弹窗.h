#pragma once
#include "mysql.h"
#include "winsock.h"

#pragma comment (lib,"libmysql.lib")

// �޸�ͼ����Ϣ���� �Ի���

class �޸�ͼ����Ϣ���� : public CDialog
{
	DECLARE_DYNAMIC(�޸�ͼ����Ϣ����)

public:
	�޸�ͼ����Ϣ����(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~�޸�ͼ����Ϣ����();

// �Ի�������
	enum { IDD = IDD_FUN_RESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	virtual BOOL OnInitDialog();
	CString ResetBookid;
	CString	SQL;
	char *sql;
	MYSQL *conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
	void SQLtosql(void);
	void sql_connect(void);
	afx_msg void OnBnClickedCancel();
	void SetData(void);
	afx_msg void OnBnClickedOk();
	CString RESET_PRICE;
	CString RESET_TIME;
	CString RESET_PRINT;
	CString SETWRITTER;
	CString RESET_NAME;
	CString RESET_ID;
};
