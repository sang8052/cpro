// 我的计算器Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "我的计算器.h"
#include "我的计算器Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
int nEditFlag=0;
CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_num1 = 0.0;
	m_num2 = 0.0;
	m_result = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_EDIT3, m_CResult);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_EDIT3, m_result);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3_03)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5_05)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_EN_SETFOCUS(IDC_EDIT1, OnSetfocusEdit1)
	ON_EN_SETFOCUS(IDC_EDIT2, OnSetfocusEdit2)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1_01, OnButton101)
	ON_BN_CLICKED(IDC_BUTTON2_02, OnButton202)
	ON_BN_CLICKED(IDC_BUTTON3_03, OnButton303)
	ON_BN_CLICKED(IDC_BUTTON_04, OnButton04)
	ON_BN_CLICKED(IDC_BUTTON6_06, OnButton606)
	ON_BN_CLICKED(IDC_BUTTON7_07, OnButton707)
	ON_BN_CLICKED(IDC_BUTTON8_08, OnButton808)
	ON_BN_CLICKED(IDC_BUTTON9_09, OnButton909)
	//ON_BN_CLICKED(IDC_BUTTON_4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON10_0, OnButton100)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton3_03() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	double n_result;
	n_result=m_num1*m_num2;
	m_result=n_result;
	char sz[20];
	sprintf(sz,"%f",m_result);
	m_CResult.SetWindowText(sz);
}

void CMyDlg::OnButton5_05() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+5;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+5;
	}
	UpdateData( FALSE );
}

void CMyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	double n_result;
	n_result=m_num1+m_num2;
	m_result=n_result;
	char sz[20];
	sprintf(sz,"%f",m_result);
	m_CResult.SetWindowText(sz);
}

void CMyDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	double n_result;
	n_result=m_num1-m_num2;
	m_result=n_result;
	char sz[20];
	sprintf(sz,"%f",m_result);
	m_CResult.SetWindowText(sz);
}

void CMyDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	double n_result;
	n_result=m_num1/m_num2;
	m_result=n_result;
	char sz[20];
	sprintf(sz,"%f",m_result);
	m_CResult.SetWindowText(sz);
}

void CMyDlg::OnSetfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	nEditFlag=1;
}

void CMyDlg::OnSetfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	nEditFlag=2;
}

void CMyDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	this->SetFocus();
	nEditFlag=0;
	CDialog::OnLButtonDown(nFlags, point);
}


void CMyDlg::OnButton101() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+1;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+1;
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton202() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+2;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+2;
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton303() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+3;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+3;
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton04() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+4;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+4;
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton606() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+6;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+6;
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton707() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+7;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+7;
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton808() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+8;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+8;
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton909() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10+9;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10+9;
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton100() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(nEditFlag==1)
	{
		m_num1=m_num1*10;
	}
	else if(nEditFlag==2)
	{
		m_num2=m_num2*10;
	}
	UpdateData(FALSE);
}
