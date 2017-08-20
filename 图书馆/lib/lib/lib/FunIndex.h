#pragma once
#include "mysql.h"
#include <WinSock.h> 
#include "md5.h"
#include "explorer_qr.h"
#include "Mshtml.h" 
#include "FunThank.h"
#include "FunAbout.h"

#pragma comment(lib,"libmysql.lib") 

// FunIndex 对话框

class FunIndex : public CDialog
{
	DECLARE_DYNAMIC(FunIndex)

public:
	FunIndex(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FunIndex();

// 对话框数据
	enum { IDD = IDD_FUN_INDEX };

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString SQL;
	CString username;
	CString LoginTime;
	CString LimitTime;
	char* TempSql;
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
    //实例化窗口类对象

	FunThank DlgThank;
	FunAbout DlgAbout;

	// 连接数据库服务器
    int Server_Connect(void);
	void SetData(CString,CString,CString);
	CExplorer_qr Url_Qr;

	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorerQr(LPDISPATCH pDisp, VARIANT* URL);
	// //查询编辑框的Csting类型变量
	CString Messagein;
	// //用来输出书名
	CString Messageout01;
	// //用于输出图书状态
	CString Messageout02;
	afx_msg void OnBnClickedButton3search();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1lend();
	afx_msg void OnBnClickedButton2return();
	afx_msg void Menu_About();
	afx_msg void Menu_Thanks();
	afx_msg void Menu_Select();
	afx_msg void Menu_MyLend();
	afx_msg void Menu_AddTbook();
	afx_msg void Menu_AddNbook();
	virtual BOOL PreTranslateMessage(MSG *);
	afx_msg void OnBnClickedButton4reflash();
	
};
