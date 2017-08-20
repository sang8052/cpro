// ÎÒµÄ¼ÆËãÆ÷Dlg.h : header file
//

#if !defined(AFX_DLG_H__77C78104_097B_47F5_ABDC_455A902AB77C__INCLUDED_)
#define AFX_DLG_H__77C78104_097B_47F5_ABDC_455A902AB77C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CEdit	m_CResult;
	double	m_num1;
	double	m_num2;
	double	m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton3_03();
	afx_msg void OnButton5_05();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton4();
	afx_msg void OnSetfocusEdit1();
	afx_msg void OnSetfocusEdit2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButton101();
	afx_msg void OnButton202();
	afx_msg void OnButton303();
	afx_msg void OnButton04();
	afx_msg void OnButton606();
	afx_msg void OnButton707();
	afx_msg void OnButton808();
	afx_msg void OnButton909();
	afx_msg void OnButton100();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__77C78104_097B_47F5_ABDC_455A902AB77C__INCLUDED_)
