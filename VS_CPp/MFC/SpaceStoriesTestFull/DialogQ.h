#pragma once


// CDialogQ dialog

class CDialogQ : public CDialog
{
	DECLARE_DYNAMIC(CDialogQ)

public:
	CDialogQ(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogQ();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon;
	DECLARE_MESSAGE_MAP()
public:
	CStatic mpic;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

private:

	COLORREF cf, c[25];
	HFONT hold, hNew, hbk;
	HPEN hPenOxy, hOldPen, pen;
	HBRUSH m, oldm, brush;
	CPen d, oldd;
	CBitmap PIC;
	CRect rc, w, kw[30];

	CString ms, t, z;

	int Matrix[50][50];
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int RH, RW, k, i, j, p,q, x, y, cx, cy, dx, dy;
	bool fg;


};
