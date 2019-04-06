// Відео за посиланням: В РОЗРОБЦІ

/*
Розробити програму STEaMProjectApp для
керування діалоговими вікнами з кнопками,
які реагують на вказівник і натискання миші
та викликають 	додаткове вікно

файл ресурсів: 
knopki.bmp https://miwzua.com/archiv/ONLY-F/knopki.bmp
STEaMProjectApp.ico  https://miwzua.com/archiv/ONLY-F/STEaMProjectApp.ico 
*/

// -----------------------------------------------------
private:

	COLORREF cf, c[25];
	HFONT hold, hNew, hbk;
	HPEN hPenOxy, hOldPen, pen;
	HBRUSH m, oldm, brush;
	CPen d, oldd;
	CBitmap pic;
	CRect rc, w, kw[30];

	CString ms, t, z;

	int Matrix[50][50];
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int RH, RW, k, i, j, p, x, y, cx, cy, dx, dy;
	bool fg;

	int Fx[30];

// ----------------------------------------

public:


	CBitmap PIC;
	CRect Next, Back, Sps;
	CWnd *WndPtr;


// -----------------------------------------------------

	WndPtr = GetDlgItem(IDC_PIC1);
	WndPtr->GetWindowRect(&Next);
	ScreenToClient(&Next);


	mcombo.SetCurSel(0);

// -----------------------------------------------------

	int poz = mcombo.GetCurSel();

	switch (poz)
	{
	case 0:
	{
		PIC.LoadBitmapW(IDB_BITMAP8);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		break;
	}
	case 1:
	{
		PIC.LoadBitmapW(IDB_BITMAP1);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		break;
	}	
	}


// -----------------------------------------------------


	if (PtInRect(&Next, point))
	{
		PIC.LoadBitmapW(IDB_BITMAP28);
		mpic1.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(20);
	}
	else
	{
		PIC.LoadBitmapW(IDB_BITMAP20);
		mpic1.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(20);
	}

// -----------------------------------------------------

	if (PtInRect(&Back, point))
	{
		if (MessageBox(L"Повертаємось до головного вікна програми?", L"Вікно -> Повернутись до головної програми", MB_YESNO | MB_ICONQUESTION) == IDYES) OnOK();
	}


// -----------------------------------------------------

	if (PtInRect(&Sps, point))
	{
		MessageBox(L"Натиснуто праву кнопку миші", L"Увага!", MB_OK|MB_ICONASTERISK);
	}

﻿// -----------------------------------------------------------------------

		x1 = rc.left + 5;
		y1 = rc.top + 5;
		x2 = rc.right - 5;
		y2 = rc.bottom - 5;
		dc.Rectangle(x1, y1, x2, y2);

		x1 += 45;
		y1 += 45;
		x2 -= 45;
		y2 -= 45;
		dc.Rectangle(x1, y1, x2, y2);

		dx = abs(x2 - x1) / 4;
		dy = abs(y2 - y1) / 4;

		p = 0;
		for (k = 0; k < 4; k++)
		{
			x = x1; y = y1;
			for (i = 0; i < 4; i++)
			{
				w.left = x + i * dx + 1;
				w.top = y + k * dy + 1;
				w.right = x + i * dx + dx - 1;
				w.bottom = y + k * dy + dy - 1;
				kw[p] = w; p++;
				dc.Rectangle(&w);
			}
		}


// -----------------------------------------------------------------------

	for (k = 0; k < p; k++)
	{
		if (PtInRect(&kw[k], point))
		{
			dc.FillSolidRect(&kw[k], RGB(105, 105, 105));
		}
		else
		{
			dc.FillSolidRect(&kw[k], RGB(255, 255, 255));
		}
	}

// -----------------------------------------------------------------------

	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);

// -----------------------------------------------------------------------

	if (MessageBox(L"Бажаєте вийти з програми?", 
				L"Вікно виходу", 
				MB_YESNO | MB_ICONQUESTION) == IDYES) exit(0);

// -----------------------------------------------------------------------

		hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
		hNew = CreateFont(28, 0, 0, 0,
			FW_NORMAL,
			0, 0, 0,
			ANSI_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Arial");
		hold = (HFONT)SelectObject(dc, hNew);

		
		// TO DO

		hold = (HFONT)SelectObject(dc, hbk);

// -----------------------------------------------------------------------

		CClientDC dc(this);
		GetClientRect(&rc);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH/2;
		cy = RW/2;
	
		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


		// TODO


		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		

// -----------------------------------------------------------------------

	setlocale(LC_ALL, "rus");

	CStdioFile inf(L"data.txt",CFile::modeCreate|CFile::modeWrite);
	
	k=wcslen(ms);


	inf.WriteString(ms);
	inf.Flush();
	inf.Close();

	CStdioFile otf(L"data.txt",CFile::modeRead);
	otf.ReadString(ms);
	j=wcslen(ms);
	otf.Close();

// -----------------------------------------------------

