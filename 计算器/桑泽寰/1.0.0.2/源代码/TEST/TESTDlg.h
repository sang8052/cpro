// TESTDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <math.h>
#pragma comment(lib, "Version.lib ")

// CTESTDlg �Ի���
class CTESTDlg : public CDialog
{
// ����
public:
	CTESTDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nPreOperator; // ����ϴΰ��µ�һ��������ŵ�ֵ +��-*��/ �ֱ�1�� 2�� 3�� 4
	bool LastPressOperater;//������һ�ΰ��µ������������Ϊ1
	double m_nPlanNum;//���ڼ�¼����ֵ���ۼ�
	double m_nowNum;//���ڼ�¼Ŀǰ������е����µ�ֵ
	afx_msg void OnBnClickedOk();
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_edt_cs;
	CEdit m_edt1_ct1;
	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum0();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	afx_msg void OnBnClickedButtonbackspace();
	afx_msg void OnBnClickedButtonpoint();
	afx_msg void OnBnClickedButtonzfh();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonC();
	int plan(int nNowOperator);// //ʵ�ּӼ��˳������㴦����
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonOut();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonRide();
	afx_msg void OnBnClickedButtonRid();
	// ��ʾ������0-9�е�ĳ����
	int PressNum(int nNum);
	
	
	afx_msg void OnBnClickedButtonbfh();
	afx_msg void OnBnClickedButtonds();
	afx_msg void OnBnClickedButtonsqrt();
	double memory;
	
	afx_msg void OnBnClickedButtonMc();
	afx_msg void OnBnClickedButtonMr();
	afx_msg void OnBnClickedButtonMs();
	afx_msg void OnBnClickedButtonMadd();
	afx_msg void menu_about();

	afx_msg void menu_copy();
	afx_msg void menu_paste();
	// �ж��Ƿ񼤻��˵��ں�
	bool outvaule;
	afx_msg void OnEnChangeEdit1();
};
