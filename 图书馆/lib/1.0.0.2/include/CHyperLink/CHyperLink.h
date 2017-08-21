#pragma once
// CHyperLink
class CHyperLink : public CStatic
{
    DECLARE_DYNAMIC(CHyperLink)

public:
    CHyperLink();
    virtual ~CHyperLink();

public: 

    void SetURL(CString strURL);
    CString GetURL() const;
    void SetColor(COLORREF clr,BYTE clrItem);//设置颜色
    COLORREF GetColor(BYTE clrItem);//得到颜色
    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CHyperLink)
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
    //{{AFX_MSG(CHyperLink)
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnPaint();
    afx_msg LRESULT  OnMouseHover(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT  OnMouseLeave(WPARAM wParam,LPARAM lParam);
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

protected:
    DECLARE_MESSAGE_MAP()
};