
// newKvadratik.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CnewKvadratikApp:
// � ���������� ������� ������ ��. newKvadratik.cpp
//

class CnewKvadratikApp : public CWinApp
{
public:
	CnewKvadratikApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CnewKvadratikApp theApp;