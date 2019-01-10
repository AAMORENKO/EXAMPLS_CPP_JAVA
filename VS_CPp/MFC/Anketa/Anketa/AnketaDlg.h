
// AnketaDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CAnketaDlg
class CAnketaDlg : public CDialog
{
// Создание
public:
	CAnketaDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANKETA_DIALOG };
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
public:
	CString NAME1;
	CString NAME2;
	CString NAME3;
	CString DDMMYYYY;
	afx_msg void OnBnClickedButton1();
};
