#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "mysql.h"
#include "winsock.h"
#include "修改图书信息弹窗.h"

#pragma comment (lib,"libmysql.lib")

// 图书查询标签 对话框

class 图书查询标签 : public CDialog
{
	DECLARE_DYNAMIC(图书查询标签)

public:
	图书查询标签(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~图书查询标签();

// 对话框数据
	enum { IDD = IDD_FUN_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 重载类的初始化函数
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
	
//重载回车消息
	BOOL  PreTranslateMessage(MSG*   pMsg) ;
};
