#pragma once


// COkno1 dialog

class COkno1 : public CDialog
{
	DECLARE_DYNAMIC(COkno1)

public:
	COkno1(CWnd* pParent = NULL);   // standard constructor
	virtual ~COkno1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnExit();
};
