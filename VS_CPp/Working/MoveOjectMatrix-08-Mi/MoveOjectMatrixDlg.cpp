
// MoveOjectMatrixDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MoveOjectMatrix.h"
#include "MoveOjectMatrixDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMoveOjectMatrixDlg dialog



CMoveOjectMatrixDlg::CMoveOjectMatrixDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MOVEOJECTMATRIX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoveOjectMatrixDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMoveOjectMatrixDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMoveOjectMatrixDlg message handlers

BOOL CMoveOjectMatrixDlg::OnInitDialog()
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

void CMoveOjectMatrixDlg::OnPaint()
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

		x1 = minX + 100; y1 = minY + 35;
		x2 = maxX - 80; y2 = maxY - 30;

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


		/*
		x1 = minX + 100; y1 = minY + 35;
		x2 = maxX - 80; y2 = maxY - 30;

		pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
		brush = CreateSolidBrush(cf);
		SelectObject(dc, pen);
		SelectObject(dc, brush);
		dc.Rectangle(x1, y1, x2, y2);
		*/
		
		
		ck =cf;

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




		x1 = bx; y1 = by;
		while (y1 <= ey)
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

			x1 = ex; y1 +=dy;

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
			y1+=dy;
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
HCURSOR CMoveOjectMatrixDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

