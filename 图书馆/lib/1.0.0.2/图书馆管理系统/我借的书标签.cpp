// 我借的书标签.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "我借的书标签.h"


// 我借的书标签 对话框

IMPLEMENT_DYNAMIC(我借的书标签, CDialog)

我借的书标签::我借的书标签(CWnd* pParent /*=NULL*/)
	: CDialog(我借的书标签::IDD, pParent)
{

}

我借的书标签::~我借的书标签()
{
}

void 我借的书标签::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(我借的书标签, CDialog)
END_MESSAGE_MAP()


// 重载类的初始化函数

BOOL 我借的书标签::OnInitDialog(void)
{
	return TRUE;
}
