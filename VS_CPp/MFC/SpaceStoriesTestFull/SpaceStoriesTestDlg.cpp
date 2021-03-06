
// SpaceStoriesTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpaceStoriesTest.h"
#include "SpaceStoriesTestDlg.h"
#include "afxdialogex.h"
#include "DialogQ.h"
#include "DialogR.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// CSpaceStoriesTestDlg dialog



CSpaceStoriesTestDlg::CSpaceStoriesTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SPACESTORIESTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpaceStoriesTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSpaceStoriesTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CSpaceStoriesTestDlg message handlers

BOOL CSpaceStoriesTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSpaceStoriesTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSpaceStoriesTestDlg::OnPaint()
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

		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


		// TODO

		y = 140; dx = dy = 40;
		p = 1;
		for (k = 0; k < 2; k++)
		{
			x = 95;
			for (i = 0; i < 5; i++)
			{
				x1 = w.left = rc.left + x;
				y1 = w.top = rc.top + y;
				x2 = w.right = x1 + dx;
				y2 = w.bottom = y1 + dy;

				kw[p] = w;

				//dc.MoveTo(x1, y1);
				//dc.LineTo(x2, y1);
				//dc.LineTo(x2, y2);
				//dc.LineTo(x1, y2);
				//dc.LineTo(x1, y1);

				p++;
				x += dx; x += 15;
			}
			y += dy; y += 20;
		}

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);



		CDialog::OnPaint();

	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSpaceStoriesTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CAboutDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	OnOK();
	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CSpaceStoriesTestDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default



	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialog::OnMouseMove(nFlags, point);
}


void CSpaceStoriesTestDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (MessageBox(TEXT("Ви дійсно бажаєте вийти ?"), TEXT("УВАГА!!!"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
	{
		OnOK();
	};
	CDialog::OnLButtonDblClk(nFlags, point);
}


void CSpaceStoriesTestDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	GetClientRect(&rc);

	y = 140; dx = dy = 40;
	p = 0;
	for (k = 0; k < 2; k++)
	{
		x = 95;
		for (i = 0; i < 5; i++)
		{
			x1 = w.left = rc.left + x;
			y1 = w.top = rc.top + y;
			x2 = w.right = x1 + dx;
			y2 = w.bottom = y1 + dy;

			kw[p] = w;

			p++;
			x += dx; x += 15;
		}
		y += dy; y += 20;
	}

	for (int j = 0; j < p; j++)
	{
		if (PtInRect(&kw[j], point))
		{
			CStdioFile inf(L"data.txt", CFile::modeCreate | CFile::modeWrite);
			switch (j)
			{
			case 0: ms = "1"; break;
			case 1: ms = "2"; break;
			case 2: ms = "3"; break;
			case 3: ms = "4"; break;
			case 4: ms = "5"; break;
			case 5: ms = "6"; break;
			case 6: ms = "7"; break;
			case 7: ms = "8"; break;
			case 8: ms = "9"; break;
			case 9: ms = "10"; break;
			}
			inf.WriteString(ms);
			inf.Flush();
			inf.Close();
		
			CDialogQ dlg1;
			dlg1.DoModal();
		}

	}
	
	CDialog::OnLButtonDown(nFlags, point);
}


void CSpaceStoriesTestDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CAboutDlg dlg;
	dlg.DoModal();
	CDialog::OnRButtonDown(nFlags, point);
}
