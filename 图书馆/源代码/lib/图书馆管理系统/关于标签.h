#pragma once
#include "������.h"     //�����Ӷ������
#include "explorer.h"   //���õ��������ͷ�ļ�
#include "Mshtml.h"     //���������������ҳ���д����ͷ�ļ�

// ���ڱ�ǩ �Ի���

class ���ڱ�ǩ : public CDialog
{
	DECLARE_DYNAMIC(���ڱ�ǩ)

public:
	���ڱ�ǩ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~���ڱ�ǩ();

// �Ի�������
	enum { IDD = IDD_FUN_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
public:
	// ��ĳ�ʼ������
	DECLARE_EVENTSINK_MAP(); //�ڲ�������¼�
	������ AboutUrl;
	afx_msg void OnStnClickedStaticAbouturl();
	CString strVERSION;
	CExplorer Explorer_About;
	
	void DocumentCompleteExplorerAbout(LPDISPATCH pDisp, VARIANT* URL);
    BOOL  PreTranslateMessage(MSG*   pMsg) ;
};
