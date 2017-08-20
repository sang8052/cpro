// DIALOG1.cpp : 实现文件
//

#include "stdafx.h"
#include "lib.h"
#include "DIALOG1.h"
#include "SetMessage.h"

// DIALOG1 对话框

IMPLEMENT_DYNAMIC(DIALOG1, CDialog)

DIALOG1::DIALOG1(CWnd* pParent /*=NULL*/)
	: CDialog(DIALOG1::IDD, pParent)
{

}

DIALOG1::~DIALOG1()
{
}

void DIALOG1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DIALOG1, CDialog)
	ON_COMMAND(ID_32779, &DIALOG1::OnMile_tebeimingxie)
	ON_COMMAND(ID_titlebar, &DIALOG1::Ontitlebar_guanyutext)
	ON_COMMAND(ID_exit, &DIALOG1::Onexit)
	
	ON_COMMAND(ID_32784, &DIALOG1::OnOpenSMWin)
	ON_COMMAND(ID_32772, &DIALOG1::OnSearchBook)
	ON_COMMAND(ID_32774, &DIALOG1::On32774)
END_MESSAGE_MAP()


// DIALOG1 消息处理程序

void DIALOG1::OnMile_tebeimingxie()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("I LOVE 金城");
}

void DIALOG1::Ontitlebar_guanyutext()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("制作人：南航金城16届软件工程4班的四个小伙伴~	任何问题请联系：QQ275969819/925040692");
}

void DIALOG1::Onexit()
{
	// TODO: 在此添加命令处理程序代码
	::SendMessage(m_hWnd,WM_CLOSE,0,0);
	MessageBox("欢迎再次使用");
}
SetMessage m;
void DIALOG1::OnOpenSMWin()
{
	m.DoModal();
}
LendBook lendbook;
void DIALOG1::OnSearchBook()
{
	// TODO: 在此添加命令处理程序代码
	lendbook.DoModal();
}

void DIALOG1::On32774()
{
	// TODO: 在此添加命令处理程序代码
	lendbook.DoModal();
}
