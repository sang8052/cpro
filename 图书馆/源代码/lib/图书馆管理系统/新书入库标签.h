#pragma once
#include "afxwin.h"
#include "mysql.h"
#include "winsock.h"

#pragma comment(lib,"libmysql.lib")  //����֧��mysql�ľ�̬���ӿ�


// ��������ǩ �Ի���

class ��������ǩ : public CDialog
{
	DECLARE_DYNAMIC(��������ǩ)

public:
	��������ǩ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~��������ǩ();

// �Ի�������
	enum { IDD = IDD_FUN_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	virtual BOOL OnInitDialog();
	CString AddNum;
	CString AddName;
	CString AddWritter;
	CString AddPrint;
	CString AddPrinttime;
	CString AddPrice;
	CString Addamount;
	CString SQL;  //��������mysql�Ĳ������
	char* sql;
	MYSQL *conn; //mysql���ݿ�����Ӿ��
	MYSQL_RES *res;   //mysql���ݿ�Ľ����
	MYSQL_ROW row;   //mysql���ݿ�ķ��ص�����
	void SQLtosql(void);
	void sql_connect(void);
	
	bool CheckAdd(void);
	bool ChectInt(double a );
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonReset();
};
