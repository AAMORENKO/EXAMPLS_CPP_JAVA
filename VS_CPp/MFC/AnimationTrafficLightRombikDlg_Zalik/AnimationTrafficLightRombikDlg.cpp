
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


		// TODO
		x1 = cx-470;
		y1 = cy-140;
		x2 = cx + 469;
		y2 = cy + 141;

		dc.Rectangle(x1, y1, x2, y2);
	
		dx = abs(x2 - x1) / 6;
		dy = abs(y2 - y1) / 2;

		int s1x1, s1y1, s1x2, s1y2;
		int s2x1, s2y1, s2x2, s2y2;
		int s3x1, s3y1, s3x2, s3y2;

		s1x1 = x1;
		s1y1 = y1;
		s1x2 = dx;
		s1y2 = dy;

		s2x1 = x1+2*dx;
		s2y1 = y1;
		s2x2 = dx;
		s2y2 = dy;

		s3x1 = x1 + 4 * dx;
		s3y1 = y1;
		s3x2 = dx;
		s3y2 = dy;

		Rombik(s1x1, s1y1, s1x2, s1y2, 3, cf);
		Rombik(s2x1, s2y1, s2x2, s2y2, 3, cf);
		Rombik(s3x1, s3y1, s3x2, s3y2, 3, cf);

		for (i = 0; i < 50; i++)
		{
			// red
			ks1 = new CBrush(RGB(255, 0, 0));
			dc.SelectObject(*ks1);
			dc.FloodFill(s1x1 + dx, s1y1 + dy , RGB(0, 0, 0));

			Sleep(1500);

			//yelo
			ks2 = new CBrush(RGB(255, 221, 0));
			dc.SelectObject(*ks2);
			dc.FloodFill(s2x1 + dx, s2y1 + dy, RGB(0, 0, 0));

			Sleep(1500);

			// red
			ks1 = new CBrush(RGB(255, 255, 255));
			dc.SelectObject(*ks1);
			dc.FloodFill(s1x1 + dx, s1y1 + dy, RGB(0, 0, 0));

			//yelo
			ks2 = new CBrush(RGB(255, 255, 255));
			dc.SelectObject(*ks2);
			dc.FloodFill(s2x1 + dx, s2y1 + dy, RGB(0, 0, 0));

			//green
			ks3 = new CBrush(RGB(0, 221, 0));
			dc.SelectObject(*ks3);
			dc.FloodFill(s3x1 + dx, s3y1 + dy , RGB(0, 0, 0));

			Sleep(1500);

			for (k = 0; k < 5; k++)
			{

				//green
				ks3 = new CBrush(RGB(0, 221, 0));
				dc.SelectObject(*ks3);
				dc.FloodFill(s3x1 + dx, s3y1 + dy, RGB(0, 0, 0));

				Sleep(250);

				//green
				ks3 = new CBrush(RGB(255, 255, 255));
				dc.SelectObject(*ks3);
				dc.FloodFill(s3x1 + dx, s3y1 + dy, RGB(0, 0, 0));

				Sleep(250);
			}
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

void CProgramDlg:: Rombik(int X, int Y, int DX, int DY, int WDT, COLORREF CF)
{
	CClientDC dc(this);
	hPenOxy = CreatePen(PS_SOLID, WDT, CF);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);
	dc.MoveTo(X, Y + DY);
	dc.LineTo(X + DX, Y);
	dc.LineTo(X + 2 * DX, Y + DY);
	dc.LineTo(X + DX, Y + 2 * DY);
	dc.LineTo(X, Y + DY);
}