#pragma once

#define mtime_0 98

// CKw0 dialog

class CKw0 : public CDialog
{
	DECLARE_DYNAMIC(CKw0)

public:
	CKw0(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKw0();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon;
	
public:
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:

	HFONT hold, hNew, hbk;
	CString ms, t;
	CRect rc,w,kw[6];
	COLORREF cf, c[25];
	HBRUSH m, oldm;
	CPen d, oldd;

	int RH, RW, k, i, j, dx, dy, cx, cy;

	bool fg;

	DECLARE_MESSAGE_MAP()

};
