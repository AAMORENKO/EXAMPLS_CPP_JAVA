
// ProgramDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"
#include "Dialog2.h"
#include "Dintro.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CProgramDlg



CProgramDlg::CProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	//fg = true;

	//SetWindowTextW(L"Program");
	DDX_Control(pDX, IDC_PIC, mpic);


}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// обработчики сообщений CProgramDlg

BOOL CProgramDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	for (i = 0; i<30; i++) counter[i] = 0;
	SCn = 0;
	inder1 = inder2 = inder3 = 0;
	CDintro dlg;
	dlg.DoModal();
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CProgramDlg::OnPaint()
{
	if (IsIconic())
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
		
		pic.LoadBitmapW(IDB_BITMAP1);
		mpic.SetBitmap(pic);
		pic.DeleteObject();
		for (i = 0; i<30; i++) counter[i] = 0;
		SCn = 0;
		inder1 = inder2 = inder3 = 0;
		//Invalidate();

		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgramDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default




	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialog::OnMouseMove(nFlags, point);
}


void CProgramDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//int x1, y1, x2, y2;
	//HPEN hPenOxy, hOldPen;
	
	CClientDC dc(this);
	GetClientRect(&rc);
	int rozmir = 6;

	hPenOxy = CreatePen(PS_SOLID, rozmir, 0x000000FF);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	if (PtInRect(&kw[28], point))
	{
		CDintro dlg;
		dlg.DoModal();
	}
	else
	{
		w.left = rc.left;
		w.right = rc.right;
		w.top = rc.top;
		w.bottom = rc.bottom;

		// Красная кнопка ВЫХОД

		x1 = kw[0].left = w.left + 670;
		y1 = kw[0].top = w.top + 555;
		x2 = kw[0].right = kw[0].left + 100;
		y2 = kw[0].bottom = kw[0].top + 105;

		x1 = x1 + 10;
		y1 = y1 + 7;
		x2 = x2 - 5;
		y2 = y2 - 1;

		//dc.Rectangle(&kw[0]);
		if (PtInRect(&kw[0], point))
		{
			POINT pt[5] = { { x1, y1 },{ x2, y1 },{ x2, y2 },{ x1, y2 },{ x1, y1 } };
			dc.Polyline(pt, 5);

			if (MessageBox(TEXT("Ви дійсно бажаєте вийти ?"), TEXT("УВАГА!!!"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
			{
				OnOK();
			}
			else
			{
				pic.LoadBitmapW(IDB_BITMAP1);
				mpic.SetBitmap(pic);
				pic.DeleteObject();
				for (i = 0; i < 30; i++) counter[i] = 0;
				SCn = 0;
				inder1 = inder2 = inder3 = 0;
			}
		}

		// Подсчет координат

		x1 = w.left + 10;
		y1 = w.top + 10;
		y2 = y1 + 120;
		int p = 1;
		for (k = 0; k < 5; k++)
		{
			for (int i = 1; i < 7; i++)
			{

				x2 = x1 + 110;
				kw[p].left = x1;
				kw[p].top = y1;
				kw[p].right = x2;
				kw[p].bottom = y2;
				//dc.Rectangle(&kw[p]);
				x1 += 130;
				p++;

			}
			y1 += 132;
			y2 = y1 + 120;
			x1 = w.left + 10;
		}

		hPenOxy = CreatePen(PS_SOLID, rozmir, 0x0000D500);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		// Сумматор

		x1 = kw[29].left;
		y1 = kw[29].top;
		x2 = kw[29].right;
		y2 = kw[29].bottom;

		x1 = x1 + 10;
		y1 = y1 + 23;
		x2 = x2 - 10;
		y2 = y2 + 2;

		if (PtInRect(&kw[29], point))
		{
			POINT pt[5] = { { x1, y1 },{ x2, y1 },{ x2, y2 },{ x1, y2 },{ x1, y1 } };
			dc.Polyline(pt, 5);

			//for (k = 1; k < 28; k++)
			//{
				//SCn += counter[k];
			//}
			if (SCn == 3)
			{
				//ms.Format(L"Обрано %i малюнків", SCn);
				//MessageBox(ms, L"Результати вибору", MB_OK | MB_ICONINFORMATION);

				CStdioFile inf(L"data.txt", CFile::modeCreate | CFile::modeWrite);
				SCn = 0;
				/*
				for (k = 1; k < 28; k++)
				{
					if ((counter[k] != 0) && (SCn != 3))
					{
						ms.Format(L"%i %i ", k, counter[k]);
						inf.WriteString(ms); // записать в файл
						SCn++;
					}
				}
				*/
				ms.Format(L"%i %i %i", inder1, inder2, inder3);
				inf.WriteString(ms); // записать в файл

				inf.Flush();
				inf.Close();
				OnOK();
				CDialog2 dlg;
				dlg.DoModal();

			}
			else
			{
				ms.Format(L"Ви не обрали трьох малюнків");
				MessageBox(ms, L"Помилка вибору", MB_OK | MB_ICONERROR);
			}
			pic.LoadBitmapW(IDB_BITMAP1);
			mpic.SetBitmap(pic);
			pic.DeleteObject();
			for (i = 0; i < 30; i++) counter[i] = 0;
			SCn = 0;
			inder1 = inder2 = inder3 = 0;

		}

		for (k = 1; k < 28; k++)
		{
			SCn += counter[k];
		}

		if (SCn < 4)
		{
			if (PtInRect(&kw[1], point))
			{
				cx = kw[1].left;
				if (counter[1] == 1) { cx = kw[1].left + 3 * rozmir; }
				else if (counter[1] == 2) { cx = kw[1].left + 6 * rozmir; }
				cy = kw[1].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir},{cx + rozmir,cy},{cx,cy} };
				dc.Polyline(pt, 5);
				counter[1]++;

				if (inder1 == 0)
				{
					inder1 = 1;
				}
				else if (inder2 == 0)
				{
					inder2 = 1;
				}
				else if (inder3 == 0)
				{
					inder3 = 1;
				}

			}


			if (PtInRect(&kw[2], point))
			{

				cx = kw[2].left;
				cx = kw[2].left;
				if (counter[2] == 1) { cx = kw[2].left + 3 * rozmir; }
				else if (counter[2] == 2) { cx = kw[2].left + 6 * rozmir; }
				cy = kw[2].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[2]++;

				if (inder1 == 0)
				{
					inder1 = 2;
				}
				else if (inder2 == 0)
				{
					inder2 = 2;
				}
				else if (inder3 == 0)
				{
					inder3 = 2;
				}

			}

			if (PtInRect(&kw[3], point))
			{

				cx = kw[3].left;
				cx = kw[3].left;
				if (counter[3] == 1) { cx = kw[3].left + 3 * rozmir; }
				else if (counter[3] == 2) { cx = kw[3].left + 6 * rozmir; }
				cy = kw[3].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[3]++;

				if (inder1 == 0)
				{
					inder1 = 3;
				}
				else if (inder2 == 0)
				{
					inder2 = 3;
				}
				else if (inder3 == 0)
				{
					inder3 = 3;
				}

			}

			if (PtInRect(&kw[4], point))
			{

				cx = kw[4].left;
				cx = kw[4].left;
				if (counter[4] == 1) { cx = kw[4].left + 3 * rozmir; }
				else if (counter[4] == 2) { cx = kw[4].left + 6 * rozmir; }
				cy = kw[4].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[4]++;

				if (inder1 == 0)
				{
					inder1 = 4;
				}
				else if (inder2 == 0)
				{
					inder2 = 4;
				}
				else if (inder3 == 0)
				{
					inder3 = 4;
				}

			}

			if (PtInRect(&kw[5], point))
			{

				cx = kw[5].left;
				cx = kw[5].left;
				if (counter[5] == 1) { cx = kw[5].left + 3 * rozmir; }
				else if (counter[5] == 2) { cx = kw[5].left + 6 * rozmir; }
				cy = kw[5].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[5]++;

				if (inder1 == 0)
				{
					inder1 = 5;
				}
				else if (inder2 == 0)
				{
					inder2 = 5;
				}
				else if (inder3 == 0)
				{
					inder3 = 5;
				}


			}

			if (PtInRect(&kw[6], point))
			{

				cx = kw[6].left;
				cx = kw[6].left;
				if (counter[6] == 1) { cx = kw[6].left + 3 * rozmir; }
				else if (counter[6] == 2) { cx = kw[6].left + 6 * rozmir; }
				cy = kw[6].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[6]++;

				if (inder1 == 0)
				{
					inder1 = 6;
				}
				else if (inder2 == 0)
				{
					inder2 = 6;
				}
				else if (inder3 == 0)
				{
					inder3 = 6;
				}


			}

			if (PtInRect(&kw[7], point))
			{

				cx = kw[7].left;
				cx = kw[7].left;
				if (counter[7] == 1) { cx = kw[7].left + 3 * rozmir; }
				else if (counter[7] == 2) { cx = kw[7].left + 6 * rozmir; }
				cy = kw[7].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[7]++;

				if (inder1 == 0)
				{
					inder1 = 7;
				}
				else if (inder2 == 0)
				{
					inder2 = 7;
				}
				else if (inder3 == 0)
				{
					inder3 = 7;
				}


			}

			if (PtInRect(&kw[8], point))
			{

				cx = kw[8].left;
				cx = kw[8].left;
				if (counter[8] == 1) { cx = kw[8].left + 3 * rozmir; }
				else if (counter[8] == 2) { cx = kw[8].left + 6 * rozmir; }
				cy = kw[8].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[8]++;

				if (inder1 == 0)
				{
					inder1 = 8;
				}
				else if (inder2 == 0)
				{
					inder2 = 8;
				}
				else if (inder3 == 0)
				{
					inder3 = 8;
				}


			}

			if (PtInRect(&kw[9], point))
			{

				cx = kw[9].left;
				cx = kw[9].left;
				if (counter[9] == 1) { cx = kw[9].left + 3 * rozmir; }
				else if (counter[9] == 2) { cx = kw[9].left + 6 * rozmir; }
				cy = kw[9].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[9]++;

				if (inder1 == 0)
				{
					inder1 = 9;
				}
				else if (inder2 == 0)
				{
					inder2 = 9;
				}
				else if (inder3 == 0)
				{
					inder3 = 9;
				}


			}

			if (PtInRect(&kw[10], point))
			{

				cx = kw[10].left;
				cx = kw[10].left;
				if (counter[10] == 1) { cx = kw[10].left + 3 * rozmir; }
				else if (counter[10] == 2) { cx = kw[10].left + 6 * rozmir; }
				cy = kw[10].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[10]++;

				if (inder1 == 0)
				{
					inder1 = 10;
				}
				else if (inder2 == 0)
				{
					inder2 = 10;
				}
				else if (inder3 == 0)
				{
					inder3 = 10;
				}


			}

			if (PtInRect(&kw[11], point))
			{

				cx = kw[11].left;
				cx = kw[11].left;
				if (counter[11] == 1) { cx = kw[11].left + 3 * rozmir; }
				else if (counter[11] == 2) { cx = kw[11].left + 6 * rozmir; }
				cy = kw[11].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[11]++;

				if (inder1 == 0)
				{
					inder1 = 11;
				}
				else if (inder2 == 0)
				{
					inder2 = 11;
				}
				else if (inder3 == 0)
				{
					inder3 = 11;
				}


			}

			if (PtInRect(&kw[12], point))
			{

				cx = kw[12].left;
				cx = kw[12].left;
				if (counter[12] == 1) { cx = kw[12].left + 3 * rozmir; }
				else if (counter[12] == 2) { cx = kw[12].left + 6 * rozmir; }
				cy = kw[12].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[12]++;

				if (inder1 == 0)
				{
					inder1 = 12;
				}
				else if (inder2 == 0)
				{
					inder2 = 12;
				}
				else if (inder3 == 0)
				{
					inder3 = 12;
				}


			}

			if (PtInRect(&kw[13], point))
			{

				cx = kw[13].left;
				cx = kw[13].left;
				if (counter[13] == 1) { cx = kw[13].left + 3 * rozmir; }
				else if (counter[13] == 2) { cx = kw[13].left + 6 * rozmir; }
				cy = kw[13].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[13]++;

				if (inder1 == 0)
				{
					inder1 = 13;
				}
				else if (inder2 == 0)
				{
					inder2 = 13;
				}
				else if (inder3 == 0)
				{
					inder3 = 13;
				}


			}

			if (PtInRect(&kw[14], point))
			{

				cx = kw[14].left;
				cx = kw[14].left;
				if (counter[14] == 1) { cx = kw[14].left + 3 * rozmir; }
				else if (counter[14] == 2) { cx = kw[14].left + 6 * rozmir; }
				cy = kw[14].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[14]++;

				if (inder1 == 0)
				{
					inder1 = 14;
				}
				else if (inder2 == 0)
				{
					inder2 = 14;
				}
				else if (inder3 == 0)
				{
					inder3 = 14;
				}


			}

			if (PtInRect(&kw[15], point))
			{

				cx = kw[15].left;
				cx = kw[15].left;
				if (counter[15] == 1) { cx = kw[15].left + 3 * rozmir; }
				else if (counter[15] == 2) { cx = kw[15].left + 6 * rozmir; }
				cy = kw[15].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[15]++;

				if (inder1 == 0)
				{
					inder1 = 15;
				}
				else if (inder2 == 0)
				{
					inder2 = 15;
				}
				else if (inder3 == 0)
				{
					inder3 = 15;
				}


			}

			if (PtInRect(&kw[16], point))
			{

				cx = kw[16].left;
				cx = kw[16].left;
				if (counter[16] == 1) { cx = kw[16].left + 3 * rozmir; }
				else if (counter[16] == 2) { cx = kw[16].left + 6 * rozmir; }
				cy = kw[16].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[16]++;

				if (inder1 == 0)
				{
					inder1 = 16;
				}
				else if (inder2 == 0)
				{
					inder2 = 16;
				}
				else if (inder3 == 0)
				{
					inder3 = 16;
				}


			}

			if (PtInRect(&kw[17], point))
			{

				cx = kw[17].left;
				cx = kw[17].left;
				if (counter[17] == 1) { cx = kw[17].left + 3 * rozmir; }
				else if (counter[17] == 2) { cx = kw[17].left + 6 * rozmir; }
				cy = kw[17].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[17]++;

				if (inder1 == 0)
				{
					inder1 = 17;
				}
				else if (inder2 == 0)
				{
					inder2 = 17;
				}
				else if (inder3 == 0)
				{
					inder3 = 17;
				}


			}

			if (PtInRect(&kw[18], point))
			{

				cx = kw[18].left;
				cx = kw[18].left;
				if (counter[18] == 1) { cx = kw[18].left + 3 * rozmir; }
				else if (counter[18] == 2) { cx = kw[18].left + 6 * rozmir; }
				cy = kw[18].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[18]++;

				if (inder1 == 0)
				{
					inder1 = 18;
				}
				else if (inder2 == 0)
				{
					inder2 = 18;
				}
				else if (inder3 == 0)
				{
					inder3 = 18;
				}


			}

			if (PtInRect(&kw[19], point))
			{

				cx = kw[19].left;
				cx = kw[19].left;
				if (counter[19] == 1) { cx = kw[19].left + 3 * rozmir; }
				else if (counter[19] == 2) { cx = kw[19].left + 6 * rozmir; }
				cy = kw[19].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[19]++;

				if (inder1 == 0)
				{
					inder1 = 19;
				}
				else if (inder2 == 0)
				{
					inder2 = 19;
				}
				else if (inder3 == 0)
				{
					inder3 = 19;
				}


			}

			if (PtInRect(&kw[20], point))
			{

				cx = kw[20].left;
				cx = kw[20].left;
				if (counter[20] == 1) { cx = kw[20].left + 3 * rozmir; }
				else if (counter[20] == 2) { cx = kw[20].left + 6 * rozmir; }
				cy = kw[20].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[20]++;

				if (inder1 == 0)
				{
					inder1 = 20;
				}
				else if (inder2 == 0)
				{
					inder2 = 20;
				}
				else if (inder3 == 0)
				{
					inder3 = 20;
				}


			}

			if (PtInRect(&kw[21], point))
			{

				cx = kw[21].left;
				cx = kw[21].left;
				if (counter[21] == 1) { cx = kw[21].left + 3 * rozmir; }
				else if (counter[21] == 2) { cx = kw[21].left + 6 * rozmir; }
				cy = kw[21].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[21]++;

				if (inder1 == 0)
				{
					inder1 = 21;
				}
				else if (inder2 == 0)
				{
					inder2 = 21;
				}
				else if (inder3 == 0)
				{
					inder3 = 21;
				}


			}

			if (PtInRect(&kw[22], point))
			{

				cx = kw[22].left;
				cx = kw[22].left;
				if (counter[22] == 1) { cx = kw[22].left + 3 * rozmir; }
				else if (counter[22] == 2) { cx = kw[22].left + 6 * rozmir; }
				cy = kw[22].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[22]++;

				if (inder1 == 0)
				{
					inder1 = 22;
				}
				else if (inder2 == 0)
				{
					inder2 = 22;
				}
				else if (inder3 == 0)
				{
					inder3 = 22;
				}


			}

			if (PtInRect(&kw[23], point))
			{

				cx = kw[23].left;
				cx = kw[23].left;
				if (counter[23] == 1) { cx = kw[23].left + 3 * rozmir; }
				else if (counter[23] == 2) { cx = kw[23].left + 6 * rozmir; }
				cy = kw[23].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[23]++;

				if (inder1 == 0)
				{
					inder1 = 23;
				}
				else if (inder2 == 0)
				{
					inder2 = 23;
				}
				else if (inder3 == 0)
				{
					inder3 = 23;
				}


			}

			if (PtInRect(&kw[24], point))
			{

				cx = kw[24].left;
				cx = kw[24].left;
				if (counter[24] == 1) { cx = kw[24].left + 3 * rozmir; }
				else if (counter[24] == 2) { cx = kw[24].left + 6 * rozmir; }
				cy = kw[24].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[24]++;

				if (inder1 == 0)
				{
					inder1 = 24;
				}
				else if (inder2 == 0)
				{
					inder2 = 24;
				}
				else if (inder3 == 0)
				{
					inder3 = 24;
				}


			}

			if (PtInRect(&kw[25], point))
			{

				cx = kw[25].left;
				cx = kw[25].left;
				if (counter[25] == 1) { cx = kw[25].left + 3 * rozmir; }
				else if (counter[25] == 2) { cx = kw[25].left + 6 * rozmir; }
				cy = kw[25].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[25]++;

				if (inder1 == 0)
				{
					inder1 = 25;
				}
				else if (inder2 == 0)
				{
					inder2 = 25;
				}
				else if (inder3 == 0)
				{
					inder3 = 25;
				}


			}

			if (PtInRect(&kw[26], point))
			{

				cx = kw[26].left;
				cx = kw[26].left;
				if (counter[26] == 1) { cx = kw[26].left + 3 * rozmir; }
				else if (counter[26] == 2) { cx = kw[26].left + 6 * rozmir; }
				cy = kw[26].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[26]++;

				if (inder1 == 0)
				{
					inder1 = 26;
				}
				else if (inder2 == 0)
				{
					inder2 = 26;
				}
				else if (inder3 == 0)
				{
					inder3 = 26;
				}


			}


			if (PtInRect(&kw[27], point))
			{

				cx = kw[27].left;
				cx = kw[27].left;
				if (counter[27] == 1) { cx = kw[27].left + 3 * rozmir; }
				else if (counter[27] == 2) { cx = kw[27].left + 6 * rozmir; }
				cy = kw[27].top + 110;
				POINT pt[5] = { { cx, cy },{ cx , cy + rozmir },{ cx + rozmir, cy + rozmir },{ cx + rozmir,cy },{ cx,cy } };
				dc.Polyline(pt, 5);
				counter[27]++;

				if (inder1 == 0)
				{
					inder1 = 27;
				}
				else if (inder2 == 0)
				{
					inder2 = 27;
				}
				else if (inder3 == 0)
				{
					inder3 = 27;
				}


			}



		}
		else
		{
			if ((PtInRect(&kw[0], point)) && (SCn > 3))
			{
				OnOK();
			}
			else
			{
				ms.Format(L"Обрано більше трьох малюнків");
				MessageBox(ms, L"Помилка вибору", MB_OK | MB_ICONERROR);
				pic.LoadBitmapW(IDB_BITMAP1);
				mpic.SetBitmap(pic);
				pic.DeleteObject();
				for (i = 0; i < 30; i++) counter[i] = 0;
				SCn = 0;
				inder1 = inder2 = inder3 = 0;
			}
		}

	}
	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);

	CDialog::OnLButtonDown(nFlags, point);
}


void CProgramDlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	if (MessageBox(TEXT("Ви дійсно бажаєте вийти ?"), TEXT("УВАГА!!!"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
	{
		OnOK();
	}
	else
	{
		pic.LoadBitmapW(IDB_BITMAP1);
		mpic.SetBitmap(pic);
		pic.DeleteObject();
		for (i = 0; i<30; i++) counter[i] = 0;
		SCn = 0;
		inder1 = inder2 = inder3 = 0;
	}
	
}
