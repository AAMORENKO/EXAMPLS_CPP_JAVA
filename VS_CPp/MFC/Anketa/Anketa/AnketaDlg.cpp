
// AnketaDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Anketa.h"
#include "AnketaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAnketaDlg



CAnketaDlg::CAnketaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ANKETA_DIALOG, pParent)
	, NAME1(_T("ѳ���"))
	, NAME2(_T("����"))
	, NAME3(_T("�����������"))
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


// ����������� ��������� CAnketaDlg

BOOL CAnketaDlg::OnInitDialog()
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

void CAnketaDlg::OnPaint()
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
HCURSOR CAnketaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAnketaDlg::OnBnClickedButton1()
{
	// ���������� ������ ��� ��������
	CString ms, name1, name2, name3, ddmmyyyy;

	// ������� ����� � �����
	UpdateData(true);
	name1 = NAME1;
	name2 = NAME2;
	name3 = NAME3;
	ddmmyyyy = DDMMYYYY;
	UpdateData(false);

	// ��������� �����������
	ms = "�� ����� ������� ���\n\n";
	//ms += "   �������: ";
	ms += name1;
	ms += "\n";
	//ms += "\n       ��`�: ";
	ms += name2;
	ms += "\n";
	//ms += "\n�� �������: ";
	ms += name3;
	ms += "\n";
	//ms += "\n ��-��-����: ";
	ms += ddmmyyyy;

	// ��������� ����������� ������� �����
	MessageBox(ms, L"��������", MB_OK | MB_ICONINFORMATION);

}
