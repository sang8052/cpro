#pragma once
#include "mysql.h"
#include <WinSock.h> 
#include "md5.h"
#include "explorer_qr.h"
#include "Mshtml.h" 
#include "FunThank.h"
#include "FunAbout.h"

#pragma comment(lib,"libmysql.lib") 

// FunIndex �Ի���

class FunIndex : public CDialog
{
	DECLARE_DYNAMIC(FunIndex)

public:
	FunIndex(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FunIndex();

// �Ի�������
	enum { IDD = IDD_FUN_INDEX };

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString SQL;
	CString username;
	CString LoginTime;
	CString LimitTime;
	char* TempSql;
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
    //ʵ�������������

	FunThank DlgThank;
	FunAbout DlgAbout;

	// �������ݿ������
    int Server_Connect(void);
	void SetData(CString,CString,CString);
	CExplorer_qr Url_Qr;

	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorerQr(LPDISPATCH pDisp, VARIANT* URL);
	// //��ѯ�༭���Csting���ͱ���
	CString Messagein;
	// //�����������
	CString Messageout01;
	// //�������ͼ��״̬
	CString Messageout02;
	afx_msg void OnBnClickedButton3search();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1lend();
	afx_msg void OnBnClickedButton2return();
	afx_msg void Menu_About();
	afx_msg void Menu_Thanks();
	afx_msg void Menu_Select();
	afx_msg void Menu_MyLend();
	afx_msg void Menu_AddTbook();
	afx_msg void Menu_AddNbook();
	virtual BOOL PreTranslateMessage(MSG *);
	afx_msg void OnBnClickedButton4reflash();
	
};
