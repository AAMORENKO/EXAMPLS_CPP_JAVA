
// Kava.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CKavaApp:
// � ���������� ������� ������ ��. Kava.cpp
//

class CKavaApp : public CWinApp
{
public:
	CKavaApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CKavaApp theApp;