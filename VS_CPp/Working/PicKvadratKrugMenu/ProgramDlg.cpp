//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////
		
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
		hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, 
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
			DEFAULT_PITCH | FF_DONTCARE, L"Penta");

		t = "Эта именно ТА САМАЯ фраза";

		hold = (HFONT)SelectObject(dc, hNew);
		SetTextColor(dc, c[7]);
		dc.TextOutW(75, 80, t, t.GetLength());
		hold = (HFONT)SelectObject(dc, hbk);
		w.left = rc.left;
		w.right = rc.right;
		w.top = rc.top + 200;
		w.bottom = rc.bottom;
		dc.FillSolidRect(&w, RGB(0, 0, 0));
//////////////////////////////////////////////////////////////////////////////
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

	dc.FillSolidRect(&rc, RGB(0, 0, 0));

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "Квадрати";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[11]);
	dc.TextOutW(75, 380, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);
	
	x1=w.left = rc.left;
	x2=w.right = rc.right;
	y1=w.top = rc.top;
	y2=w.bottom = rc.bottom;
	
	w.left = x1 + 380;
	w.right = x2 -100;
	w.top = y1 + 100;
	w.bottom = y2 - 100;


	kw[0].left = x1 + 380;
	kw[0].right = x2 - 100;
	kw[0].top = y1 + 100;
	kw[0].bottom = y2 - 100;

	CBrush br1(c[9]);
	dc.FillRect(&kw[0], &br1);

	kw[1].left = x1 + 400;
	kw[1].right = x2 - 430;
	kw[1].top = y1 + 400;
	kw[1].bottom = y2 - 120;

	CBrush br2(c[4]);
	dc.FillRect(&kw[1], &br2);

	kw[2].left = x1 + 550;
	kw[2].right = x2 - 120;
	kw[2].top = y1 + 130;
	kw[2].bottom = y2 - 220;

	CBrush br3(c[7]);
	dc.FillRect(&kw[2], &br3);
//////////////////////////////////////////////////////////////////////////////
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

	dc.FillSolidRect(&rc, RGB(0, 0, 0));

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "Круги";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[11]);
	dc.TextOutW(75, 380, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);

	x1 = w.left = rc.left;
	x2 = w.right = rc.right;
	y1 = w.top = rc.top;
	y2 = w.bottom = rc.bottom;

	w.left = x1 + 380;
	w.right = x2 - 100;
	w.top = y1 + 100;
	w.bottom = y2 - 100;


	kw[0].left = x1 + 380;
	kw[0].right = x2 - 100;
	kw[0].top = y1 + 100;
	kw[0].bottom = y2 - 100;

	CBrush br1(c[9]);
	SelectObject(dc, br1);
	dc.Ellipse(&kw[0]);

	kw[1].left = x1 + 400;
	kw[1].right = x2 - 430;
	kw[1].top = y1 + 400;
	kw[1].bottom = y2 - 120;

	CBrush br2(c[4]);
	SelectObject(dc, br2);
	dc.Ellipse(&kw[1]);

	kw[2].left = x1 + 550;
	kw[2].right = x2 - 120;
	kw[2].top = y1 + 130;
	kw[2].bottom = y2 - 220;

	CBrush br3(c[7]);
	SelectObject(dc, br3);
	dc.Ellipse(&kw[2]);

////////////////////////////////////////////////////////////////////////////////

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

	dc.FillSolidRect(&rc, RGB(0, 0, 0));

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

	t = "Трикутники";

	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[4]);
	dc.TextOutW(35, 80, t, t.GetLength());
	hold = (HFONT)SelectObject(dc, hbk);

	x1 = w.left = rc.left;
	x2 = w.right = rc.right;
	y1 = w.top = rc.top;
	y2 = w.bottom = rc.bottom;

	x1 = w.left + 300;
	y1 = w.top + 60;

	x2 = x1 + 500;
	y2 = y1 + 80;

	x3 = x2 - 200;
	y3 = y2 + 420;

	CBrush br1(c[2]);
	SelectObject(dc, br1);

	pen = CreatePen(PS_SOLID, 3, c[7]);
	SelectObject(dc,pen);

	dc.MoveTo(x1, y1);
	dc.LineTo(x2, y2);
	dc.LineTo(x3, y3);
	dc.LineTo(x1, y1);
	dc.FloodFill(x1 + 100, y1 + 120, c[7]);

	DeleteObject(pen);
	DeleteObject(br1);
