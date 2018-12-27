
// KavaDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Kava.h"
#include "KavaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CKavaDlg



CKavaDlg::CKavaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKavaDlg::IDD, pParent)
	, M(8.55)
	, N(3)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKavaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	SetWindowTextW(L"Кав'ярня \"Ароматна Кава\"");
	DDX_Control(pDX, IDC_COMBO1, mcombo);
	DDX_Text(pDX, IDC_EDIT1, M);
	DDX_Text(pDX, IDC_EDIT2, N);
}

BEGIN_MESSAGE_MAP(CKavaDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CKavaDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CKavaDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// обработчики сообщений CKavaDlg

BOOL CKavaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	mcombo.SetCurSel(0);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CKavaDlg::OnPaint()
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
HCURSOR CKavaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKavaDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString SORT[5] = { L"Суматра", L"Бразілія", L"Колумбія", L"Ява", L"Ефіопія" };
	double cena[5] = { 8.55, 11.60, 6.10, 8.25, 6.55 };

	int pos;
	pos = mcombo.GetCurSel();


	double sum = 0;

	int n;

	UpdateData(true);
	n = N;
	UpdateData(false);

	sum = n*cena[pos];

	ms.Format(L"Загальна вартість: %5.2f грн.", sum);
	MessageBox(ms);




}


void CKavaDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	CString SORT[5] = { L"Суматра", L"Бразілія", L"Колумбія", L"Ява", L"Ефіопія" };
	double cena[5] = { 8.55, 11.60, 6.10, 8.25, 6.55 };

	int pos;
	pos = mcombo.GetCurSel();

	UpdateData(true);
	M = cena[pos];
	UpdateData(false);

}
