#pragma once
#include "DlgLogin.h"

// CDlgIndex �Ի���

class CDlgIndex : public CDialog
{
	public:
	CDlgIndex(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DIALOG_INDEX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CDlgLogin login;

	afx_msg void OnBnClickedButtonExit();
	
};
