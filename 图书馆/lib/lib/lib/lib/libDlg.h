// libDlg.h : ͷ�ļ�
//

#pragma once
#include  <string>
using namespace std;
#include <atlconv.h>
#include "afxwin.h"
#include  <afxinet.h>
#include <WinSock.h>  //win��ز���ͷ�ļ�
#include "mysql.h"    //����mysqlͷ�ļ���������Ŀ�������ԡ���c/c++���������������ú�·��
#include "md5.h"
#include <iostream>
#include <UrlMon.h>
#include <afxconv.h>
#include <shlwapi.h>
#include "DIALOG1.h"
#include "SetMessage.h"

#pragma comment(lib, "Version.lib ")
#pragma comment(lib,"wsock32.lib")//win��ز������׽ӿ�
#pragma comment(lib,"libmysql.lib") //����mysqlͷ�ļ���������Ŀ�������ԡ������������������������ú�·��
#pragma comment(lib,"urlmon.lib")
// ClibDlg �Ի���
class ClibDlg : public CDialog 
{
public:
	ClibDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LIB_DIALOG };

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	// �û���
	CString username;
	// ��¼����
	CString password;
	
  CString SQL;//ִ��SQL�����ֶ�
  MYSQL * conn;  
  MYSQL_RES *res;
  MYSQL_ROW row; 
	
  int Server_connect(void);
  
  
  bool downloadfile(CString *strFileURLInServer, CString *strFileLocalFullPath);
  CString strVERSION;
  afx_msg void Ontip();
  afx_msg void OnSetMessageWindow();
};

