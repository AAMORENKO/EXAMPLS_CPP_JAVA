#pragma once
#include "afxwin.h"


// CDialog2 dialog

class CDialog2 : public CDialog
{
	DECLARE_DYNAMIC(CDialog2)

public:
	CDialog2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

private:

	//HPEN hPenOxy, hOldPen;
	//HBRUSH m, oldm, brush;
	//HPEN pen;

	//COLORREF cf, c[25];

	//CPen d, oldd;
	CBitmap pic, pc[28];
	CRect rc, w, kw[3];


	int mpc[3];

	CString ms, t, z;

	//int Matrix[50][50], SCn;
	int RH, RW, k, i, j, p, cx, cy, dx, dy, x1, y1, x2, y2;
	//bool fg;

public:
	CStatic mpic1;
	CStatic mpic2;
	CStatic mpic3;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnCancel();
};
