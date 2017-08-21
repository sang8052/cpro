#pragma once


// 修改图书信息弹窗 对话框

class 修改图书信息弹窗 : public CDialog
{
	DECLARE_DYNAMIC(修改图书信息弹窗)

public:
	修改图书信息弹窗(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~修改图书信息弹窗();

// 对话框数据
	enum { IDD = IDD_FUN_RESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 重载类的初始化函数
	virtual BOOL OnInitDialog();
};
