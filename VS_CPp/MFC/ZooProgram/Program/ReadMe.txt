=============================================================================
    БИБЛИОТЕКА MICROSOFT FOUNDATION CLASS. Обзор проекта Program
=============================================================================

Это приложение Program автоматически создано с помощью мастера приложений. Это приложение демонстрирует основные принципы использования классов Microsoft Foundation; оно также может использоваться в качестве основы для написания собственных приложений.

В этом файле представлена сводка содержимого всех файлов, входящих в состав приложения Program.

Program.vcxproj
    Это основной файл проекта VC++, создаваемый с помощью мастера приложений. Он содержит данные о версии языка Visual C++, использованной для создания файла, а также сведения о платформах, конфигурациях и функциях проекта, выбранных с помощью мастера приложений.

Program.vcxproj.filters
    Это файл фильтров для проектов VC++, созданный с помощью мастера приложений. Он содержит сведения о сопоставлениях между файлами в вашем проекте и фильтрами. Эти сопоставления используются в среде IDE для группировки файлов с одинаковыми расширениями в одном узле (например CPP-файлы сопоставляются с фильтром "Исходные файлы").

Program.h
    Это основной файл заголовка приложения.
    Он содержит прочие заголовки, относящиеся к проекту (включая Resource.h), а также объявляет класс приложения CProgramApp.

Program.cpp
    Это основной исходный файл приложения, в котором содержится класс приложения CProgramApp.

Program.rc
    Он представляет собой список всех ресурсов Microsoft Windows, используемых программой. В него включены значки, точечные рисунки и курсоры, хранящиеся в подкаталоге RES. Этот файл можно редактировать непосредственно в Microsoft Visual C++. Ресурсы проекта находятся в 1049.

res\Program.ico
    Файл значка, используемый в качестве значка приложения. Этот значок включен с помощью основного файла ресурсов Program.rc.

res\Program.rc2
    Этот файл содержит ресурсы, которые нельзя редактировать в Microsoft Visual C++. В этот файл следует поместить все ресурсы, не редактируемые редактором ресурсов.


/////////////////////////////////////////////////////////////////////////////

Мастер приложений создает один класс диалогового окна:

ProgramDlg.h, ProgramDlg.cpp — диалоговое окно
    Эти файлы содержат класс CProgramDlg. Этот класс определяет поведение главного диалогового окна приложения. Шаблон диалогового окна находится в файле Program.rc, который можно изменять с помощью Microsoft Visual C++.

/////////////////////////////////////////////////////////////////////////////

Другие возможности.

Элементы управления ActiveX
    Приложение включает поддержку элементов управления ActiveX.

Поддержка печати и предварительного просмотра
    Мастер приложений создал код для обработки команд печати, настройки печати и предварительного просмотра, используя вызовы функций-членов в классе CView из библиотеки MFC.

/////////////////////////////////////////////////////////////////////////////

Другие стандартные файлы:

StdAfx.h, StdAfx.cpp
    Эти файлы используются для построения файла предкомпилированного заголовка (PCH) с именем Program.pch и файла предкомпилированных типов с именем StdAfx.obj.

Resource.h
    Это стандартный файл заголовка, в котором определяются новые идентификаторы ресурсов. Такой файл можно прочитать и обновить в Microsoft Visual C++.

Program.manifest
	Файлы манифеста приложения используются операционной системой Windows XP для описания зависимости приложений от определенных версий параллельных сборок. Эти сведения используются загрузчиком для загрузки соответствующей сборки из кэша сборок или частным образом из приложения. Манифест приложения можно включить для распространения в качестве внешнего MANIFEST-файла, устанавливаемого в одной папке с исполняемым файлом приложения, или внедрить в исполняемый файл в виде ресурса.
/////////////////////////////////////////////////////////////////////////////

Прочие примечания.

С помощью комментариев «TODO:» в мастере приложений обозначаются фрагменты исходного кода, которые необходимо дополнить или изменить.

Если приложение использует MFC в общей библиотеке DLL, необходимо обеспечить распространение библиотек DLL MFC. Если в приложении используется язык, отличный от языка операционной системы, потребуется также обеспечить распространение соответствующих локализованных ресурсов mfc110XXX.DLL.
Дополнительные сведения о выполнении этих задач см. в разделе документации MSDN, посвященном распространению приложений Visual C++.

/////////////////////////////////////////////////////////////////////////////

	c[0] = 0xFF00FF;	// розовый
	c[1] = 0xFFA500;	// бирюза
	c[2] = 0xFFFF;		// желтый
	c[3] = 0x0C7800;	// зеленый
	c[4] = 0x005690;	// охра
	c[5] = 0xFFFF0000;	// черный
	c[6] = 0xCC00AA;	// фиолетовый
	c[7] = 0xAA5600;	// синий
	c[8] = 0xAAAA;		// оранжевый
	c[9] = 0x00CC00;	// синий
	c[10] = 0x090056;	// коричневый
	c[11] = 0xF0F0F0;	// бело-серый

---------------------------------------------------------

#include <time.h>
#include <fstream>

using namespace std;

---------------------------------------------------------

	srand((unsigned)time(NULL));

---------------------------------------------------------

	int d, m, g, k;

	UpdateData(true);
	d = D;
	m = M;
	g = G;
	UpdateData(false);

__________________________________________________________________________


		CClientDC dc(this);
		GetClientRect(&rc);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
		hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");
		
		t = "Эта именно ТА САМАЯ фраза";

		hold = (HFONT)SelectObject(dc, hNew);
		SetTextColor(dc, c[5]);
		dc.TextOutW(75, 80, t, t.GetLength());

		hold = (HFONT)SelectObject(dc, hbk);

__________________________________________________________________________

		w.left = rc.left;
		w.right = rc.right;
		w.top = rc.top + 200;
		w.bottom = rc.bottom;
		dc.FillSolidRect(&w, RGB(0, 0, 0));

__________________________________________________________________________

	switch (k)
	{
	case 0: 		
		SetTextColor(dc, c[0]);
		hNew = CreateFont(144, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");
		hold = (HFONT)SelectObject(dc, hNew);
		dc.TextOutW(75, 240, ms[0], ms[0].GetLength());
		break;
	
	}

	hold = (HFONT)SelectObject(dc, hbk);

__________________________________________________________________________

CString mz[12] = { L"Овен", 
		               L"Телец", 
					   L"Близнецы", 
					   L"Рак", 
					   L"Лев", 
					   L"Дева", 
					   L"Весы", 
					   L"Скорпион", 
					   L"Стрелец", 
					   L"Козерог", 
					   L"Водолей", 
					   L"Рыбы" };

__________________________________________________________________________

	if (((d >= 21) && (d <= 31) && (m == 3)) ||
		((d >= 1) && (d <= 20) && (m == 4)))
	{
		//MessageBox(ms[0]); // Овен
		k = 0;
	}

	if (((d >= 21) && (d <= 30) && (m == 4)) ||
		((d >= 1) && (d <= 21) && (m == 5)))
	{
		//MessageBox(ms[1]); // Телец
		k = 1;
	}

	if (((d >= 22) && (d <= 31) && (m == 5)) ||
		((d >= 1) && (d <= 21) && (m == 6)))
	{
		//MessageBox(ms[2]); // Близнецы
		k = 2;
	}

	if (((d >= 22) && (d <= 30) && (m == 6)) ||
		((d >= 1) && (d <= 23) && (m == 7)))
	{
		//MessageBox(ms[3]); // Рак
		k = 3;
	}

	if (((d >= 24) && (d <= 31) && (m == 7)) ||
		((d >= 1) && (d <= 23) && (m == 8)))
	{
		//MessageBox(ms[4]); // Лев
		k = 4;
	}

	if (((d >= 24) && (d <= 31) && (m == 8)) ||
		((d >= 1) && (d <= 23) && (m == 9)))
	{
		//MessageBox(ms[5]); // Дева
		k = 5;
	}

	if (((d >= 24) && (d <= 30) && (m == 9)) ||
		((d >= 1) && (d <= 23) && (m == 10)))
	{
		//MessageBox(ms[6]); // Весы
		k = 6;
	}

	if (((d >= 24) && (d <= 31) && (m == 10)) ||
		((d >= 1) && (d <= 22) && (m == 11)))
	{
		//MessageBox(ms[7]); // Скорпион
		k = 7;
	}

	if (((d >= 23) && (d <= 30) && (m == 11)) ||
		((d >= 1) && (d <= 21) && (m == 12)))
	{
		//MessageBox(ms[8]); // Стрелец
		k = 8;
	}

	if (((d >= 22) && (d <= 31) && (m == 12)) ||
		((d >= 1) && (d <= 20) && (m == 1)))
	{
		//MessageBox(ms[9]); // Козерог
		k = 9;
	}

	if (((d >= 21) && (d <= 31) && (m == 1)) ||
		((d >= 1) && (d <= 19) && (m == 2)))
	{
		//MessageBox(ms[10]); // Водолей
		k = 10;
	}

	if (((d >= 20) && (d <= 29) && (m == 2)) ||
		((d >= 1) && (d <= 20) && (m == 3)))
	{
		//MessageBox(ms[11]); // Рыбы
		k = 11;
	}

__________________________________________________________________________

		RH = abs(rc.right - rc.left);
		RW = abs(rc.top - rc.bottom);

		dx = RH / 3;
		dy = RW / 2;
		j = 0;
		for (k = 0; k < 2; k++)
		{
			for (i = 0; i < 3; i++)
			{
				cf = c[j];
				m = CreateSolidBrush(cf);
				oldm = (HBRUSH)dc.SelectObject(m);
				w.top = k*dy;
				w.bottom = (k + 1)*dy;
				w.left = i*dx;
				if (i == 2)
				{
					w.right = (i + 1)*dx + 1;
				}
				else
				{
					w.right = (i + 1)*dx;
				}
				w.DeflateRect(1, 1);
				dc.RoundRect(&w, CPoint(25, 25));
				j++;
				DeleteObject(m);
				SelectObject(dc, oldm);
			}
		}

__________________________________________________________________________

	CClientDC dc(this);
	GetClientRect(&rc);
	RH = abs(rc.right - rc.left);
	RW = abs(rc.bottom - rc.top);
	dx = RH / 3;
	dy = RW / 2;
	j = 0;
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 3; i++)
		{
			w.top = k*dy;
			w.bottom = (k + 1)*dy;
			w.left = i*dx;
			w.right = (i + 1)*dx;
			kw[j] = w;
			j++;
		}
	}


__________________________________________________________________________


	if (PtInRect(&kw[0], point))
	{
		cf = c[6];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[0].DeflateRect(1, 1);
		dc.RoundRect(&kw[0], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
		cf = c[0];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[0].DeflateRect(1, 1);
		dc.RoundRect(&kw[0], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}

//------------------

	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);


__________________________________________________________________________


	UpdateData(true);
	n = N;
	UpdateData(false);

	p = n*n;

	ms.Empty();
	ms = "\n     Матриця А[";
	t.Format(L"%i][%i] сформована!\n\n", n, n);
	ms += t;

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (k % 2 == 0)
			{
				t.Format(L"%4i\t", p);
				ms += t;
				p--;
			}
			else
			{
				t.Format(L"%4i\t", p - n + i + 1);
				ms += t;
			}
		}
		if (k % 2 != 0) p -= n;
		ms += "\n";
	}


	E.SetWindowTextW(ms);

	
