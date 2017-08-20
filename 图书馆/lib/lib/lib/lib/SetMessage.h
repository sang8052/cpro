#pragma once
#include "DIALOG1.h"

// SetMessage 对话框

class SetMessage : public CDialog
{
	DECLARE_DYNAMIC(SetMessage)

public:
	SetMessage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SetMessage();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnOpenSMWin();
};
