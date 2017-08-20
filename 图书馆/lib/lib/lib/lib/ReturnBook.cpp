// ReturnBook.cpp : 实现文件
//

#include "stdafx.h"
#include "lib.h"
#include "ReturnBook.h"


// ReturnBook 对话框

IMPLEMENT_DYNAMIC(ReturnBook, CDialog)

ReturnBook::ReturnBook(CWnd* pParent /*=NULL*/)
	: CDialog(ReturnBook::IDD, pParent)
{

}

ReturnBook::~ReturnBook()
{
}

void ReturnBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReturnBook, CDialog)
END_MESSAGE_MAP()


// ReturnBook 消息处理程序
