// 登录窗口.h : 头文件
#pragma once
#include <string>    //c++ string字符串的所使用的头文件
using namespace std; //引入命名空间
#include "mysql.h"   //Mysql数据库的头文件
#include "winsock.h" //Windows下网络编程的规范，该是Windows下得到广泛应用的、开放的、支持多种协议的网络编程接口
#include <shlwapi.h> //Windows关于文件路径的头文件
#include <fstream>   //fstream是C++ STL中对文件操作的合集，包含了常用的所有文件操作。
#include "md5.h"     //用来执行md5加密的头文件
#include "主窗口.h"

#pragma comment(lib,"libmysql.lib")  //用来支持mysql的静态连接库
#pragma comment(lib, "Version.lib ") //获取版本信息时所使用的静态连接库

// 登录窗口 对话框
class 登录窗口 : public CDialog
{
// 构造
public:
	登录窗口(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LOGIN };

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
	
	afx_msg void OnBnClickedButtonCancel();
	// 用来记录用户名的CString 字符串
	CString Username;
	// 用来记录密码的CString 字符串
	CString Password;
	CString SQL;  //用来承载mysql的操作语句
	
	char* sql;
	MYSQL *conn; //mysql数据库的连接句柄
	MYSQL_RES *res;   //mysql数据库的结果集
	MYSQL_ROW row;   //mysql数据库的返回的数组
    CString strVERSION; //用来记录当前程序版本

	// 数据库用来连接的函数
	void SQL_connect(void);
	afx_msg void OnBnClickedButtonLogin();
	// 把一个CString的字符串转换成char*类型的字符串
	// 初始化函数
	void Getready(void);
	// CString 的SQL 转换到 char* sql
	void SQLtosql(void);
	
	// 获得本机外网ip地址
	void Getip(void);
	//重载回车消息
	BOOL  PreTranslateMessage(MSG*   pMsg) ;
};
