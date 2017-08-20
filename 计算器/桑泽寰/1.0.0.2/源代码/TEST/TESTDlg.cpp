// TESTDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TEST.h"
#include "TESTDlg.h"
#include <atlconv.h>
#include "afxwin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	
	CString strVersion;
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
, strVersion(_T(""))
{
	wchar_t cPath[200];
 DWORD dwHandle,InfoSize;
 ::GetModuleFileName(NULL,cPath,sizeof(cPath)); //首先获得版本信息资源的长度
 InfoSize = GetFileVersionInfoSize(cPath,&dwHandle); //将版本信息资源读入缓冲区
 if(InfoSize==0) {AfxMessageBox(_T("None VerSion Supprot"));return ;}
 char *InfoBuf = new char[InfoSize];
 GetFileVersionInfo(cPath,0,InfoSize,InfoBuf); //获得生成文件使用的代码页及文件版本
 unsigned int  cbTranslate = 0;
 struct LANGANDCODEPAGE {WORD wLanguage; WORD wCodePage; } *lpTranslate;
 VerQueryValue(InfoBuf, TEXT("\\VarFileInfo\\Translation"),(LPVOID*)&lpTranslate,&cbTranslate);
 // Read the file description for each language and code page.
 for(unsigned int i=0; i < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); i++ )
 { wchar_t  SubBlock[200];wsprintf( SubBlock,TEXT("\\StringFileInfo\\%04x%04x\\FileVersion"),lpTranslate[i].wLanguage,lpTranslate[i].wCodePage);
  void *lpBuffer=NULL;unsigned int dwBytes=0;VerQueryValue(InfoBuf,SubBlock,&lpBuffer,&dwBytes);
  CString strTemp=( wchar_t *)lpBuffer;strVersion+=strTemp;}
  delete InfoBuf;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
	DDX_Text(pDX, IDC_STATIC_VERSION, strVersion);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)

END_MESSAGE_MAP()


// CTESTDlg 对话框




CTESTDlg::CTESTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTESTDlg::IDD, pParent)
	, m_edt_cs(_T(""))
	, m_nPreOperator(0)
	, memory(0)
	, outvaule(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
   
   //MessageBox(L"CTESTDlg 类的构造函数");
}

void CTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edt_cs);
	DDX_Control(pDX, IDC_EDIT1, m_edt1_ct1);
}

