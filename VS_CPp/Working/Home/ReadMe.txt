Задача: Графічні примітиви. Будинок.

Інструменти: // ---------------------- HomeDlg.h

private:

	HFONT hold, hNew, hbk;
	COLORREF cf, c[25];

	HBRUSH m, oldm;
	CPen d, oldd;
	HPEN hPenOxy,hOldPen;

	CBitmap pic;
	CRect rc, w;

	CString ms, z, t;
	int RH, RW, k, i, j, cx, cy, dx, dy;
	bool fg;

Процедура малювання OnPaint // ---------------------- HomeDlg.cpp

	CClientDC dc(this);
	GetClientRect(&rc);

	dc.FillSolidRect(&rc, RGB(255, 255, 255));

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "Це мій будинок";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[5]);
	dc.TextOutW(75, 80, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);

	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;

	int x, y, x1, y1, x2, y2;

	//stena
	x1 = w.left + 100;
	y1 = w.top + 200;
	x2 = x1 + 200;
	y2 = w.bottom - 80;
	m = CreateSolidBrush(0x0000FFFF);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x1, y1, x2, y2);

	//dver
	x = x1 + 40;
	y = y1 + 70;
	m = CreateSolidBrush(0x0023356E);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 - 110, y2);

	//okno
	x = x1 + 130;
	y = y1 + 40;
	m = CreateSolidBrush(0x00000000);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 - 20, y2 - 80);

	//swet v okne
	x += 9;
	y += 6;
	m = CreateSolidBrush(0x00D8B871);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 - 29, y2 - 120);
	y += 33;
	dc.Rectangle(x, y, x2 - 29, y2 - 85);

	//krusha
	x = x1 - 20;
	y = y1 - 30;
	m = CreateSolidBrush(0x0000650B);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 + 20, y2 - 196);

	//truba
	x = x1 + 154;
	y = y1 - 100;
	m = CreateSolidBrush(0x001E53DE);
	oldm = (HBRUSH)SelectObject(dc, m);
	dc.Rectangle(x, y, x2 - 30, y2 - 226);


	DeleteObject(m);
	SelectObject(dc, oldm);