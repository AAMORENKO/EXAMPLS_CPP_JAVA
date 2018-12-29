
// ProgramDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"

#define mtime 298
#define pi 3.14159265358979323846

// диалоговое окно CProgramDlg
class CProgramDlg : public CDialog
{
// Создание
public:
	CProgramDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:

	HPEN hPenOxy, hOldPen;
	//HBRUSH m, oldm, brush;
	//HPEN pen;

	COLORREF cf, c[25];

	//CPen d, oldd;
	CBitmap pic;
	CRect rc, w, kw[40];
	int SCn, counter[40];
	int inder1, inder2, inder3;
	//int mpc1, mpc2, mpc3;
	CString ms, t, z;

	//int Matrix[50][50];
	int RH, RW, k, i, j, cx, cy, dx, dy, x1,y1,x2,y2;
	//bool fg;


public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnCancel();
	CStatic mpic;
};
