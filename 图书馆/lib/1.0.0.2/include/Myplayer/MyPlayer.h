//Download by http://www.NewXing.com
// MyPlayer.h : main header file for the MYPLAYER application
//

#if !defined(AFX_MYPLAYER_H__18D2313D_0ADC_4601_9400_9F23318B26A7__INCLUDED_)
#define AFX_MYPLAYER_H__18D2313D_0ADC_4601_9400_9F23318B26A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyPlayerApp:
// See MyPlayer.cpp for the implementation of this class
//

class CMyPlayerApp : public CWinApp
{
public:
	CMyPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyPlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyPlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYPLAYER_H__18D2313D_0ADC_4601_9400_9F23318B26A7__INCLUDED_)
