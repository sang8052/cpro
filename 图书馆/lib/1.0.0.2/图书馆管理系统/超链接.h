// copyright (c) from http://blog.csdn.net/u013051748/article/details/45599429
// 作者：codnumber

//sang8052 改写于 2017-08-21
//改写声明： 只修改了类名为 超链接以适合本项目中文化的特性

#pragma once
// 超链接
#include "stdafx.h"
#include "MyPlayer.h"  //注：此文件来自外部调用，相关代码已经放在了项目外的include文件夹下的MyPlayer目录内，使用时
//直接在项目属性-->C/C++ 中添加附加包含到项目外的include文件夹下的MyPlayer目录
class 超链接 : public CStatic
{
    DECLARE_DYNAMIC(超链接)

public:
    超链接();
    virtual ~超链接();

public: 

    void SetURL(CString strURL);
    CString GetURL() const;
    void SetColor(COLORREF clr,BYTE clrItem);//设置颜色
    COLORREF GetColor(BYTE clrItem);//得到颜色
    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(超链接)
protected:
    virtual void PreSubclassWindow();
    //}}AFX_VIRTUAL

    // Implementation
protected:
    int GotoURL(LPCTSTR url, int showcmd);
    // Protected attributes
protected:
    COLORREF m_clrHot;      // Link normal color
    COLORREF m_clrNor;      // Link active color
    COLORREF m_clrBG;       // Link active color
    BOOL     m_bHot;                // Is the link active?
    CString  m_strURL;                  // Hyperlink URL string

    // Generated message map functions
protected:
    //{{AFX_MSG(超链接)
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnPaint();
    afx_msg LRESULT  OnMouseHover(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT  OnMouseLeave(WPARAM wParam,LPARAM lParam);
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

protected:
    DECLARE_MESSAGE_MAP()
};