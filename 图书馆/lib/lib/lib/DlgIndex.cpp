// DlgIndex.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lib.h"
#include "DlgIndex.h"


// CDlgIndex �Ի���
CDlgIndex::CDlgIndex(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgIndex::IDD, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CDlgIndex::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CDlgIndex, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	
	
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CDlgIndex::OnBnClickedButtonExit)
	
END_MESSAGE_MAP()


// CDlgIndex ��Ϣ�������

BOOL CDlgIndex::OnInitDialog()
{
	CDialog::OnInitDialog();
    
    // TODO: �ڴ���Ӷ���ĳ�ʼ������
	login.Create(IDD_LIB_DIALOG,this);
	login.ShowWindow(SW_SHOW);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDlgIndex::OnPaint()
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
HCURSOR CDlgIndex::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDlgIndex::OnBnClickedButtonExit()
{
	exit(0);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

