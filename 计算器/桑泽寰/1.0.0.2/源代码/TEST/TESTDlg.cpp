// TESTDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TEST.h"
#include "TESTDlg.h"
#include <atlconv.h>
#include "afxwin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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
 ::GetModuleFileName(NULL,cPath,sizeof(cPath)); //���Ȼ�ð汾��Ϣ��Դ�ĳ���
 InfoSize = GetFileVersionInfoSize(cPath,&dwHandle); //���汾��Ϣ��Դ���뻺����
 if(InfoSize==0) {AfxMessageBox(_T("None VerSion Supprot"));return ;}
 char *InfoBuf = new char[InfoSize];
 GetFileVersionInfo(cPath,0,InfoSize,InfoBuf); //��������ļ�ʹ�õĴ���ҳ���ļ��汾
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


// CTESTDlg �Ի���




CTESTDlg::CTESTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTESTDlg::IDD, pParent)
	, m_edt_cs(_T(""))
	, m_nPreOperator(0)
	, memory(0)
	, outvaule(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
   
   //MessageBox(L"CTESTDlg ��Ĺ��캯��");
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


// CTESTDlg ��Ϣ�������

BOOL CTESTDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
  //MessageBox(L"OnInitDialog����");
	/*HWND h=::GetDlgItem(m_hWnd,IDC_EDIT1);
	::SetWindowText(h,L"0.");*/
	//GetDlgItem(IDC_EDIT1)-> SetWindowText(L"0.");
	/*m_edt_cs=L"0.";
	UpdateData(FALSE); //��ʾ�ѹ����������µĴ��� TRUE��ʾ�Ѵ��ڵĸ��µ���������*/
	m_edt1_ct1.SetWindowText(L"0.");//ʡ���˲��� m_edt1_ctl.m_hWnd
	memory=0;
	return TRUE;// ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int CTESTDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	//MessageBox(L"Oncreate ���ڴ�������");
	return 0;
}



void CTESTDlg::OnBnClickedButtonNum1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PressNum(1);
}

void CTESTDlg::OnBnClickedButtonNum2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PressNum(2);
}

void CTESTDlg::OnBnClickedButtonNum3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PressNum(3);
}

void CTESTDlg::OnBnClickedButtonNum4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PressNum(4);
}

void CTESTDlg::OnBnClickedButtonNum5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PressNum(5);
}

void CTESTDlg::OnBnClickedButtonNum6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PressNum(6);
}

void CTESTDlg::OnBnClickedButtonNum7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
  PressNum(7);
}

void CTESTDlg::OnBnClickedButtonNum8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PressNum(8);
}

void CTESTDlg::OnBnClickedButtonNum9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PressNum(9);
}

void CTESTDlg::OnBnClickedButtonNum0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������.
	PressNum(0);
}
void CTESTDlg::OnBnClickedButtonbackspace()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edt_cs.GetBuffer()[m_edt_cs.GetLength()-1]=0; //��m_edt_cs�Ķ�Ӧ��������������һλ��Ϊ0���գ��� 
	m_edt_cs.ReleaseBuffer();//�ͷ��ַ���������
	UpdateData(false);
}

void CTESTDlg::OnBnClickedButtonpoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	const TCHAR * temp=m_edt_cs.GetBuffer();
	if(temp==L"")//�ж�������Ƿ��Ѿ�����ʼ��
	{m_edt_cs+=L".";//ÿ����������β������һ��С����
	UpdateData(false);}
	else{
	      if(temp[m_edt_cs.GetLength()-1]=='.')//�ж���������Ƿ��Ѿ�����С����
	        {
		      m_edt_cs.ReleaseBuffer();//�ͷŻ�����
		      //�������ִ���κβ���
	        }
	     else
	         { 
				 m_edt_cs.ReleaseBuffer();//�ͷŻ�����
	             m_edt_cs+=L".";//ÿ����������β������һ��С����
                 UpdateData(false);
	         }
	}
	
	
}

void CTESTDlg::OnBnClickedButtonzfh()//�����Ű�ť��ִ�д���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
   const TCHAR * temp=m_edt_cs.GetBuffer();
	if(temp[0]=='-')//�ж���������Ƿ��Ѿ������м���
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



void CTESTDlg::OnBnClickedButtonCe()//ֻ�ǰѵ�ǰ�����Ĵ�����Ϊ0��������ֵ���䡣
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
     m_edt_cs=L"0.";
	 UpdateData(false);
	 LastPressOperater=1;
}

void CTESTDlg::OnBnClickedButtonC()// ȫ����Ϊ0
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedButtonCe();
    m_nPlanNum=0;
	m_nowNum=0;
    LastPressOperater=1;
    m_nPreOperator=0;
}

