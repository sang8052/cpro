#pragma once
#include "SetMessage.h"
#include "ReturnBook.h"//����
#include "LendBook.h"//����
// DIALOG1 �Ի���

class DIALOG1 : public CDialog
{
	DECLARE_DYNAMIC(DIALOG1)
friend class ClibDlg;

public:
	DIALOG1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DIALOG1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMile_tebeimingxie();
	afx_msg void Ontitlebar_guanyutext();
	afx_msg void Onexit();
	
	afx_msg void OnOpenSMWin();
	afx_msg void OnSearchBook();
	afx_msg void On32774();
};
