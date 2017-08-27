// 主窗口.h : 头文件
//

#pragma once
#include "借书还书标签.h"
#include "图书查询标签.h"
#include "新书入库标签.h"
#include "我借的书标签.h"
#include "关于标签.h"




// 主窗口 对话框
class 主窗口 : public CDialog
{
// 构造
public:
	主窗口(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_INDEX };

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
	关于标签 DlgAbout;
    借书还书标签 DlgLeTurn;
    图书查询标签 DlgSelect;
    我借的书标签 DlgMyLend;
    新书入库标签 DlgAdd;
   
    // 自定义的初始化函数
	void Getready(void);
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	//重载回车消息
	BOOL  PreTranslateMessage(MSG*   pMsg) ;
};
