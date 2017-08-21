// 关于标签.cpp : 实现文件
//

#include "stdafx.h"
#include "图书馆管理系统.h"
#include "关于标签.h"


// 关于标签 对话框

IMPLEMENT_DYNAMIC(关于标签, CDialog)

关于标签::关于标签(CWnd* pParent /*=NULL*/)
	: CDialog(关于标签::IDD, pParent)
	, strVERSION(_T(""))
{

}

关于标签::~关于标签()
{
}

void 关于标签::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_STATIC_ABOUTURL, AboutUrl);
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_STATIC_VER, strVERSION);
	DDX_Control(pDX, IDC_EXPLORER_ABOUT, Explorer_About);
}


BEGIN_MESSAGE_MAP(关于标签, CDialog)
	ON_STN_CLICKED(IDC_STATIC_ABOUTURL, &关于标签::OnStnClickedStaticAbouturl)
END_MESSAGE_MAP()

BOOL 关于标签::OnInitDialog()
{
	CDialog::OnInitDialog();


	
    //获得版本信息并显示
	char cPath[200];
    DWORD dwHandle,InfoSize;
    ::GetModuleFileName(NULL,cPath,sizeof(cPath)); //首先获得版本信息资源的长度
    InfoSize = GetFileVersionInfoSize(cPath,&dwHandle); //将版本信息资源读入缓冲区
	char *InfoBuf = new char[InfoSize];
	GetFileVersionInfo(cPath,0,InfoSize,InfoBuf); //获得生成文件使用的代码页及文件版本
	unsigned int  cbTranslate = 0;
	struct LANGANDCODEPAGE {WORD wLanguage; WORD wCodePage; } *lpTranslate;
	VerQueryValue(InfoBuf, TEXT("\\VarFileInfo\\Translation"),(LPVOID*)&lpTranslate,&cbTranslate);
	for(unsigned int i=0; i < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); i++ )
	{char SubBlock[200];wsprintf( SubBlock,TEXT("\\StringFileInfo\\%04x%04x\\FileVersion"),lpTranslate[i].wLanguage,lpTranslate[i].wCodePage);
	void *lpBuffer=NULL;unsigned int dwBytes=0;VerQueryValue(InfoBuf,SubBlock,&lpBuffer,&dwBytes);
	CString strTemp=( char *)lpBuffer;strVERSION=strTemp;UpdateData(false);}
	delete InfoBuf; 
    Explorer_About.Navigate("mysscloud.xyz/show/thanks.php",NULL,NULL,NULL,NULL);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}




// 登录窗口 消息处理程序



// 重载类的初始化函数


void 关于标签::OnStnClickedStaticAbouturl() //点击网址的函数
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, "open", "http://www.wt-dk.cn/wordpress/cpro/", NULL, NULL, SW_SHOWNORMAL); //调用DOS命令打开浏览器访问页面
}
BEGIN_EVENTSINK_MAP(关于标签, CDialog)
	ON_EVENT(关于标签, IDC_EXPLORER_ABOUT, 259, 关于标签::DocumentCompleteExplorerAbout, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

void 关于标签::DocumentCompleteExplorerAbout(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO: 在此处添加消息处理程序代码
		HRESULT hr;  
pDisp = this->Explorer_About.get_Document();              
IHTMLDocument2 *pDocument1 = NULL;  
IHTMLElement*   pE2;    
IHTMLBodyElement * pBodyE2;    
hr = pDisp->QueryInterface(IID_IHTMLDocument2, (void**)&pDocument1);  
if(SUCCEEDED(pDocument1->get_body(&pE2)))    
{    
    if(SUCCEEDED(pE2->QueryInterface(IID_IHTMLBodyElement,   (void**)&pBodyE2)))    
    {    
        pBodyE2->put_scroll(L"no");//去滚动条  
    }    
    IHTMLStyle   *phtmlStyle2;    
    pE2->get_style(&phtmlStyle2);    
   
    if(phtmlStyle2 != NULL)    
    {    
        phtmlStyle2->put_overflow(L"hidden");    
        phtmlStyle2->put_border(L"none");//   去除边框       
        phtmlStyle2->Release();    
        pE2->Release();    
    }    
}
}
