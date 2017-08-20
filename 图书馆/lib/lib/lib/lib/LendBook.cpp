// LendBook.cpp : 实现文件
//

#include "stdafx.h"
#include "lib.h"
#include "LendBook.h"


// LendBook 对话框

IMPLEMENT_DYNAMIC(LendBook, CDialog)

LendBook::LendBook(CWnd* pParent /*=NULL*/)
	: CDialog(LendBook::IDD, pParent)
{

}

LendBook::~LendBook()
{
}

void LendBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LendBook, CDialog)
	ON_COMMAND(ID_32774, &LendBook::OnLendBook)
	ON_COMMAND(ID_32772, &LendBook::OnSearchBook)
END_MESSAGE_MAP()


// LendBook 消息处理程序

void LendBook::OnLendBook()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("您已在借书窗口哦~");
}

void LendBook::OnSearchBook()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("您已在查找窗口哦~");
}
