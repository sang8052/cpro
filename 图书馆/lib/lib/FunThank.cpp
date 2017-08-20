// Fun_Thank.cpp : 实现文件
//

#include "stdafx.h"
#include "lib.h"
#include "FunThank.h"


// Fun_Thank 对话框

IMPLEMENT_DYNAMIC(FunThank, CDialog)

FunThank::FunThank(CWnd* pParent /*=NULL*/)
	: CDialog(FunThank::IDD, pParent)
{
    

}

FunThank::~FunThank()
{
}

void FunThank::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER_thank, Ex_Thanks);
}


BEGIN_MESSAGE_MAP(FunThank, CDialog)
END_MESSAGE_MAP()


// Fun_Thank 消息处理程序

void FunThank::SetData(void)
{
	CString Ex_Thanks_string;
	Ex_Thanks_string.Format("http://mysscloud.xyz/show/thanks.php");
	Ex_Thanks.Navigate(Ex_Thanks_string,NULL,NULL,NULL,NULL);
}
BEGIN_EVENTSINK_MAP(FunThank, CDialog)
	ON_EVENT(FunThank, IDC_EXPLORER_thank, 259, FunThank::DocumentCompleteExplorerthank, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

void FunThank::DocumentCompleteExplorerthank(LPDISPATCH pDisp, VARIANT* URL)
	{
		// TODO: 在此处添加消息处理程序代码
		HRESULT hr;  
	pDisp = this->Ex_Thanks.get_Document();              
	IHTMLDocument2 *pDocument = NULL;  
	IHTMLElement*   pEl;    
	IHTMLBodyElement * pBodyEl;    
	hr = pDisp->QueryInterface(IID_IHTMLDocument2, (void**)&pDocument);  
	if(SUCCEEDED(pDocument->get_body(&pEl)))    
	{    
	    if(SUCCEEDED(pEl->QueryInterface(IID_IHTMLBodyElement,   (void**)&pBodyEl)))    
	    {    
	        pBodyEl->put_scroll(L"no");//去滚动条  
	    }    
	    IHTMLStyle   *phtmlStyle;    
	    pEl->get_style(&phtmlStyle);    
	   
	    if(phtmlStyle  != NULL)    
	    {    
	        phtmlStyle->put_overflow(L"hidden");    
	        phtmlStyle->put_border(L"none");//   去除边框       
	        phtmlStyle->Release();    
	        pEl->Release();    
	    }    
	}  
}
