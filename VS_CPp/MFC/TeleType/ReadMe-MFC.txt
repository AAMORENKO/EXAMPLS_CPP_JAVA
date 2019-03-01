// Повна версія - додані - Змійка Спіраль Телетайп
// MoveObjectinMatrix

// MoveObjectinMatrixDlg.h : header file
//

#pragma once

#define PI 3.1415926535897932384626433832795
#define mtime 20

// CMoveObjectinMatrixDlg dialog
class CMoveObjectinMatrixDlg : public CDialog
{
// Construction
public:
	CMoveObjectinMatrixDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOVEOBJECTINMATRIX_DIALOG };
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

private:

	COLORREF cf, ck, c[25];
	HFONT hold, hNew, hbk;
	HPEN hPenOxy, hOldPen, pen;
	HBRUSH m, oldm, brush;
	CPen d, oldd;
	CBitmap pic;
	CRect rc, w, kw[30];

	CString ms, t, z;

	int Matrix[50][50];
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int RH, RW, k, i, j, p, x, y, cx, cy, dx, dy;
	bool fg;

	DECLARE_MESSAGE_MAP()
};


//====================================


// MoveObjectinMatrixDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MoveObjectinMatrix.h"
#include "MoveObjectinMatrixDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMoveObjectinMatrixDlg dialog



CMoveObjectinMatrixDlg::CMoveObjectinMatrixDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MOVEOBJECTINMATRIX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoveObjectinMatrixDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	SetWindowTextW(L"Програма рухомих об'єктів ");
}

BEGIN_MESSAGE_MAP(CMoveObjectinMatrixDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMoveObjectinMatrixDlg message handlers

BOOL CMoveObjectinMatrixDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMoveObjectinMatrixDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		CClientDC dc(this);
		GetClientRect(&rc);

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		// TODO
		int bx, ex, by, ey;

		int maxX = rc.right;
		int minX = rc.left;
		int maxY = rc.bottom;
		int minY = rc.top;

		cf = RGB(0, 0, 0);
		dc.FillSolidRect(&rc, cf);

		x1 = minX + 70; y1 = minY + 35;
		x2 = maxX - 50; y2 = maxY - 30;

		pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
		brush = CreateSolidBrush(cf);
		SelectObject(dc, pen);
		SelectObject(dc, brush);
		dc.Rectangle(x1, y1, x2, y2);
		DeleteObject(pen);
		DeleteObject(brush);

		bx = minX + 110; by = minY + 60;
		ex = maxX - 120; ey = maxY - 65;

		dx = dy = 30;

		x1 = (bx + ex) / 2; y1 = by;

		while (x1 <= ex)
		{
			pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			Sleep(mtime);
			pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			x1 += dx;
			y1 += dy;

		}

		x1 = ex; y1 = (by + ey) / 2;

		while (x1 > (bx + ex) / 2)
		{
			pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			Sleep(mtime);
			pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			x1 -= dx;
			y1 += dy;

		}


		x1 = (bx + ex) / 2; y1 = ey - dy * 0.5;

		while (x1 > bx)
		{
			pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			Sleep(mtime);
			pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			x1 -= dx;
			y1 -= dy;

		}


		x1 = bx; y1 = (by + ey) / 2 - dy / 2;

		while (x1 < (bx + ex) / 2)
		{
			pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			Sleep(mtime);
			pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			x1 += dx;
			y1 -= dy;

		}

		Sleep(mtime + 40);
//-------------------------------------------------


		ck = cf;

		for (int j = 0; j < 1; j++)
		{
			x1 = bx; y1 = by;

			while (x1 <= ex)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 += dx;
				//y1 += dy;

			}

			x1 = ex; y1 = by;

			while (y1 <= ey)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				//x1 += dx;
				y1 += dy;

			}


			x1 = ex; y1 = ey;

			while (x1 >= bx)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 -= dx;
				//y1 += dy;

			}

			x1 = bx; y1 = ey;

			while (y1 >= by)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				//x1 += dx;
				y1 -= dy;

			}

			x1 = bx; y1 = by;

			while (x1 <= ex)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 += dx;
				y1 += dy;

			}


			x1 = ex; y1 = ey;

			while (x1 >= bx)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 -= dx;
				//y1 += dy;

			}


			x1 = bx; y1 = ey;

			while (y1 > by)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 += dx;
				y1 -= dy;

			}


			x1 = ex; y1 = by;

			while (x1 >= bx)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 -= dx;
				//y1 += dy;

			}

		}

		Sleep(mtime + 40);

