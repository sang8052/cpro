#pragma once


// ReturnBook �Ի���

class ReturnBook : public CDialog
{
	DECLARE_DYNAMIC(ReturnBook)

public:
	ReturnBook(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ReturnBook();

// �Ի�������
	enum { IDD = IDD_ReturnBook };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
