#pragma once
#include "SetMessage.h"
#include "ReturnBook.h"//还书
#include "LendBook.h"//找书
// DIALOG1 对话框

class DIALOG1 : public CDialog
{
	DECLARE_DYNAMIC(DIALOG1)
friend class ClibDlg;

public:
	DIALOG1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIALOG1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMile_tebeimingxie();
	afx_msg void Ontitlebar_guanyutext();
	afx_msg void Onexit();
	
	afx_msg void OnOpenSMWin();
	afx_msg void OnSearchBook();
	afx_msg void On32774();
};
