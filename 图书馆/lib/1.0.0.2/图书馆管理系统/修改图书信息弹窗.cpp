// �޸�ͼ����Ϣ����.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "�޸�ͼ����Ϣ����.h"


// �޸�ͼ����Ϣ���� �Ի���

IMPLEMENT_DYNAMIC(�޸�ͼ����Ϣ����, CDialog)

�޸�ͼ����Ϣ����::�޸�ͼ����Ϣ����(CWnd* pParent /*=NULL*/)
	: CDialog(�޸�ͼ����Ϣ����::IDD, pParent)
{

}

�޸�ͼ����Ϣ����::~�޸�ͼ����Ϣ����()
{
}

void �޸�ͼ����Ϣ����::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(�޸�ͼ����Ϣ����, CDialog)
END_MESSAGE_MAP()


// ������ĳ�ʼ������

BOOL �޸�ͼ����Ϣ����::OnInitDialog()
{
	return TRUE;
}
