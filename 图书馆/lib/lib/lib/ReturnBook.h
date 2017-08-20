#pragma once


// ReturnBook 对话框

class ReturnBook : public CDialog
{
	DECLARE_DYNAMIC(ReturnBook)

public:
	ReturnBook(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ReturnBook();

// 对话框数据
	enum { IDD = IDD_ReturnBook };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
