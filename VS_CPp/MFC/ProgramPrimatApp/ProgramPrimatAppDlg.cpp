
// ProgramPrimatAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProgramPrimatApp.h"
#include "ProgramPrimatAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgramPrimatAppDlg dialog



CProgramPrimatAppDlg::CProgramPrimatAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PROGRAMPRIMATAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramPrimatAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramPrimatAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProgramPrimatAppDlg message handlers

BOOL CProgramPrimatAppDlg::OnInitDialog()
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

void CProgramPrimatAppDlg::OnPaint()
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

		hNew = CreateFont(28, 0, 0, 0, FW_NORMAL, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Times New Roman Cyr");
		hold = (HFONT)SelectObject(dc, hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		int d;
		// TODO
		
		d = 100; dx = d / sqrt(2); dy = d / sqrt(2) + 10;

		y1 = 40;
		for (k = 0; k < 3; k++)
		{
			x1 = 80;
			for (i = 0; i < 4; i++)
			{
				KWD(x1, y1, d);
				x1 += (dx + dx / 8);
			}
			y1 += dy;
		}

		y1 = 40 + dy / 2;
		for (k = 0; k < 2; k++)
		{
			x1 = 85 + dx / 2;
			for (i = 0; i < 3; i++)
			{
				KWD(x1, y1, d);
				x1 += (dx + dx / 8);
			}
			y1 += dy;
		}




		d = 85;
		x1 = 85; y1 = 50;
		
		for (k = 0; k < 4; k++)
		{
			x1 = 85; 
			for (i = 0; i < 5; i++)
			{
				//dc.Ellipse(x1, y1, x2, y2);
				Circl(x1, y1, d);
				x1 += d; x1 -= 15; 
			}
			y1 += d; y1 -= 15; 
		}






		d = 77;
		x1 = 45; y1 = 10;
		x2 = x1 + d; y2 = y1 + d;

		for (k = 0; k < 4; k++)
		{
			x1 = 45; x2 = x1 + d;
			for (i = 0; i < 5; i++)
			{
				dc.Ellipse(x1, y1, x2, y2);
				x1 += d; x1 -= 10; x2 = x1 + d;
			}
			y1 += d; y1 -= 10; y2 = y1 + d;
		}


		d = 300;
		x1 = 85; y1 = 10; 
		x2 = x1 + d; y2 = y1 + d;
		dx = dy = 12;

		for (k = 0; k < 13; k++)
		{
			dc.Rectangle(x1+dx*k, y1+dy*k, x2-dx*k, y2-dy*k);
			dc.Ellipse(x1 + dx*k, y1 + dy*k, x2 - dx*k, y2 - dy*k);
		}



		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);
		hold = (HFONT)SelectObject(dc, hbk);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProgramPrimatAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

afx_msg void CProgramPrimatAppDlg::Circl(int X, int Y, int D)
{
	CClientDC dc(this);
	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	double xf, yf, f;
	f = 0;

	dc.MoveTo(X + D / 2, Y);

	do
	{
		xf = D / 2 * cos(f);
		yf = D / 2 * sin(f);
		//dc.SetPixel(xf+X, yf+Y, cf);
		dc.LineTo(xf + X, yf + Y);
		f += 0.09;
	} while (f <= 360);
}


void CProgramPrimatAppDlg::KWD(int X, int Y, int D)
{
	CClientDC dc(this);
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);
	dc.MoveTo(X, Y);
	double d = D / sqrt(2);
	dx = d;
	dc.LineTo(X + dx, Y);
	dc.LineTo(X + d, Y + d);
	dc.LineTo(X, Y + d);
	dc.LineTo(X, Y);
}