BEGIN_MESSAGE_MAP(CTESTDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_NUM7, &CTESTDlg::OnBnClickedButtonNum7)
	ON_BN_CLICKED(IDC_BUTTON_NUM8, &CTESTDlg::OnBnClickedButtonNum8)
	ON_BN_CLICKED(IDC_BUTTON_NUM0, &CTESTDlg::OnBnClickedButtonNum0)
	ON_BN_CLICKED(IDC_BUTTON_NUM9, &CTESTDlg::OnBnClickedButtonNum9)
	ON_BN_CLICKED(IDC_BUTTON_NUM4, &CTESTDlg::OnBnClickedButtonNum4)
	ON_BN_CLICKED(IDC_BUTTON_NUM5, &CTESTDlg::OnBnClickedButtonNum5)
	ON_BN_CLICKED(IDC_BUTTON_NUM6, &CTESTDlg::OnBnClickedButtonNum6)
	ON_BN_CLICKED(IDC_BUTTON_NUM1, &CTESTDlg::OnBnClickedButtonNum1)
	ON_BN_CLICKED(IDC_BUTTON_NUM2, &CTESTDlg::OnBnClickedButtonNum2)
	ON_BN_CLICKED(IDC_BUTTON_NUM3, &CTESTDlg::OnBnClickedButtonNum3)
	ON_BN_CLICKED(IDC_BUTTON_backspace, &CTESTDlg::OnBnClickedButtonbackspace)
	ON_BN_CLICKED(IDC_BUTTON_point, &CTESTDlg::OnBnClickedButtonpoint)
	ON_BN_CLICKED(IDC_BUTTON_zfh, &CTESTDlg::OnBnClickedButtonzfh)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CTESTDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_C, &CTESTDlg::OnBnClickedButtonC)
	
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CTESTDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_OUT, &CTESTDlg::OnBnClickedButtonOut)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CTESTDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_RIDE, &CTESTDlg::OnBnClickedButtonRide)
	ON_BN_CLICKED(IDC_BUTTON_RID, &CTESTDlg::OnBnClickedButtonRid)
	
	ON_BN_CLICKED(IDC_BUTTON_bfh, &CTESTDlg::OnBnClickedButtonbfh)
	ON_BN_CLICKED(IDC_BUTTON_ds, &CTESTDlg::OnBnClickedButtonds)
	ON_BN_CLICKED(IDC_BUTTON_sqrt, &CTESTDlg::OnBnClickedButtonsqrt)
	
	ON_BN_CLICKED(IDC_BUTTON_MC, &CTESTDlg::OnBnClickedButtonMc)
	ON_BN_CLICKED(IDC_BUTTON_MR, &CTESTDlg::OnBnClickedButtonMr)
	ON_BN_CLICKED(IDC_BUTTON_MS, &CTESTDlg::OnBnClickedButtonMs)
	ON_BN_CLICKED(IDC_BUTTON_MADD, &CTESTDlg::OnBnClickedButtonMadd)
	ON_COMMAND(ID_32777, &CTESTDlg::menu_about)
	ON_COMMAND(ID_32771, &CTESTDlg::menu_copy)
	ON_COMMAND(ID_32779, &CTESTDlg::menu_paste)
	ON_EN_CHANGE(IDC_EDIT1, &CTESTDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CTESTDlg 消息处理程序

BOOL CTESTDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
  //MessageBox(L"OnInitDialog函数");
	/*HWND h=::GetDlgItem(m_hWnd,IDC_EDIT1);
	::SetWindowText(h,L"0.");*/
	//GetDlgItem(IDC_EDIT1)-> SetWindowText(L"0.");
	/*m_edt_cs=L"0.";
	UpdateData(FALSE); //表示把关联变量更新的窗口 TRUE表示把窗口的更新到关联变量*/
	m_edt1_ct1.SetWindowText(L"0.");//省略了参数 m_edt1_ctl.m_hWnd
	memory=0;
	return TRUE;// 除非将焦点设置到控件，否则返回 TRUE
}

void CTESTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTESTDlg::OnPaint()
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
HCURSOR CTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int CTESTDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//MessageBox(L"Oncreate 窗口创建函数");
	return 0;
}



void CTESTDlg::OnBnClickedButtonNum1()
{
	// TODO: 在此添加控件通知处理程序代码
	PressNum(1);
}

void CTESTDlg::OnBnClickedButtonNum2()
{
	// TODO: 在此添加控件通知处理程序代码
	PressNum(2);
}

void CTESTDlg::OnBnClickedButtonNum3()
{
	// TODO: 在此添加控件通知处理程序代码
	PressNum(3);
}

void CTESTDlg::OnBnClickedButtonNum4()
{
	// TODO: 在此添加控件通知处理程序代码
	PressNum(4);
}

void CTESTDlg::OnBnClickedButtonNum5()
{
	// TODO: 在此添加控件通知处理程序代码
	PressNum(5);
}

void CTESTDlg::OnBnClickedButtonNum6()
{
	// TODO: 在此添加控件通知处理程序代码
	PressNum(6);
}

void CTESTDlg::OnBnClickedButtonNum7()
{
	// TODO: 在此添加控件通知处理程序代码
  PressNum(7);
}

void CTESTDlg::OnBnClickedButtonNum8()
{
	// TODO: 在此添加控件通知处理程序代码
	PressNum(8);
}

void CTESTDlg::OnBnClickedButtonNum9()
{
	// TODO: 在此添加控件通知处理程序代码
	PressNum(9);
}

void CTESTDlg::OnBnClickedButtonNum0()
{
	// TODO: 在此添加控件通知处理程序代码.
	PressNum(0);
}
void CTESTDlg::OnBnClickedButtonbackspace()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edt_cs.GetBuffer()[m_edt_cs.GetLength()-1]=0; //把m_edt_cs的对应变量的数组的最后一位置为0（空）； 
	m_edt_cs.ReleaseBuffer();//释放字符串缓冲区
	UpdateData(false);
}

