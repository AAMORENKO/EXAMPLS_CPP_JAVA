
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
	, N(1)
	, M(-1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	fg = true;

	SetWindowTextW(L"Program");
	DDX_Control(pDX, IDC_PIC, mpic);
	DDX_Control(pDX, IDC_E, E);
	DDX_Text(pDX, IDC_EDIT1, N);
	DDX_Text(pDX, IDC_EDIT2, M);
	E.SetWindowTextW(L"Hello, World!");
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

		hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
		hNew = CreateFont(28, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

		t = "це і є ТА САМА фраза";

		hold = (HFONT)SelectObject(dc, hNew);
		SetTextColor(dc, RGB(255,0,0));
		dc.TextOutW(540, 360, t, t.GetLength());

		hold = (HFONT)SelectObject(dc, hbk);

		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

