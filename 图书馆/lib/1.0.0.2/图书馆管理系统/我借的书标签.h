#pragma once


// �ҽ�����ǩ �Ի���

class �ҽ�����ǩ : public CDialog
{
	DECLARE_DYNAMIC(�ҽ�����ǩ)

public:
	�ҽ�����ǩ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~�ҽ�����ǩ();

// �Ի�������
	enum { IDD = IDD_FUN_MYLEND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	virtual BOOL OnInitDialog();
};
