#pragma once
#include "afxcmn.h"
#include "winsock.h"
#include "mysql.h"

#pragma comment(lib,"libmysql.lib")


// 我借的书标签 对话框

class 我借的书标签 : public CDialog
{
	DECLARE_DYNAMIC(我借的书标签)

public:
	我借的书标签(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~我借的书标签();

// 对话框数据
	enum { IDD = IDD_FUN_MYLEND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 重载类的初始化函数
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
