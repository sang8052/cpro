// ͼ���ѯ��ǩ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "ͼ���ѯ��ǩ.h"


// ͼ���ѯ��ǩ �Ի���

IMPLEMENT_DYNAMIC(ͼ���ѯ��ǩ, CDialog)

ͼ���ѯ��ǩ::ͼ���ѯ��ǩ(CWnd* pParent /*=NULL*/)
	: CDialog(ͼ���ѯ��ǩ::IDD, pParent)
{

}

ͼ���ѯ��ǩ::~ͼ���ѯ��ǩ()
{
}

void ͼ���ѯ��ǩ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ͼ���ѯ��ǩ, CDialog)
END_MESSAGE_MAP()


// ������ĳ�ʼ������

BOOL ͼ���ѯ��ǩ::OnInitDialog(void)
{
	return TRUE;
}
