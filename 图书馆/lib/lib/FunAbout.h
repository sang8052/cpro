#pragma once


// FunAbout �Ի���

class FunAbout : public CDialog
{
	DECLARE_DYNAMIC(FunAbout)

public:
	FunAbout(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FunAbout();

// �Ի�������
	enum { IDD = IDD_FUN_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString strVERSION;
	void GetVersion(void);
	
};
