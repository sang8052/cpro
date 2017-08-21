//Download by http://www.NewXing.com
// MyDlgAbout.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "MyDlgAbout.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDlgAbout dialog


CMyDlgAbout::CMyDlgAbout(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlgAbout::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlgAbout)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyDlgAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlgAbout)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyDlgAbout, CDialog)
	//{{AFX_MSG_MAP(CMyDlgAbout)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlgAbout message handlers

void CMyDlgAbout::OnMenuitem32771() 
{
	// TODO: Add your command handler code here
	CMyDlgAbout MyDlgAbout;
	MyDlgAbout.DoModal();
}
