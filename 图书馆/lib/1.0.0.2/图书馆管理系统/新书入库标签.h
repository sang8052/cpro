#pragma once


// ��������ǩ �Ի���

class ��������ǩ : public CDialog
{
	DECLARE_DYNAMIC(��������ǩ)

public:
	��������ǩ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~��������ǩ();

// �Ի�������
	enum { IDD = IDD_FUN_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	virtual BOOL OnInitDialog();
};
