Програма Розв'язування трикутників
Теорема косинусів, існування трикутника, Тип трикутника
Теорема синусів - діаметр описаного кола

відео - https://youtu.be/-5LA14ETXW0 

Лістинг програми:

///////////////////////////////////////////////////////////////////////////////////
private:

	float a, b, c;
	float ca, cb, cc;
	CString ms, t;

	bool fg;

	afx_msg bool existing(float x, float y, float z);
	afx_msg float max2(float x, float y);
///////////////////////////////////////////////////////////////////////////////////

	E.SetWindowTextW(L"\n\n\n\n\n\n\n\n\n       Натисніть кнопку \n       <обчислити>");

////

	UpdateData(true);
	a = A;
	b = B;
	c = C;
	UpdateData(false);

	fg = existing(a, b, c);

	ms = "Результат обчислень:\n\n";
	ms += "Вами введені\n";
	t.Format(L"a=%3.1f\n", a);
	ms += t;
	t.Format(L"b=%3.1f\n", b);
	ms += t;
	t.Format(L"c=%3.1f\n", c);
	ms += t;


	if (fg)
	{
		ms += "трикутник існує\n";

		float buf, znak;

		buf = max2(max2(a, b), c);

		if (buf == a)
		{
			znak = b * b + c * c - a * a;
			if (znak > 0)
			{
				ms += "і він - гострокутний";
			}
			if (znak == 0)
			{
				ms += "і він - прямокутний";
			}
			if (znak < 0)
			{
				ms += "і він - тупокутний";
			}
		}
		else

			if (buf == b)
			{
				znak = a * a + c * c - b * b;
				if (znak > 0)
				{
					ms += "і він - гострокутний";
				}
				if (znak == 0)
				{
					ms += "і він - прямокутний";
				}
				if (znak < 0)
				{
					ms += "і він - тупокутний";
				}
			}

			else
				if (buf == c)
				{
					znak = b * b + a * a - c * c;
					if (znak > 0)
					{
						ms += "і він - гострокутний";
					}
					if (znak == 0)
					{
						ms += "і він - прямокутний";
					}
					if (znak < 0)
					{
						ms += "і він - тупокутний";
					}
				}
	}
	else
	{
		ms += "трикутник не існує";
	}
	E.SetWindowTextW(ms);

///////////////////////////////////////////////////////////////////////////////////
afx_msg bool  CProgramDlg::existing(float x, float y, float z)
{
	bool res = false;
	if (x > 0 && y > 0 && z > 0
		&& x + y > z && x + z > y && y + z > x) res = true;
	return res;
}

afx_msg float  CProgramDlg::max2(float x, float y)
{
	float res;
	if (x >= y) res = x; else res = y;
	return res;
}
///////////////////////////////////////////////////////////////////////////////////
void CProgramDlg::OnFileMainwindow()
{
	// TODO: Add your command handler code here
}


void CProgramDlg::OnFileNewwindow()
{
	// TODO: Add your command handler code here
	CNewWindow dlg;
	OnOK();
	dlg.DoModal();


}


void CProgramDlg::OnFileExit()
{
	// TODO: Add your command handler code here
	OnOK();
}
///////////////////////////////////////////////////////////////////////////////////
#define PI 3.14159265359

private:

	float a;
	float sa;
	float R;
	float alpha;
	CString ms, t;

	bool fg;

///////////////////////////////////////////////////////////////////////////////////
	E.SetWindowTextW(L"\n\n\n\n\n\n\n       Натисніть кнопку \n       <обчислити>");

/////////////////

	UpdateData(true);
	a = A;
	alpha = ALPHA;
	UpdateData(false);

	sa = alpha * PI / 180.0;

	R = a / (2 * sinf(sa));

	ms = "Результати обчислень:\n";
	ms += "для трикутника із\n";
	t.Format(L"стороною a=%3.1f", a);
	ms += t;
	ms += "\nі протилежним кутом\n";
	t.Format(L"A=%3.0f", alpha);
	ms += t;
	ms += "\nдіаметр описаного кола\n";
	t.Format(L"становить 2R=%3.1f", 2 * R);
	ms += t;


	E.SetWindowTextW(ms);
///////////////////////////////////////////////////////////////////////////////////
void CNewWindow::OnFileNewwindow()
{
	// TODO: Add your command handler code here
}


void CNewWindow::OnFileMainwindow()
{
	// TODO: Add your command handler code here
	CProgramDlg dlg;
	OnOK();
	dlg.DoModal();
}


void CNewWindow::OnFileExit()
{
	// TODO: Add your command handler code here
	OnOK();
}
///////////////////////////////////////////////////////////////////////////////////
