// ��������ǩ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "��������ǩ.h"


// ��������ǩ �Ի���

IMPLEMENT_DYNAMIC(��������ǩ, CDialog)

��������ǩ::��������ǩ(CWnd* pParent /*=NULL*/)
	: CDialog(��������ǩ::IDD, pParent)
{

}

��������ǩ::~��������ǩ()
{
}

void ��������ǩ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(��������ǩ, CDialog)
END_MESSAGE_MAP()


// ������ĳ�ʼ������

BOOL ��������ǩ::OnInitDialog(void)
{
	return TRUE;
}
