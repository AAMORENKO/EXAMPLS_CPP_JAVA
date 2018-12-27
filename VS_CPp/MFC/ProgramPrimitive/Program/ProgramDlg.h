
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

	COLORREF cf, c[25], pir[7];

	HFONT hold, hNew, hbk;
	HBRUSH m, oldm;
	HPEN hPenOxy, hOldPen;

	CPen d, oldd;
	CBitmap pic;
	CRect mp, rc, w, kw[12];

	CString ms, t, z;

	int Matrix[50][50];
	int RH, RW, k, i, p, j, cx, cy, dx, dy;
	int x, y, x1, y1, x2, y2;
	bool fg;


public:
	afx_msg void OnFileExit();
	afx_msg void OnFilePic1();
	afx_msg void OnFilePic2();
	afx_msg void OnFilePic3();
	afx_msg void OnFilePic4();
	CStatic mpic;
	afx_msg void OnFileReset();
};
