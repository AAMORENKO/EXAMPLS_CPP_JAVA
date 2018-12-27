
// newKvadratikDlg.h : файл заголовка
//

#pragma once


#define mtime 50

// диалоговое окно CnewKvadratikDlg
class CnewKvadratikDlg : public CDialog
{
// Создание
public:
	CnewKvadratikDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_NEWKVADRATIK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:

	HFONT hold, hNew, hbk;
	COLORREF cf, c[25];
	HBRUSH m, oldm;
	CPen d, oldd;
	CString ms, t;
	CRect rc,w,kw[6];

	int RH, RW, k, i, j, dx, dy, cx, cy;

	bool fg;

	DECLARE_MESSAGE_MAP()
};
