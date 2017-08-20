// SetMessage.cpp : 实现文件
//

#include "stdafx.h"
#include "lib.h"
#include "SetMessage.h"


// SetMessage 对话框

IMPLEMENT_DYNAMIC(SetMessage, CDialog)

SetMessage::SetMessage(CWnd* pParent /*=NULL*/)
	: CDialog(SetMessage::IDD, pParent)
{

}

SetMessage::~SetMessage()
{
}

void SetMessage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SetMessage, CDialog)

	ON_EN_CHANGE(IDC_EDIT5, &SetMessage::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT3, &SetMessage::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT9, &SetMessage::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT2, &SetMessage::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &SetMessage::OnEnChangeEdit4)
	ON_COMMAND(ID_32784, &SetMessage::OnOpenSMWin)
END_MESSAGE_MAP()


// SetMessage 消息处理程序

void SetMessage::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}

void SetMessage::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void SetMessage::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void SetMessage::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void SetMessage::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void SetMessage::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void SetMessage::OnOpenSMWin()
{
  MessageBox("您正在使用该功能哦");
}
