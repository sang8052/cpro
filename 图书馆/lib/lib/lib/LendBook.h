#pragma once


// LendBook �Ի���

class LendBook : public CDialog
{
	DECLARE_DYNAMIC(LendBook)

public:
	LendBook(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LendBook();

// �Ի�������
	enum { IDD = IDD_LendBook };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLendBook();
	afx_msg void OnSearchBook();
};
