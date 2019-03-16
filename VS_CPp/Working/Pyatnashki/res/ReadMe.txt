#include <iostream>

// додаткова бібліотека 
#include <time.h>

using namespace std;

int main()
{
	// генератор випадкових чисел
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	// розміри матрицi
	int A[100][100];
	int n, k, i;
	char z;

	n = 17;
	int a = -99;
	int b = 99;

	do
	{
		system("cls");
		printf("\n\tЗаповнення матрицi A[%2i][%2i] цiлими двозначними числами. \n\n", n, n);

		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				do
				{
					A[k][i] = a + rand() % (b - a + 1);
				} while (abs(A[k][i])<10||abs(A[k][i])>99);
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}
		cout << "\n\n\tПродовжити (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}


--------------------------------------------------------------------------------------

#define PI 3.1415926535897932384626433832795

afx_msg void Circl(int X, int Y, int D, int WDT, COLORREF CF);

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

--------------------------------------------------------------------------------------

#include <time.h>

using namespace std;

srand((unsigned) time (NULL));

--------------------------------------------------------------------------------------

		CClientDC dc(this);
		GetClientRect(&rc);

		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,
		ANSI_CHARSET,OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
		DEFAULT_PITCH|FF_DONTCARE,
		L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);

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
		hold=(HFONT)SelectObject(dc,hbk);

--------------------------------------------------------------------------------------

afx_msg void Circl(int X, int Y, int D, int WDT, COLORREF CF)
{
	CClientDC dc(this);
	
	hPenOxy = CreatePen(PS_SOLID, WDT, CF);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	double xf, yf, f;
	f = 0;

	dc.MoveTo(X + D / 2, Y);

	do
	{
		xf = D / 2 * cos(f);
		yf = D / 2 * sin(f);
		//dc.SetPixel(xf+X, yf+Y, cf);
		dc.LineTo(xf + X, yf + Y);
		f += 0.09;
	} while (f <= 360);
}