__________________________________________________________________________



	CStdioFile inf(L"data.txt", CFile::modeCreate | CFile::modeWrite);
	
	

	if (PtInRect(&kw[0], point))
	{
		ms = "0";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		CKw0 dlg;
		dlg.DoModal();
	}
	


---------------------------------------------------


	CClientDC dc(this);
	GetClientRect(&rc);

	RH = abs(rc.right - rc.left);
	RW = abs(rc.bottom - rc.top);
	dx = RH / 15;
	dy = RW / 15;

	w.left = rc.left + dx;
	w.right = rc.right - dx;
	w.top = rc.top + dy;
	w.bottom = rc.bottom - dy;

	ClientToScreen(&w);
	ScreenToClient(&w);

	CStdioFile otf;
	otf.Open(L"data.txt", CFile::modeRead);
	
	otf.ReadString(ms);
	otf.Close();

	k=_wtoi(ms);
	
	switch (k)
	{
		case 0: SetWindowTextW(L"Розовый");
			cf = c[0];
			break;
		case 1: SetWindowTextW(L"Бирюзовый");
			cf = c[1];
			break;
		case 2: SetWindowTextW(L"Желтый");
			cf = c[2];
			break;
		case 3: SetWindowTextW(L"Зеленый");
			cf = c[3];
			break;
		case 4: SetWindowTextW(L"Коричневый");
			cf = c[4];
			break;
		case 5: SetWindowTextW(L"Черный");
			cf = c[5];
			break;
	}
	
----------------------------------------------------------


	if (IsIconic()&&fg)
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	} 
	else
	{
		CClientDC dc(this);
		GetClientRect(&rc);
		ClientToScreen(&rc);
		ScreenToClient(&rc);

		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		rc.DeflateRect(5, 5);
		dc.RoundRect(&rc, CPoint(45, 45));
		DeleteObject(m);
		SelectObject(dc, oldm);
		fg = false;
	}
	
	CDialog::OnPaint();

----------------------------------------------------------

	CClientDC dc(this);
	GetClientRect(&rc);

	m = CreateSolidBrush(cf);
	oldm = (HBRUSH)dc.SelectObject(m);


	if (PtInRect(&w, point))
	{
		

		switch (k)
		{
		case 0: cf = c[6];
			break;
		case 1: cf = c[7];
			break;
		case 2: cf = c[8];
			break;
		case 3: cf = c[9];
			break;
		case 4: cf = c[10];
			break;
		case 5: cf = c[11];
			break;
		}


		rc.DeflateRect(5, 5);
		dc.RoundRect(&rc, CPoint(45, 45));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
	
		switch (k)
		{
		case 0: cf = c[0];
			break;
		case 1: cf = c[1];
			break;
		case 2: cf = c[2];
			break;
		case 3: cf = c[3];
			break;
		case 4: cf = c[4];
			break;
		case 5: cf = c[5];
			break;
		}
	
		rc.DeflateRect(5, 5);
		dc.RoundRect(&rc, CPoint(45, 45));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}

	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);

