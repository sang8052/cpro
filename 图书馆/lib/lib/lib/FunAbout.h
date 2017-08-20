#pragma once


// FunAbout 对话框

class FunAbout : public CDialog
{
	DECLARE_DYNAMIC(FunAbout)

public:
	FunAbout(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FunAbout();

// 对话框数据
	enum { IDD = IDD_FUN_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString strVERSION;
	void GetVersion(void);
	
};
