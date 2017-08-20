#pragma once
#include "explorer_qr.h"
#include "Mshtml.h" 



// FunThank 对话框

class FunThank : public CDialog
{
	DECLARE_DYNAMIC(FunThank)

public:
	FunThank(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FunThank();

// 对话框数据
	enum { IDD = IDD_FUN_THANKS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CExplorer_qr Ex_Thanks;
	void SetData(void);
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorerthank(LPDISPATCH pDisp, VARIANT* URL);
};
