// ������.h : ͷ�ļ�
//

#pragma once
#include "���黹���ǩ.h"
#include "ͼ���ѯ��ǩ.h"
#include "��������ǩ.h"
#include "�ҽ�����ǩ.h"
#include "���ڱ�ǩ.h"




// ������ �Ի���
class ������ : public CDialog
{
// ����
public:
	������(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_INDEX };

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
	���ڱ�ǩ DlgAbout;
    ���黹���ǩ DlgLeTurn;
    ͼ���ѯ��ǩ DlgSelect;
    �ҽ�����ǩ DlgMyLend;
    ��������ǩ DlgAdd;
   
    // �Զ���ĳ�ʼ������
	void Getready(void);
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	//���ػس���Ϣ
	BOOL  PreTranslateMessage(MSG*   pMsg) ;
};