----------------------------------------------------------

	CClientDC dc(this);
	GetClientRect(&rc);

	if (PtInRect(&w, point)&&(k!=5))
	{

    	cf = c[5];
		dc.FillSolidRect(&rc, cf);
		Sleep(mtime_0);

		OnOK();
	}
	else
	{
		cf = c[5];
		dc.FillSolidRect(&rc, cf);
		Sleep(mtime_0);

		if (MessageBox(L"Вы действительно хотите выйти?", L"ВЫХОД", MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			OnOK();
		}
		else
		{
			OnOK();
			CnewKvadratikDlg dlg;
			dlg.DoModal();
		}
	}
	

===========================================================================


		CClientDC dc(this);
		GetClientRect(&rc);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
		hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

		t = "Для продовження натисніть <START>";

		hold = (HFONT)SelectObject(dc, hNew);
		SetTextColor(dc, c[5]);
		dc.TextOutW(75, 80, t, t.GetLength());

		hold = (HFONT)SelectObject(dc, hbk);


===========================================================================

	double a, b, x1, y1, x2, y2, ZZ[20];
	CString mz[4];

	UpdateData(true);
	a = A;
	b = B;
	UpdateData(false);

	j = 0;
	for (k = 0; k < 4; k++)
	{
		mz[k].Empty();
		for (i = 0; i < 5; i++)
		{
			x1 = a + (double)rand() / RAND_MAX*(b - a);
			y1 = a + (double)rand() / RAND_MAX*(b - a);

			x2 = myfx(x1);
			y2 = myfy(x1, y1, x2);
			ZZ[j] = myfz(x1, y1, x2, y2);

			t.Format(L"%8.2f", ZZ[j]);
			mz[k] += t;
			j++;
		}
	}

==========================================================================

	CClientDC dc(this);
	GetClientRect(&rc);

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(36, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");


	hold = (HFONT)SelectObject(dc, hNew);
	SetTextColor(dc, c[11]);
	
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top + 150;
	w.bottom = rc.bottom;
	dc.FillSolidRect(&w, RGB(0, 0, 0));


	for (k = 0; k < 4; k++)
	{
		t = mz[k];
		dc.TextOutW(75, 220 + k * 44, t, t.GetLength());
	}

	hold = (HFONT)SelectObject(dc, hbk);


==========================================================================


double CProgramDlg::myfx(double aa)
{
	double res;
	res = exp(0.5*aa);
	return res;
}

double CProgramDlg::myfy(double aa, double bb, double xx)
{
	double res;
	res = bb - aa*xx;
	return res;
}

double CProgramDlg::myfz(double aa, double bb, double xx, double yy)
{
	double res;
	
	if (yy > 0)
	{
		res = sqrt(xx*yy + aa);
	}
	else
	{
		res = sin(aa*aa) + bb*cos(xx*xx);
	}
	
	return res;
}

=============================================================================

#define proga "MATEMATIKA.exe"

public:
	char m_AppPath[_MAX_PATH], path_buffer[_MAX_PATH];
	TCHAR exepath[MAX_PATH];
	CString pth, tmp;

=============================================================================

	GetModuleFileName(NULL, exepath, MAX_PATH);
	tmp=proga;
	pth=exepath;
	pth.Delete(pth.Find(tmp, 0),tmp.GetLength());

=============================================================================

private:
	CRect BtnExitRect;
	CRect BtnPointRect;
-------------------------------------------------------------------------------
	CWnd * WndPtr = GetDlgItem( IDC_EXIT );
	WndPtr->GetWindowRect( &BtnExitRect );
	ScreenToClient( &BtnExitRect );

	WndPtr = GetDlgItem( IDC_POINT );
	WndPtr->GetWindowRect( &BtnPointRect );
	ScreenToClient( &BtnPointRect );

=============================================================================

	CBitmap PIC;
	if(BtnExitRect.PtInRect(point))
	{
		PIC.LoadBitmap( IDB_EXITON );
		BtnExit.SetBitmap( PIC );
		PIC.DeleteObject();
	} else
	{
		PIC.LoadBitmap( IDB_EXITOFF );
		BtnExit.SetBitmap( PIC );
		PIC.DeleteObject();
	}
	
	SendMessage( WM_SYSCOMMAND, 0xF012, NULL );

=============================================================================

	if(BtnExitRect.PtInRect(point))
	{
		if(MessageBox(TEXT("Ви дійсно бажаєте вийти ?"),TEXT("УВАГА!!!"),MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
		{
			OnOK();
		};
	} 


=============================================================================

	if(BtnPointRect.PtInRect(point))
	{
		CString PresentFile;
		PresentFile="МАТЕРИКИ.pptx";
		PresentFile.Insert(0,pth);
		ShellExecute( m_hWnd, L"open",(LPCTSTR)PresentFile,NULL,NULL, SW_SHOWDEFAULT );
	} 

=============================================================================
#include <time.h>
#include <math.h>
#include <fstream>

using namespace std;



srand((unsigned)time(NULL));



	setlocale(LC_ALL,"rus");

	CString s,t, msg;
	int a[100][100];
	int i,k,j;
		
	s="Исходная матрица\n\n";

	for (i=0;i<5;i++)
	{
		for (k=0;k<5;k++)
		{	
			do // генерируем случайное, двузначное (см.условие)
			{
				 a[i][k]=rand()%100;					
			 }while ((a[i][k]<10)||(a[i][k]>99));
			
			j=(-1);// генерируем знак
			for(int l=0;l<=rand()%10;l++) j*=(-1);

			a[i][k]*=j;// изменяем знак

			t.Format(L"%4i\t",a[i][k]); // преобразовать в текст
			s+=t;
		}
		t="\n";// перейти на новую строчку
		s+=t;
	}
	
	E.SetWindowTextW(s); //вывести в первое окно

	s.Empty();//очистить
	msg.Empty();
	s="Зашифрованная матрица (+1) \n\n";

	for (i=0;i<5;i++)
	{
		for (k=0;k<5;k++)
		{	
			a[i][k]=a[i][k]+1;// увеличить на 1
			t.Format(L"%4i\t",a[i][k]);
			s+=t;
			msg+=t;
		}
		t="\n";
		s+=t;
		msg+=t;
	}
	
	R.SetWindowTextW(s); // вывести во второе окно

	CStdioFile inf(L"d:\\temp\\data.txt",CFile::modeCreate|CFile::modeWrite);
	inf.WriteString(msg); // записать в файл
	inf.Flush();
	inf.Close();

	// откроем блокнот, чтобы не искать
	//ShellExecute(m_hWnd,L"open",L"d:\\temp\\data.txt",NULL,NULL,SW_SHOWDEFAULT);

	CStdioFile otf(L"d:\\temp\\data.txt",CFile::modeRead);
	CString v,z;
	int m,p,h;
	s.Empty();
	s="Отправленная матрица (-10) \n\n";
	for (i=0;i<5;i++)
	{
		otf.ReadString(t); //читаем строчку текста с числами


		j=wcslen(t);
		k=0;
		m=p=0; 
		while(m<=j-2)
		{
			v.Empty();
			z.Empty();
			m=p;
			while((m<=j-1)&&(t[m]!='\t'))
			{
				v+=t[m];
				m++;
			}
			z=v;
			h=_wtoi(z);
			a[i][k]=h-10;
			msg.Format(L"%4i\t",a[i][k]);
			s+=msg;
			k++;
			p=m;
			p++;
			if(m>=j) p=m+1;
		}		
		
		
		msg="\n";
		s+=msg;
	}

	F.SetWindowTextW(s);// вывести в третье окно

static string ReadFile(string FileName)
{
        string Result, temp;
        ifstream in(FileName.c_str()); // <-----
        getline(in, Result);
    while (!in.eof())
        {
                getline(in, temp);
                Result += ' ' + temp;
        }
        in.close();
        return Result;
}


  ofstream out("test", ios::out | ios::binary); 
  if(!out) { 
    cout << "Cannot open file.\n"; 
    return 1; 
   } 


=============================================================================
public:
	CPoint mpoint;
	UINT m_cur;
        int m_Pos;
		

	m_aniBBS.Open(IDR_BBS);
	m_aniBBS.Play(0, (UINT) -1, 1);

if((!bEx.PtInRect(point))&&(!bNx.PtInRect(point)))
	{
		SetCursor(m_hCursor);
		ShowCursor(TRUE);
	}

	m_hIcon = AfxGetApp()->LoadIcon(IDR_PLANTS);
	m_hCursor = AfxGetApp()->LoadCursor(IDC_MAINFRAME);

	m_K_Plants01.LoadBitmap(IDB_K_PLANTS01);

	int st=m_Combo.GetCurSel();
	switch(st)
	{
	case 0:
		{
			CStatic* bmpStatic1 = (CStatic*) GetDlgItem(IDC_K_PLANTS);
			bmpStatic1->SetBitmap(m_K_Plants01); 
			Invalidate(FALSE);
		}
		break;
        }
	}
	SetTimer(1,300,0);

=============================================================================


	// TODO: добавьте дополнительную инициализацию

	Slider.SetRange(0,1024,TRUE);
	Slider.SetTicFreq(128);
	Slider.SetLineSize(32);
	Slider.SetPageSize(256);
	Progres.SetRange(0,1024);



	CClientDC clientDC(this);
	CBrush brBack(RGB(255,255,255));

	::GetWindowRect(::GetDlgItem(m_hWnd,IDC_PICTURE), &pslider);
	ScreenToClient(&pslider);

	pslider.left +=2;
	pslider.top +=2;
	pslider.right -=2;
	pslider.bottom -=2;

	clientDC.FillRect(pslider,&brBack);


	UpdateData();
	if(Reset)
	{
		Progres.SetPos(0);
		Slider.SetPos(0);

		CClientDC clientDC(this);
		CRgn prm;
		CBrush brBack(RGB(255,255,255));

		prm.CreateRectRgnIndirect(pslider);
		clientDC.SelectClipRgn(&prm);
		clientDC.FillRect(pslider,&brBack);

		//mReset.SetCheck(FALSE);
	}

	CSliderCtrl* sl=(CSliderCtrl*) pScrollBar;
	if(!Reset && (Progres.GetPos()<sl->GetPos())) 
	{
		Progres.SetPos(sl->GetPos());

		CClientDC clientDC(this);
		CRgn prm;
		CBrush brDn(RGB(63,127,127));

		CRect dslider=pslider;

		prm.CreateRectRgnIndirect(pslider);
		clientDC.SelectClipRgn(&prm);


		dslider.right=pslider.left + (int)(pslider.Width()*sl->GetPos())/sl->GetRangeMax();
		clientDC.FillRect(dslider,&brDn);

	}else
	{
		Progres.SetPos(0);
		Progres.SetPos(sl->GetPos());

	}
------------------------------------------


#include <time.h>
#include <fstream>

using namespace std;

	srand((unsigned)NULL(time));



	CString s,tmp, msg,y;

	setlocale(LC_ALL, "rus");

	CStdioFile inf(L"d:\\temp\\data.txt",CFile::modeCreate|CFile::modeWrite);

	int i,j,k,m;
	UpdateData(TRUE);
	s=S;
	UpdateData(FALSE);
	E.SetWindowTextW(s);

	
	k=wcslen(s);
	tmp=s[k];
	for(i=k-1;i>=0;i--) tmp+=s[i];
	R.SetWindowTextW(tmp);

	inf.WriteString(tmp);
	inf.Flush();
	inf.Close();

	CStdioFile otf(L"d:\\temp\\data.txt",CFile::modeRead);
	otf.ReadString(msg);
	j=wcslen(msg);
	y=msg[j];
	for(m=k-1;m>=0;m--) y+=msg[m];
	F.SetWindowTextW(y);
	otf.Close();

-------------------


void CMatrix2Dlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	CString s,t;
		
	s="Исходная матрица\n\n";


	int a[100][100];
	int i,k,j;
	for (i=0;i<5;i++)
	{
		for (k=0;k<5;k++)
		{	
			do 
			{
				 a[i][k]=rand()%100;					
			 }while ((a[i][k]<10)||(a[i][k]>99));
			
			j=(-1);
			for(int l=0;l<=rand()%10;l++) j*=(-1);

			a[i][k]*=j;

			t.Format(L"%4i\t",a[i][k]);
			s+=t;
		}
		t="\n";
		s+=t;
	}
	E.SetWindowTextW(s);
// ------------------------------------------------

	int max, n,m;
	max=a[0][0];
	m=0;
	n=0;

	for (i=0;i<5;i++)
	{
	    for (k=0;k<5;k++)
		{	
			if(a[i][k]>max)
			{
				max=a[i][k];
				m=i;
				n=k;
			}
		}
	}

	CString r,w;

	r="Результаты поиска и подсчёта \n\n";
	r+="MaX=";
	w.Format(L"%i",max);
	r+=w;
	w.Format(L"\nстрока = %i",m+1);
	r+=w;
	w.Format(L"\nстолбец = %i",n+1);
	r+=w;

	int sum=0;
	for (int g=0;g<5;g++) sum+=a[g][n];
	for (int g=0;g<5;g++) sum+=a[m][g];
	sum-=(2*max);
	w.Format(L"\nSuMMA = %i",sum);
	r+=w;

	R.SetWindowTextW(r);
// -----------------------------------------

	s.Empty();
	s="Результат - новая матрица\n\n";

	for (int g=0;g<5;g++) a[g][n]=0;
	for (int g=0;g<5;g++) a[m][g]=0;
	a[m][n]=max;
	
	for (i=0;i<5;i++)
	{
	    for (k=0;k<5;k++)
		{	
			t.Format(L"%4i\t",a[i][k]);
  			s+=t;
		}
		t="\n";
		s+=t;
	}
	V.SetWindowTextW(s);

}

============================== OnInitDialog

	Slider.SetRange(0,1024,TRUE);
	Slider.SetTicFreq(128);
	Slider.SetLineSize(32);
	Slider.SetPageSize(256);
	Progres.SetRange(0,1024);

============================== OnPain

	CClientDC clientDC(this);
	CBrush brBack(RGB(255,255,255));

	::GetWindowRect(::GetDlgItem(m_hWnd,IDC_PICTURE), &pslider);
	ScreenToClient(&pslider);

	pslider.left +=2;
	pslider.top +=2;
	pslider.right -=2;
	pslider.bottom -=2;

	clientDC.FillRect(pslider,&brBack);

+++++++++++++++++++++++++++++++++++ OnReset

	UpdateData();
	if(Reset)
	{
		Progres.SetPos(0);
		Slider.SetPos(0);

		CClientDC clientDC(this);
		CRgn prm;
		CBrush brBack(RGB(255,255,255));

		prm.CreateRectRgnIndirect(pslider);
		clientDC.SelectClipRgn(&prm);
		clientDC.FillRect(pslider,&brBack);

		//mReset.SetCheck(FALSE);
	}

------------------------------------------------------------------ OnHSCROOL

	CSliderCtrl* sl=(CSliderCtrl*) pScrollBar;
	if(!Reset && (Progres.GetPos()<sl->GetPos())) 
	{
		Progres.SetPos(sl->GetPos());

		CClientDC clientDC(this);
		CRgn prm;
		CBrush brDn(RGB(63,127,127));

		CRect dslider=pslider;

		prm.CreateRectRgnIndirect(pslider);
		clientDC.SelectClipRgn(&prm);


		dslider.right=pslider.left + (int)(pslider.Width()*sl->GetPos())/sl->GetRangeMax();
		clientDC.FillRect(dslider,&brDn);

	}else
	{
		Progres.SetPos(0);
		Progres.SetPos(sl->GetPos());

	}

=============================================================================

#include "Kw0.h"
#include "nKvadratikiDlg.h"


#define mtime 50

#define mtime_0 1000

private:

	HFONT hold, hNew, hbk;
	CString ms,t;
	CRect rc;
	CRect w;
	int RH, RW, k, i, j, dx, dy, cx, cy;
	COLORREF cf, c[25];
	CRect kw[6];
	HBRUSH m, oldm;
	CPen d,oldd;

-----------------------------------------------------------

		CClientDC dc(this);
		GetClientRect(&rc);
		
		RH = abs(rc.right - rc.left);
		RW = abs(rc.top - rc.bottom);
		
		dx = RH / 3;
		dy = RW / 2;
		
		j = 0;
		
		for (k = 0; k < 2; k++)
		{
			for (i = 0; i < 3; i++)
			{
				cf = c[j];

				w.top = k*dy;
				w.bottom = (k+1)*dy;
				w.left = i*dx;
				if (i == 2)
				{
					
					w.right = (i + 1)*dx+2;
				}
				else
				{
					
					w.right = (i + 1)*dx;
				}

				dc.FillSolidRect(&w, cf);
				
				j++;

			}
		}

-----------------------------------------------------------------


		CClientDC dc(this);
		GetClientRect(&rc);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.right - rc.left);
		RW = abs(rc.top - rc.bottom);
		
		dx = RH / 3;
		dy = RW / 2;
		j = 0;
		for (k = 0; k < 2; k++)
		{
			for (i = 0; i < 3; i++)
			{
				cf = c[j];
				m = CreateSolidBrush(cf);
				oldm = (HBRUSH)dc.SelectObject(m);
				w.top = k*dy;
				w.bottom = (k + 1)*dy;
				w.left = i*dx;
				if (i == 2)
				{
					w.right = (i + 1)*dx + 2;
				}
				else
				{
					w.right = (i + 1)*dx;
				}
				w.DeflateRect(1, 1);
				dc.RoundRect(&w, CPoint(25, 25));
				j++;
				DeleteObject(m);
				SelectObject(dc, oldm);
			}
		}

-----------------------------------------------------------

	if (PtInRect(&kw[0], point))
	{
		CKw0 dlg;
		dlg.DoModal();
	}

-----------------------------------------------------------

	if (PtInRect(&kw[0], point))
	{
		cf = c[6];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[0].DeflateRect(1, 1);
		dc.RoundRect(&kw[0], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}
	else
	{
		cf = c[0];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		kw[0].DeflateRect(1, 1);
		dc.RoundRect(&kw[0], CPoint(25, 25));
		DeleteObject(m);
		SelectObject(dc, oldm);
	}


-----------------------------------------------------------

void CKw0::OnPaint()
{
	CClientDC dc(this);
	GetClientRect(&rc);
	cf = c[0];
	m = CreateSolidBrush(cf);
	oldm = (HBRUSH)dc.SelectObject(m);
	rc.DeflateRect(5,5);
	dc.RoundRect(&rc, CPoint(45,45));
	DeleteObject(m);
	SelectObject(dc, oldm);
}

---------------------------------------------------------------

void CKw0::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	GetClientRect(&rc);
	RH = abs(rc.right - rc.left);
	RW = abs(rc.bottom - rc.top);
	dx = RH / 5;
	dy = RW / 5;
	w.left = rc.left + dx;
	w.right = rc.right - dx;
	w.top = rc.top + dy;
	w.bottom = rc.bottom - dy;

	if (PtInRect(&w, point))
	{
		cf = c[6];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		rc.DeflateRect(5, 5);
		dc.RoundRect(&rc, CPoint(45, 45));
		DeleteObject(m);
		SelectObject(dc, oldm);
		Sleep(mtime_0);
	}
	else
	{
		cf = c[0];
		m = CreateSolidBrush(cf);
		oldm = (HBRUSH)dc.SelectObject(m);
		rc.DeflateRect(5, 5);
		dc.RoundRect(&rc, CPoint(45, 45));
		DeleteObject(m);
		SelectObject(dc, oldm);
		Sleep(mtime_0);
	}
	
       CDialog::OnMouseMove(nFlags, point);
}

-------------------------------------------------------------------

void CKw0::OnLButtonDown(UINT nFlags, CPoint point)
{
	OnOK();
	CDialog::OnLButtonDown(nFlags, point);
}




=============================================================================


	UpdateData(true);
	n = N;
	UpdateData(false);

	p = n*n;

	ms.Empty();
	ms = "\n     Матриця А[";
	t.Format(L"%i][%i] сформована!\n\n", n, n);
	ms += t;

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (k % 2 == 0)
			{
				t.Format(L"%4i\t", p);
				ms += t;
				p--;
			}
			else
			{
				t.Format(L"%4i\t", p - n + i + 1);
				ms += t;
			}
		}
		if (k % 2 != 0) p -= n;
		ms += "\n";
	}


	E.SetWindowTextW(ms);



