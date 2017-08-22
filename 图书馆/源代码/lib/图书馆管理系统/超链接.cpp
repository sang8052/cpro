// copyright (c) from http://blog.csdn.net/u013051748/article/details/45599429
// 作者：codnumber

//sang8052 改写于 2017-08-21
//改写声明： 只修改了类名为 超链接以适合本项目中文化的特性

// 超链接.cpp : 实现文件
//

#pragma once
#include "stdafx.h"
#include "超链接.h"


// 超链接

IMPLEMENT_DYNAMIC(超链接, CStatic)

超链接::超链接()
{
    m_bHot              = FALSE;    // Control doesn't own the focus yet
    m_strURL.Empty();               // Set URL to an empty string
    m_clrHot = RGB(0,0,255);
    m_clrNor = RGB(0,0,255);
    m_clrBG = RGB(240,240,240);
}

超链接::~超链接()
{
}


BEGIN_MESSAGE_MAP(超链接, CStatic)
        //{{AFX_MSG_MAP(超链接)
        ON_WM_MOUSEMOVE()
        ON_WM_LBUTTONUP()
        ON_WM_PAINT()
        ON_MESSAGE(WM_MOUSEHOVER,&OnMouseHover)
        ON_MESSAGE(WM_MOUSELEAVE,&OnMouseLeave)
        ON_WM_SETCURSOR()
        //}}AFX_MSG_MAP
    END_MESSAGE_MAP()

    /////////////////////////////////////////////////////////////////////////////
    void 超链接::PreSubclassWindow() 
    {
        // TODO: Add your specialized code here and/or call the base class
        DWORD dwStyle = GetStyle();
        ::SetWindowLong(GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);

        //  SetFont(GetParent()->GetFont());
        CStatic::PreSubclassWindow();
    }

    void 超链接::OnMouseMove(UINT nFlags, CPoint point) 
    {
        TRACKMOUSEEVENT tme; 
        tme.cbSize = sizeof(tme); 
        tme.hwndTrack = m_hWnd; 
        tme.dwFlags = TME_LEAVE | TME_HOVER; 
        tme.dwHoverTime =  1; 
        _TrackMouseEvent(&tme); 

        //  CStatic::OnMouseMove(nFlags, point);
    }

    //鼠标在上面
    LRESULT 超链接::OnMouseHover(WPARAM wParam,LPARAM lParam)
    {   
        if (!m_bHot)
        {
            m_bHot = TRUE; 
            Invalidate();
        }  
        return TRUE;
    }

    //鼠标离开
    LRESULT 超链接::OnMouseLeave(WPARAM wParam,LPARAM lParam)
    {
        m_bHot = FALSE;
        Invalidate();
        return TRUE;
    }


    void 超链接::OnLButtonUp(UINT nFlags, CPoint point) 
    {
        if (m_strURL.IsEmpty())
        {
            GetWindowText(m_strURL);
        }
        GotoURL(m_strURL, SW_SHOW);
    }

    /////////////////////////////////////////////////////////////////////////////
    // 超链接 operations

    void 超链接::SetURL(CString strURL)
    {
        m_strURL = strURL;
    }

    CString 超链接::GetURL() const 
    { 
        return m_strURL;   
    }


    int 超链接::GotoURL(LPCTSTR url, int showcmd)
    {
        HINSTANCE result = ShellExecute(NULL, _T("open"), url, NULL,NULL, showcmd); 
        return (int)result;
    }


    void 超链接::OnPaint() 
    {
        CPaintDC dc(this); // device context for painting   
        // TODO: Add your message handler code here
        CFont* pFont = GetFont();
        CFont m_Font;
        if (pFont != NULL)
        {
            LOGFONT lf;
            pFont->GetLogFont(&lf);
            lf.lfUnderline = m_bHot;
            if (m_Font.CreateFontIndirect(&lf))
                dc.SelectObject(m_Font);
        }
        if (m_bHot)
        {   
            dc.SetTextColor(m_clrHot);
        }
        else
        {
            dc.SetTextColor(m_clrNor);
        }
        dc.SetBkMode(TRANSPARENT);
        ///准备工作
        CRect rect;
        CBrush BGBrush,*pOldBrush;
        int nTextLeft=4,nTextTop=2; //文字输出的位置
        this->GetClientRect(&rect);
        //画背景
        BGBrush.CreateSolidBrush(m_clrBG);
        pOldBrush=dc.SelectObject(&BGBrush);
        dc.FillRect(&rect,&BGBrush);
        dc.SelectObject(pOldBrush);
        BGBrush.DeleteObject();
        ///输出文字
        TEXTMETRIC tm;
        dc.GetTextMetrics(&tm);
        CString strText;
        this->GetWindowText(strText);
        nTextTop=rect.top+(rect.Height()-tm.tmHeight)/2;
        if(strText.GetLength()>0)
        {
            dc.TextOut(nTextLeft,nTextTop,strText);
        }   
        BGBrush.DeleteObject();
        m_Font.DeleteObject();
    }


    BOOL 超链接::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
    {
        // TODO: Add your message handler code here and/or call default
        if (m_bHot)
        {
            ::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(32649)));
            return TRUE;
        }
        return CStatic::OnSetCursor(pWnd, nHitTest, message);
    }