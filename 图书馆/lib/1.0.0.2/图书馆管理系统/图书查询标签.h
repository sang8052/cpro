#pragma once


// ͼ���ѯ��ǩ �Ի���

class ͼ���ѯ��ǩ : public CDialog
{
	DECLARE_DYNAMIC(ͼ���ѯ��ǩ)

public:
	ͼ���ѯ��ǩ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ͼ���ѯ��ǩ();

// �Ի�������
	enum { IDD = IDD_FUN_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	virtual BOOL OnInitDialog();
};
