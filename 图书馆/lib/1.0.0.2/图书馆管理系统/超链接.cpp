// copyright (c) from http://blog.csdn.net/u013051748/article/details/45599429
// ���ߣ�codnumber

//sang8052 ��д�� 2017-08-21
//��д������ ֻ�޸�������Ϊ ���������ʺϱ���Ŀ���Ļ�������

// ������.cpp : ʵ���ļ�
//

#pragma once
#include "stdafx.h"
#include "������.h"


// ������

IMPLEMENT_DYNAMIC(������, CStatic)

������::������()
{
    m_bHot              = FALSE;    // Control doesn't own the focus yet
    m_strURL.Empty();               // Set URL to an empty string
    m_clrHot = RGB(0,0,255);
    m_clrNor = RGB(0,0,255);
    m_clrBG = RGB(240,240,240);
}

������::~������()
{
}


BEGIN_MESSAGE_MAP(������, CStatic)
        //{{AFX_MSG_MAP(������)
        ON_WM_MOUSEMOVE()
        ON_WM_LBUTTONUP()
        ON_WM_PAINT()
        ON_MESSAGE(WM_MOUSEHOVER,&OnMouseHover)
        ON_MESSAGE(WM_MOUSELEAVE,&OnMouseLeave)
        ON_WM_SETCURSOR()
        //}}AFX_MSG_MAP
    END_MESSAGE_MAP()

    /////////////////////////////////////////////////////////////////////////////
    void ������::PreSubclassWindow() 
    {
        // TODO: Add your specialized code here and/or call the base class
        DWORD dwStyle = GetStyle();
        ::SetWindowLong(GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);

        //  SetFont(GetParent()->GetFont());
        CStatic::PreSubclassWindow();
    }

    void ������::OnMouseMove(UINT nFlags, CPoint point) 
    {
        TRACKMOUSEEVENT tme; 
        tme.cbSize = sizeof(tme); 
        tme.hwndTrack = m_hWnd; 
        tme.dwFlags = TME_LEAVE | TME_HOVER; 
        tme.dwHoverTime =  1; 
        _TrackMouseEvent(&tme); 

        //  CStatic::OnMouseMove(nFlags, point);
    }

    //���������
    LRESULT ������::OnMouseHover(WPARAM wParam,LPARAM lParam)
    {   
        if (!m_bHot)
        {
            m_bHot = TRUE; 
            Invalidate();
        }  
        return TRUE;
    }

    //����뿪
    LRESULT ������::OnMouseLeave(WPARAM wParam,LPARAM lParam)
    {
        m_bHot = FALSE;
        Invalidate();
        return TRUE;
    }


    void ������::OnLButtonUp(UINT nFlags, CPoint point) 
    {
        if (m_strURL.IsEmpty())
        {
            GetWindowText(m_strURL);
        }
        GotoURL(m_strURL, SW_SHOW);
    }

    /////////////////////////////////////////////////////////////////////////////
    // ������ operations

    void ������::SetURL(CString strURL)
    {
        m_strURL = strURL;
    }

    CString ������::GetURL() const 
    { 
        return m_strURL;   
    }


    int ������::GotoURL(LPCTSTR url, int showcmd)
    {
        HINSTANCE result = ShellExecute(NULL, _T("open"), url, NULL,NULL, showcmd); 
        return (int)result;
    }


    void ������::OnPaint() 
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
        ///׼������
        CRect rect;
        CBrush BGBrush,*pOldBrush;
        int nTextLeft=4,nTextTop=2; //���������λ��
        this->GetClientRect(&rect);
        //������
        BGBrush.CreateSolidBrush(m_clrBG);
        pOldBrush=dc.SelectObject(&BGBrush);
        dc.FillRect(&rect,&BGBrush);
        dc.SelectObject(pOldBrush);
        BGBrush.DeleteObject();
        ///�������
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


    BOOL ������::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
    {
        // TODO: Add your message handler code here and/or call default
        if (m_bHot)
        {
            ::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(32649)));
            return TRUE;
        }
        return CStatic::OnSetCursor(pWnd, nHitTest, message);
    }