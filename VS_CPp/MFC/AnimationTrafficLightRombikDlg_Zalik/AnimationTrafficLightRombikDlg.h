
// ProgramDlg.h : header file
//

#pragma once

#define mtime 298
#define PI 3.1415926535897932384626433832795


// CProgramDlg dialog
class CProgramDlg : public CDialog
{
// Construction
public:
	CProgramDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void Rombik(int X, int Y, int DX, int DY, int WDT, COLORREF CF);

private:

	COLORREF cf, c[25];
	HFONT hold, hNew, hbk;
	HPEN hPenOxy, hOldPen, pen;
	HBRUSH m, oldm, brush;
	CPen d, oldd;
	CBitmap pic;
	CRect rc, w, kw[30];
	CBrush *ks1, *ks2, *ks3;
	CString ms, t, z;

	int Matrix[50][50];
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int RH, RW, k, i, j, p, x, y, cx, cy, dx, dy;
	bool fg;




	DECLARE_MESSAGE_MAP()
};
