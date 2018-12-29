// Dialog3.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "Dialog3.h"
#include "afxdialogex.h"


// CDialog3 dialog

IMPLEMENT_DYNAMIC(CDialog3, CDialog)

CDialog3::CDialog3(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG3, pParent)
{

}

CDialog3::~CDialog3()
{
}

void CDialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog3, CDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CDialog3 message handlers


void CDialog3::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialog::OnMouseMove(nFlags, point);
}


void CDialog3::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	
	
	CDialog::OnLButtonDown(nFlags, point);
}


void CDialog3::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	EndDialog(0);
	CDialog::OnLButtonDblClk(nFlags, point);
}


void CDialog3::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	EndDialog(0);
	CDialog::OnRButtonDown(nFlags, point);
}
