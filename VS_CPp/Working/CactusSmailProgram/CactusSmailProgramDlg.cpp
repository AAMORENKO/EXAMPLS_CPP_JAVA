
// CactusSmailProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CactusSmailProgram.h"
#include "CactusSmailProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCactusSmailProgramDlg dialog



CCactusSmailProgramDlg::CCactusSmailProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CACTUSSMAILPROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCactusSmailProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, mpic);

	CWnd *WndPtr = GetDlgItem(IDC_PIC);
	WndPtr->GetWindowRect(&w);
	ScreenToClient(&w);

}

BEGIN_MESSAGE_MAP(CCactusSmailProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CCactusSmailProgramDlg message handlers

BOOL CCactusSmailProgramDlg::OnInitDialog()
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

void CCactusSmailProgramDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCactusSmailProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCactusSmailProgramDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CBitmap PIC;
	if (PtInRect(&w, point))
	{
		PIC.LoadBitmapW(IDB_BITMAP2);
		mpic.SetBitmap(PIC);
		PIC.DeleteObject();
	}
	else
	{
		PIC.LoadBitmapW(IDB_BITMAP1);
		mpic.SetBitmap(PIC);
		PIC.DeleteObject();
	}



	CDialog::OnMouseMove(nFlags, point);
}