=============================================================================

	SetWindowTextW(L"Заполнение квадратной матрицы");
	
	n = 9;
	p = n / 2;
	i = 1;



	for (k = 1; k <= p; k++)
	{
		for (j = k - 1; j < n - k + 1; j++) A[k - 1][j] = i++;
		for (j = k; j < n - k + 1; j++) A[j][n - k] = i++;
		for (j = n - k - 1; j >= k - 1; --j) A[n - k][j] = i++;
		for (j = n - k - 1; j >= k; j--) A[j][k - 1] = i++;

	}
	if (n % 2 == 1) A[p][p] = n*n;

	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			t.Format(L"%8i\t", A[k][j]);
			ms += t;
		}
		ms += "\n";
	}

	E.SetWindowTextW(ms);


=============================================================================

	n = 9;
	pic = 0;
	a = 200;
	b = 204;

	z = "*";
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;

	p = n / 2;
	i = 1;

	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			A[k][j] = a + rand() % (b - a);
			t.Format(L"%4i\t", A[k][j]);
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i",pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	pic = 9;
	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (j>n/2)
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (j<n / 2)
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (k>n / 2)
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (k<n / 2)
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (k>n-j-1)
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (k<n - j - 1)
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (k<j)
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (k>j)
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);


	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k>n - j - 1) || (k<j))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k<n - j - 1) || (k>j))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k>n - j - 1) || (k>j))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k<n - j - 1) || (k<j))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (((k<n - j - 1) || (k>j)) && ((k>n - j - 1) || (k<j)))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (((k<n - j - 1) || (k<j)) && ((k>n - j - 1) || (k>j)))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k>n/2) || (j>n/2))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k<n / 2) || (j<n / 2))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((n-k-1<n / 2) || (n-j-1>n / 2))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((n - k - 1>n / 2) || (n - j - 1<n / 2))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (((k>n / 2) || (j>n / 2)) && ((k<n / 2) || (j<n / 2)))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if (((n - k - 1>n / 2) || (n - j - 1<n / 2)) && ((n - k - 1<n / 2) || (n - j - 1>n / 2)))
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			else
			{
				t.Format(L"%4s\t", z);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((n / 2> k - j-1) && (n / 2 <k + j+1) && (j-1<n / 2))
			{
				t.Format(L"%4s\t", z);
			}
			else
			{
				t.Format(L"%4i\t", A[k][j]);
			}

			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((j - k - 1< n / 2) && (n >j + k - n / 2) && (j + 1>n / 2))
			{
				t.Format(L"%4s\t", z);
			}
			else
			{
				t.Format(L"%4i\t", A[k][j]);
			}

			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((n / 2< k + j + 1) && (n /2 > j-k - 1) && (k - 1<n / 2))
			{
				t.Format(L"%4s\t", z);
			}
			else
			{
				t.Format(L"%4i\t", A[k][j]);
			}

			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((n / 2> k - j -1) && (n > j+k-n/2 ) && (k+1 >n / 2))
			{
				t.Format(L"%4s\t", z);
			}
			else
			{
				t.Format(L"%4i\t", A[k][j]);
			}

			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\n\nРисунок номер: %i", pic);
	ms += t;
	pic++;
	E.SetWindowTextW(ms);

	pic = 41;
	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k>n - j-2) || (k-1<j))
			{
				t.Format(L"%4s\t", z);
			}
			else
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\nРисунок номер: %i", pic);
	ms += t; pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k+2>n - j) || (k>j-1))
			{
				t.Format(L"%4s\t", z);
			}
			else
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\nРисунок номер: %i", pic);
	ms += t; pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k<n - j) || (k>j-1))
			{
				t.Format(L"%4s\t", z);
			}
			else
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\nРисунок номер: %i", pic);
	ms += t; pic++;
	E.SetWindowTextW(ms);

	Sleep(mtime);
	ms.Empty();
	ms = "\nИсходная матрица A[";
	t.Format(L"%i][%i]\n\n", n, n);
	ms += t;
	for (k = 0; k < n; k++)
	{
		for (j = 0; j < n; j++)
		{
			if ((k<n - j) || (k<j+1))
			{
				t.Format(L"%4s\t", z);
			}
			else
			{
				t.Format(L"%4i\t", A[k][j]);
			}
			ms += t;
		}
		ms += "\n";
	}
	t.Format(L"\nРисунок номер: %i", pic);
	ms += t; pic++;
	E.SetWindowTextW(ms);


=============================================================================


	
	_getcwd(m_AppPath, _MAX_PATH);
	printf("Current directory is %s\n", m_AppPath);
	curdrive = _getdrive();
	printf("Current drive is %c = %i\n", curdrive + 'A'-1, curdrive-1);
	pth=m_AppPath;

	for(drive = 1; drive <= 26; drive++)
		if(!_chdrive(drive)) printf("%c: ", drive + 'A' - 1);

	printf("\n\nType drive letter to check: \n\n");
   
	// If we can switch to the drive, it exists.
    for( drive = 1; drive <= 26; drive++ )
    {
      if( !_chdrive( drive ) )
      {
         printf( "%c:", drive + 'A' - 1 );
         if( _getdcwd( drive, path_buffer, _MAX_PATH ) != NULL )
            printf( " (Current directory is %s)", path_buffer );
         putchar( '\n' );
      }
    }

    // Restore original drive.
    _chdrive( curdrive );


// ------------------------------------- ТЕОРИЯ ------------------

Using _getdrive(), _getch(), _putch(), _getdcwd(), _chdrive(), _mkdir(), _rmdir(), system()

 

Compiler: Visual C++ Express Edition 2005

Compiled on Platform: Windows XP Pro SP2

Header file: Standard

Additional library: none/default 

Additional project setting: Set project to be compiled as C

Project -> your_project_name Properties -> Configuration Properties -> C/C++ -> Advanced -> Compiled As: Compiled as C Code (/TC)

Other info: none

To do: Manipulating drive, directory and files

To show: Using _getdrive(), _getch(), _putch(), _getdcwd(), _chdrive(), _mkdir(), _rmdir() and system()


/* More example of the drive, directory and file */

#include <stdio.h>

#include <conio.h>

#include <direct.h>

#include <stdlib.h>

#include <ctype.h>

 

int main(void)

{

int chr, drive, curdrive;

static char path[_MAX_PATH];

char buffer[_MAX_PATH];

char newdir[50] = "\\testdir";

// char path1[50] = "C:\\WINNT\\System32\\config"; - Windows 2000

char path1[50] = "C:\\Windows\\System32\\config";

 

/* Save current drive. */

curdrive = _getdrive();

printf("Available drives in this machine are: \n");

 

/* If we can switch to the drive, it exists. */

for(drive = 1; drive <= 26; drive++)

if(!_chdrive(drive))

printf("%c: ", drive + 'A' - 1);

printf("\n\nType drive letter to check: ");

 

chr = _getch();

if(chr == 27)

printf("Illegal drive input\n");

if(isalpha(chr))

_putch(chr);

if(_getdcwd(toupper(chr) - 'A' + 1, path, _MAX_PATH) != NULL)

printf("\nCurrent directory on that drive is:\n%s\n", path);


/* Restore original drive. */

_chdrive(curdrive);

 

/* Get the current working directory */

if(_getcwd(buffer, _MAX_PATH) == NULL)

perror("_getcwd error");

else

printf("\nCurrent working directory is: %s\n", buffer);

 

/* Create a directory and then delete */

if(_mkdir(newdir) == 0)

{

printf("\nDirectory %s was successfully created\n", newdir);

system("dir \\testdir");


if(_rmdir(newdir) == 0)

printf("\nDirectory %s was successfully removed\n", newdir);

else

printf("\nProblem removing directory %s\n", newdir);

}

else

printf("\nProblem creating directory %s\n", newdir);

 

/* Uses _chdir() function to verify that a given directory exists */

printf("\n");

printf("Change directory........\n");

if(_chdir(path1))

printf("Unable to locate the directory: %s\n", path1);

else

system("dir *.log /a");

printf("\n");

return 0;

}



// ------------------------------------- ТЕОРИЯ ------------------
	


 	// Запоминаем текущую директорию
	curdrive = _getdrive();

	// Перебор существующих
	for(drive = 1; drive <= 26; drive++)
		if(!_chdrive(drive))
			printf("%c: ", drive+'A'-1);
	_chdrive( curdrive );
	
	// Проверка самостоятельно 
	_getcwd(m_AppPath, _MAX_PATH);
	printf("\n\nтекущая директория\\>> %s\n", m_AppPath);

	

	Следующая программа выводит элементы полного пути C:\MYDIR\MYFILE.DAT:

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
char fname[9];
char dir[64];
char drive[3];
char ext[5];
 _splitpath("C:\\MYDIR\\MYFILE.DAT", drive, dir, fname, ext);
printf("%s %s %s %s\n", drive, dir, fname, ext);
return 0;
}







	/*
	printf("\nСуществуют директории: ");
	for(drive = 1; drive <= 26; drive++)
		if(!_chdrive(drive)) printf("%c: ", drive + 'A' - 1);

	_chdrive(curdrive);
	*/



////////////////////////// S T O P ////////////////////////////////////////

 else
	{
		cout<<endl<<endl;
		_chdir(pvd);
		//system("dir *.*");
		cout<<" ---------------------------------------------- "<<endl;
		cout<<"|               Диск R: подключен              |"<<endl;
		cout<<"|          Отключаем виртуальный диск R:       |"<<endl;
		cout<<" ---------------------------------------------- "<<endl;
		Sleep(tms);
		system(d_vdx);
		cout<<" ============================================== "<<endl;
		cout<<"|               Диск R: отключен               |"<<endl;
		cout<<" ============================================== "<<endl;
		_chdir(host_dir);
		system(kill_host);
		Sleep(tms);
		system(restore_host);
		Sleep(tms);
		
        cout<<"\nОтключаем почтовую службу"<<endl;
        WinExec(mail_stop,SW_RESTORE);
    	Sleep(tms);

		cout<<"\nОтключаем Apache Service"<<endl;
		ZeroMemory(&szi,sizeof(STARTUPINFO));
		szi.cb = sizeof(szi);
		ZeroMemory( &pci, sizeof(pci) );
	    szCmdline = _wcsdup(apache_stop);
		CreateProcess(NULL, szCmdline,NULL, NULL, FALSE, 0, NULL, NULL, &szi, &pci);		
		WinExec(mapache_stop,SW_RESTORE);
		Sleep(tms);
 
		cout<<"\nОтключаем MySQL Service"<<endl;
		ZeroMemory(&szi,sizeof(STARTUPINFO));
		szi.cb = sizeof(szi);
		ZeroMemory( &pci, sizeof(pci) );
	    szCmdline = _wcsdup(mysql_stop);
		CreateProcess(NULL, szCmdline,NULL, NULL, FALSE, 0, NULL, NULL, &szi, &pci);		
		Sleep(tms);

		_chdir(lhost_dir);

		Sleep(tms);

		cout<<endl<<endl;
		cout<<" ---------------------------------------------- "<<endl;
		cout<<"| Задание выполнено. Система готова к работе.  |"<<endl;
		cout<<" ---------------------------------------------- "<<endl;

		//system("dir *.*");
	}


