
//Програма керування об'єктами, що намальовані : Risovanie

//Докладніше:  https://youtu.be/Olwa9JYCtr4

public:


	CBitmap PIC;
	CRect Next, Back, Sps;
	CWnd *WndPtr;


-----------------------------------------------------

	WndPtr = GetDlgItem(IDC_PIC1);
	WndPtr->GetWindowRect(&Next);
	ScreenToClient(&Next);

	WndPtr = GetDlgItem(IDC_PIC2);
	WndPtr->GetWindowRect(&Back);
	ScreenToClient(&Back);

	WndPtr = GetDlgItem(IDC_PIC3);
	WndPtr->GetWindowRect(&Sps);
	ScreenToClient(&Sps);

	mcombo.SetCurSel(0);

-----------------------------------------------------

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
	case 2:
	{
		PIC.LoadBitmapW(IDB_BITMAP4);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		break;
	}
	case 3:
	{
		PIC.LoadBitmapW(IDB_BITMAP5);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		break;
	}
	case 4:
	{
		PIC.LoadBitmapW(IDB_BITMAP9);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		break;
	}


-----------------------------------------------------


	if (PtInRect(&Next, point))
	{
		PIC.LoadBitmapW(IDB_BITMAP28);
		mpic1.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}
	else
	{
		PIC.LoadBitmapW(IDB_BITMAP20);
		mpic1.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}

	if (PtInRect(&Back, point))
	{
		PIC.LoadBitmapW(IDB_BITMAP18);
		mpic2.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}
	else
	{
		PIC.LoadBitmapW(IDB_BITMAP5);
		mpic2.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}

	if (PtInRect(&Sps, point))
	{
		PIC.LoadBitmapW(IDB_BITMAP24);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}
	else
	{
		PIC.LoadBitmapW(IDB_BITMAP1);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}



	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);

-----------------------------------------------------

	if (PtInRect(&Next, point))
	{
		if (MessageBox(L"Бажаєте вийти з програми?", L"Вікно виходу", MB_YESNO | MB_ICONQUESTION) == IDYES) exit(0);
	}

	if (PtInRect(&Back, point))
	{
		if (MessageBox(L"Повертаємось до головного вікна програми?", L"Вікно -> Повернутись до головної програми", MB_YESNO | MB_ICONQUESTION) == IDYES) OnOK();
	}


-----------------------------------------------------

	if (PtInRect(&Sps, point))
	{
		MessageBox(L"Натиснуто праву кнопку миші", L"Увага!", MB_OK|MB_ICONASTERISK);
	}




