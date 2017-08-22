#pragma once
#include "mysql.h"
#include "winsock.h"

#pragma comment (lib,"libmysql.lib")

// 修改图书信息弹窗 对话框

class 修改图书信息弹窗 : public CDialog
{
	DECLARE_DYNAMIC(修改图书信息弹窗)

public:
	修改图书信息弹窗(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~修改图书信息弹窗();

// 对话框数据
	enum { IDD = IDD_FUN_RESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 重载类的初始化函数
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
