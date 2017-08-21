//Download by http://www.NewXing.com
// MyPlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "MyPlayerDlg.h"

#include "MyDlgAbout.h"

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
// CMyPlayerDlg dialog

CMyPlayerDlg::CMyPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyPlayerDlg)
	m_filename = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyPlayerDlg)
	DDX_Text(pDX, IDC_EDIT1, m_filename);
	DDX_Control(pDX, IDC_ACTIVEMOVIECONTROL1, m_ActiveMovie);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CMyPlayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FULLY, OnFully)
	ON_BN_CLICKED(IDC_VOLUME_ADD, OnVolumeAdd)
	ON_BN_CLICKED(IDC_VOLUME_REDUCE, OnVolumeReduce)
	ON_BN_CLICKED(IDC_VOLUME_MUTE, OnVolumeMute)
	ON_COMMAND(ID_MENUITEMExit, OnMENUITEMExit)
	ON_COMMAND(ID_MENUITEMOpen, OnMENUITEMOpen)
	ON_COMMAND(ID_MENUITEMFull, OnMENUITEMFull)
	ON_COMMAND(ID_MENUITEMAbout, OnMENUITEMAbout)
	ON_COMMAND(ID_MENUITEMAdd, OnMENUITEMAdd)
	ON_COMMAND(ID_MENUITEMDelete, OnMENUITEMDelete)
	ON_COMMAND(ID_MENUITEMW, OnMenuitemw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyPlayerDlg message handlers

BOOL CMyPlayerDlg::OnInitDialog()
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

void CMyPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyPlayerDlg::OnPaint() 
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
HCURSOR CMyPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CMyPlayerDlg::OnFully() 
{
	// TODO: Add your control notification handler code here
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetFullScreenMode(TRUE);
	m_ActiveMovie.SetMovieWindowSize(SW_SHOWMAXIMIZED);
	m_ActiveMovie.Run();
}

void CMyPlayerDlg::OnVolumeAdd() 
{
	// TODO: Add your control notification handler code here
	long volume=m_ActiveMovie.GetVolume();
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(volume+100);
	m_ActiveMovie.Run();
}


void CMyPlayerDlg::OnVolumeReduce() 
{
	// TODO: Add your control notification handler code here
	long volume=m_ActiveMovie.GetVolume();
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(volume-100);
	m_ActiveMovie.Run();
}

void CMyPlayerDlg::OnVolumeMute() 
{
	// TODO: Add your control notification handler code here
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(-4000);
	m_ActiveMovie.Run();
}


void CMyPlayerDlg::OnMENUITEMExit() 
{
	// TODO: Add your command handler code here
	OnOK();
}

void CMyPlayerDlg::OnMENUITEMOpen() 
{
	// TODO: Add your command handler code here
	char szFileFilter[]=
		
		"Wmv File(*.wmv)|*.wmv|"
		"Mp3 File(*.mp3)|*.mp3|"
		"Wma File(*.wma)|*.wma|"
		"MPEG File(*.mpg)|*.mpg|"
		"Wave File(*.wav)|*.wav|"
		
		"Avi File(*.avi)|*.avi|"
		"Movie File(*.mov)|*.mov|"
		"Rmvb File(*.rmvb)|*.rmvb|"
		"Hid File(*.mid;*.rm)|*.mid;*.rm|"
		"ALL File(*.*)|*.*||";
		
	    //"Video File(*.dat)|*.dat|";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,szFileFilter,this);
	if(dlg.DoModal()==IDCANCEL)return;
	m_filename=dlg.GetPathName();
	UpdateData(FALSE);
	m_ActiveMovie.SetFileName(m_filename);
}

void CMyPlayerDlg::OnMENUITEMFull() 
{
	// TODO: Add your command handler code here
    m_ActiveMovie.Pause();
	m_ActiveMovie.SetFullScreenMode(TRUE);
	m_ActiveMovie.SetMovieWindowSize(SW_SHOWMAXIMIZED);
	m_ActiveMovie.Run();
}

void CMyPlayerDlg::OnMENUITEMAbout() 
{
	// TODO: Add your command handler code here
	CMyDlgAbout MyDlgAbout;
	MyDlgAbout.DoModal();
}

void CMyPlayerDlg::OnMENUITEMAdd() 
{
	// TODO: Add your command handler code here
	long volume=m_ActiveMovie.GetVolume();
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(volume+100);
	m_ActiveMovie.Run();
}

void CMyPlayerDlg::OnMENUITEMDelete() 
{
	// TODO: Add your command handler code here
	long volume=m_ActiveMovie.GetVolume();
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(volume-100);
	m_ActiveMovie.Run();
}

void CMyPlayerDlg::OnMenuitemw() 
{
	// TODO: Add your command handler code here
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(-4000);
	m_ActiveMovie.Run();
}
