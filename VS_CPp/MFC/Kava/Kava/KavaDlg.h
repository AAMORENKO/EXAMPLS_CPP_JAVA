
// KavaDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� CKavaDlg
class CKavaDlg : public CDialog
{
// ��������
public:
	CKavaDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_KAVA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
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
