// DIALOG1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lib.h"
#include "DIALOG1.h"
#include "SetMessage.h"

// DIALOG1 �Ի���

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


// DIALOG1 ��Ϣ�������

void DIALOG1::OnMile_tebeimingxie()
{
	// TODO: �ڴ���������������
	MessageBox("I LOVE ���");
}

void DIALOG1::Ontitlebar_guanyutext()
{
	// TODO: �ڴ���������������
	MessageBox("�����ˣ��Ϻ����16���������4����ĸ�С���~	�κ���������ϵ��QQ275969819/925040692");
}

void DIALOG1::Onexit()
{
	// TODO: �ڴ���������������
	::SendMessage(m_hWnd,WM_CLOSE,0,0);
	MessageBox("��ӭ�ٴ�ʹ��");
}
SetMessage m;
void DIALOG1::OnOpenSMWin()
{
	m.DoModal();
}
LendBook lendbook;
void DIALOG1::OnSearchBook()
{
	// TODO: �ڴ���������������
	lendbook.DoModal();
}

void DIALOG1::On32774()
{
	// TODO: �ڴ���������������
	lendbook.DoModal();
}
