// ��¼����.h : ͷ�ļ�
#pragma once
#include <string>    //c++ string�ַ�������ʹ�õ�ͷ�ļ�
using namespace std; //���������ռ�
#include "mysql.h"   //Mysql���ݿ��ͷ�ļ�
#include "winsock.h" //Windows�������̵Ĺ淶������Windows�µõ��㷺Ӧ�õġ����ŵġ�֧�ֶ���Э��������̽ӿ�
#include <shlwapi.h> //Windows�����ļ�·����ͷ�ļ�
#include <fstream>   //fstream��C++ STL�ж��ļ������ĺϼ��������˳��õ������ļ�������
#include "md5.h"     //����ִ��md5���ܵ�ͷ�ļ�
#include "������.h"

#pragma comment(lib,"libmysql.lib")  //����֧��mysql�ľ�̬���ӿ�
#pragma comment(lib, "Version.lib ") //��ȡ�汾��Ϣʱ��ʹ�õľ�̬���ӿ�

// ��¼���� �Ի���
class ��¼���� : public CDialog
{
// ����
public:
	��¼����(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOGIN };

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
	
	afx_msg void OnBnClickedButtonCancel();
	// ������¼�û�����CString �ַ���
	CString Username;
	// ������¼�����CString �ַ���
	CString Password;
	CString SQL;  //��������mysql�Ĳ������
	
	char* sql;
	MYSQL *conn; //mysql���ݿ�����Ӿ��
	MYSQL_RES *res;   //mysql���ݿ�Ľ����
	MYSQL_ROW row;   //mysql���ݿ�ķ��ص�����
    CString strVERSION; //������¼��ǰ����汾

	// ���ݿ��������ӵĺ���
	void SQL_connect(void);
	afx_msg void OnBnClickedButtonLogin();
	// ��һ��CString���ַ���ת����char*���͵��ַ���
	// ��ʼ������
	void Getready(void);
	// CString ��SQL ת���� char* sql
	void SQLtosql(void);
	
	// ��ñ�������ip��ַ
	void Getip(void);
	//���ػس���Ϣ
	BOOL  PreTranslateMessage(MSG*   pMsg) ;
};