void CTESTDlg::OnBnClickedButtonpoint()
{
	// TODO: 在此添加控件通知处理程序代码
	const TCHAR * temp=m_edt_cs.GetBuffer();
	if(temp==L"")//判断输入框是否已经被初始化
	{m_edt_cs+=L".";//每次在输入框的尾部增加一个小数点
	UpdateData(false);}
	else{
	      if(temp[m_edt_cs.GetLength()-1]=='.')//判断输入框中是否已经存在小数点
	        {
		      m_edt_cs.ReleaseBuffer();//释放缓冲区
		      //如果有则不执行任何操作
	        }
	     else
	         { 
				 m_edt_cs.ReleaseBuffer();//释放缓冲区
	             m_edt_cs+=L".";//每次在输入框的尾部增加一个小数点
                 UpdateData(false);
	         }
	}
	
	
}

void CTESTDlg::OnBnClickedButtonzfh()//正负号按钮的执行代码
{
	// TODO: 在此添加控件通知处理程序代码
   const TCHAR * temp=m_edt_cs.GetBuffer();
	if(temp[0]=='-')//判断输入框中是否已经存在有减号
	{
		temp++;
		m_edt_cs=temp;
	}
	else
	{
		CString temp2;
		temp2=_T("-");
		temp2+=m_edt_cs;
		m_edt_cs=temp2;
	}
	m_edt_cs.ReleaseBuffer();
	UpdateData(false);

}



void CTESTDlg::OnBnClickedButtonCe()//只是把当前输入框的代码清为0，其他的值不变。
{
	// TODO: 在此添加控件通知处理程序代码
     m_edt_cs=L"0.";
	 UpdateData(false);
	 LastPressOperater=1;
}

void CTESTDlg::OnBnClickedButtonC()// 全部清为0
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedButtonCe();
    m_nPlanNum=0;
	m_nowNum=0;
    LastPressOperater=1;
    m_nPreOperator=0;
}

// //实现加减乘除的运算处理函数
int  CTESTDlg::plan(int nNowOperator)
{
	bool judge=1;
	if(LastPressOperater){m_nPreOperator=nNowOperator; return 1;} //如果上一个按键也是运算符号，就把新的运算符号更新到旧的运算符号里面去，并退出函数
	m_nowNum=_wtof(m_edt_cs);//消息框中目前的值将字串转换成一个双精度的数据 （注:_wtoi()表示转换成整形，_wtof()表示转换成双精度）
	switch(m_nPreOperator)
	       {
	          case 0:       m_nPlanNum=m_nowNum;      break;//空运算
	          case 1:       m_nPlanNum+=m_nowNum;     break;//加号
	          case 2:       m_nPlanNum-=m_nowNum;     break;//减号
	          case 3:       m_nPlanNum*=m_nowNum;     break;//乘号
			  case 4:       if(m_nowNum==0){judge=0;}else{m_nPlanNum/=m_nowNum;}     break;//除号
			  
	       }
	      if(judge==0)
		  {m_nPlanNum=0;
			m_nPreOperator=nNowOperator;//把运算符按键的信息写到上一个运算符按键信息中去
		   LastPressOperater=1;
		   m_edt_cs.Format(L"除数不能为零！");//相当于printf,输出值到字串中去
		   UpdateData(false);
		   return 0;}
		  else{
		   m_nPreOperator=nNowOperator;//把运算符按键的信息写到上一个运算符按键信息中去
		   LastPressOperater=1;
		   m_edt_cs.Format(L"%g",m_nPlanNum);//相当于printf,输出值到字串中去
		   UpdateData(false);
		   return 0;}
	    
}

void CTESTDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	if(outvaule){plan(0);m_nPreOperator=1;outvaule=0;}
	plan(1);
}



void CTESTDlg::OnBnClickedButtonOut()
{
	// TODO: 在此添加控件通知处理程序代码

	plan(m_nPreOperator);
	outvaule=1;
	//按下等于号就相当于全清按钮C，但是输出的结果不应该被改变。
	
}

void CTESTDlg::OnBnClickedButtonMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	if(outvaule){plan(0);m_nPreOperator=2;outvaule=0;}
	plan(2);
}

