// FUNABOUT.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lib.h"
#include "FunAbout.h"


// FUNABOUT �Ի���

IMPLEMENT_DYNAMIC(FunAbout, CDialog)

FunAbout::FunAbout(CWnd* pParent /*=NULL*/)
	: CDialog(FunAbout::IDD, pParent)
	, strVERSION(_T(""))
{

}

FunAbout::~FunAbout()
{
}

void FunAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_ver, strVERSION);
}


BEGIN_MESSAGE_MAP(FunAbout, CDialog)
END_MESSAGE_MAP()


// FUNABOUT ��Ϣ�������

void FunAbout::GetVersion(void)
{
	char cPath[200];
 DWORD dwHandle,InfoSize;
 ::GetModuleFileName(NULL,cPath,sizeof(cPath)); //���Ȼ�ð汾��Ϣ��Դ�ĳ���
 InfoSize = GetFileVersionInfoSize(cPath,&dwHandle); //���汾��Ϣ��Դ���뻺����

 char *InfoBuf = new char[InfoSize];
 GetFileVersionInfo(cPath,0,InfoSize,InfoBuf); //��������ļ�ʹ�õĴ���ҳ���ļ��汾
 unsigned int  cbTranslate = 0;
 struct LANGANDCODEPAGE {WORD wLanguage; WORD wCodePage; } *lpTranslate;
 VerQueryValue(InfoBuf, TEXT("\\VarFileInfo\\Translation"),(LPVOID*)&lpTranslate,&cbTranslate);
 // Read the file description for each language and code page.
 for(unsigned int i=0; i < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); i++ )
 { char SubBlock[200];wsprintf( SubBlock,TEXT("\\StringFileInfo\\%04x%04x\\FileVersion"),lpTranslate[i].wLanguage,lpTranslate[i].wCodePage);
  void *lpBuffer=NULL;unsigned int dwBytes=0;VerQueryValue(InfoBuf,SubBlock,&lpBuffer,&dwBytes);
  CString strTemp=( char *)lpBuffer;
  strVERSION=strTemp;UpdateData(false);}
  delete InfoBuf;
}
