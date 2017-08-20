// TESTDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <math.h>
#pragma comment(lib, "Version.lib ")

// CTESTDlg 对话框
class CTESTDlg : public CDialog
{
// 构造
public:
	CTESTDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nPreOperator; // 存放上次按下的一个运算符号的值 +，-*，/ 分别1， 2， 3， 4
	bool LastPressOperater;//如果最后一次按下的是运算符则置为1
	double m_nPlanNum;//用于记录运算值的累加
	double m_nowNum;//用于记录目前输入框中的最新的值
	afx_msg void OnBnClickedOk();
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_edt_cs;
	CEdit m_edt1_ct1;
	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum0();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	afx_msg void OnBnClickedButtonbackspace();
	afx_msg void OnBnClickedButtonpoint();
	afx_msg void OnBnClickedButtonzfh();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonC();
	int plan(int nNowOperator);// //实现加减乘除的运算处理函数
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonOut();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonRide();
	afx_msg void OnBnClickedButtonRid();
	// 表示按下了0-9中的某个键
	int PressNum(int nNum);
	
	
	afx_msg void OnBnClickedButtonbfh();
	afx_msg void OnBnClickedButtonds();
	afx_msg void OnBnClickedButtonsqrt();
	double memory;
	
	afx_msg void OnBnClickedButtonMc();
	afx_msg void OnBnClickedButtonMr();
	afx_msg void OnBnClickedButtonMs();
	afx_msg void OnBnClickedButtonMadd();
	afx_msg void menu_about();

	afx_msg void menu_copy();
	afx_msg void menu_paste();
	// 判断是否激活了等于号
	bool outvaule;
	afx_msg void OnEnChangeEdit1();
};
