#pragma once
#include "explorer_qr.h"
#include "Mshtml.h" 



// FunThank �Ի���

class FunThank : public CDialog
{
	DECLARE_DYNAMIC(FunThank)

public:
	FunThank(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FunThank();

// �Ի�������
	enum { IDD = IDD_FUN_THANKS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CExplorer_qr Ex_Thanks;
	void SetData(void);
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorerthank(LPDISPATCH pDisp, VARIANT* URL);
};
