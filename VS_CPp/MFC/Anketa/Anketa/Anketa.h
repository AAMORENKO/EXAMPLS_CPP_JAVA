
// Anketa.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CAnketaApp:
// � ���������� ������� ������ ��. Anketa.cpp
//

class CAnketaApp : public CWinApp
{
public:
	CAnketaApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CAnketaApp theApp;