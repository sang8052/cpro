// ͼ��ݹ���ϵͳ.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "������.h"
#include "��¼����.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ͼ��ݹ���ϵͳ

BEGIN_MESSAGE_MAP(ͼ��ݹ���ϵͳ, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// ͼ��ݹ���ϵͳ ����

ͼ��ݹ���ϵͳ::ͼ��ݹ���ϵͳ()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� ͼ��ݹ���ϵͳ ����

ͼ��ݹ���ϵͳ theApp;


// Cͼ��ݹ���ϵͳApp ��ʼ��

BOOL ͼ��ݹ���ϵͳ::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	��¼���� DlgLogin;
	DlgLogin.DoModal();

	������ DlgIndex;
	m_pMainWnd = &DlgIndex;
	INT_PTR nResponse = DlgIndex.DoModal();
;
	//��һ�������Ĵ����ǵ�¼���ڡ�����¼���ڱ��رղŻ���ʾ������
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
