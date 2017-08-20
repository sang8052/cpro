#pragma once


// LendBook 对话框

class LendBook : public CDialog
{
	DECLARE_DYNAMIC(LendBook)

public:
	LendBook(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LendBook();

// 对话框数据
	enum { IDD = IDD_LendBook };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLendBook();
	afx_msg void OnSearchBook();
};
