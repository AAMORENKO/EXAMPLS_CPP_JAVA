// Kw0.cpp : implementation file
//

#include "stdafx.h"
#include "newKvadratik.h"
#include "Kw0.h"
#include "afxdialogex.h"
#include "newKvadratikDlg.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;


IMPLEMENT_DYNAMIC(CKw0, CDialog)

CKw0::CKw0(CWnd* pParent /*=NULL*/)
	: CDialog(CKw0::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CKw0::~CKw0()
{
}

void CKw0::DoDataExchange(CDataExchange* pDX)
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

	CClientDC dc(this);
	GetClientRect(&rc);

	RH = abs(rc.right - rc.left);
	RW = abs(rc.bottom - rc.top);
	dx = RH / 15;
	dy = RW / 15;

	w.left = rc.left + dx;
	w.right = rc.right - dx;
	w.top = rc.top + dy;
	w.bottom = rc.bottom - dy;

	ClientToScreen(&w);
	ScreenToClient(&w);

	CStdioFile otf;
	otf.Open(L"data.txt", CFile::modeRead);
	
	otf.ReadString(ms);
	otf.Close();

	k=_wtoi(ms);
	
	switch (k)
	{
		case 0: SetWindowTextW(L"Розовый");
			cf = c[0];
			break;
		case 1: SetWindowTextW(L"Бирюзовый");
			cf = c[1];
			break;
		case 2: SetWindowTextW(L"Желтый");
			cf = c[2];
			break;
		case 3: SetWindowTextW(L"Зеленый");
			cf = c[3];
			break;
		case 4: SetWindowTextW(L"Коричневый");
			cf = c[4];
			break;
		case 5: SetWindowTextW(L"Черный");
			cf = c[5];
			break;
	}
	


}


BEGIN_MESSAGE_MAP(CKw0, CDialog)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CKw0 message handlers


void CKw0::OnPaint()
{
	if (IsIconic()&&fg)
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
		ClientToScreen(&rc);
		ScreenToClient(&rc);

		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		rc.DeflateRect(5, 5);
		dc.RoundRect(&rc, CPoint(45, 45));
		DeleteObject(m);
		SelectObject(dc, oldm);
		fg = false;
	}
	
	CDialog::OnPaint();
	
}


void CKw0::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	

	CClientDC dc(this);
	GetClientRect(&rc);

	m = CreateSolidBrush(cf);
	oldm = (HBRUSH)dc.SelectObject(m);


	if (PtInRect(&w, point))
	{
		

		switch (k)
		{
		case 0: cf = c[6];
			break;
		case 1: cf = c[7];
			break;
		case 2: cf = c[8];
			break;
		case 3: cf = c[9];
			break;
		case 4: cf = c[10];
			break;
		case 5: cf = c[11];
			break;
		}


		rc.DeflateRect(5, 5);
		dc.RoundRect(&rc, CPoint(45, 45));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
	
		switch (k)
		{
		case 0: cf = c[0];
			break;
		case 1: cf = c[1];
			break;
		case 2: cf = c[2];
			break;
		case 3: cf = c[3];
			break;
		case 4: cf = c[4];
			break;
		case 5: cf = c[5];
			break;
		}
	
		rc.DeflateRect(5, 5);
		dc.RoundRect(&rc, CPoint(45, 45));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}

	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);

	CDialog::OnMouseMove(nFlags, point);
}


void CKw0::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CClientDC dc(this);
	GetClientRect(&rc);

	if (PtInRect(&w, point)&&(k!=5))
	{

    	cf = c[5];
		dc.FillSolidRect(&rc, cf);
		Sleep(mtime_0);

		OnOK();
	}
	else
	{
		cf = c[5];
		dc.FillSolidRect(&rc, cf);
		Sleep(mtime_0);

		if (MessageBox(L"Вы действительно хотите выйти?", L"ВЫХОД", MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			OnOK();
		}
		else
		{
			OnOK();
			CnewKvadratikDlg dlg;
			dlg.DoModal();
		}
	}
	

	CDialog::OnLButtonDown(nFlags, point);
}
