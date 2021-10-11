Програма графічних примітивів 
Хатинка, 
Пірамідка, 
Кольорові мішені - Квадрати, Круги

///////////////////////////////////////////////////////////////////

private:

	COLORREF cf, ck, c[25];
	HFONT hold, hNew, hbk;
	HPEN hPenOxy, hOldPen, pen;
	HBRUSH m, oldm, brush;
	CPen d, oldd;
	CBitmap pic;
	CRect rc, w, kw[30];

	CBrush br1, br2, br3;
	CRect ww;

	CString ms, t, z;

	int Matrix[50][50];
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int RH, RW, k, i, j, p, x, y, cx, cy, dx, dy;
	bool fg;

///////////////////////////////////////////////////////////////////

	CClientDC dc(this);
	GetClientRect(&rc);

	c[6] = 0x000000FF;
	c[5] = 0x000088FF;
	c[4] = 0x0000DDFF;
	c[3] = 0x000D820D;
	c[2] = 0x00FF9D3A;
	c[1] = 0x00945823;
	c[0] = 0x007A1B50;
	c[7] = 0xAA5600;
	c[8] = 0xAAAA;
	c[9] = 0x00CC00;
	c[10] = 0x090056;
	c[11] = 0xF0F0F0;

	dc.FillSolidRect(&rc, RGB(255, 255, 255));

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "Эта именно ТА САМАЯ фраза";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[0]);
	dc.TextOutW(75, 80, t, t.GetLength());
hold = (HFONT)SelectObject(dc, hbk);
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top + 200;
	w.bottom = rc.bottom;
	dc.FillSolidRect(&w, RGB(0, 0, 0));

	
///////////////////////////////////////////////////////////////////

	CClientDC dc(this);
	GetClientRect(&rc);

	c[6] = 0x000000FF;
	c[5] = 0x000088FF;
	c[4] = 0x0000DDFF;
	c[3] = 0x000D820D;
	c[2] = 0x00FF9D3A;
	c[1] = 0x00945823;
	c[0] = 0x007A1B50;
	c[7] = 0xAA5600;
	c[8] = 0xAAAA;
	c[9] = 0x00CC00;
	c[10] = 0x090056;
	c[11] = 0xF0F0F0;

	dc.FillSolidRect(&rc, RGB(255, 255, 255));
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

	SelectObject(dc, oldm);
	DeleteObject(m);
	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(55, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "Это мой домик";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[3]);
	dc.TextOutW(400, 320, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);

///////////////////////////////////////////////////////////////////




	CClientDC dc(this);
	GetClientRect(&rc);

	dc.FillSolidRect(&rc, RGB(255, 255, 255));
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;

	int  x1, y1, x2, y2;

	//piramidka

	COLORREF pir[7];
	CRect mp;
	HPEN hPenOxy, hOldPen;

	pir[6] = 0x000000FF;
	pir[5] = 0x000088FF;
	pir[4] = 0x0000DDFF;
	pir[3] = 0x000D820D;
	pir[2] = 0x00FF9D3A;
	pir[1] = 0x00945823;
	pir[0] = 0x007A1B50;

	x1 = w.left + 400;
	y1 = w.top + 100;
	x2 = w.right - 100;
	y2 = w.bottom - 80;

	int i, k, p;
	k = (x2 - x1) / 14;
	p = (y2 - y1) / 7;

	for (i = 0; i < 7; i++)
	{
		m = CreateSolidBrush(pir[6 - i]);
		oldm = (HBRUSH)SelectObject(dc, m);
		hPenOxy = CreatePen(PS_SOLID, 2, pir[6 - i]);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		//dc.Rectangle(x1+k*i, y1, x1+k*(i+1), y2);
		//dc.Rectangle(x1, y2-p*i, x2, y2-p*(i+1));

		mp.left = x1 + k*i;
		mp.top = y2 - p*i;
		mp.right = x2 - k*i;
		mp.bottom = y2 - p*(i + 1);

		mp.DeflateRect(1, 1);
		dc.RoundRect(&mp, CPoint(21, 21));
	}



	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(50, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Impact");

	t = "СПЕКТР - ПИРАМИДА";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[1]);
	dc.TextOutW(40, 320, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);

	SelectObject(dc, oldm);
	DeleteObject(m);
	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);
	DeleteObject(hNew);


///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////

	CClientDC dc(this);
	GetClientRect(&rc);
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;
	dc.FillSolidRect(&rc, RGB(255, 255, 255));

	COLORREF pir[7];
	HPEN hPenOxy, hOldPen;


	pir[6] = 0x000000FF;
	pir[5] = 0x000088FF;
	pir[4] = 0x0000FFFF;
	pir[3] = 0x00009400;
	pir[2] = 0x00FFBF00;
	pir[1] = 0x00E2383A;
	pir[0] = 0x00A90D8A;

	int  x1, y1, x2, y2;

	// Mishen-1
	x1 = w.left + 50;
	y1 = w.top + 100;
	x2 = w.right - 425;
	y2 = w.bottom - 80;

	int i, k, p;
	k = (x2 - x1) / 14;
	p = (y2 - y1) / 14;
	for (i = 0; i < 7; i++)
	{
		m = CreateSolidBrush(pir[6 - i]);
		oldm = (HBRUSH)SelectObject(dc, m);
		hPenOxy = CreatePen(PS_SOLID, 2, pir[6 - i]);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		dc.Rectangle(x1 + i*k, y1 + p*i, x2 - i*k, y2 - p*i);
	}

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "СПЕКТР - КВАДРАТИКИ";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[0]);
	dc.TextOutW(360, 320, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);



	SelectObject(dc, oldm);
	DeleteObject(m);
	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);
	DeleteObject(hNew);

///////////////////////////////////////////////////////////////////

	CClientDC dc(this);
	GetClientRect(&rc);
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;
	dc.FillSolidRect(&rc, RGB(255, 255, 255));

	COLORREF pir[7];
	HPEN hPenOxy, hOldPen;


	pir[6] = 0x000000FF;
	pir[5] = 0x000088FF;
	pir[4] = 0x0000FFFF;
	pir[3] = 0x00009400;
	pir[2] = 0x00FFBF00;
	pir[1] = 0x00E2383A;
	pir[0] = 0x00A90D8A;

	int  x1, y1, x2, y2;

	


	int i, k, p;
	
	//Mishen-2
	x1 = w.left + 400;
	y1 = w.top + 100;
	x2 = w.right - 75;
	y2 = w.bottom - 80;
k = (x2 - x1) / 14;
	p = (y2 - y1) / 14;

	for (i = 0; i < 7; i++)
	{
		m = CreateSolidBrush(pir[i]);
		oldm = (HBRUSH)SelectObject(dc, m);
		hPenOxy = CreatePen(PS_SOLID, 2, pir[i]);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		dc.Ellipse(x1 + i*k, y1 + p*i, x2 - i*k, y2 - p*i);
	}

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(56, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Opium");

	t = "СПЕКТР - КРУГИ";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[6]);
	dc.TextOutW(10, 200, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);


	SelectObject(dc, oldm);
	DeleteObject(m);
	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);
	DeleteObject(hNew);

///////////////////////////////////////////////////////////////////







