// 主窗口.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "主窗口.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif





// 主窗口 对话框




主窗口::主窗口(CWnd* pParent /*=NULL*/)
	: CDialog(主窗口::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void 主窗口::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(主窗口, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &主窗口::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()


// C主窗口 消息处理程序

BOOL 主窗口::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	 //实例化所有标签对象
	
    Getready();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}



// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void 主窗口::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR 主窗口::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 自定义的初始化函数
void 主窗口::Getready(void)
{
	//获取选项卡控件的指针
	CTabCtrl *Ptab=(CTabCtrl*)GetDlgItem(IDC_TAB_MAIN);
	Ptab->InsertItem(1,"借书/还书");
	Ptab->InsertItem(2,"图书查询");
	Ptab->InsertItem(3,"新书入库");
	Ptab->InsertItem(4,"我借的书");
    Ptab->InsertItem(5,"关于");
	//创建所有标签
	DlgAbout.Create(IDD_FUN_ABOUT);
	DlgLeTurn.Create(IDD_FUN_LETURN);
	DlgSelect.Create(IDD_FUN_SELECT);
	DlgMyLend.Create(IDD_FUN_MYLEND);
	DlgAdd.Create(IDD_FUN_ADD);
	//设置标签的父窗口
	DlgAbout.SetParent(Ptab);
	DlgLeTurn.SetParent(Ptab);
    DlgSelect.SetParent(Ptab);
	DlgMyLend.SetParent(Ptab);
	DlgAdd.SetParent(Ptab);
	//设置默认显示那个标签页；
	 DlgLeTurn.ShowWindow(SW_SHOW);
	
}

//更换选项卡的时候调用的函数
void 主窗口::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CTabCtrl *Ptab=(CTabCtrl*)GetDlgItem(IDC_TAB_MAIN);
	int Tabsel=Ptab->GetCurSel();//定义一个整形变量来获取目前的选项卡
	switch(Tabsel)
	{
	  case 0:       
		  DlgLeTurn.ShowWindow(SW_SHOW);
		  DlgSelect.ShowWindow(SW_HIDE);
		  DlgAdd.ShowWindow(SW_HIDE);
		  DlgMyLend.ShowWindow(SW_HIDE);
		  DlgAbout.ShowWindow(SW_HIDE);
		  break;
	  case 1:  
		  DlgLeTurn.ShowWindow(SW_HIDE);
		  DlgSelect.ShowWindow(SW_SHOW);
		  DlgAdd.ShowWindow(SW_HIDE);
		  DlgMyLend.ShowWindow(SW_HIDE);
		  DlgAbout.ShowWindow(SW_HIDE);
		  break;
	  case 2:   
		  DlgLeTurn.ShowWindow(SW_HIDE);
		  DlgSelect.ShowWindow(SW_HIDE);
		  DlgAdd.ShowWindow(SW_SHOW);
		  DlgMyLend.ShowWindow(SW_HIDE);
		  DlgAbout.ShowWindow(SW_HIDE);
		  break;
	  case 3:   
		  DlgLeTurn.ShowWindow(SW_HIDE);
		  DlgSelect.ShowWindow(SW_HIDE);
		  DlgAdd.ShowWindow(SW_HIDE);
		  DlgMyLend.ShowWindow(SW_SHOW);
		  DlgAbout.ShowWindow(SW_HIDE);
		  break;
	case 4:   
		  DlgLeTurn.ShowWindow(SW_HIDE);
		  DlgSelect.ShowWindow(SW_HIDE);
		  DlgAdd.ShowWindow(SW_HIDE);
		  DlgMyLend.ShowWindow(SW_HIDE);
		  DlgAbout.ShowWindow(SW_SHOW);
		  break;
	  default:   
		  break;

	*pResult = 0;
	}
}

BOOL   主窗口::PreTranslateMessage(MSG*   pMsg)    
  {  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_ESCAPE)     return   TRUE;  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_RETURN)   return  	TRUE;    
    else    
          return   CDialog::PreTranslateMessage(pMsg);  
  }
