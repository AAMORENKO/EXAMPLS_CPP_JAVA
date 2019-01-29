
// ProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgramDlg dialog



CProgramDlg::CProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	fg = true;

	SetWindowTextW(L"Program");

	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProgramDlg message handlers

BOOL CProgramDlg::OnInitDialog()
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

void CProgramDlg::OnPaint()
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
		// визначення розмірів малювання

		CClientDC dc(this);
		GetClientRect(&rc);

		// вибір шрифтів
		hNew = CreateFont(36, 0, 0, 0, FW_NORMAL, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Trebuchet Ms");
		hold = (HFONT)SelectObject(dc, hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		// горизонтальний та вертикальний розміри
		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		
		// координати центру
		cx = RH / 2;
		cy = RW / 2;

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		int xmax, ymax;
		xmax = rc.right;
		ymax = rc.bottom;


		// ось ОХ  із стрілочками
		dc.MoveTo(0, cy);
		dc.LineTo(xmax, cy);
		dc.LineTo(xmax - xmax / 100 * 2, cy - ymax / 100 * 2);
		dc.MoveTo(xmax, cy);
		dc.LineTo(xmax - xmax / 100 * 2, cy + ymax / 100 * 2);
		dc.TextOutW(xmax - xmax / 100 * 2-10, cy + ymax / 100 * 2, L"X");

		// ось ОY  із стрілочками
		dc.MoveTo(cx, 0);
		dc.LineTo(cx, ymax);
		dc.MoveTo(cx, 0);
		dc.LineTo(cx-xmax/100*2, ymax/100*3);
		dc.MoveTo(cx, 0);
		dc.LineTo(cx + xmax / 100 * 2, ymax / 100 * 3);
		dc.TextOutW(cx + xmax / 100 * 2, ymax / 300,L"Y");


		double xf, yf, a, b;

		a = -15; b = 5;

		x1 = 0;
		xf = a + x1*(b - a) / xmax;
		yf = xf*xf + 4 * xf + 3;
		y1 = yf*xmax / (b - a);
		y1 = ymax / 2 - y1;
		dc.MoveTo(x1-cx/2, y1);
		
		//креслимо параболу
		for (x1 = 1; x1 < xmax; x1++)
		{
			xf = a + x1*(b - a) / xmax;
			yf = yf = xf*xf + 4 * xf + 3;
			y1 = yf*xmax / (b - a);
			y1 = ymax / 2 - y1;
			dc.LineTo(x1-cx/2, y1);
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
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

