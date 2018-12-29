#pragma once


// CDintro dialog

class CDintro : public CDialogEx
{
	DECLARE_DYNAMIC(CDintro)

public:
	CDintro(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDintro();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTRO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};
