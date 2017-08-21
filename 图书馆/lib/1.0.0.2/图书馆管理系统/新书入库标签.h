#pragma once


// 新书入库标签 对话框

class 新书入库标签 : public CDialog
{
	DECLARE_DYNAMIC(新书入库标签)

public:
	新书入库标签(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~新书入库标签();

// 对话框数据
	enum { IDD = IDD_FUN_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 重载类的初始化函数
	virtual BOOL OnInitDialog();
};
