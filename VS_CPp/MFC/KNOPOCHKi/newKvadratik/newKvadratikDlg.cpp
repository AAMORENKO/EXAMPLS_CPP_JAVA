
// newKvadratikDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "newKvadratik.h"
#include "newKvadratikDlg.h"
#include "afxdialogex.h"
#include "Kw0.h"
#include <fstream>
using namespace std;



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CnewKvadratikDlg



CnewKvadratikDlg::CnewKvadratikDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CnewKvadratikDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CnewKvadratikDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	c[0] = 0xFF00FF;
	c[1] = 0xFFA500;
	c[2] = 0xFFFF;
	c[3] = 0x0C7800;
	c[4] = 0x005690;
	c[5] = 0xFFFF0000;
	c[6] = 0xCC00AA;
	c[7] = 0xAA5600;
	c[8] = 0xAAAA;
	c[9] = 0x00CC00;
	c[10] = 0x090056;
	c[11] = 0xF0F0F0;

	fg = true;

	SetWindowTextW(L"Цветные квадраты");


}

BEGIN_MESSAGE_MAP(CnewKvadratikDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// обработчики сообщений CnewKvadratikDlg

BOOL CnewKvadratikDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CnewKvadratikDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		CClientDC dc(this);
		GetClientRect(&rc);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.right - rc.left);
		RW = abs(rc.top - rc.bottom);

		dx = RH / 3;
		dy = RW / 2;
		j = 0;
		for (k = 0; k < 2; k++)
		{
			for (i = 0; i < 3; i++)
			{
				cf = c[j];
				m = CreateSolidBrush(cf);
				oldm = (HBRUSH)dc.SelectObject(m);
				w.top = k*dy;
				w.bottom = (k + 1)*dy;
				w.left = i*dx;
				if (i == 2)
				{
					w.right = (i + 1)*dx + 1;
				}
				else
				{
					w.right = (i + 1)*dx;
				}
				w.DeflateRect(1, 1);
				dc.RoundRect(&w, CPoint(25, 25));
				j++;
				DeleteObject(m);
				SelectObject(dc, oldm);
			}
		}
		
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CnewKvadratikDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CnewKvadratikDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	CClientDC dc(this);
	GetClientRect(&rc);
	RH = abs(rc.right - rc.left);
	RW = abs(rc.bottom - rc.top);
	dx = RH / 3;
	dy = RW / 2;
	j = 0;
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 3; i++)
		{
			w.top = k*dy;
			w.bottom = (k + 1)*dy;
			w.left = i*dx;
			w.right = (i + 1)*dx;
			kw[j] = w;
			j++;
		}
	}


	if (PtInRect(&kw[0], point))
	{
		cf = c[6];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[0].DeflateRect(1, 1);
		dc.RoundRect(&kw[0], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
		cf = c[0];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[0].DeflateRect(1, 1);
		dc.RoundRect(&kw[0], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}


	if (PtInRect(&kw[1], point))
	{
		cf = c[7];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[1].DeflateRect(1, 1);
		dc.RoundRect(&kw[1], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
		cf = c[1];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[1].DeflateRect(1, 1);
		dc.RoundRect(&kw[1], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}


	if (PtInRect(&kw[2], point))
	{
		cf = c[8];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[2].DeflateRect(1, 1);
		dc.RoundRect(&kw[2], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
		cf = c[2];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[2].DeflateRect(1, 1);
		dc.RoundRect(&kw[2], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}


	if (PtInRect(&kw[3], point))
	{
		cf = c[9];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[3].DeflateRect(1, 1);
		dc.RoundRect(&kw[3], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
		cf = c[3];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[3].DeflateRect(1, 1);
		dc.RoundRect(&kw[3], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}


	if (PtInRect(&kw[4], point))
	{
		cf = c[10];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[4].DeflateRect(1, 1);
		dc.RoundRect(&kw[4], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
		cf = c[4];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[4].DeflateRect(1, 1);
		dc.RoundRect(&kw[4], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}

	if (PtInRect(&kw[5], point))
	{
		cf = c[11];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[5].DeflateRect(1, 1);
		dc.RoundRect(&kw[5], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
		cf = c[5];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[5].DeflateRect(1, 1);
		dc.RoundRect(&kw[5], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}


	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);

	CDialog::OnMouseMove(nFlags, point);
}


void CnewKvadratikDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	GetClientRect(&rc);
	RH = abs(rc.right - rc.left);
	RW = abs(rc.bottom - rc.top);
	dx = RH / 3;
	dy = RW / 2;
	j = 0;
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 3; i++)
		{
			w.top = k*dy;
			w.bottom = (k + 1)*dy;
			w.left = i*dx;
			w.right = (i + 1)*dx;
			kw[j] = w;
			j++;
		}
	}

	CStdioFile inf(L"data.txt", CFile::modeCreate | CFile::modeWrite);
	
	

	if (PtInRect(&kw[0], point))
	{
		ms = "0";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		CKw0 dlg;
		dlg.DoModal();
	}
	
	if (PtInRect(&kw[1], point))
	{
		ms = "1";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		CKw0 dlg;
		dlg.DoModal();
	}

	if (PtInRect(&kw[2], point))
	{
		ms = "2";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		CKw0 dlg;
		dlg.DoModal();
	}

	if (PtInRect(&kw[3], point))
	{
		ms = "3";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		CKw0 dlg;
		dlg.DoModal();
	}

	if (PtInRect(&kw[4], point))
	{
		ms = "4";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		CKw0 dlg;
		dlg.DoModal();
	}

	if (PtInRect(&kw[5], point))
	{
		ms = "5";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		OnOK();
		CKw0 dlg;
		dlg.DoModal();
	}

	CDialog::OnLButtonDown(nFlags, point);
}
