
// CactusSmailProgramDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CCactusSmailProgramDlg dialog
class CCactusSmailProgramDlg : public CDialog
{
// Construction
public:
	CCactusSmailProgramDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CACTUSSMAILPROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	CRect w;

	CStatic mpic;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
