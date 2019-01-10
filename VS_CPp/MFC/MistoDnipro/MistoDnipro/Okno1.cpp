// Okno1.cpp : implementation file
//

#include "stdafx.h"
#include "MistoDnipro.h"
#include "Okno1.h"
#include "afxdialogex.h"
#include "MistoDniproDlg.h"


// COkno1 dialog

IMPLEMENT_DYNAMIC(COkno1, CDialog)

COkno1::COkno1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

COkno1::~COkno1()
{
}

void COkno1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	SetWindowTextW(L"Google впроваджує новітні сервіси");
}


BEGIN_MESSAGE_MAP(COkno1, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &COkno1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COkno1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON12, &COkno1::OnBnExit)
END_MESSAGE_MAP()


// COkno1 message handlers


BOOL COkno1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void COkno1::OnPaint()
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
		CDialog::OnPaint();
	}
}


void COkno1::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CMistoDniproDlg dlg;
	OnOK();
	dlg.DoModal();
}


void COkno1::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}


void COkno1::OnBnExit()
{
	// TODO: Add your control notification handler code here
	if (MessageBox(L"Ви бажаєте вийти?", L"Вікно завершення роботи", MB_YESNO | MB_ICONQUESTION) == IDYES) OnOK();
}
