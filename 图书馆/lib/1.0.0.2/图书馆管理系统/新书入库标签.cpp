// 新书入库标签.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "新书入库标签.h"


// 新书入库标签 对话框

IMPLEMENT_DYNAMIC(新书入库标签, CDialog)

新书入库标签::新书入库标签(CWnd* pParent /*=NULL*/)
	: CDialog(新书入库标签::IDD, pParent)
{

}

新书入库标签::~新书入库标签()
{
}

void 新书入库标签::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(新书入库标签, CDialog)
END_MESSAGE_MAP()


// 重载类的初始化函数

BOOL 新书入库标签::OnInitDialog(void)
{
	return TRUE;
}
