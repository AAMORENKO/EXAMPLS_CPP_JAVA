
// nPoligonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "nPoligon.h"
#include "nPoligonDlg.h"
#include "afxdialogex.h"


#include <time.h>

using namespace std;




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CnPoligonDlg dialog



CnPoligonDlg::CnPoligonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_NPOLIGON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	srand((unsigned)time(NULL));
}

void CnPoligonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CnPoligonDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CnPoligonDlg message handlers

BOOL CnPoligonDlg::OnInitDialog()
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

void CnPoligonDlg::OnPaint()
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
		int n = 15; 
		int XA[360], YA[360];
		int D = 550;
		//Circl(cx, cy, D, 8, RGB(255, 0, 0));

		double xf, yf, f;
		f = 0;
		
		dc.MoveTo(cx , cy+D/2);
		k = 0;
		
		while(k<n)
		{
			xf = D / 2 * cos(f);
			yf = D / 2 * sin(f);
			XA[k] = xf + cx;
			YA[k] = yf + cy;
			k++;
			//dc.LineTo(xf + cx, yf + cy);
			f += (2*PI/n);
		} 

		for (k = 0; k < n; k++)
		{
			//dc.Ellipse(XA[k], YA[k], XA[k] + 5, YA[k] + 5);
			for (i = k+1; i < n; i++)
			{
				
				cf = RGB(rand()%255, rand() % 255, rand() % 255);
				hPenOxy = CreatePen(PS_SOLID, rand()%10, cf);
				hOldPen = (HPEN)SelectObject(dc, hPenOxy);

				dc.MoveTo(XA[k], YA[k]);
				dc.LineTo(XA[i], YA[i]);

				Sleep(15);

				SelectObject(dc, hOldPen);
				DeleteObject(hPenOxy);
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
HCURSOR CnPoligonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

afx_msg void CnPoligonDlg::Circl(int X, int Y, int D, int WDT, COLORREF CF)
{
	CClientDC dc(this);

	hPenOxy = CreatePen(PS_SOLID, WDT, CF);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	double xf, yf, f;
	f = 0;

	dc.MoveTo(X + D / 2, Y);

	do
	{
		xf = D / 2 * cos(f);
		yf = D / 2 * sin(f);
		dc.LineTo(xf + X, yf + Y);
		f += 0.09;
	} while (f <= 360);
}

