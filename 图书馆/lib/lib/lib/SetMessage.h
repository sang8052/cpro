#pragma once
#include "DIALOG1.h"

// SetMessage �Ի���

class SetMessage : public CDialog
{
	DECLARE_DYNAMIC(SetMessage)

public:
	SetMessage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SetMessage();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnOpenSMWin();
};
