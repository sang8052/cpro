// ������1_1Dlg.h : header file
//

#if !defined(AFX_1_1DLG_H__3A031195_1B16_442F_8E05_E201DB62E3D0__INCLUDED_)
#define AFX_1_1DLG_H__3A031195_1B16_442F_8E05_E201DB62E3D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1_1Dlg dialog

class CMy1_1Dlg : public CDialog
{
// Construction
public:
	CMy1_1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1_1Dlg)
	enum { IDD = IDD_MY1_1_DIALOG };
	CEdit	m_edt1_ct;
	CString	m_edt_cs;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1_1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1_1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButton03();
	afx_msg void OnButton01();
	afx_msg void OnButton02();
	afx_msg void OnOnButton04();
	afx_msg void OnButton05();
	afx_msg void OnButton06();
	afx_msg void OnButton07();
	afx_msg void OnButton08();
	afx_msg void OnButton09();
	afx_msg void OnButton00();
	afx_msg void OnButton_BackSpace();
	afx_msg void OnButton_CE();
	afx_msg void OnButton9_addsub();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	// ���ڴ�ż����ֵ
	int m_nPlanNum;
	// ���ڴ�ŵ�ǰ�༭���ֵ
	int m_NowNum;
	// ������������ +-*/ �ֱ���1 2 3 4 ����
	int plan(int nOperator);
	// ����ϴΰ��µ��������+-*/�� 1 2 3 4 ��ʾ
     int m_nPreOperator;
	// �������µ��Ƿ�������� �����Ϊ1 ����Ϊ0
	int LPIO;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton10getanswer();
	int PressNum(int nNum);
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton24C();
	afx_msg void OnBnClickedButton2Cc();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5xiaoshudian();
	afx_msg void OnBnClickedButton7();
	int M;
	CString M_string;
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton29();
	// �ж���һ���Ƿ�Ϊ���ں�
	int estimateequal;
	afx_msg void OnBnClickedButton21();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1_1DLG_H__3A031195_1B16_442F_8E05_E201DB62E3D0__INCLUDED_)
