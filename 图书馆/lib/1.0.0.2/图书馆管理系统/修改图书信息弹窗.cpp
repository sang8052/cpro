// 修改图书信息弹窗.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "修改图书信息弹窗.h"


// 修改图书信息弹窗 对话框

IMPLEMENT_DYNAMIC(修改图书信息弹窗, CDialog)

修改图书信息弹窗::修改图书信息弹窗(CWnd* pParent /*=NULL*/)
	: CDialog(修改图书信息弹窗::IDD, pParent)
{

}

修改图书信息弹窗::~修改图书信息弹窗()
{
}

void 修改图书信息弹窗::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(修改图书信息弹窗, CDialog)
END_MESSAGE_MAP()


// 重载类的初始化函数

BOOL 修改图书信息弹窗::OnInitDialog()
{
	return TRUE;
}
