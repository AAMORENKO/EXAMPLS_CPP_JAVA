
// Kava.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CKavaApp:
// О реализации данного класса см. Kava.cpp
//

class CKavaApp : public CWinApp
{
public:
	CKavaApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CKavaApp theApp;