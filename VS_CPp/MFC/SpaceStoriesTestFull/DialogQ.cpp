// DialogQ.cpp : implementation file
//

#include "stdafx.h"
#include "SpaceStoriesTest.h"
#include "DialogQ.h"
#include "afxdialogex.h"
#include "DialogR.h"

// CDialogQ dialog

IMPLEMENT_DYNAMIC(CDialogQ, CDialog)

CDialogQ::CDialogQ(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CDialogQ::~CDialogQ()
{
}

void CDialogQ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, mpic);
}


BEGIN_MESSAGE_MAP(CDialogQ, CDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDialogQ message handlers


void CDialogQ::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialog::OnMouseMove(nFlags, point);
}


void CDialogQ::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	GetClientRect(&rc);

	y = 235; dx = 180; dy = 40;
	p = 0;
	for (k = 0; k < 2; k++)
	{
		x = 50;
		for (i = 0; i < 2; i++)
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
		y += dy; y += 10;
	}

	for (int j = 0; j < p; j++)
	{
		if (PtInRect(&kw[j], point))
		{

			CStdioFile inf(L"res.txt", CFile::modeCreate | CFile::modeWrite);
			switch (j)
			{
			case 0: ms = "1"; break;
			case 1: ms = "2"; break;
			case 2: ms = "3"; break;
			case 3: ms = "4"; break;
			}
			inf.WriteString(ms);
			inf.Flush();
			inf.Close();
		}
	}

	CStdioFile otf1(L"data.txt", CFile::modeRead);
	otf1.ReadString(ms);
	p = _wtoi(ms);
	otf1.Close();

	CStdioFile otf2(L"res.txt", CFile::modeRead);
	otf2.ReadString(ms);
	q = _wtoi(ms);
	otf2.Close();

	switch (p)
	{
	case 1:
		if (q == 2)
		{
			OnOK();
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 2:
		if (q == 3)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 3:
		if (q == 4)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 4:
		if (q == 1)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 5:
		if (q == 4)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 6:
		if (q == 2)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 7:
		if (q == 4)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 8:
		if (q == 3)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 9:
		if (q == 1)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	case 10:
		if (q == 3)
		{
			OnOK(); 
			CDialogR dlg;
			dlg.DoModal();
		}
		else
		{
			MessageBox(L"Вм помиляєтесь!", L"Помилка", MB_OK | MB_ICONINFORMATION);
			OnOK();
		}
		break;
	}

	CDialog::OnLButtonDown(nFlags, point);
}


void CDialogQ::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	OnOK();
	CDialog::OnLButtonDblClk(nFlags, point);
}


BOOL CDialogQ::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CDialogQ::OnPaint()
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
			PIC.LoadBitmapW(IDB_BITMAP4);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 2:
			PIC.LoadBitmapW(IDB_BITMAP5);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 3:
			PIC.LoadBitmapW(IDB_BITMAP6);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 4:
			PIC.LoadBitmapW(IDB_BITMAP7);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 5:
			PIC.LoadBitmapW(IDB_BITMAP8);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 6:
			PIC.LoadBitmapW(IDB_BITMAP9);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 7:
			PIC.LoadBitmapW(IDB_BITMAP10);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 8:
			PIC.LoadBitmapW(IDB_BITMAP11);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 9:
			PIC.LoadBitmapW(IDB_BITMAP12);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		case 10:
			PIC.LoadBitmapW(IDB_BITMAP23);
			mpic.SetBitmap(PIC);
			PIC.DeleteObject();
			break;
		}

		CClientDC dc(this);
		GetClientRect(&rc);

		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


		// TODO

		y = 235; dx = 180; dy = 40;
		p = 1;
		for (k = 0; k < 2; k++)
		{
			x = 50;
			for (i = 0; i < 2; i++)
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
			y += dy; y += 10;
		}

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);

		CDialog::OnPaint();
	}
}
