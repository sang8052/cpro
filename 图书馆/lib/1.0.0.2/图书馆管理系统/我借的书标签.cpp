// �ҽ�����ǩ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "�ҽ�����ǩ.h"


// �ҽ�����ǩ �Ի���

IMPLEMENT_DYNAMIC(�ҽ�����ǩ, CDialog)

�ҽ�����ǩ::�ҽ�����ǩ(CWnd* pParent /*=NULL*/)
	: CDialog(�ҽ�����ǩ::IDD, pParent)
{

}

�ҽ�����ǩ::~�ҽ�����ǩ()
{
}

void �ҽ�����ǩ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(�ҽ�����ǩ, CDialog)
END_MESSAGE_MAP()


// ������ĳ�ʼ������

BOOL �ҽ�����ǩ::OnInitDialog(void)
{
	return TRUE;
}
