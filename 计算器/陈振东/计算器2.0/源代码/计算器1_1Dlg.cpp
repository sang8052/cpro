// 计算器1_1Dlg.cpp : implementation file
//
#include"math.h"
#include "stdafx.h"
#include "计算器1_1.h"
#include "计算器1_1Dlg.h"
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
// CMy1_1Dlg dialog

CMy1_1Dlg::CMy1_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1_1Dlg::IDD, pParent)
	, m_nPlanNum(0)
	, m_NowNum(0)
	, m_nPreOperator(0)
	, LPIO(0)
	, M(0)
	, M_string(_T(""))
	, estimateequal(0)
{
	//{{AFX_DATA_INIT(CMy1_1Dlg)
	m_edt_cs = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	MessageBox("欢迎使用计算器！");
}

void CMy1_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1_1Dlg)
	DDX_Control(pDX, IDC_EDIT1, m_edt1_ct);
	DDX_Text(pDX, IDC_EDIT1, m_edt_cs);
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDIT2, M_string);
}

BEGIN_MESSAGE_MAP(CMy1_1Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1_1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON04, OnButton03)
	ON_BN_CLICKED(IDC_BUTTON01, OnButton01)
	ON_BN_CLICKED(IDC_BUTTON02, OnButton02)
	ON_BN_CLICKED(OnButton04, OnOnButton04)
	ON_BN_CLICKED(IDC_BUTTON05, OnButton05)
	ON_BN_CLICKED(IDC_BUTTON06, OnButton06)
	ON_BN_CLICKED(IDC_BUTTON07, OnButton07)
	ON_BN_CLICKED(IDC_BUTTON08, OnButton08)
	ON_BN_CLICKED(IDC_BUTTON09, OnButton09)
	ON_BN_CLICKED(IDC_BUTTON00, OnButton00)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton_BackSpace)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton_CE)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9_addsub)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON4, &CMy1_1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON10_getanswer, &CMy1_1Dlg::OnBnClickedButton10getanswer)
	ON_BN_CLICKED(IDC_BUTTON22, &CMy1_1Dlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON20, &CMy1_1Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON12, &CMy1_1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON2_CC, &CMy1_1Dlg::OnBnClickedButton2Cc)
	ON_BN_CLICKED(IDC_BUTTON25, &CMy1_1Dlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy1_1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5_xiaoshudian, &CMy1_1Dlg::OnBnClickedButton5xiaoshudian)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy1_1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON28, &CMy1_1Dlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON17, &CMy1_1Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON29, &CMy1_1Dlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON21, &CMy1_1Dlg::OnBnClickedButton21)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1_1Dlg message handlers

BOOL CMy1_1Dlg::OnInitDialog()
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
	
	// TODO: Add extra initializatin here
	HWND h=::GetDlgItem(m_hWnd,IDC_EDIT1);
	::SetWindowText(h,"0.");
	M=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1_1Dlg::OnPaint() 
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
HCURSOR CMy1_1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1_1Dlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

int CMy1_1Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	return 0;
}


void CMy1_1Dlg::OnButton01() 
{
	// TODO: Add your control notification handler code here
PressNum( 1 );
}

void CMy1_1Dlg::OnButton02() 
{
	// TODO: Add your control notification handler code here
PressNum( 2 );
}
void CMy1_1Dlg::OnButton03() 
{
	// TODO: Add your control notification handler code here
PressNum( 3 );
}

void CMy1_1Dlg::OnOnButton04() 
{
	// TODO: Add your control notification handler code here
PressNum( 4 );
}

void CMy1_1Dlg::OnButton05() 
{
	// TODO: Add your control notification handler code here
PressNum( 5 );
}


void CMy1_1Dlg::OnButton06() 
{
	// TODO: Add your control notification handler code here
PressNum( 6 );	
}

void CMy1_1Dlg::OnButton07() 
{
	// TODO: Add your control notification handler code here
PressNum( 7 );
}

void CMy1_1Dlg::OnButton08() 
{
	// TODO: Add your control notification handler code here
PressNum( 8 );
}

void CMy1_1Dlg::OnButton09() 
{
	// TODO: Add your control notification handler code here
PressNum( 9);
}

void CMy1_1Dlg::OnButton00() 
{
	// TODO: Add your control notification handler code here
PressNum( 0 );
}

void CMy1_1Dlg::OnButton_BackSpace() 
{
	// TODO: Add your control notification handler code here
   m_edt_cs= m_edt_cs.Left(m_edt_cs.GetLength()-1);
	UpdateData(false);
}

