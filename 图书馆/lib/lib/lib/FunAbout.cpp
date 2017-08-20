// FUNABOUT.cpp : 实现文件
//

#include "stdafx.h"
#include "lib.h"
#include "FunAbout.h"


// FUNABOUT 对话框

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


// FUNABOUT 消息处理程序

void FunAbout::GetVersion(void)
{
	char cPath[200];
 DWORD dwHandle,InfoSize;
 ::GetModuleFileName(NULL,cPath,sizeof(cPath)); //首先获得版本信息资源的长度
 InfoSize = GetFileVersionInfoSize(cPath,&dwHandle); //将版本信息资源读入缓冲区

 char *InfoBuf = new char[InfoSize];
 GetFileVersionInfo(cPath,0,InfoSize,InfoBuf); //获得生成文件使用的代码页及文件版本
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