//-------------------------------------------------------------------


		x1 = bx; y1 = by;
		while (y1 <= ey - dy)
		{
			while (x1 <= ex)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 += dx;
				//y1 += dy;

			}

			x1 = ex; y1 += dy;

			while (x1 > bx + dx)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 -= dx;
				//y1 += dy;

			}
			y1 += dy;
		}


		Sleep(mtime + 40);

//-------------------------------------------------------------------


		//ck = RGB(240, 120, 25);
		ck = cf;

		int nx = bx;
		int kx = ex;
		int ny = by;
		int ky = ey;

		while (x1 < (nx + kx) / 2)
		{

			x1 = bx; y1 = by;

			while (x1 <= ex)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 += dx;
				//y1 += dy;

			}

			x1 = ex; y1 = by;

			while (y1 <= ey)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				//x1 += dx;
				y1 += dy;

			}


			x1 = ex; y1 = ey;

			while (x1 >= bx)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				x1 -= dx;
				//y1 += dy;

			}

			x1 = bx; y1 = ey;

			while (y1 > by + 2 * dy)
			{
				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				Sleep(mtime);
				//pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				pen = CreatePen(PS_SOLID, 5, ck);
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
				DeleteObject(pen);
				DeleteObject(brush);
				//x1 += dx;
				y1 -= dy;

			}

			bx += dx; ex -= dx;
			by += dy; ey -= dy;
		}


		Sleep(mtime + 40);

//-------------------------------------------------------------------


		ms = "Я вивчаю мову програмування C++";

		x1 = cx - 265; y1 = cy; dx = 18;

		for (k = 0; k < ms.GetLength(); k++)
		{
			t = ""; t += ms[k];
			hNew = CreateFont(29, 0, 0, 0, FW_NORMAL, 0, 0, 0,
				ANSI_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_DONTCARE,
				L"Trebuchet Ms");
			hold = (HFONT)SelectObject(dc, hNew);
			dc.SetTextColor(RGB(0, 0, 0));
			dc.SetBkColor(RGB(255, 255, 255));
			dc.TextOutW(x1, y1, t, t.GetLength());
			DeleteObject(hNew);
			hold = (HFONT)SelectObject(dc, hbk);
			Sleep(mtime);

			hNew = CreateFont(29, 0, 0, 0, FW_NORMAL, 0, 0, 0,
				ANSI_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_DONTCARE,
				L"Trebuchet Ms");
			hold = (HFONT)SelectObject(dc, hNew);
			dc.SetTextColor(RGB(255, 255, 255));
			dc.SetBkColor(RGB(0, 0, 0));
			dc.TextOutW(x1, y1, t, t.GetLength());
			DeleteObject(hNew);
			hold = (HFONT)SelectObject(dc, hbk);

			x1 += dx;
		}


		DeleteObject(pen);
		DeleteObject(brush);

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMoveObjectinMatrixDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




/*
x1 = minX + 100; y1 = minY + 35;
x2 = maxX - 80; y2 = maxY - 30;
pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
brush = CreateSolidBrush(cf);
SelectObject(dc, pen);
SelectObject(dc, brush);
dc.Rectangle(x1, y1, x2, y2);
*/


/*
"Найбiльше i найдорожче добро кожного народу – це його мова, та жива схованка людського духу, його багата скарбниця, в яку народ складає і своє давнє життя i свої сподiванки, розум, досвiд, почування.";
"Запашна, співуча, гнучка, милозвучна, сповнена музики і квіткових пахощів – скількома епітетами супроводяться визнання української мови.";
"Мова – втілення думки. Що багатша думка, то багатша мова. Любімо її, вивчаймо її, розвиваймо її! Борімося за красу мови, за правильність мови, за приступність мови, за багатство мови.";
"Народ, що не усвідомлює значення рідної мови для свого вищого духовного життя і сам її покидає й відрікається, виконує над собою самовбивство.";
*/