//////////////////////// S T A R T ////////////////////////////////

	    cout<<endl<<endl;
		cout<<" ---------------------------------------------- "<<endl;
		cout<<"|          Подключаем виртуальный диск R:      |"<<endl;
		cout<<" ---------------------------------------------- "<<endl;
		Sleep(tms);
		system(m_vdx);
		cout<<" ============================================== "<<endl;
		cout<<"|               Диск R: подключен              |"<<endl;
		cout<<" ============================================== "<<endl;
		_chdir(host_dir);
		system(kill_host);
		Sleep(tms);
		system(copy_host);
		Sleep(tms);

        cout<<"\nЗапускаем почтовую службу"<<endl;
        WinExec(mail_start,SW_RESTORE);
		Sleep(tms);

		cout<<"\nЗапускаем Apache Service"<<endl;
		ZeroMemory(&szi,sizeof(STARTUPINFO));
		szi.cb = sizeof(szi);
		ZeroMemory( &pci, sizeof(pci) );
	    szCmdline = _wcsdup(apache_start);
		CreateProcess(NULL, szCmdline,NULL, NULL, FALSE, 0, NULL, NULL, &szi, &pci);		
		WinExec(mapache_start,SW_RESTORE);
		Sleep(tms);

		cout<<"\nЗапускаем MySQL Service"<<endl;
		ZeroMemory(&szi,sizeof(STARTUPINFO));
		szi.cb = sizeof(szi);
		ZeroMemory( &pci, sizeof(pci) );
	    szCmdline = _wcsdup(mysql_start);
		CreateProcess(NULL, szCmdline,NULL, NULL, FALSE, 0, NULL, NULL, &szi, &pci);		
		Sleep(tms);

		cout<<endl<<endl;
		cout<<" ---------------------------------------------- "<<endl;
		cout<<"| Задание выполнено. Система готова к работе.  |"<<endl;
		cout<<" ---------------------------------------------- "<<endl;



// ---------------------------------------------------------------

	int n, n1, n2, n3, n4;
	UpdateData(true);
	n = N;
	UpdateData(false);

	n4 = n % 10;
	n3 = (n - n4) / 10 % 10;
	n2 = (n - n4 - n3 * 10) / 100 % 10;
	n1 = n / 1000;


	CClientDC dc(this);
	GetClientRect(&rc);

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");
	
	ms.Empty();

		switch (n1)
		{
		case 0: t = "";
			break;
		case 1: t = "одна тысяча ";
			break;
		case 2: t = "две тысячи ";
			break;
		case 3: t = "три тысячи ";
			break;
		case 4: t = "четыре тысячи ";
			break;
		case 5: t = "пять тысяч ";
			break;
		case 6: t = "шесть тысяч ";
			break;
		case 7: t = "семь тысяч ";
			break;
		case 8: t = "восемь тысяч ";
			break;
		case 9: t = "девять тысяч ";
			break;
		}
		ms += t;


		switch (n2)
		{
		case 0: t = "";
			break;
		case 1: t = "сто ";
			break;
		case 2: t = "двести ";
			break;
		case 3: t = "триста ";
			break;
		case 4: t = "четыреста ";
			break;
		case 5: t = "пятьсот ";
			break;
		case 6: t = "шестьсот ";
			break;
		case 7: t = "семьсот ";
			break;
		case 8: t = "восемьсот ";
			break;
		case 9: t = "девятьсот ";
			break;
		}
		ms += t;

		switch (n3)
		{
		case 0: t = "";
			break;
		case 1:
			switch (n4)
			{
			case 0: t = "десять ";
				break;
			case 1: t = "одиннадцать ";
				break;
			case 2: t = "двенадцать ";
				break;
			case 3: t = "тринадцать ";
				break;
			case 4: t = "четырнадцать ";
				break;
			case 5: t = "пятнадцать ";
				break;
			case 6: t = "шестнадцать ";
				break;
			case 7: t = "семнадцать ";
				break;
			case 8: t = "восемнадцать ";
				break;
			case 9: t = "девятнадцать ";
				break;
			}
			break;
		case 2: t = "двадцать ";
			break;
		case 3: t = "тридцать ";
			break;
		case 4: t = "сорок ";
			break;
		case 5: t = "пятьдесят ";
			break;
		case 6: t = "шестьдесят ";
			break;
		case 7: t = "семьдесят ";
			break;
		case 8: t = "восемьдесят ";
			break;
		case 9: t = "девяносто ";
			break;
		}
		ms += t;

		if (n3 != 1)
		{
			switch (n4)
			{
			case 0: t = "";
				break;
			case 1: t = "один";
				break;
			case 2: t = "два";
				break;
			case 3: t = "три";
				break;
			case 4: t = "четыре";
				break;
			case 5: t = "пять";
				break;
			case 6: t = "шесть";
				break;
			case 7: t = "семь";
				break;
			case 8: t = "восемь";
				break;
			case 9: t = "девять";
				break;
			}
			ms += t;
		}
		else
		{
			t = "";
			ms += t;
		}

	

		hold = (HFONT)SelectObject(dc, hNew);
		SetTextColor(dc, RGB(255, 255, 255));

		w.left = rc.left;
		w.right = rc.right;
		w.top = rc.top + 200;
		w.bottom = rc.bottom;
		dc.FillSolidRect(&w, RGB(0, 0, 0));
		dc.TextOutW(75, 320, ms, ms.GetLength());
	
	hold = (HFONT)SelectObject(dc, hbk);


=============================================================================
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

	CClientDC dc(this);
	GetClientRect(&rc);
	RH = abs(rc.right - rc.left);
	RW = abs(rc.bottom - rc.top);
	dx = RH / 3;
	dy = RW / 2;
	j = 0;
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 3; i++)
		{
			w.top = k*dy;
			w.bottom = (k + 1)*dy;
			w.left = i*dx;
			w.right = (i + 1)*dx;
			kw[j] = w;
			j++;
		}
	}

	CStdioFile inf(L"data.txt", CFile::modeCreate | CFile::modeWrite);
	
	

	if (PtInRect(&kw[0], point))
	{
		ms = "0";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		CKw0 dlg;
		dlg.DoModal();
	}
	
	if (PtInRect(&kw[1], point))
	{
		ms = "1";
		inf.WriteString(ms); // записать в файл
		inf.Flush();
		inf.Close();
		CKw0 dlg;
		dlg.DoModal();
	}

------------------------------------------
	ClientToScreen(&w);
	ScreenToClient(&w);

	CStdioFile otf;
	otf.Open(L"data.txt", CFile::modeRead);
	
	otf.ReadString(ms);
	otf.Close();

	k=_wtoi(ms);


=============================================================================

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

BOOL CCircleToRectangleDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
	{
		switch (pMsg->wParam)
		{
		case 'K':
		{
			this->Invalidate();
			CPaintDC dc(this);
			GetClientRect(&wHd);
			ClientToScreen(&wHd);

			int x_max = wHd.Size().cx; // max x
			int y_max = wHd.Size().cy; // max y
			int cxx = x_max / 2;
			int cyy = y_max / 2;
			int RR = (x_max + y_max) / st;
			int x1 = cxx - RR;
			int y1 = cyy - RR;
			int x2 = cxx + RR;
			int y2 = cyy + RR;
			dc.Rectangle(x1, y1, x2, y2);
			break;
		}
		case 'C':
		{
			this->Invalidate();
			CPaintDC dc(this);
			GetClientRect(&wHd);
			ClientToScreen(&wHd);

			int x_max = wHd.Size().cx; // max x
			int y_max = wHd.Size().cy; // max y

			int cxx = x_max / 2;
			int cyy = y_max / 2;
			int RR = (x_max + y_max) / st;

			int x1 = cxx - RR;
			int y1 = cyy - RR;
			int x2 = cxx + RR;
			int y2 = cyy + RR;
			dc.Ellipse(x1, y1, x2, y2);
			break;
		}

		case 'R':
		{
			// http://www.color-hex.com/

			c[0] = 0xFFFFFF; // белый
			c[1] = 0x0000FF; // красный
			c[2] = 0x00B2FF; // оранжевый
			c[3] = 0x00FFFF; // желтый
			c[4] = 0x00CC00; // зеленый
			c[5] = 0xFEC880; // голубой
			c[6] = 0xCC0000; // синий
			c[7] = 0xCC0099; // фиолетовый
			c[8] = 0x000000; // черный   
			c[9] = 0xDFD8DA; // серый
			
			this->Invalidate();
			CPaintDC dc(this);
			GetClientRect(&wHd);
			ClientToScreen(&wHd);
			ScreenToClient(&wHd);


			int x_max = wHd.Size().cx; // max x
			int y_max = wHd.Size().cy; // max y

			i = 0; 	k = 1+abs(x_max) / 9;
			
			wd = wHd;

			for (j = 0; j < x_max; j += k)
			{
				wd.top = 0;
				wd.left = j;
				wd.right = j + k;
				wd.bottom = y_max;

				dc.FillSolidRect(&wd, c[i]);
				
				i++;
			}

			break;
		}

		case VK_ESCAPE:
		{
			AfxMessageBox(L"Нажатие на кнопку <ESC>", MB_OK | MB_ICONINFORMATION);
			this->Invalidate();
			break;
		}
			
			// другие фигурки ...
		}
		return true;
	}
		break;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CCircleToRectangleDlg::OnFiguraClear()
{
	// TODO: Add your command handler code here
	this->Invalidate();
}

-----------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int i, k, n;
char AB[256];
string ms, t;
fstream otf;

void main()
{
	setlocale(LC_ALL, "rus");
	cout << "Практическая работа. Строки. \n";
	cout << "автор:Моренко А.А.\n\n";
	
	ms = "УЧИСЬ КОДИРОВАТЬ И БУДЕШЬ СУПЕР КОДЕРОМ";

	cout << endl << "Исходная фраза: \n" << ms << endl;

	k = 65;
	for (i = 192; i < 256; i++)
	{
		AB[k - 64] = char(i);
		k++;
	}

	// КОДИРОВАНИЕ НОВОЙ ФРАЗЫ

	cout << "\n\nКодированная фраза: \n";


	otf.open("A.txt", ios::out);
	if (!otf) return;

	n = ms.size();
	for (i = 0; i < n; i++)
	{
		if (ms[i] != ' ')
		{
			k = (char)ms[i] + 65;
			otf << k + 64;
			cout << k + 64;
		}
		else
		{
			otf << '.';
			cout << '.';
		}
	}

	otf.flush();
	otf.close();

	cout << endl << endl;
	system("pause");
}

**********************************************************************
pN.SetRange32(1,12);


