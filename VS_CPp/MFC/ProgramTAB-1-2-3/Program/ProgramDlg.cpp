
// ProgramDlg.cpp : ���� ����������
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


CProgramDlg::CProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	srand((unsigned)time(NULL));
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);



	fg = true;

	SetWindowTextW(L"������� ����� � ��������. �������.");
	
	DDX_Control(pDX, IDC_T1, T1);
	DDX_Control(pDX, IDC_T2, T2);
	DDX_Control(pDX, IDC_T3, T3);

	T1.SetWindowTextW(L"\tTAB-1");
	T2.SetWindowTextW(L"TAB-2");
	T3.SetWindowTextW(L"\n\n\t\tTAB-3");

}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CProgramDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CProgramDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CProgramDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// ����������� ��������� CProgramDlg

BOOL CProgramDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CProgramDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgramDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	int A[30];
	int k, i, p;

	ms = "TAB-1: ";

	for (k = 0; k < 16; k++)
	{
		p = -1;
		for (i = 0; i < rand() % 9; i++) p *= (-1);
		A[k] = p*rand() % 99;
		t.Format(L"%5i", A[k]);
		ms += t;
	}
	T1.SetWindowTextW(ms);

}


void CProgramDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	int A[30];
	int k, i, p;

	ms = "TAB-2:\n";

	for (k = 0; k < 12; k++)
	{
		p = -1;
		for (i = 0; i < rand() % 9; i++) p *= (-1);
		A[k] = p*rand() % 99;
		t.Format(L"%4i\n", A[k]);
		ms += t;
	}
	T2.SetWindowTextW(ms);

}


void CProgramDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	int A[30][30];
	int k, i,j, p;

	ms = "TAB-3:\n";

	for (k = 0; k < 9; k++)
	{
		for (j = 0; j < 9; j++)
		{
			p = -1;
			for (i = 0; i < rand() % 9; i++) p *= (-1);
			A[k][j] = p*rand() % 99;
			t.Format(L"%5i", A[k][j]);
			ms += t;
		}
		ms += "\n";
	}
	T3.SetWindowTextW(ms);
}
