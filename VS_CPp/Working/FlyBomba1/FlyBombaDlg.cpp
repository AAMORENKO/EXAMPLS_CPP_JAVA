
// FlyBombaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FlyBomba.h"
#include "FlyBombaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFlyBombaDlg dialog



CFlyBombaDlg::CFlyBombaDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_FLYBOMBA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlyBombaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, mspin);
}

BEGIN_MESSAGE_MAP(CFlyBombaDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CFlyBombaDlg::OnDeltaposSpin1)
END_MESSAGE_MAP()


// CFlyBombaDlg message handlers

BOOL CFlyBombaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	n = 20;
	mspin.SetRange32(20, 30);
	mspin.SetPos(n);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFlyBombaDlg::OnPaint()
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
		int minx, maxx, miny, maxy, x1, y1;
		double a, b, v0, alpha, L, H, g, PI, xf, yf, v0x, v0y;

		PI = 3.1415926535;
		g = 9.8;

		CClientDC dc(this);
		GetClientRect(&rc);

		minx = w.left = rc.left + 120;
		maxx = w.right = rc.right;
		miny = w.top = rc.top;
		maxy = w.bottom = rc.bottom;

		dc.FillSolidRect(&w, RGB(255, 255, 255));

		cx = maxx / 2;
		cy = maxy / 2;

		a = 0;
		b = 24 * PI;
		v0 = n;
		for (alpha = 10 * PI / 180; alpha < 70 * PI / 180; alpha += (5 * PI / 180))
		{
			x1 = 0;
			xf = a + x1 * (b - a) / maxx;
			v0x = v0 * cosf(alpha);
			v0y = v0 * sinf(alpha);
			yf = v0y / v0x * xf - 9.8*xf*xf / (2 * v0x*v0x);
			y1 = yf * maxx / (b - a);
			y1 = maxy / 2 - y1;
			dc.MoveTo(x1 + 120, y1 + maxy / 2);


			cf = RGB(0, 120, alpha * 180 / PI * 3.5);
			hPen = CreatePen(PS_SOLID, 3, cf);
			hOld = (HPEN)SelectObject(dc, hPen);

			for (x1 = 1; x1 < maxx; x1++)
			{
				xf = a + x1 * (b - a) / maxx;
				v0x = v0 * cosf(alpha);
				v0y = v0 * sinf(alpha);
				yf = v0y / v0x * xf - 9.8*xf*xf / (2 * v0x*v0x);
				y1 = yf * maxx / (b - a);
				y1 = maxy / 2 - y1;
				dc.LineTo(x1 + 120, y1 + maxy / 2);				
			}

			Sleep(3);
		}

		SelectObject(dc, hOld);
		DeleteObject(hPen);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFlyBombaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFlyBombaDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(true);
	nS = pNMUpDown->iPos + pNMUpDown->iDelta;
	n = nS;
	UpdateData(false);

	int minx, maxx, miny, maxy, x1, y1;
	double a, b, v0, alpha, L, H, g, PI, xf, yf, v0x, v0y;

	PI = 3.1415926535;
	g = 9.8;

	CClientDC dc(this);
	GetClientRect(&rc);

	minx = w.left = rc.left + 120;
	maxx = w.right = rc.right;
	miny = w.top = rc.top;
	maxy = w.bottom = rc.bottom;

	dc.FillSolidRect(&w, RGB(255, 255, 255));

	cx = maxx / 2;
	cy = maxy / 2;

	a = 0;
	b = 24 * PI;
	v0 = n;
	for (alpha = 10*PI/180; alpha < 70*PI/180; alpha += (5*PI/180))
	{
		x1 = 0;
		xf = a + x1 * (b - a) / maxx;
		v0x = v0 * cosf(alpha);
		v0y = v0 * sinf(alpha);
		yf = v0y / v0x * xf - 9.8*xf*xf / (2 * v0x*v0x);
		y1 = yf * maxx / (b - a);
		y1 = maxy / 2 - y1;
		dc.MoveTo(x1+120, y1+maxy/2);


		cf = RGB(0, 120, alpha*180/PI*3.5);
		hPen = CreatePen(PS_SOLID, 3, cf);
		hOld = (HPEN)SelectObject(dc, hPen);
		
		for (x1 = 1; x1 < maxx; x1++)
		{
			xf = a + x1 * (b - a) / maxx;
			v0x = v0 * cosf(alpha);
			v0y = v0 * sinf(alpha);
			yf = v0y / v0x * xf - 9.8*xf*xf / (2 * v0x*v0x);
			y1 = yf * maxx / (b - a);
			y1 = maxy / 2 - y1;
			dc.LineTo(x1+120, y1 + maxy / 2);
		}
		
		Sleep(3);
	}

	SelectObject(dc, hOld);
	DeleteObject(hPen);

	*pResult = 0;
}