void CViknoSpinDlg::OnDeltaposSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	
	int n,p1,p2;
	
	UpdateData(TRUE);
	mB=pNMUpDown->iPos+pNMUpDown->iDelta;
	n=mB;
	UpdateData(FALSE);

	p1=n*n;
	p2=n*n*n;

	msg.Format(L"\n\t%i^2=%i", n,p1);	
	tmp.Format(L"\n\t%i^3=%i", n,p2);	
	msg+=tmp;


	E.SetWindowTextW(msg);

	*pResult = 0;


}



void CViknoSpinDlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	int n,p1,p2;
	
	UpdateData(TRUE);
	n=mB;
	UpdateData(FALSE);

	p1=n*n;
	p2=n*n*n;

	msg.Format(L"\n\t%i^2=%i", n,p1);	
	tmp.Format(L"\n\t%i^3=%i", n,p2);	
	msg+=tmp;

	E.SetWindowTextW(msg);


}

-------------------------------------------------------------------------------

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

----------------------------------------------------

BOOL CCircleToRectangleDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
	{
		switch (pMsg->wParam)
		{
		case 'K':
		{
			this->Invalidate();
			CPaintDC dc(this);
			GetClientRect(&wHd);
			ClientToScreen(&wHd);

			int x_max = wHd.Size().cx; // max x
			int y_max = wHd.Size().cy; // max y
			int cxx = x_max / 2;
			int cyy = y_max / 2;
			int RR = (x_max + y_max) / st;
			int x1 = cxx - RR;
			int y1 = cyy - RR;
			int x2 = cxx + RR;
			int y2 = cyy + RR;
			dc.Rectangle(x1, y1, x2, y2);
			break;
		}
		case 'C':
		{
			this->Invalidate();
			CPaintDC dc(this);
			GetClientRect(&wHd);
			ClientToScreen(&wHd);

			int x_max = wHd.Size().cx; // max x
			int y_max = wHd.Size().cy; // max y

			int cxx = x_max / 2;
			int cyy = y_max / 2;
			int RR = (x_max + y_max) / st;

			int x1 = cxx - RR;
			int y1 = cyy - RR;
			int x2 = cxx + RR;
			int y2 = cyy + RR;
			dc.Ellipse(x1, y1, x2, y2);
			break;
		}

		case 'R':
		{
			// http://www.color-hex.com/

			c[0] = 0xFFFFFF; // белый
			c[1] = 0x0000FF; // красный
			c[2] = 0x00B2FF; // оранжевый
			c[3] = 0x00FFFF; // желтый
			c[4] = 0x00CC00; // зеленый
			c[5] = 0xFEC880; // голубой
			c[6] = 0xCC0000; // синий
			c[7] = 0xCC0099; // фиолетовый
			c[8] = 0x000000; // черный   
			c[9] = 0xDFD8DA; // серый
			
			this->Invalidate();
			CPaintDC dc(this);
			GetClientRect(&wHd);
			ClientToScreen(&wHd);
			ScreenToClient(&wHd);


			int x_max = wHd.Size().cx; // max x
			int y_max = wHd.Size().cy; // max y

			i = 0; 	k = 1+abs(x_max) / 9;
			
			wd = wHd;

			for (j = 0; j < x_max; j += k)
			{
				wd.top = 0;
				wd.left = j;
				wd.right = j + k;
				wd.bottom = y_max;

				dc.FillSolidRect(&wd, c[i]);
				
				i++;
			}

			break;
		}

		case VK_ESCAPE:
		{
			AfxMessageBox(L"Нажатие на кнопку <ESC>", MB_OK | MB_ICONINFORMATION);
			this->Invalidate();
			break;
		}
			
			// другие фигурки ...
		}
		return true;
	}
		break;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CCircleToRectangleDlg::OnFiguraCicle()
{
	// TODO: Add your command handler code here
	this->Invalidate();
	CPaintDC dc(this);
	GetClientRect(&wHd);
	ClientToScreen(&wHd);

	int x_max = wHd.Size().cx; // max x
	int y_max = wHd.Size().cy; // max y

	int cxx = x_max / 2;
	int cyy = y_max / 2;
	int RR = (x_max + y_max) / st;

	int x1 = cxx - RR;
	int y1 = cyy - RR;
	int x2 = cxx + RR;
	int y2 = cyy + RR;
	dc.Ellipse(x1, y1, x2, y2);
}


void CCircleToRectangleDlg::OnFiguraRectangle()
{
	// TODO: Add your command handler code here
	this->Invalidate();
	CPaintDC dc(this);
	GetClientRect(&wHd);
	ClientToScreen(&wHd);

	int x_max = wHd.Size().cx; // max x
	int y_max = wHd.Size().cy; // max y
	int cxx = x_max / 2;
	int cyy = y_max / 2;
	int RR = (x_max + y_max) / st;
	int x1 = cxx - RR;
	int y1 = cyy - RR;
	int x2 = cxx + RR;
	int y2 = cyy + RR;
	dc.Rectangle(x1, y1, x2, y2);
}

void CCircleToRectangleDlg::OnFiguraRainbow()
{
	// TODO: Add your command handler code here
	// http://www.color-hex.com/

	c[0] = 0xFFFFFF; // белый
	c[1] = 0x0000FF; // красный
	c[2] = 0x00B2FF; // оранжевый
	c[3] = 0x00FFFF; // желтый
	c[4] = 0x00CC00; // зеленый
	c[5] = 0xFEC880; // голубой
	c[6] = 0xCC0000; // синий
	c[7] = 0xCC0099; // фиолетовый
	c[8] = 0x000000; // черный   
	c[9] = 0xDFD8DA; // серый

	this->Invalidate();
	CPaintDC dc(this);
	GetClientRect(&wHd);
	ClientToScreen(&wHd);
	ScreenToClient(&wHd);


	int x_max = wHd.Size().cx; // max x
	int y_max = wHd.Size().cy; // max y

	i = 0; 	k = 1 + abs(x_max) / 9;

	wd = wHd;

	for (j = 0; j < x_max; j += k)
	{
		wd.top = 0;
		wd.left = j;
		wd.right = j + k;
		wd.bottom = y_max;

		dc.FillSolidRect(&wd, c[i]);

		i++;
	}

}


void CCircleToRectangleDlg::OnFiguraClear()
{
	// TODO: Add your command handler code here
	this->Invalidate();
}


void CCircleToRectangleDlg::OnFiguraExit()
{
	// TODO: Add your command handler code here
	AfxMessageBox(L"Вы вышли из программы.", MB_OK | MB_ICONINFORMATION);
	OnOK();
}

-----------------------------------------------------------

void CPravDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	Invalidate();
	UpdateData(TRUE);
	n=N;
	UpdateData(FALSE);
	
	CPaintDC dc(this);
		GetClientRect(&rc);
		
		
		int Lx,Px,Vy,Ny;
		Lx=rc.left;
		Px=rc.right;
		Vy=rc.top;
		Ny=rc.bottom;

		int Cx,Cy;
		Cx=abs(Px-Lx)/2;
		Cy=abs(Ny-Vy)/2;

		cf=RGB(89,89,89);
		hN=CreatePen(PS_SOLID,50,cf);
		hS=(HPEN)SelectObject(dc,hN);

		int r=200;

		//n=6;
		m=360/n;
		f=0;

		x=Cx;
		y=Cy;

		x=x+r*cos(f+PI/4);
		y=y+r*sin(f+PI/4);

		MoveToEx(dc,x,y,NULL);
		
		for(i=1;i<=n;i++)
		{
			f+=m;
			x=r*cos(f*PI/180+PI/4);
			y=r*sin(f*PI/180+PI/4);
			LineTo(dc,x+Cx,y+Cy);
		}



		SelectObject(dc,hS);
		DeleteObject(hN);	
	
	//*pResult = 0;
}

-----------------------------------------------
#include <iostream>
#include <fstream>

using namespace std;

int a [15] [15];
int i,j,n,m,k;
fstream inf;
int s[15];

void main()

{
	setlocale (LC_ALL,"rus");
	inf.open("data.txt", ios::in);
	if(!inf) return;
	
	inf>>n;
	
	for (i=0;  i<n; i++)
	{
		for(j=0; j<n;j++)
		{
			inf>>a[i][j];
			cout<<" "<<a[i][j];
		}
		cout<<endl;
	}
	cout<<endl;

	inf.close();

	int p;
	for(p=0;p<(2*n+2);p++) s[p]=0;

	for(p=0;p<2*n;p++)
	{
		for(k=0;k<n;k++)
		{
			if(p<n) s[p]+=a[k][p]; else s[p]+=a[p][k];
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)s[p]+=a[i][j];
			if(i==(n-j))s[p+1]+=a[i][j];
		}
	}

	for(k=0;k<(2*n+2);k++) cout<<k+1<<" -> "<<s[k]<<endl;

	cout<<endl<<endl;		
	system("pause");
}

--------------------------------------------------
#define PI 3.14159268

void CGsinDlg::OnExit()
{
	// TODO: Add your command handler code here
	OnOK();
}


void CGsinDlg::OnRest()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	GetClientRect(&rc);
	hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
	hold=(HFONT)SelectObject(dc,hNew);
		
	dc.FillSolidRect(&rc,RGB(255,255,255));
	msg.Format(L"График тригонометрической функции");
	cf=RGB(255,255,255);
	c=RGB(50,70,120);
	SetTextColor(dc,c);
	SetBkColor(dc,cf);
	TextOutW(dc,rc.left+150,rc.bottom-250,msg,msg.GetLength());


	DeleteObject(hNew);		
	hold=(HFONT)SelectObject(dc,hbk);		

}


void CGsinDlg::OnSinn()
{
	// TODO: Add your command handler code here
		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		msg.Format(L"График тригонометрической функции");
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		TextOutW(dc,rc.left+150,rc.bottom-450,msg,msg.GetLength());



		COLORREF crFunction = RGB(190,0,0);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,50,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,50,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2+50);
		MoveToEx(dc,cxClient/2,50,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2+50);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200+50,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-120,cyClient/200+140,L"y=sin(x)",8);
		

		// рисуем график y=sin(x)
		double Xmin;//минимальный Х
		double Xmax;//максимальны Х
		double x,y;//значений функций
		int width,height;//высота, ширина делений

		Xmin=-2*PI;
		Xmax=2*PI;

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		for(x=Xmin;x<=Xmax;x+=0.001)
		{
			y=-sin(x);//минус так как ось У направлена вниз
			SetPixel(dc,width*x+cxClient/2,height*y+cyClient/2,crFunction);
			
			//width* - коэф. для оси Х
			//height* - коэф. для оси У
		}

		
		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);		

}


void CGsinDlg::OnCoss()
{
	// TODO: Add your command handler code here
		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		msg.Format(L"График тригонометрической функции");
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		TextOutW(dc,rc.left+150,rc.bottom-450,msg,msg.GetLength());



		COLORREF crFunction = RGB(0,190,0);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,50,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,50,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2+50);
		MoveToEx(dc,cxClient/2,50,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2+50);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200+50,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-120,cyClient/200+140,L"y=cos(x)",8);
		

		// рисуем график y=sin(x)
		double Xmin;//минимальный Х
		double Xmax;//максимальны Х
		double x,y;//значений функций
		int width,height;//высота, ширина делений

		Xmin=-2*PI;
		Xmax=2*PI;

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		for(x=Xmin;x<=Xmax;x+=0.001)
		{
			y=-cos(x);//минус так как ось У направлена вниз
			SetPixel(dc,width*x+cxClient/2,height*y+cyClient/2,crFunction);
			
			//width* - коэф. для оси Х
			//height* - коэф. для оси У
		}

		
		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);		


}


