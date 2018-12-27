
// newKvadratik.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CnewKvadratikApp:
// О реализации данного класса см. newKvadratik.cpp
//

class CnewKvadratikApp : public CWinApp
{
public:
	CnewKvadratikApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CnewKvadratikApp theApp;