// //ʵ�ּӼ��˳������㴦����
int  CTESTDlg::plan(int nNowOperator)
{
	bool judge=1;
	if(LastPressOperater){m_nPreOperator=nNowOperator; return 1;} //�����һ������Ҳ��������ţ��Ͱ��µ�������Ÿ��µ��ɵ������������ȥ�����˳�����
	m_nowNum=_wtof(m_edt_cs);//��Ϣ����Ŀǰ��ֵ���ִ�ת����һ��˫���ȵ����� ��ע:_wtoi()��ʾת�������Σ�_wtof()��ʾת����˫���ȣ�
	switch(m_nPreOperator)
	       {
	          case 0:       m_nPlanNum=m_nowNum;      break;//������
	          case 1:       m_nPlanNum+=m_nowNum;     break;//�Ӻ�
	          case 2:       m_nPlanNum-=m_nowNum;     break;//����
	          case 3:       m_nPlanNum*=m_nowNum;     break;//�˺�
			  case 4:       if(m_nowNum==0){judge=0;}else{m_nPlanNum/=m_nowNum;}     break;//����
			  
	       }
	      if(judge==0)
		  {m_nPlanNum=0;
			m_nPreOperator=nNowOperator;//���������������Ϣд����һ�������������Ϣ��ȥ
		   LastPressOperater=1;
		   m_edt_cs.Format(L"��������Ϊ�㣡");//�൱��printf,���ֵ���ִ���ȥ
		   UpdateData(false);
		   return 0;}
		  else{
		   m_nPreOperator=nNowOperator;//���������������Ϣд����һ�������������Ϣ��ȥ
		   LastPressOperater=1;
		   m_edt_cs.Format(L"%g",m_nPlanNum);//�൱��printf,���ֵ���ִ���ȥ
		   UpdateData(false);
		   return 0;}
	    
}

void CTESTDlg::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(outvaule){plan(0);m_nPreOperator=1;outvaule=0;}
	plan(1);
}



void CTESTDlg::OnBnClickedButtonOut()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	plan(m_nPreOperator);
	outvaule=1;
	//���µ��ںž��൱��ȫ�尴ťC����������Ľ����Ӧ�ñ��ı䡣
	
}

void CTESTDlg::OnBnClickedButtonMinus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(outvaule){plan(0);m_nPreOperator=2;outvaule=0;}
	plan(2);
}

void CTESTDlg::OnBnClickedButtonRide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(outvaule){plan(0);m_nPreOperator=3;outvaule=0;}
	plan(3);
}

void CTESTDlg::OnBnClickedButtonRid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(outvaule){plan(0);m_nPreOperator=4;outvaule=0;}
	plan(4);
}

// ��ʾ������0-9�е�ĳ����
int CTESTDlg::PressNum(int nNum)
{
if(outvaule){m_nPlanNum=0;m_nowNum=0;LastPressOperater=1;m_nPreOperator=0;}
	CString tp;
	tp.Format(L"%d",nNum);//���������Ĳ�����ʽ����һ���ִ�
    if(LastPressOperater){m_edt_cs=tp;}//�����һ�����µļ��������������Ϣ���е�ֱֵ�ӱ���ɴ����ֵת���ɵ��ִ�
	else{m_edt_cs+=tp;}//�����һ�����µļ����������������Ϣ���β������һ���ɴ����ֵת���ɵ��ִ�
	LastPressOperater=0;//��ʶ��һ�����µļ������������
	UpdateData(false);
	return 0;
}

void CTESTDlg::OnBnClickedButtonbfh() //%����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	double ts;
	ts=_wtof(m_edt_cs);
	LastPressOperater=1;
	ts=ts/100;
	m_edt_cs.Format(L"%g",ts);
	UpdateData(false);
}

void CTESTDlg::OnBnClickedButtonds() //��������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	double ts;
	ts=_wtof(m_edt_cs);
	LastPressOperater=1;
	if(ts==0){m_edt_cs.Format(L"��ĸ����Ϊ�㣡");}
	else{ts=1/ts;m_edt_cs.Format(L"%g",ts);}
	UpdateData(false);

}


void CTESTDlg::OnBnClickedButtonsqrt() //��������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	double ts;
	ts=_wtof(m_edt_cs);
	LastPressOperater=1;
	ts=sqrt(ts);m_edt_cs.Format(L"%g",ts);
	UpdateData(false);
}


void CTESTDlg::OnBnClickedButtonMc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	memory=0;
	CString str; str.Format(L"");
	SetDlgItemText( IDC_STATIC, str);

}

void CTESTDlg::OnBnClickedButtonMr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edt_cs.Format(L"%g",memory);
	UpdateData(false);

}

void CTESTDlg::OnBnClickedButtonMs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	memory=_wtof(m_edt_cs);
	CString str; str.Format(L"M");
	SetDlgItemText( IDC_STATIC, str);
}



void CTESTDlg::OnBnClickedButtonMadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	double ts;
	ts=_wtof(m_edt_cs);
	ts=ts+memory;
	m_edt_cs.Format(L"%g",ts);
	UpdateData(false);

}
 CAboutDlg about;
