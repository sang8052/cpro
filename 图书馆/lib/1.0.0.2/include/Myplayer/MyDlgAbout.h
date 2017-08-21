//Download by http://www.NewXing.com
#if !defined(AFX_MYDLGABOUT_H__44AE3318_9B92_4961_BD04_09F90FF1DEB3__INCLUDED_)
#define AFX_MYDLGABOUT_H__44AE3318_9B92_4961_BD04_09F90FF1DEB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDlgAbout.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDlgAbout dialog

class CMyDlgAbout : public CDialog
{
// Construction
public:
	CMyDlgAbout(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlgAbout)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlgAbout)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyDlgAbout)
	afx_msg void OnMenuitem32771();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDLGABOUT_H__44AE3318_9B92_4961_BD04_09F90FF1DEB3__INCLUDED_)
