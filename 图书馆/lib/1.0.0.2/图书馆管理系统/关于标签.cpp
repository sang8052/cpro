// ���ڱ�ǩ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ͼ��ݹ���ϵͳ.h"
#include "���ڱ�ǩ.h"


// ���ڱ�ǩ �Ի���

IMPLEMENT_DYNAMIC(���ڱ�ǩ, CDialog)

���ڱ�ǩ::���ڱ�ǩ(CWnd* pParent /*=NULL*/)
	: CDialog(���ڱ�ǩ::IDD, pParent)
	, strVERSION(_T(""))
{

}

���ڱ�ǩ::~���ڱ�ǩ()
{
}

void ���ڱ�ǩ::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_STATIC_ABOUTURL, AboutUrl);
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_STATIC_VER, strVERSION);
	DDX_Control(pDX, IDC_EXPLORER_ABOUT, Explorer_About);
}


BEGIN_MESSAGE_MAP(���ڱ�ǩ, CDialog)
	ON_STN_CLICKED(IDC_STATIC_ABOUTURL, &���ڱ�ǩ::OnStnClickedStaticAbouturl)
END_MESSAGE_MAP()

BOOL ���ڱ�ǩ::OnInitDialog()
{
	CDialog::OnInitDialog();


	
    //��ð汾��Ϣ����ʾ
	char cPath[200];
    DWORD dwHandle,InfoSize;
    ::GetModuleFileName(NULL,cPath,sizeof(cPath)); //���Ȼ�ð汾��Ϣ��Դ�ĳ���
    InfoSize = GetFileVersionInfoSize(cPath,&dwHandle); //���汾��Ϣ��Դ���뻺����
	char *InfoBuf = new char[InfoSize];
	GetFileVersionInfo(cPath,0,InfoSize,InfoBuf); //��������ļ�ʹ�õĴ���ҳ���ļ��汾
	unsigned int  cbTranslate = 0;
	struct LANGANDCODEPAGE {WORD wLanguage; WORD wCodePage; } *lpTranslate;
	VerQueryValue(InfoBuf, TEXT("\\VarFileInfo\\Translation"),(LPVOID*)&lpTranslate,&cbTranslate);
	for(unsigned int i=0; i < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); i++ )
	{char SubBlock[200];wsprintf( SubBlock,TEXT("\\StringFileInfo\\%04x%04x\\FileVersion"),lpTranslate[i].wLanguage,lpTranslate[i].wCodePage);
	void *lpBuffer=NULL;unsigned int dwBytes=0;VerQueryValue(InfoBuf,SubBlock,&lpBuffer,&dwBytes);
	CString strTemp=( char *)lpBuffer;strVERSION=strTemp;UpdateData(false);}
	delete InfoBuf; 
    Explorer_About.Navigate("mysscloud.xyz/show/thanks.php",NULL,NULL,NULL,NULL);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}




// ��¼���� ��Ϣ�������



// ������ĳ�ʼ������


void ���ڱ�ǩ::OnStnClickedStaticAbouturl() //�����ַ�ĺ���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "http://www.wt-dk.cn/wordpress/cpro/", NULL, NULL, SW_SHOWNORMAL); //����DOS��������������ҳ��
}
BEGIN_EVENTSINK_MAP(���ڱ�ǩ, CDialog)
	ON_EVENT(���ڱ�ǩ, IDC_EXPLORER_ABOUT, 259, ���ڱ�ǩ::DocumentCompleteExplorerAbout, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

void ���ڱ�ǩ::DocumentCompleteExplorerAbout(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO: �ڴ˴������Ϣ����������
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
        pBodyE2->put_scroll(L"no");//ȥ������  
    }    
    IHTMLStyle   *phtmlStyle2;    
    pE2->get_style(&phtmlStyle2);    
   
    if(phtmlStyle2 != NULL)    
    {    
        phtmlStyle2->put_overflow(L"hidden");    
        phtmlStyle2->put_border(L"none");//   ȥ���߿�       
        phtmlStyle2->Release();    
        pE2->Release();    
    }    
}
}
