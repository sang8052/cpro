#pragma once


// �޸�ͼ����Ϣ���� �Ի���

class �޸�ͼ����Ϣ���� : public CDialog
{
	DECLARE_DYNAMIC(�޸�ͼ����Ϣ����)

public:
	�޸�ͼ����Ϣ����(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~�޸�ͼ����Ϣ����();

// �Ի�������
	enum { IDD = IDD_FUN_RESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	virtual BOOL OnInitDialog();
};