void CTESTDlg::OnBnClickedButtonRide()
{
	// TODO: 在此添加控件通知处理程序代码
	if(outvaule){plan(0);m_nPreOperator=3;outvaule=0;}
	plan(3);
}

void CTESTDlg::OnBnClickedButtonRid()
{
	// TODO: 在此添加控件通知处理程序代码
	if(outvaule){plan(0);m_nPreOperator=4;outvaule=0;}
	plan(4);
}

// 表示按下了0-9中的某个键
int CTESTDlg::PressNum(int nNum)
{
if(outvaule){m_nPlanNum=0;m_nowNum=0;LastPressOperater=1;m_nPreOperator=0;}
	CString tp;
	tp.Format(L"%d",nNum);//将传进来的参数格式化成一个字串
    if(LastPressOperater){m_edt_cs=tp;}//如果上一个按下的键是运算符，则消息框中的值直接变成由传入的值转化成的字串
	else{m_edt_cs+=tp;}//如果上一个按下的键不是运算符，则消息框的尾部增加一个由传入的值转化成的字串
	LastPressOperater=0;//标识上一个按下的键不是运算符号
	UpdateData(false);
	return 0;
}

void CTESTDlg::OnBnClickedButtonbfh() //%运算
{
	// TODO: 在此添加控件通知处理程序代码
	double ts;
	ts=_wtof(m_edt_cs);
	LastPressOperater=1;
	ts=ts/100;
	m_edt_cs.Format(L"%g",ts);
	UpdateData(false);
}

void CTESTDlg::OnBnClickedButtonds() //倒数运算
{
	// TODO: 在此添加控件通知处理程序代码
	double ts;
	ts=_wtof(m_edt_cs);
	LastPressOperater=1;
	if(ts==0){m_edt_cs.Format(L"分母不能为零！");}
	else{ts=1/ts;m_edt_cs.Format(L"%g",ts);}
	UpdateData(false);

}


void CTESTDlg::OnBnClickedButtonsqrt() //开方运算
{
	// TODO: 在此添加控件通知处理程序代码
	double ts;
	ts=_wtof(m_edt_cs);
	LastPressOperater=1;
	ts=sqrt(ts);m_edt_cs.Format(L"%g",ts);
	UpdateData(false);
}


void CTESTDlg::OnBnClickedButtonMc()
{
	// TODO: 在此添加控件通知处理程序代码
	memory=0;
	CString str; str.Format(L"");
	SetDlgItemText( IDC_STATIC, str);

}

void CTESTDlg::OnBnClickedButtonMr()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edt_cs.Format(L"%g",memory);
	UpdateData(false);

}

void CTESTDlg::OnBnClickedButtonMs()
{
	// TODO: 在此添加控件通知处理程序代码
	memory=_wtof(m_edt_cs);
	CString str; str.Format(L"M");
	SetDlgItemText( IDC_STATIC, str);
}



void CTESTDlg::OnBnClickedButtonMadd()
{
	// TODO: 在此添加控件通知处理程序代码
	double ts;
	ts=_wtof(m_edt_cs);
	ts=ts+memory;
	m_edt_cs.Format(L"%g",ts);
	UpdateData(false);

}
 CAboutDlg about;
void CTESTDlg::menu_about()
{
	// TODO: 在此添加命令处理程序代码
	if(about.m_hWnd==0)//如果窗口的句柄为零，即没有创建
	{
		about.Create(IDD_ABOUTBOX,this);//创建一次窗口的句柄
	}
	about.ShowWindow(SW_SHOW);//显示窗口
}




