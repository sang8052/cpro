// ������.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "������.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif





// ������ �Ի���




������::������(CWnd* pParent /*=NULL*/)
	: CDialog(������::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void ������::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(������, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &������::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()


// C������ ��Ϣ�������

BOOL ������::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	 //ʵ�������б�ǩ����
	
    Getready();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}



// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void ������::OnPaint()
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
HCURSOR ������::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// �Զ���ĳ�ʼ������
void ������::Getready(void)
{
	//��ȡѡ��ؼ���ָ��
	CTabCtrl *Ptab=(CTabCtrl*)GetDlgItem(IDC_TAB_MAIN);
	Ptab->InsertItem(1,"����/����");
	Ptab->InsertItem(2,"ͼ���ѯ");
	Ptab->InsertItem(3,"�������");
	Ptab->InsertItem(4,"�ҽ����");
    Ptab->InsertItem(5,"����");
	//�������б�ǩ
	DlgAbout.Create(IDD_FUN_ABOUT);
	DlgLeTurn.Create(IDD_FUN_LETURN);
	DlgSelect.Create(IDD_FUN_SELECT);
	DlgMyLend.Create(IDD_FUN_MYLEND);
	DlgAdd.Create(IDD_FUN_ADD);
	//���ñ�ǩ�ĸ�����
	DlgAbout.SetParent(Ptab);
	DlgLeTurn.SetParent(Ptab);
    DlgSelect.SetParent(Ptab);
	DlgMyLend.SetParent(Ptab);
	DlgAdd.SetParent(Ptab);
	//����Ĭ����ʾ�Ǹ���ǩҳ��
	 DlgLeTurn.ShowWindow(SW_SHOW);
	
}

//����ѡ���ʱ����õĺ���
void ������::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTabCtrl *Ptab=(CTabCtrl*)GetDlgItem(IDC_TAB_MAIN);
	int Tabsel=Ptab->GetCurSel();//����һ�����α�������ȡĿǰ��ѡ�
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

BOOL   ������::PreTranslateMessage(MSG*   pMsg)    
  {  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_ESCAPE)     return   TRUE;  
    if(pMsg->message==WM_KEYDOWN   &&   pMsg->wParam==VK_RETURN)   return  	TRUE;    
    else    
          return   CDialog::PreTranslateMessage(pMsg);  
  }
