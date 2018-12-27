
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
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	pir[6] = 0x000000FF;
	pir[5] = 0x000088FF;
	pir[4] = 0x0000DDFF;
	pir[3] = 0x000D820D;
	pir[2] = 0x00FF9D3A;
	pir[1] = 0x00945823;
	pir[0] = 0x007A1B50;

	k = 0;

	fg = true;

	SetWindowTextW(L"Примитивы");
	DDX_Control(pDX, IDC_PIC, mpic);
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, &CProgramDlg::OnFileExit)
	ON_COMMAND(ID_FILE_PIC1, &CProgramDlg::OnFilePic1)
	ON_COMMAND(ID_FILE_PIC2, &CProgramDlg::OnFilePic2)
	ON_COMMAND(ID_FILE_PIC3, &CProgramDlg::OnFilePic3)
	ON_COMMAND(ID_FILE_PIC4, &CProgramDlg::OnFilePic4)
	ON_COMMAND(ID_FILE_RESET, &CProgramDlg::OnFileReset)
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
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgramDlg::OnFileExit()
{
	// TODO: Add your command handler code here
	if (MessageBox(TEXT("Ви дійсно бажаєте вийти ?"), TEXT("УВАГА!!!"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK) OnOK();

}


void CProgramDlg::OnFilePic1()
{
	// TODO: Add your command handler code here

	k = 1;

	CClientDC dc(this);
	GetClientRect(&rc);
	dc.FillSolidRect(&rc, RGB(255, 255, 255));
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;

	//stena
	x1 = w.left + 100;
	y1 = w.top + 200;
	x2 = x1 + 200;
	y2 = w.bottom - 80;
	m = CreateSolidBrush(0x0000FFFF);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x1, y1, x2, y2);

	//dver
	x = x1 + 40;
	y = y1 + 70;
	m = CreateSolidBrush(0x0023356E);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 - 110, y2);

	//okno
	x = x1 + 130;
	y = y1 + 40;
	m = CreateSolidBrush(0x00000000);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 - 20, y2 - 80);

	//swet v okne
	x += 9;
	y += 6;
	m = CreateSolidBrush(0x00D8B871);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 - 29, y2 - 120);
	y += 33;
	dc.Rectangle(x, y, x2 - 29, y2 - 85);

	//krusha
	x = x1 - 20;
	y = y1 - 30;
	m = CreateSolidBrush(0x0000650B);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 + 20, y2 - 196);

	//truba
	x = x1 + 154;
	y = y1 - 100;
	m = CreateSolidBrush(0x001E53DE);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 - 30, y2 - 226);

	SelectObject(dc, oldm);
	DeleteObject(m);
	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(55, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "Это мой домик";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, pir[3]);
	dc.TextOutW(400, 320, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);


}


void CProgramDlg::OnFilePic2()
{
	// TODO: Add your command handler code here
	k = 2;

	CClientDC dc(this);
	GetClientRect(&rc);
	dc.FillSolidRect(&rc, RGB(255, 255, 255));
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;

	//piramidka


	x1 = w.left + 400;
	y1 = w.top + 100;
	x2 = w.right - 100;
	y2 = w.bottom - 80;

	k = (x2 - x1) / 14;
	p = (y2 - y1) / 7;

	for (i = 0; i < 7; i++)
	{
		m = CreateSolidBrush(pir[6 - i]);
		oldm = (HBRUSH)SelectObject(dc, m);
		hPenOxy = CreatePen(PS_SOLID, 2, pir[6 - i]);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		//dc.Rectangle(x1+k*i, y1, x1+k*(i+1), y2);
		//dc.Rectangle(x1, y2-p*i, x2, y2-p*(i+1));

		mp.left = x1 + k*i;
		mp.top = y2 - p*i;
		mp.right = x2 - k*i;
		mp.bottom = y2 - p*(i + 1);

		mp.DeflateRect(1, 1);
		dc.RoundRect(&mp, CPoint(21, 21));
	}



	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(50, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Impact");

	t = "СПЕКТР - ПИРАМИДА";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, pir[1]);
	dc.TextOutW(40, 320, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);

	SelectObject(dc, oldm);
	DeleteObject(m);
	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);
	DeleteObject(hNew);



}


void CProgramDlg::OnFilePic3()
{
	// TODO: Add your command handler code here
	k = 3;

	CClientDC dc(this);
	GetClientRect(&rc);
	dc.FillSolidRect(&rc, RGB(255, 255, 255));
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;

	// Mishen-1
	x1 = w.left + 50;
	y1 = w.top + 100;
	x2 = w.right - 425;
	y2 = w.bottom - 80;

	k = (x2 - x1) / 14;
	p = (y2 - y1) / 14;
	for (i = 0; i < 7; i++)
	{
		m = CreateSolidBrush(pir[6 - i]);
		oldm = (HBRUSH)SelectObject(dc, m);
		hPenOxy = CreatePen(PS_SOLID, 2, pir[6 - i]);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		dc.Rectangle(x1 + i*k, y1 + p*i, x2 - i*k, y2 - p*i);
	}

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "СПЕКТР - КВАДРАТИКИ";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, pir[0]);
	dc.TextOutW(360, 320, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);



	SelectObject(dc, oldm);
	DeleteObject(m);
	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);
	DeleteObject(hNew);



}


void CProgramDlg::OnFilePic4()
{
	// TODO: Add your command handler code here
	k = 4;

	CClientDC dc(this);
	GetClientRect(&rc);
	dc.FillSolidRect(&rc, RGB(255, 255, 255));
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;


	//Mishen-2
	x1 = w.left + 400;
	y1 = w.top + 100;
	x2 = w.right - 75;
	y2 = w.bottom - 80;
	k = (x2 - x1) / 14;
	p = (y2 - y1) / 14;

	for (i = 0; i < 7; i++)
	{
		m = CreateSolidBrush(pir[i]);
		oldm = (HBRUSH)SelectObject(dc, m);
		hPenOxy = CreatePen(PS_SOLID, 2, pir[i]);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		dc.Ellipse(x1 + i*k, y1 + p*i, x2 - i*k, y2 - p*i);
	}

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(56, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Opium");

	t = "СПЕКТР - КРУГИ";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, pir[6]);
	dc.TextOutW(10, 200, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);


	SelectObject(dc, oldm);
	DeleteObject(m);
	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);
	DeleteObject(hNew);



}


void CProgramDlg::OnFileReset()
{
	// TODO: Add your command handler code here

	pic.LoadBitmapW(IDB_BITMAP1);
	mpic.SetBitmap(pic);
	pic.DeleteObject();
	fg = true;

}
