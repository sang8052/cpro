// 图书馆管理系统.h : PROJECT_NAME 应用程序的主头文件
//
#define   $DEBUG      "false"    //开发人员模式请设置成true 否则设置成 "false"
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// 图书馆管理系统:
// 有关此类的实现，请参阅 图书馆管理系统.cpp
//

class 图书馆管理系统 : public CWinApp
{
public:
	图书馆管理系统();

// 重写
	public:
	virtual BOOL InitInstance();
	CString Username;
	CString Logintime;
	CString LimitTime;
	CString data;
// 实现

	DECLARE_MESSAGE_MAP()
};

extern 图书馆管理系统 theApp;