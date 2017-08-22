//Download by http://www.NewXing.com
// MyPlayerDlg.h : header file
//
//{{AFX_INCLUDES()
#include "activemovie3.h"
//}}AFX_INCLUDES

#if !defined(AFX_MYPLAYERDLG_H__8827309D_1BF4_49DA_86D0_321D6509161D__INCLUDED_)
#define AFX_MYPLAYERDLG_H__8827309D_1BF4_49DA_86D0_321D6509161D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyPlayerDlg dialog

class CMyPlayerDlg : public CDialog
{
// Construction
public:
	CMyPlayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyPlayerDlg)
	enum { IDD = IDD_MYPLAYER_DIALOG };
	CString	m_filename;
	CActiveMovie3	m_ActiveMovie;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFully();
	afx_msg void OnVolumeAdd();
	afx_msg void OnVolumeReduce();
	afx_msg void OnVolumeMute();
	afx_msg void OnMenuitem32771();
	afx_msg void OnMENUITEMExit();
	afx_msg void OnMENUITEMOpen();
	afx_msg void OnMENUITEMFull();
	afx_msg void OnMENUITEMAbout();
	afx_msg void OnMENUITEMAdd();
	afx_msg void OnMENUITEMDelete();
	afx_msg void OnMenuitemw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYPLAYERDLG_H__8827309D_1BF4_49DA_86D0_321D6509161D__INCLUDED_)
