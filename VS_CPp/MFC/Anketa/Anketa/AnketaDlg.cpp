
// AnketaDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Anketa.h"
#include "AnketaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CAnketaDlg



CAnketaDlg::CAnketaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ANKETA_DIALOG, pParent)
	, NAME1(_T("Сірко"))
	, NAME2(_T("Іван"))
	, NAME3(_T("Омельянович"))
	, DDMMYYYY(_T("21-07-1956"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnketaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, NAME1);
	DDX_Text(pDX, IDC_EDIT2, NAME2);
	DDX_Text(pDX, IDC_EDIT3, NAME3);
	DDX_Text(pDX, IDC_EDIT4, DDMMYYYY);
}

BEGIN_MESSAGE_MAP(CAnketaDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAnketaDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// обработчики сообщений CAnketaDlg

BOOL CAnketaDlg::OnInitDialog()
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

void CAnketaDlg::OnPaint()
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
HCURSOR CAnketaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAnketaDlg::OnBnClickedButton1()
{
	// визначення змінних для програми
	CString ms, name1, name2, name3, ddmmyyyy;

	// читання даних з форми
	UpdateData(true);
	name1 = NAME1;
	name2 = NAME2;
	name3 = NAME3;
	ddmmyyyy = DDMMYYYY;
	UpdateData(false);

	// підготовка повідомлення
	ms = "Ви ввели наступні дані\n\n";
	//ms += "   Прізвище: ";
	ms += name1;
	ms += "\n";
	//ms += "\n       Ім`я: ";
	ms += name2;
	ms += "\n";
	//ms += "\nПо батькові: ";
	ms += name3;
	ms += "\n";
	//ms += "\n дд-мм-рррр: ";
	ms += ddmmyyyy;

	// виведення повідомлення окремим вікном
	MessageBox(ms, L"Перевірка", MB_OK | MB_ICONINFORMATION);

}
