
// ProgramDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#include <time.h>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CProgramDlg



CProgramDlg::CProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	srand((unsigned)time(NULL));
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	SetWindowTextW(L"Обробка даних в таблиці");
	DDX_Control(pDX, IDC_E1, E1);
	DDX_Control(pDX, IDC_E2, E2);

	E1.SetWindowTextW(L"\n\n\n\n\tНатисніть кнопку <ПОШУК>");
	E2.SetWindowTextW(L"\nРезультати пошуку\n\nПОРОЖНЬО");
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CProgramDlg::OnBnClickedButton1)
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



void CProgramDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	ms="\nРезультати пошуку\n\n";
	t = "\n\tДана таблиця M[10][10]:\n";
	CString w;
	int M[50][50];
	int sum = 0;
	int n = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			p = -1;
			for (k = 0; k < rand() % 10; k++) p *= (-1);
			M[i][j] = p*  rand() % 100;
			if (M[i][j] < 0)
			{
				sum += M[i][j];
				n++;
			}
			w.Format(L"%6i", M[i][j]);
			t += w;
		}
		t += "\n";
	}

	int seredne = sum / n;
	w.Format(L"MiD=%4i", seredne);
	ms += w;

	E1.SetWindowTextW(t);
	E2.SetWindowTextW(ms);

}
