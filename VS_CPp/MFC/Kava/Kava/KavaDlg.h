
// KavaDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CKavaDlg
class CKavaDlg : public CDialog
{
// Создание
public:
	CKavaDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_KAVA_DIALOG };

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
public:
	afx_msg void OnBnClickedOk();
	CComboBox mcombo;

public:
	CString S, ms;
	CString SORT[5];
	double cena[5];

	afx_msg void OnCbnSelchangeCombo1();
	double M;
	int N;
};