void CTESTDlg::menu_about()
{
	// TODO: �ڴ���������������
	if(about.m_hWnd==0)//������ڵľ��Ϊ�㣬��û�д���
	{
		about.Create(IDD_ABOUTBOX,this);//����һ�δ��ڵľ��
	}
	about.ShowWindow(SW_SHOW);//��ʾ����
}




void CTESTDlg::menu_copy()
{
	// TODO: �ڴ���������������

    //�����ַ���ת��

	//char cs[256]="";
	//USES_CONVERSION;
	//strcpy(cs,W2A(m_edt_cs.GetBuffer()));
	//HGLOBAL hmem=NULL;
	//if(OpenClipboard())//�Ƿ�ɹ����˼��а�
	//{
	//	if(EmptyClipboard())//��ռ��а壬�ɹ������
	//	{
	//		hmem=GlobalAlloc(GHND,sizeof(cs));//�����ڴ�
	//	    char* pmem=(char*)GlobalLock(hmem);//�����ڴ�
	//		memcpy(pmem,cs,sizeof(cs));
	//		SetClipboardData(CF_TEXT,hmem);//����а�Ļ���ؼ��и�ֵ
	//		CloseClipboard();//�رռ��а��߳�
	//		GlobalUnlock(pmem);//����ڴ�(����ڴ�������
	//	}

	//}

	//�������ַ���ת��
	HGLOBAL hmem=NULL;
	if(OpenClipboard())//�Ƿ�ɹ����˼��а�
	{
		if(EmptyClipboard())//��ռ��а壬�ɹ������
		{
			hmem=GlobalAlloc(GHND,(m_edt_cs.GetLength()+1)*2);//�����ڴ�
		    wchar_t* pmem=(WCHAR*)GlobalLock(hmem);//�����ڴ�
			memcpy(pmem,m_edt_cs.GetBuffer(),(m_edt_cs.GetLength()+1)*2);
			SetClipboardData(CF_UNICODETEXT ,hmem);//����а�Ļ���ؼ��и�ֵ
			CloseClipboard();//�رռ��а��߳�
			GlobalUnlock(pmem);//����ڴ�(����ڴ�������
		}

	}
}

void CTESTDlg::menu_paste()
{
	// TODO: �ڴ���������������
	
	// ���ַ��������

	////�����ڴ��ŵ�λ�ã��Լ���ŵ����ͣ����ڴ�Ĵ�С
	HGLOBAL hmem=NULL;
	char s[256]="";
	if(IsClipboardFormatAvailable(CF_TEXT))//CF_UNICODETEXT  �жϼ��а�ճ�������ݸ�ʽ�Ƿ�����������Ҫ��
	{
		//�򿪼��а�
		if(OpenClipboard())
		{
			//�õ����а�ľ��
			hmem=GetClipboardData(CF_TEXT);
			if(hmem)
			{
				//����ȫ���ڴ��û�������ָ��
				char* ps=(char*)GlobalLock(hmem);
				memcpy(s,ps,GlobalSize(hmem));
			}
		}
		//�رռ��а壬��ʹ����������Ҳ���Է��ʣ������ͷ��ڴ���
	CloseClipboard();
	GlobalUnlock(hmem);
	m_edt_cs=s;
	UpdateData(false);
	}
	
	//���ַ��������
if(IsClipboardFormatAvailable(CF_UNICODETEXT))//CF_UNICODETEXT  �жϼ��а�ճ�������ݸ�ʽ�Ƿ�����������Ҫ��
	{
		HGLOBAL hmem=NULL;
		//�򿪼��а�
		if(OpenClipboard())
		{
			//�õ����а�ľ��
			hmem=GetClipboardData(CF_UNICODETEXT);
			if(hmem)
			{
				//����ȫ���ڴ��û�������ָ��
				LPTSTR ps=(WCHAR*)GlobalLock(hmem);
				m_edt_cs=ps;
			}
		}
		//�رռ��а壬��ʹ����������Ҳ���Է��ʣ������ͷ��ڴ���
	CloseClipboard();
	GlobalUnlock(hmem);
	
	UpdateData(false);
	}
}

void CTESTDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���������������
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
	WCHAR c=ts[nselStart-1];//��ȡ�����������ַ�
	  //�ж� �����֣�����С�����������
	if (c>='0'&&c<='9' ||c=='.')
	{
		if (c=='.')
		{
			//�ж��ִ����С����ĸ��� ����Ϊ1 ����1
			for (unsigned int i=0;i<=wcslen(ts);i++)
			{
				if (ts[i]=='.')
				{
					num++;
				}
			}
			if (num>1)
			{
				//m_edt_cs��������������
				UpdateData(false);
				m_edt1_ct1.SetSel(nselStart-1,nselStart-1);
				return;
			}
         
		}
		UpdateData(true);//���´�������������
	}else
	{   //����ĸ��С����
		//m_edt_cs��������������
		UpdateData(false);
		m_edt1_ct1.SetSel(nselStart-1,nselStart-1);
	}

}
