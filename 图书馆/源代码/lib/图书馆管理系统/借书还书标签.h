#pragma once
#include "explorer.h"
#include "Mshtml.h"     //���������������ҳ���д����ͷ�ļ�
#include "mysql.h"   //Mysql���ݿ��ͷ�ļ�
#include "winsock.h" //Windows�������̵Ĺ淶������Windows�µõ��㷺Ӧ�õġ����ŵġ�֧�ֶ���Э��������̽ӿ�
#include "md5.h"
#pragma comment(lib,"libmysql.lib")  //����֧��mysql�ľ�̬���ӿ�

// ���黹���ǩ �Ի���

class ���黹���ǩ : public CDialog
{
	DECLARE_DYNAMIC(���黹���ǩ)

public:
	���黹���ǩ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~���黹���ǩ();

// �Ի�������
	enum { IDD = IDD_FUN_LETURN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
    virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
public:
	// ������ĳ�ʼ������
	
	CString EDIT_BOOKNUM;
	CString EDIT_BOOKNAME;
	CString EDIT_WRITTER;
	CString EDIT_STATE;
	int bookstate;
	
    CString Username;
	CString LoginTime;
	CString LimitTime;
	CString SQL;  //��������mysql�Ĳ������
	char* sql;
	MYSQL *conn; //mysql���ݿ�����Ӿ��
	MYSQL_RES *res;   //mysql���ݿ�Ľ����
	MYSQL_ROW row;   //mysql���ݿ�ķ��ص�����
    CString strVERSION; //������¼��ǰ����汾
	void SQL_server(void);
	void SQLtosql(void);
	
	CExplorer PIC_QR;
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorerQr(LPDISPATCH pDisp, VARIANT* URL);
	afx_msg void OnBnClickedButtonRefalsh();
	afx_msg void OnBnClickedButtonSelect();
	afx_msg void OnBnClickedButtonLend();
	afx_msg void OnBnClickedButtonReturn();
    
   //���ػس���Ϣ
	BOOL  PreTranslateMessage(MSG*   pMsg) ;
	
};


