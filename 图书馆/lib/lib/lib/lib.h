// lib.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������



// ClibApp:
// �йش����ʵ�֣������ lib.cpp
//

class ClibApp : public CWinApp
{
public:
	ClibApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	// ���ӷ����������ݿ�

};

extern ClibApp theApp;