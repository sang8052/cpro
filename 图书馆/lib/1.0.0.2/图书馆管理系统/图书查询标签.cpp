// 图书查询标签.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "图书查询标签.h"


// 图书查询标签 对话框

IMPLEMENT_DYNAMIC(图书查询标签, CDialog)

图书查询标签::图书查询标签(CWnd* pParent /*=NULL*/)
	: CDialog(图书查询标签::IDD, pParent)
{

}

图书查询标签::~图书查询标签()
{
}

void 图书查询标签::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(图书查询标签, CDialog)
END_MESSAGE_MAP()


// 重载类的初始化函数

BOOL 图书查询标签::OnInitDialog(void)
{
	return TRUE;
}
