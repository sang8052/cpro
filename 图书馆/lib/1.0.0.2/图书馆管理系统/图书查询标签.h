#pragma once


// 图书查询标签 对话框

class 图书查询标签 : public CDialog
{
	DECLARE_DYNAMIC(图书查询标签)

public:
	图书查询标签(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~图书查询标签();

// 对话框数据
	enum { IDD = IDD_FUN_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 重载类的初始化函数
	virtual BOOL OnInitDialog();
};
