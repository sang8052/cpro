#pragma once
#include "afxwin.h"
#include "mysql.h"
#include "winsock.h"

#pragma comment(lib,"libmysql.lib")  //用来支持mysql的静态连接库


// 新书入库标签 对话框

class 新书入库标签 : public CDialog
{
	DECLARE_DYNAMIC(新书入库标签)

public:
	新书入库标签(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~新书入库标签();

// 对话框数据
	enum { IDD = IDD_FUN_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 重载类的初始化函数
	virtual BOOL OnInitDialog();
	CString AddNum;
	CString AddName;
	CString AddWritter;
	CString AddPrint;
	CString AddPrinttime;
	CString AddPrice;
	CString Addamount;
	CString SQL;  //用来承载mysql的操作语句
	char* sql;
	MYSQL *conn; //mysql数据库的连接句柄
	MYSQL_RES *res;   //mysql数据库的结果集
	MYSQL_ROW row;   //mysql数据库的返回的数组
	void SQLtosql(void);
	void sql_connect(void);
	
	bool CheckAdd(void);
	bool ChectInt(double a );
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonReset();
};