void CMy1_1Dlg::OnButton_CE() 
{
	// TODO: Add your control notification handler code here
	m_edt_cs="";
	UpdateData(false);
}

void CMy1_1Dlg::OnButton9_addsub() 
{
	// TODO: Add your control notification handler code here
	const TCHAR* ps=m_edt_cs.GetBuffer();
	if(ps[0]=='-')
	{
		ps++;
		m_edt_cs=ps;
	}else
	{
		CString s;
		s=_T("-");
		s+=m_edt_cs;
		m_edt_cs=s;
	}
	m_edt_cs.ReleaseBuffer();
	UpdateData(false);
}

// 用于四则运算 +-*/ %分别用1 2 3 4 5代替
int CMy1_1Dlg::plan(int nOperator)
{
	if(estimateequal==1)
	{
		OnBnClickedButton2Cc();
		estimateequal=0;
	}
if(LPIO)
{
	m_nPreOperator=nOperator;
	return 1;
}
	m_NowNum=atoi(m_edt_cs);
	switch(m_nPreOperator)
	{
	case 0:
			m_nPlanNum=m_NowNum;
			break;
	case 1:
			m_nPlanNum+=m_NowNum;
			break;
	case 2:
			m_nPlanNum-=m_NowNum;
			break;
	case 3:
            m_nPlanNum*=m_NowNum;
			break;
	case 4:
			m_nPlanNum/=m_NowNum;
			break;
	case 5:
		m_nPlanNum=m_nPlanNum%m_NowNum;
		break;
	case 6:
		double m,n;
		m=m_nPlanNum;
		n=m_NowNum;
		m_nPlanNum=pow(m,n);
	
	}
m_nPreOperator=nOperator;
LPIO=1;
m_edt_cs.Format("%d",m_nPlanNum);
UpdateData(false);
return 0;
}

void CMy1_1Dlg::OnBnClickedButton4()//运算 +
{
	plan(1);// TODO: 在此添加控件通知处理程序代码
}

void CMy1_1Dlg::OnBnClickedButton10getanswer()
{
	// TODO: 在此添加控件通知处理程序代码
plan(m_nPreOperator);
estimateequal=1;
}

int CMy1_1Dlg::PressNum(int nNum)
{
	
	if(estimateequal==1)
	{
		OnBnClickedButton2Cc();
		estimateequal=0;
	}
	CString ts;
	ts.Format(_T("%d"),nNum);
		if(LPIO)
	{
		m_edt_cs=ts;
	}
	else
	{
		m_edt_cs+=ts;
	}
	LPIO=0;
	UpdateData(false);
	return 0;
}

void CMy1_1Dlg::OnBnClickedButton22()
{
	// TODO: 在此添加控件通知处理程序代码
plan(4);
}

void CMy1_1Dlg::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
plan(2);
}

void CMy1_1Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
plan(3);
}

void CMy1_1Dlg::OnBnClickedButton24()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMy1_1Dlg::OnBnClickedButton24C()
{
	// TODO: 在此添加控件通知处理程序代码
    m_edt_cs="";
	UpdateData(false);
    m_nPlanNum=0;
}
void CMy1_1Dlg::OnBnClickedButton2Cc()
{
	// TODO: 在此添加控件通知处理程序代码
m_edt_cs="";
UpdateData(false);
LPIO=0;
m_NowNum=0;
m_nPlanNum=0;
m_nPreOperator=0;



}

void CMy1_1Dlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
plan(5);
}

void CMy1_1Dlg::OnBnClickedButton3()
{
plan(6);
}

void CMy1_1Dlg::OnBnClickedButton5xiaoshudian()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edt_cs+=".";
	UpdateData(false);
}

void CMy1_1Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
m_NowNum=atoi(m_edt_cs);
M=m_NowNum;
M_string="M";
UpdateData(false);
}

void CMy1_1Dlg::OnBnClickedButton28()
{
m_edt_cs.Format("%d",M);
}

void CMy1_1Dlg::OnBnClickedButton17()
{
	M=0;
	M_string="0.";
    UpdateData(false);// TODO: 在此添加控件通知处理程序代码
}


void CMy1_1Dlg::OnBnClickedButton29()
{
	// TODO: 在此添加控件通知处理程序代码
	m_NowNum=atoi(m_edt_cs);
	M=M+m_NowNum;
	m_edt_cs.Format("%d",M);
}

void CMy1_1Dlg::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
}
