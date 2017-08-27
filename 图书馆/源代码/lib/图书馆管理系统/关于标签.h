#pragma once
#include "超链接.h"     //超链接动画插件
#include "explorer.h"   //内置的浏览器的头文件
#include "Mshtml.h"     //对内置浏览器的网页进行处理的头文件

// 关于标签 对话框

class 关于标签 : public CDialog
{
	DECLARE_DYNAMIC(关于标签)

public:
	关于标签(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~关于标签();

// 对话框数据
	enum { IDD = IDD_FUN_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
public:
	// 类的初始化函数
	DECLARE_EVENTSINK_MAP(); //内部浏览器事件
	超链接 AboutUrl;
	afx_msg void OnStnClickedStaticAbouturl();
	CString strVERSION;
	CExplorer Explorer_About;
	
	void DocumentCompleteExplorerAbout(LPDISPATCH pDisp, VARIANT* URL);
    BOOL  PreTranslateMessage(MSG*   pMsg) ;
};
