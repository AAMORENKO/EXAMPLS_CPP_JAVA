
// ProgramDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CProgramDlg



CProgramDlg::CProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgramDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
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

	SetWindowTextW(L"Это Моя Графическая Программа");

}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// обработчики сообщений CProgramDlg

BOOL CProgramDlg::OnInitDialog()
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

void CProgramDlg::OnPaint()
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
		
		w.left = rc.left;
		w.right = rc.right;
		w.top = rc.top;
		w.bottom = rc.bottom;


		int x, y, x1, y1, x2, y2;

		// dom
		x1 = w.left + 100;
		y1 = w.top + 200;
		x2 = x1 + 200;
		y2 = w.bottom - 80;
		m = CreateSolidBrush(c[2]);
		oldm = (HBRUSH)SelectObject(dc, m);
		dc.Rectangle(x1, y1, x2, y2);

		// dver
		x = x1 + 40;
		y = y1 + 70;
		m = CreateSolidBrush(c[10]);
		oldm = (HBRUSH)SelectObject(dc, m);
		dc.Rectangle(x, y, x2-110, y2);

		//okno
		x = x1 + 130;
		y = y1 + 40;
		m = CreateSolidBrush(c[5]);
		oldm = (HBRUSH)SelectObject(dc, m);
		dc.Rectangle(x, y, x2 - 20, y2-80);

		//svet v okne
		x += 9;
		y += 6;
		m = CreateSolidBrush(c[1]);
		oldm = (HBRUSH)SelectObject(dc, m);
		dc.Rectangle(x, y, x2 - 29, y2 - 120);
		y += 33;
		dc.Rectangle(x, y, x2 - 29, y2 - 85);

		//krusha
		x = x1 - 20;
		y = y1 - 30;
		m = CreateSolidBrush(c[3]);
		oldm = (HBRUSH)SelectObject(dc, m);
		dc.Rectangle(x, y, x2 + 20, y2 - 196);

		//truba
		x = x1 + 154;
		y = y1 - 100;
		m = CreateSolidBrush(RGB(255,0,0));
		oldm = (HBRUSH)SelectObject(dc, m);
		dc.Rectangle(x, y, x2 - 30, y2 - 226);

		SelectObject(dc, oldm);
		DeleteObject(m);


		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

