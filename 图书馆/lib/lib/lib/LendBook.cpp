// LendBook.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lib.h"
#include "LendBook.h"


// LendBook �Ի���

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


// LendBook ��Ϣ�������

void LendBook::OnLendBook()
{
	// TODO: �ڴ���������������
	MessageBox("�����ڽ��鴰��Ŷ~");
}

void LendBook::OnSearchBook()
{
	// TODO: �ڴ���������������
	MessageBox("�����ڲ��Ҵ���Ŷ~");
}
