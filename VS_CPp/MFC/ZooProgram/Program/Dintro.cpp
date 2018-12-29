// Dintro.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "Dintro.h"
#include "afxdialogex.h"


// CDintro dialog

IMPLEMENT_DYNAMIC(CDintro, CDialogEx)

CDintro::CDintro(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INTRO, pParent)
{

}

CDintro::~CDintro()
{
}

void CDintro::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDintro, CDialogEx)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CDintro message handlers

void CDintro::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CDintro::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	EndDialog(0);
	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CDintro::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	EndDialog(0);
	CDialogEx::OnRButtonDown(nFlags, point);
}
