// SetMessage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lib.h"
#include "SetMessage.h"


// SetMessage �Ի���

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


// SetMessage ��Ϣ�������

void SetMessage::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void SetMessage::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void SetMessage::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void SetMessage::OnEnChangeEdit9()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void SetMessage::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void SetMessage::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void SetMessage::OnOpenSMWin()
{
  MessageBox("������ʹ�øù���Ŷ");
}