void CGsinDlg::OnPolar1()
{
	// TODO: Add your command handler code here

		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		msg.Format(L"Полярная");
		TextOutW(dc,rc.left+50,rc.bottom-450,msg,msg.GetLength());
		msg.Format(L"система");
		TextOutW(dc,rc.left+50,rc.bottom-420,msg,msg.GetLength());
		msg.Format(L"координат");
		TextOutW(dc,rc.left+50,rc.bottom-390,msg,msg.GetLength());

		COLORREF crFunction = RGB(0,190,0);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,00,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2);
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-120,cyClient/200+140,L"R=200",5);
		

		// рисуем график y=sin(x)

		double x,y;//значений функций
		int width,height;//высота, ширина делений

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		double r,f;
	    r=200;
		f=0;
		do 
		{
			x=r*cos(f);
			y=r*sin(f);
			SetPixel(dc,x+cxClient/2,y+cyClient/2,crFunction);
			f+=0.01;
		} while(f<=360);


		
		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);		


}


void CGsinDlg::OnPolar2()
{
	// TODO: Add your command handler code here

		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		msg.Format(L"Полярная");
		TextOutW(dc,rc.left+50,rc.bottom-450,msg,msg.GetLength());
		msg.Format(L"система");
		TextOutW(dc,rc.left+50,rc.bottom-420,msg,msg.GetLength());
		msg.Format(L"координат");
		TextOutW(dc,rc.left+50,rc.bottom-390,msg,msg.GetLength());

		COLORREF crFunction = RGB(230,0,0);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,00,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2);
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-180,cyClient/200+110,L"спираль",7);
		TextOut(dc,cxClient-cxClient/100*2-180,cyClient/200+140,L"\"АРХИМЕДА\"",10);

		// рисуем график y=sin(x)

		double x,y;//значений функций
		int width,height;//высота, ширина делений

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		double r,f;
	    r=0;
		f=0.1;
		do 
		{
			r+=0.05;
			x=r*cos(f);
			y=r*sin(f);
			SetPixel(dc,x+cxClient/2,y+cyClient/2,crFunction);
			f+=0.01;
		} while(f<=360);

		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);	
}


void CGsinDlg::OnPolar3()
{
	// TODO: Add your command handler code here

		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		msg.Format(L"Полярная");
		TextOutW(dc,rc.left+50,rc.bottom-450,msg,msg.GetLength());
		msg.Format(L"система");
		TextOutW(dc,rc.left+50,rc.bottom-420,msg,msg.GetLength());
		msg.Format(L"координат");
		TextOutW(dc,rc.left+50,rc.bottom-390,msg,msg.GetLength());

		COLORREF crFunction = RGB(250,100,50);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,00,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2);
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-120,cyClient/200+140,L"k=7",3);
		

		// рисуем график y=sin(x)

		double x,y;//значений функций
		int width,height;//высота, ширина делений

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		double r,f;
		int a,k;
		a=200;
		k=7;
	    r=200;
		f=0.1;
		do 
		{
			r=a*sin(k*f);
			x=r*cos(f);
			y=r*sin(f);
			SetPixel(dc,x+cxClient/2,y+cyClient/2,crFunction);
			f+=0.01;
		} while(f<=360);


		
		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);	

}


void CGsinDlg::OnPolar4()
{
	// TODO: Add your command handler code here
		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		msg.Format(L"Полярная");
		TextOutW(dc,rc.left+50,rc.bottom-450,msg,msg.GetLength());
		msg.Format(L"система");
		TextOutW(dc,rc.left+50,rc.bottom-420,msg,msg.GetLength());
		msg.Format(L"координат");
		TextOutW(dc,rc.left+50,rc.bottom-390,msg,msg.GetLength());

		COLORREF crFunction = RGB(250,100,50);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,00,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2);
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-120,cyClient/200+140,L"k=3",3);
		

		// рисуем график y=sin(x)

		double x,y;//значений функций
		int width,height;//высота, ширина делений

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		double r,f;
		int a,k;
		a=200;
		k=3;
	    r=200;
		f=0.1;
		do 
		{
			r=a*sin(k*f);
			x=r*cos(f);
			y=r*sin(f);
			SetPixel(dc,x+cxClient/2,y+cyClient/2,crFunction);
			f+=0.01;
		} while(f<=360);


		
		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);	

}


void CGsinDlg::OnPolar5()
{
	// TODO: Add your command handler code here
		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		msg.Format(L"Полярная");
		TextOutW(dc,rc.left+50,rc.bottom-450,msg,msg.GetLength());
		msg.Format(L"система");
		TextOutW(dc,rc.left+50,rc.bottom-420,msg,msg.GetLength());
		msg.Format(L"координат");
		TextOutW(dc,rc.left+50,rc.bottom-390,msg,msg.GetLength());

		COLORREF crFunction = RGB(250,100,50);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,00,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2);
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-120,cyClient/200+140,L"k=5",3);
		

		// рисуем график y=sin(x)

		double x,y;//значений функций
		int width,height;//высота, ширина делений

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		double r,f;
		int a,k;
		a=200;
		k=5;
	    r=200;
		f=0.1;
		do 
		{
			r=a*sin(k*f);
			x=r*cos(f);
			y=r*sin(f);
			SetPixel(dc,x+cxClient/2,y+cyClient/2,crFunction);
			f+=0.01;
		} while(f<=360);


		
		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);	

}


void CGsinDlg::OnPolar6()
{
	// TODO: Add your command handler code here


		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		msg.Format(L"Полярная");
		TextOutW(dc,rc.left+50,rc.bottom-450,msg,msg.GetLength());
		msg.Format(L"система");
		TextOutW(dc,rc.left+50,rc.bottom-420,msg,msg.GetLength());
		msg.Format(L"координат");
		TextOutW(dc,rc.left+50,rc.bottom-390,msg,msg.GetLength());

		COLORREF crFunction = RGB(250,100,50);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,00,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2);
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-120,cyClient/200+140,L"k=129",5);
		

		// рисуем график y=sin(x)

		double x,y;//значений функций
		int width,height;//высота, ширина делений

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		double r,f;
		int a,k;
		a=200;
		k=128;
	    r=200;
		f=0.1;
		do 
		{
			r=a*sin(k*f);
			x=r*cos(f);
			y=r*sin(f);
			SetPixel(dc,x+cxClient/2,y+cyClient/2,crFunction);
			f+=0.01;
		} while(f<=360);


		
		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);	
}


void CGsinDlg::OnPolar7()
{
	// TODO: Add your command handler code here

		CClientDC dc(this);
		GetClientRect(&rc);
		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_DONTCARE,L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);
		
		dc.FillSolidRect(&rc,RGB(255,255,255));
		
		cf=RGB(255,255,255);
		c=RGB(50,70,120);
		SetTextColor(dc,c);
		SetBkColor(dc,cf);
		msg.Format(L"Полярная");
		TextOutW(dc,rc.left+50,rc.bottom-450,msg,msg.GetLength());
		msg.Format(L"система");
		TextOutW(dc,rc.left+50,rc.bottom-420,msg,msg.GetLength());
		msg.Format(L"координат");
		TextOutW(dc,rc.left+50,rc.bottom-390,msg,msg.GetLength());

		COLORREF crFunction = RGB(250,100,50);//цвет графика
		COLORREF crAxes = RGB(89,89,250);//цвет осей (линий)
		COLORREF crMarks = RGB(0,0,160);//цвет отметок на шкале
		COLORREF crXYLines = RGB(140,70,0);//название осей
		COLORREF crDeleniya = RGB(0,0,165);//цвет текста


		HPEN hPenOxy,hOldPen;
		hPenOxy=CreatePen(PS_SOLID,2,crAxes);//создаем кисть цветом "crOxy"
		hOldPen = (HPEN)SelectObject(dc,hPenOxy);

		SetTextColor(dc,crAxes);//устанавливаем цвет текста
		int cxClient,cyClient;
		cyClient = rc.bottom;//высота
		cxClient = rc.right;//ширина
	
		//выводим ось OX
		MoveToEx(dc,0,cyClient/2,NULL);
		LineTo(dc,cxClient,cyClient/2);
		//выводим стрелочку
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2-cyClient/100*2);
		MoveToEx(dc,cxClient,cyClient/2,NULL);
		LineTo(dc,cxClient-cxClient/100*2,cyClient/2+cyClient/100*2);
		//рисуем ось OY
		MoveToEx(dc,cxClient/2,00,NULL);
		LineTo(dc,cxClient/2,cyClient);
		//выводим стрелочку
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2-cxClient/100*2,cyClient/100*2);
		MoveToEx(dc,cxClient/2,0,NULL);
		LineTo(dc,cxClient/2+cxClient/100*2,cyClient/100*2);
		//название осей
		SetTextColor(dc,crXYLines);
		TextOut(dc,cxClient-cxClient/100*2-30,cyClient/2+cyClient/100*2,L"OX",2);
		TextOut(dc,cxClient/2+cxClient/100*2.5,cyClient/200,L"OY",2);
		TextOut(dc,cxClient-cxClient/100*2-150,cyClient/200+140,L"КАРДИОИДА",9);
		

		// рисуем график y=sin(x)

		double x,y;//значений функций
		int width,height;//высота, ширина делений

		//ширину области деленим на колличество делений
		width=cxClient/12;
		height=cyClient/4;

		double e,r,f;
		int a,b,k;
		a=90;
		b=70;
		k=82;
		e=a/b;
	    r=200;
		f=0;
		do 
		{
			x=(b+e*b)*cos(e*f)-k*cos(f+e*f);
			y=(b+e*b)*sin(e*f)-k*sin(f+e*f);
			SetPixel(dc,x+cxClient/2,y+cyClient/2,crFunction);
			f+=0.01;
		} while(f<=360);


		
		SelectObject(dc,hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);	

/*
    a:=70;
    b:=70;
    k:=70;
    e:=a/b;
    f:=0;
    c:=15;
    while(f<=360) do
    begin
      x:=320+trunc((b+e*b)*cos(e*f)-k*cos(f+e*f));
      y:=240+trunc((b+e*b)*sin(e*f)-k*sin(f+e*f));;
      putpixel(x,y,15);
      f:=f+0.01;
    end;

*/


}


--------------------------------------------------------------------

#define mtime 298
#define PI 3.14159268

private:

	HFONT hold, hNew, hbk;
	HBRUSH m, oldm;
	COLORREF cf, c[25];

	CPen d, oldd;
	CBitmap pic;
	CRect rc,w,kw[12];

	CString ms,t, z;

	int Matrix[50][50];
	int RH, RW, k, i, j, cx,cy, dx, dy;
	bool fg;

--------------------------------------------------------------------

		GetClientRect(&rc);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
		hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");

		t = "Зона перемещения объекта";

		hold = (HFONT)SelectObject(dc, hNew);
		SetTextColor(dc, c[5]);
		dc.TextOutW(185, 80, t, t.GetLength());
		w.left = rc.left;
		w.right = rc.right;
		w.top = rc.top + 150;
		w.bottom = rc.bottom;
		dc.FillSolidRect(&w, RGB(0, 0, 0));
		hold = (HFONT)SelectObject(dc, hbk);