void CTESTDlg::menu_copy()
{
	// TODO: 在此添加命令处理程序代码

    //进行字符创转换

	//char cs[256]="";
	//USES_CONVERSION;
	//strcpy(cs,W2A(m_edt_cs.GetBuffer()));
	//HGLOBAL hmem=NULL;
	//if(OpenClipboard())//是否成功打开了剪切板
	//{
	//	if(EmptyClipboard())//清空剪切板，成功则继续
	//	{
	//		hmem=GlobalAlloc(GHND,sizeof(cs));//分配内存
	//	    char* pmem=(char*)GlobalLock(hmem);//锁定内存
	//		memcpy(pmem,cs,sizeof(cs));
	//		SetClipboardData(CF_TEXT,hmem);//向剪切板的缓存控件中赋值
	//		CloseClipboard();//关闭剪切板线程
	//		GlobalUnlock(pmem);//清空内存(解除内存锁定）
	//	}

	//}

	//不进行字符串转换
	HGLOBAL hmem=NULL;
	if(OpenClipboard())//是否成功打开了剪切板
	{
		if(EmptyClipboard())//清空剪切板，成功则继续
		{
			hmem=GlobalAlloc(GHND,(m_edt_cs.GetLength()+1)*2);//分配内存
		    wchar_t* pmem=(WCHAR*)GlobalLock(hmem);//锁定内存
			memcpy(pmem,m_edt_cs.GetBuffer(),(m_edt_cs.GetLength()+1)*2);
			SetClipboardData(CF_UNICODETEXT ,hmem);//向剪切板的缓存控件中赋值
			CloseClipboard();//关闭剪切板线程
			GlobalUnlock(pmem);//清空内存(解除内存锁定）
		}

	}
}

void CTESTDlg::menu_paste()
{
	// TODO: 在此添加命令处理程序代码
	
	// 短字符处理代码

	////设置内存存放的位置，以及存放的类型，和内存的大小
	HGLOBAL hmem=NULL;
	char s[256]="";
	if(IsClipboardFormatAvailable(CF_TEXT))//CF_UNICODETEXT  判断剪切板粘贴的数据格式是否是我们所需要的
	{
		//打开剪切板
		if(OpenClipboard())
		{
			//得到剪切板的句柄
			hmem=GetClipboardData(CF_TEXT);
			if(hmem)
			{
				//锁定全局内存获得缓冲区的指针
				char* ps=(char*)GlobalLock(hmem);
				memcpy(s,ps,GlobalSize(hmem));
			}
		}
		//关闭剪切板，以使得其他程序也可以访问，并且释放内存锁
	CloseClipboard();
	GlobalUnlock(hmem);
	m_edt_cs=s;
	UpdateData(false);
	}
	
	//长字符处理代码
if(IsClipboardFormatAvailable(CF_UNICODETEXT))//CF_UNICODETEXT  判断剪切板粘贴的数据格式是否是我们所需要的
	{
		HGLOBAL hmem=NULL;
		//打开剪切板
		if(OpenClipboard())
		{
			//得到剪切板的句柄
			hmem=GetClipboardData(CF_UNICODETEXT);
			if(hmem)
			{
				//锁定全局内存获得缓冲区的指针
				LPTSTR ps=(WCHAR*)GlobalLock(hmem);
				m_edt_cs=ps;
			}
		}
		//关闭剪切板，以使得其他程序也可以访问，并且释放内存锁
	CloseClipboard();
	GlobalUnlock(hmem);
	
	UpdateData(false);
	}
}

void CTESTDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	// TODO: 在此添加命令处理程序代码
		int nselStart,nselEnd;
	//m_edt1_ctl.GetSel(nselStart,nselEnd);
	//nselStart=3;nselEnd=3;
	//m_edt1_ctl.SetSel(nselStart,nselEnd);
	WCHAR ts[256]=L"";
	m_edt1_ct1.GetWindowText(ts,256);
	m_edt1_ct1.GetSel(nselStart,nselEnd);
    int num=0;
	if (nselStart-1<0)
	{
		return;
	}
	WCHAR c=ts[nselStart-1];//获取的最后输入的字符
	  //判断 是数字，或者小数点才让输入
	if (c>='0'&&c<='9' ||c=='.')
	{
		if (c=='.')
		{
			//判断字串里的小数点的个数 个数为1 大于1
			for (unsigned int i=0;i<=wcslen(ts);i++)
			{
				if (ts[i]=='.')
				{
					num++;
				}
			}
			if (num>1)
			{
				//m_edt_cs让它更新至窗口
				UpdateData(false);
				m_edt1_ct1.SetSel(nselStart-1,nselStart-1);
				return;
			}
         
		}
		UpdateData(true);//更新窗口数据至变量
	}else
	{   //是字母和小数点
		//m_edt_cs让它更新至窗口
		UpdateData(false);
		m_edt1_ct1.SetSel(nselStart-1,nselStart-1);
	}

}
