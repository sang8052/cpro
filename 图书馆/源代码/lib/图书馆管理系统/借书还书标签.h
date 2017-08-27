#pragma once
#include "explorer.h"
#include "Mshtml.h"     //对内置浏览器的网页进行处理的头文件
#include "mysql.h"   //Mysql数据库的头文件
#include "winsock.h" //Windows下网络编程的规范，该是Windows下得到广泛应用的、开放的、支持多种协议的网络编程接口
#include "md5.h"
#pragma comment(lib,"libmysql.lib")  //用来支持mysql的静态连接库

// 借书还书标签 对话框

class 借书还书标签 : public CDialog
{
	DECLARE_DYNAMIC(借书还书标签)

public:
	借书还书标签(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~借书还书标签();

// 对话框数据
	enum { IDD = IDD_FUN_LETURN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
public:
	// 重载类的初始化函数
	
	CString EDIT_BOOKNUM;
	CString EDIT_BOOKNAME;
	CString EDIT_WRITTER;
	CString EDIT_STATE;
	int bookstate;
	
    CString Username;
	CString LoginTime;
	CString LimitTime;
	CString SQL;  //用来承载mysql的操作语句
	char* sql;
	MYSQL *conn; //mysql数据库的连接句柄
	MYSQL_RES *res;   //mysql数据库的结果集
	MYSQL_ROW row;   //mysql数据库的返回的数组
    CString strVERSION; //用来记录当前程序版本
	void SQL_server(void);
	void SQLtosql(void);
	
	CExplorer PIC_QR;
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorerQr(LPDISPATCH pDisp, VARIANT* URL);
	afx_msg void OnBnClickedButtonRefalsh();
	afx_msg void OnBnClickedButtonSelect();
	afx_msg void OnBnClickedButtonLend();
	afx_msg void OnBnClickedButtonReturn();
    
   //重载回车消息
	BOOL  PreTranslateMessage(MSG*   pMsg) ;
	
};


