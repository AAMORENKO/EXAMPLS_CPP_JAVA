
// AnketaDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CAnketaDlg
class CAnketaDlg : public CDialog
{
// ��������
public:
	CAnketaDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANKETA_DIALOG };
#endif

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
	CString NAME1;
	CString NAME2;
	CString NAME3;
	CString DDMMYYYY;
	afx_msg void OnBnClickedButton1();
};