---------------------------------------------------------------------

	CClientDC dc(this);
	GetClientRect(&rc);
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top + 150;
	w.bottom = rc.bottom;
	dc.FillSolidRect(&w, RGB(0, 0, 0));

	double xx, yy, xmin, xmax;
	CRect ww, mw;

	xmin = -2 * PI;
	xmax = 2 * PI;

	cx = w.right / 2;
	cy = w.bottom / 2 + 70;

	dx = w.right / 12;
	dy = w.bottom / 6;

	CBrush br1(c[2]), br2(c[7]), br3(c[5]);
	k = 0;
	do
	{
		for (xx = xmin; xx < xmax; xx += 0.01)
		{
			yy = -sin(xx);
			ww.left = xx*dx + cx;
			ww.right = xx*dx + cx + 28;
			ww.bottom = yy*dy + cy + 28;
			ww.top = yy*dy + cy;

			yy = -cos(xx);
			mw.left = xx*dx + cx;
			mw.right = xx*dx + cx + 29;
			mw.bottom = yy*dy + cy + 29;
			mw.top = yy*dy + cy;

			dc.FillRect(ww, &br1);
			dc.FillRect(mw, &br2);
			Sleep(1);
			dc.FillRect(ww, &br3);
			dc.FillRect(mw, &br3);

			yy = - sin(xx);
			dc.SetPixel(xx*dx + cx, yy*dy + cy, c[2]);
			yy = - cos(xx);
			dc.SetPixel(xx*dx + cx, yy*dy + cy, c[7]);
		}
		k++;
	} while (k<10);

---------------------------------------------------------------------

	CClientDC dc(this);
	GetClientRect(&rc);
	CRect ww;

	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top + 150;
	w.bottom = rc.bottom;
	dc.FillSolidRect(&w, RGB(0, 0, 0));
	

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Penta");
	hold = (HFONT)SelectObject(dc, hNew);


	t = "L";
	for (k = w.left; k < w.right / 3; k++)
	{
		SetTextColor(dc, c[2]);
		dc.TextOutW(k, 250, t, t.GetLength());
		Sleep(2);
	}

	t = "O";
	for (k = w.top; k < 250; k++)
	{
		SetTextColor(dc, c[0]);
		dc.TextOutW(w.right / 3 + 50, k, t, t.GetLength());
		Sleep(2);
	}

	t = "O";
	for (k = w.bottom; k > 248; k--)
	{
		SetTextColor(dc, c[6]);
		dc.TextOutW(w.right / 3 + 110, k, t, t.GetLength());
		Sleep(2);
	}

	t = "K";
	for (k = w.right; k > w.right / 3 + 170; k--)
	{
		SetTextColor(dc, c[11]);
		dc.TextOutW(k, 250, t, t.GetLength());
		Sleep(2);
	}

	hold = (HFONT)SelectObject(dc, hbk);

	

		for (k = w.left - 50; k < w.right; k++)
		{
			ww.top = 250;
			ww.bottom = 300;
			ww.left = k;
			ww.right = k + 50;
			dc.FillSolidRect(ww, c[2]);
			Sleep(2);
			dc.FillSolidRect(ww, c[5]);
		}

		for (k = w.right; k > w.left - 50; k--)
		{
			ww.top = 250;
			ww.bottom = 300;
			ww.left = k;
			ww.right = k + 50;
			dc.FillSolidRect(ww, c[2]);
			Sleep(2);
			dc.FillSolidRect(ww, c[5]);
		}

		for (k = w.top; k < w.bottom; k++)
		{
			ww.top = k;
			ww.bottom = k+50;
			ww.left = w.right/2;
			ww.right = w.right / 2 + 50;
			dc.FillSolidRect(ww, c[2]);
			Sleep(2);
			dc.FillSolidRect(ww, c[5]);
		}

		for (k = w.bottom; k > w.top ; k--)
		{
			ww.top = k;
			ww.bottom = k + 50;
			ww.left = w.right / 2;
			ww.right = w.right / 2 + 50;
			dc.FillSolidRect(ww, c[2]);
			Sleep(2);
			dc.FillSolidRect(ww, c[5]);
		}


		double x, y;//значений функций
		int wr, hr;//высота, ширина делений

		wr = abs(w.right - w.left);
		hr = abs(w.bottom - w.top);

		double r, f;
		r = 120;
		f = 0;
		k = 5;
		do
		{
			x = r*cos(f);
			y = r*sin(f);
			
			ww.top = (int)y - 15 + hr;
			ww.bottom = (int)y + hr;
			ww.left = (int)x + wr / 2;
			ww.right = (int)x + 15 + wr / 2;
			dc.FillSolidRect(ww, c[2]);
			Sleep(4);
			dc.FillSolidRect(ww, c[k]);
			f += 0.01;
			//if (k < 12) k++; else k = 0;
		} while (f <= 20);

************************************************************


	CBitmap w;
	CRect rt, rw[12];
	int RH, RW, cx, cy, x2, y2, x1, y1;
	CString ms;

	bool F;

------------------------------------------------------------------


	pic.GetWindowRect(&rt);
	ScreenToClient(&rt);

	F = true;

	SetWindowTextW(L"Зодиакальный гороскоп на сегодня");

------------------------------------------------------------------

	bmp.LoadBitmapW(IDB_BITMAP1);
	pic.SetBitmap(bmp);
	bmp.DeleteObject();
	F = false;

------------------------------------------------------------------

	CClientDC dc(this);

	RH = abs(rt.right - rt.left);
	RW = abs(rt.top - rt.bottom);

	cx = RH / 2;
	cy = RW / 2;

	//ms.Format(L"cx=%5i, cy=%5i", cx, cy);
	//AfxMessageBox(ms);
	

	x1 = 20;
	y1 = 5;
	x2 = 120;
	y2 = 135;

	rw[0].left = x1;
	rw[0].top = y1;
	rw[0].right = x2;
	rw[0].bottom = y2;


	if (PtInRect(&rw[0], point)&&F)
	{
		
		POINT pt[5] = { { x1, y1 }, { x2, y1 }, { x2, y2 }, { x1, y2 }, { x1, y1 } };

		dc.Polyline(pt,5);
		Sleep(mtimer);
		OnFileOven();
	}
	

	x1 = 130;
	y1 = 5;
	x2 = 220;
	y2 = 135;

	rw[1].left = x1;
	rw[1].top = y1;
	rw[1].right = x2;
	rw[1].bottom = y2;

	if (PtInRect(&rw[1], point) && F)
	{

		POINT pt[5] = { { x1, y1 }, { x2, y1 }, { x2, y2 }, { x1, y2 }, { x1, y1 } };

		dc.Polyline(pt, 5);
		Sleep(mtimer);
		OnFileTelec();
	}

	x1 = 230;
	y1 = 5;
	x2 = 320;
	y2 = 135;

	rw[2].left = x1;
	rw[2].top = y1;
	rw[2].right = x2;
	rw[2].bottom = y2;

	if (PtInRect(&rw[2], point) && F)
	{

		POINT pt[5] = { { x1, y1 }, { x2, y1 }, { x2, y2 }, { x1, y2 }, { x1, y1 } };

		dc.Polyline(pt, 5);
		Sleep(mtimer);
		OnFileBliznec();

	}
	
	x1 = 330;
	y1 = 5;
	x2 = 430;
	y2 = 135;

	rw[3].left = x1;
	rw[3].top = y1;
	rw[3].right = x2;
	rw[3].bottom = y2;

	if (PtInRect(&rw[3], point) && F)
	{

		POINT pt[5] = { { x1, y1 }, { x2, y1 }, { x2, y2 }, { x1, y2 }, { x1, y1 } };
		dc.Polyline(pt, 5);
		Sleep(mtimer);
		OnFileRak();
	}

	x1 = 440;
	y1 = 5;
	x2 = 530;
	y2 = 135;

	rw[4].left = x1;
	rw[4].top = y1;
	rw[4].right = x2;
	rw[4].bottom = y2;

	if (PtInRect(&rw[4], point) && F)
	{

		POINT pt[5] = { { x1, y1 }, { x2, y1 }, { x2, y2 }, { x1, y2 }, { x1, y1 } };
		dc.Polyline(pt, 5);
		Sleep(mtimer);
		OnFileRak();
	}

	x1 = 540;
	y1 = 5;
	x2 = 635;
	y2 = 135;

	rw[5].left = x1;
	rw[5].top = y1;
	rw[5].right = x2;
	rw[5].bottom = y2;

	if (PtInRect(&rw[5], point) && F)
	{

		POINT pt[5] = { { x1, y1 }, { x2, y1 }, { x2, y2 }, { x1, y2 }, { x1, y1 } };
		dc.Polyline(pt, 5);
		Sleep(mtimer);
		OnFileDeva();
	}

------------------------------------------------------------------

	if (MessageBox(TEXT("Ви дійсно бажаєте вийти ?"), TEXT("УВАГА!!!"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
	{
		OnOK();
	};

------------------------------------------------------------------

	CClientDC dc(this);
	GetClientRect(&rc);
	w.left = rc.left;
	w.right = rc.right;
	w.top = rc.top;
	w.bottom = rc.bottom;

	kw[0].left = w.left + 100;
	kw[0].top = w.top + 20;
	kw[0].right = kw[0].left + 225;
	kw[0].bottom = kw[0].top + 275;

	if (PtInRect(&kw[0], point)) OnFilePic1();
	
	kw[1].left = w.left +625;
	kw[1].top = w.top + 20;
	kw[1].right = kw[1].left + 220;
	kw[1].bottom = kw[1].top + 275;
	
	if (PtInRect(&kw[1], point)) OnFilePic2();
	
	//dc.Rectangle(&kw[1]);

------------------------------------------------------------------


	CWnd * WndPtr = GetDlgItem(IDC_PIC);
	WndPtr->GetWindowRect(&w);
	ScreenToClient(&w);

------------------------------------------------------------------

	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);

------------------------------------------------------------------





	// кот

	x1 = kw[1].left = w.left + 5;
	y1 = kw[1].top = w.top + 10;
	x2 = kw[1].right = kw[1].left + 120;
	y2 = kw[1].bottom = kw[1].top + 105;

	x1 = x1 + 10;
	y1 = y1 + 7;
	x2 = x2 - 10;
	y2 = y2 - 10;

	dc.Rectangle(&kw[1]);
	if (PtInRect(&kw[1], point))
	{
		hPenOxy = CreatePen(PS_SOLID, rozmir, 0x0000D500);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		POINT pt[3] = { { x1, y1 + 80 },{ x2 - 80, y2 },{ x1 + 20, y1 + 80 } };
		dc.Polyline(pt, 3);
	}

	// мишка

	x1 = kw[2].left = w.left + 135;
	y1 = kw[2].top = w.top + 10;
	x2 = kw[2].right = kw[2].left + 120;
	y2 = kw[2].bottom = kw[2].top + 105;

	x1 = x1 + 10;
	y1 = y1 + 7;
	x2 = x2 - 10;
	y2 = y2 - 10;

	dc.Rectangle(&kw[2]);
	if (PtInRect(&kw[2], point))
	{
		hPenOxy = CreatePen(PS_SOLID, rozmir, 0x0000D500);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		POINT pt[3] = { { x1, y1 + 80 },{ x2 - 95, y2 },{ x1 + 20, y1 + 80 } };
		dc.Polyline(pt, 3);
	}



