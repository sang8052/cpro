// ͼ��ݹ���ϵͳ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//
#define   $DEBUG      "true"    //������Աģʽ�����ó�true �������ó� "false"
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// ͼ��ݹ���ϵͳ:
// �йش����ʵ�֣������ ͼ��ݹ���ϵͳ.cpp
//

class ͼ��ݹ���ϵͳ : public CWinApp
{
public:
	ͼ��ݹ���ϵͳ();

// ��д
	public:
	virtual BOOL InitInstance();
	CString Username;
	CString Logintime;
	CString LimitTime;
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern ͼ��ݹ���ϵͳ theApp;