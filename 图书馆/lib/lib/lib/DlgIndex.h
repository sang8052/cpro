#pragma once
#include "DlgLogin.h"

// CDlgIndex 对话框

class CDlgIndex : public CDialog
{
	public:
	CDlgIndex(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DIALOG_INDEX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CDlgLogin login;

	afx_msg void OnBnClickedButtonExit();
	
};
