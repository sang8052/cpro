// libDlg.h : 头文件
//

#pragma once
#include  <string>
using namespace std;
#include <atlconv.h>
#include "afxwin.h"
#include  <afxinet.h>
#include <WinSock.h>  //win相关操作头文件
#include "mysql.h"    //引入mysql头文件，请在项目——属性——c/c++附加依赖里面设置好路径
#include "md5.h"
#include <iostream>
#include <UrlMon.h>
#include <afxconv.h>
#include <shlwapi.h>
#include "DIALOG1.h"
#include "SetMessage.h"

#pragma comment(lib, "Version.lib ")
#pragma comment(lib,"wsock32.lib")//win相关操作的套接库
#pragma comment(lib,"libmysql.lib") //引入mysql头文件，请在项目——属性——链接器附加依赖里面设置好路径
#pragma comment(lib,"urlmon.lib")
// ClibDlg 对话框
class ClibDlg : public CDialog 
{
public:
	ClibDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LIB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	// 用户名
	CString username;
	// 登录密码
	CString password;
	
  CString SQL;//执行SQL语句的字段
  MYSQL * conn;  
  MYSQL_RES *res;
  MYSQL_ROW row; 
	
  int Server_connect(void);
  
  
  bool downloadfile(CString *strFileURLInServer, CString *strFileLocalFullPath);
  CString strVERSION;
  afx_msg void Ontip();
  afx_msg void OnSetMessageWindow();
};

