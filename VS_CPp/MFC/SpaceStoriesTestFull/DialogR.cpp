// DialogR.cpp : implementation file
//

#include "stdafx.h"
#include "SpaceStoriesTest.h"
#include "DialogR.h"
#include "afxdialogex.h"


// CDialogR dialog

IMPLEMENT_DYNAMIC(CDialogR, CDialog)

CDialogR::CDialogR(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CDialogR::~CDialogR()
{
}

void CDialogR::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, mpic);
}


BEGIN_MESSAGE_MAP(CDialogR, CDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDialogR message handlers


void CDialogR::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialog::OnMouseMove(nFlags, point);
}


void CDialogR::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	OnOK();
	CDialog::OnLButtonDblClk(nFlags, point);
}


BOOL CDialogR::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CDialogR::OnPaint()
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
		CStdioFile otf(L"data.txt", CFile::modeRead);
		otf.ReadString(ms);
		p = _wtoi(ms);
		otf.Close();
		
		switch (p)
		{
		case 1:
			PIC.LoadBitmapW(IDB_BITMAP14);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 2:
			PIC.LoadBitmapW(IDB_BITMAP15);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 3:
			PIC.LoadBitmapW(IDB_BITMAP16);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 4:
			PIC.LoadBitmapW(IDB_BITMAP17);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 5:
			PIC.LoadBitmapW(IDB_BITMAP18);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 6:
			PIC.LoadBitmapW(IDB_BITMAP19);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 7:
			PIC.LoadBitmapW(IDB_BITMAP20);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 8:
			PIC.LoadBitmapW(IDB_BITMAP21);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 9:
			PIC.LoadBitmapW(IDB_BITMAP22);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 10:
			PIC.LoadBitmapW(IDB_BITMAP24);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		}
		
		CDialog::OnPaint();
	}
}
