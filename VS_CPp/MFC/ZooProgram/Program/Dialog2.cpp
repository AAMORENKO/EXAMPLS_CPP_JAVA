// Dialog2.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "Dialog2.h"
#include "afxdialogex.h"
#include "ProgramDlg.h"
#include "Dialog3.h"
#include <cstring>

// CDialog2 dialog

IMPLEMENT_DYNAMIC(CDialog2, CDialog)

CDialog2::CDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG2, pParent)
{
	CStdioFile inf(L"data.txt", CFile::modeRead);
	inf.ReadString(ms);
	inf.Close();
	ms += ' ';
	//MessageBox(ms, L"Результати вибору", MB_OK | MB_ICONINFORMATION);

	z.Empty();
	p = 0;
	k = ms.GetLength();
	for (i = 0; i <k; i++)
	{
		if (ms[i] != ' ') z += ms[i];
		else
		{
			mpc[p] = _wtoi(z);
			p++;
			z.Empty();
		}
	}

	//z.Format(L"%i %i %i", mpc[0] , mpc[1], mpc[2]);
	//MessageBox(z, L"Результати вибору", MB_OK | MB_ICONINFORMATION);
	pc[0].LoadBitmapW(IDB_BITMAP2);
	pc[1].LoadBitmapW(IDB_BITMAP3);
	pc[2].LoadBitmapW(IDB_BITMAP4);
	pc[3].LoadBitmapW(IDB_BITMAP5);
	pc[4].LoadBitmapW(IDB_BITMAP6);
	pc[5].LoadBitmapW(IDB_BITMAP7);
	pc[6].LoadBitmapW(IDB_BITMAP8);
	pc[7].LoadBitmapW(IDB_BITMAP9);
	pc[8].LoadBitmapW(IDB_BITMAP10);
	pc[9].LoadBitmapW(IDB_BITMAP11);
	pc[10].LoadBitmapW(IDB_BITMAP12);
	pc[11].LoadBitmapW(IDB_BITMAP13);
	pc[12].LoadBitmapW(IDB_BITMAP14);
	pc[13].LoadBitmapW(IDB_BITMAP15);
	pc[14].LoadBitmapW(IDB_BITMAP16);
	pc[15].LoadBitmapW(IDB_BITMAP17);
	pc[16].LoadBitmapW(IDB_BITMAP18);
	pc[17].LoadBitmapW(IDB_BITMAP19);
	pc[18].LoadBitmapW(IDB_BITMAP20);
	pc[19].LoadBitmapW(IDB_BITMAP21);
	pc[20].LoadBitmapW(IDB_BITMAP22);
	pc[21].LoadBitmapW(IDB_BITMAP23);
	pc[22].LoadBitmapW(IDB_BITMAP24);
	pc[23].LoadBitmapW(IDB_BITMAP25);
	pc[24].LoadBitmapW(IDB_BITMAP26);
	pc[25].LoadBitmapW(IDB_BITMAP27);
	pc[26].LoadBitmapW(IDB_BITMAP28);
}

CDialog2::~CDialog2()
{
}

void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PC1, mpic1);
	DDX_Control(pDX, IDC_PC2, mpic2);
	DDX_Control(pDX, IDC_PC3, mpic3);

	
	mpic1.SetBitmap(pc[mpc[0] - 1]);
	mpic2.SetBitmap(pc[mpc[1] - 1]);
	mpic3.SetBitmap(pc[mpc[2] - 1]);


}


BEGIN_MESSAGE_MAP(CDialog2, CDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDialog2 message handlers


void CDialog2::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialog::OnMouseMove(nFlags, point);
}


void CDialog2::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	GetClientRect(&rc);

	kw[0].left = rc.left+555;
	kw[0].right = rc.right-15;
	kw[0].top = rc.top+335;
	kw[0].bottom = rc.bottom-35;

	//dc.Rectangle(&w);

	if (PtInRect(kw[0], point))
	{
		CProgramDlg dlg;
		OnOK();
		dlg.DoModal();
	}


	kw[1].left = rc.left + 555;
	kw[1].right = rc.right - 15;
	kw[1].top = rc.top + 5;
	kw[1].bottom = rc.bottom - 325;

	//dc.Rectangle(&kw[1]);
	if (PtInRect(kw[1], point))
	{
		if (MessageBox(TEXT("Ви дійсно бажаєте вийти ?"), TEXT("УВАГА!!!"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
		{
			OnOK();
		}
	}


	kw[2].left = rc.left + 700;
	kw[2].right = rc.right - 20;
	kw[2].top = rc.top + 155;
	kw[2].bottom = rc.bottom - 165;

	//dc.Rectangle(&kw[2]);
	if (PtInRect(kw[2], point))
	{
		CDialog3 dlg;
		dlg.DoModal();
	}


	CDialog::OnLButtonDown(nFlags, point);
}


void CDialog2::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	if (MessageBox(TEXT("Ви дійсно бажаєте вийти ?"), TEXT("УВАГА!!!"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
	{
		OnOK();
	}
}
