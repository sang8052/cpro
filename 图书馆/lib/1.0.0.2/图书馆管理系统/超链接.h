// copyright (c) from http://blog.csdn.net/u013051748/article/details/45599429
// ���ߣ�codnumber

//sang8052 ��д�� 2017-08-21
//��д������ ֻ�޸�������Ϊ ���������ʺϱ���Ŀ���Ļ�������

#pragma once
// ������
#include "stdafx.h"
#include "MyPlayer.h"  //ע�����ļ������ⲿ���ã���ش����Ѿ���������Ŀ���include�ļ����µ�MyPlayerĿ¼�ڣ�ʹ��ʱ
//ֱ������Ŀ����-->C/C++ ����Ӹ��Ӱ�������Ŀ���include�ļ����µ�MyPlayerĿ¼
class ������ : public CStatic
{
    DECLARE_DYNAMIC(������)

public:
    ������();
    virtual ~������();

public: 

    void SetURL(CString strURL);
    CString GetURL() const;
    void SetColor(COLORREF clr,BYTE clrItem);//������ɫ
    COLORREF GetColor(BYTE clrItem);//�õ���ɫ
    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(������)
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
    //{{AFX_MSG(������)
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnPaint();
    afx_msg LRESULT  OnMouseHover(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT  OnMouseLeave(WPARAM wParam,LPARAM lParam);
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

protected:
    DECLARE_MESSAGE_MAP()
};