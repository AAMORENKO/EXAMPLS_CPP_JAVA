#include <windows.h>
#include <iostream>

#include "menu.h"
#include "program.h"
#include "resource.h"

using namespace std;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

HDC hdc,hdcbt;
PAINTSTRUCT pc;
HBITMAP PIC;
RECT rect;
HFONT hFont, hNew, hOldFont;
TEXTMETRIC tm;
LOGFONT lf;
LPTSTR lFace= (LPSTR)"Trebuchet MS";
char ms[17]="Це та САМА фраза";

HWND hButton1;
HWND hEditBox1;
TCHAR txt[256];

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    setlocale(LC_ALL,".1251");

    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    

    
    HMENU menu;
    
    HWND mybutton;    
    
   
    

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
   
    //wincl.hIcon = LoadIcon (NULL, IDI_ASTERISK);
    //wincl.hIconSm = LoadIcon (NULL, IDI_HAND);

    wincl.hIcon = (HICON)LoadImage( hThisInstance,"ProgramAppDev.ico",IMAGE_ICON,32, 32,LR_LOADFROMFILE);
    wincl.hIconSm = (HICON)LoadImage( hThisInstance,"ProgramAppDev.ico",IMAGE_ICON,16, 16,LR_LOADFROMFILE);
 
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_WINDOW;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    
    

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Діалогове вікно",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           800,                 /* The programs width */
           600,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
    // Приклеиваем меню из ресурсов
    menu = LoadMenu(hThisInstance, MAKEINTRESOURCE(IDR_MENU));
    SetMenu(hwnd, menu);
 
    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);
    

    // загружаем рисунок на форму
    PIC=(HBITMAP)::LoadImage(hThisInstance,"bitmap1.bmp",IMAGE_BITMAP,100,100,LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
    
    hdc=BeginPaint(hwnd,&pc);
    GetClientRect(hwnd,&rect);
        
    Rectangle (hdc,0,0,799,599);
    hdcbt=::CreateCompatibleDC(hdc);
    
    SelectObject(hdcbt,PIC);
    BitBlt(hdc,500,300,380,380,hdcbt,0,0,SRCCOPY);
    
    
        
    // .... TO DO TEXT  memset(&lf,0,sizeof(lf));
    

    hOldFont = (HFONT)::GetStockObject(SYSTEM_FONT);
    hNew = CreateFont(44, 0, 0, 0, FW_NORMAL, 0, 0, 0, RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, lFace);

    SetBkMode(hdc,TRANSPARENT);
    hFont=(HFONT)SelectObject(hdc, hNew); 

    SetTextColor(hdc,RGB(0,29,128));
    TextOut(hdc,420,260,ms,17);
    //DrawText(hdc,ms,17,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
    
    hFont = (HFONT)SelectObject(hdc, hOldFont);   
    DeleteDC(hdcbt);
    EndPaint(hwnd,&pc);
    
    // Кнопка 
    /*
    HWND  newCtrl = ::CreateWindow(_T("BUTTON"), _T("кнопочка"),
    WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_DEFPUSHBUTTON,
    xPos, yPos, width, height, hDlg, (HMENU)BUTTON_ID, hInstance, 0);
    */
    hButton1 = CreateWindow( 
    "BUTTON",   // predefined class 
    "BUTTON1",       // button text 
    WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // styles 
 
    // Size and position values are given explicitly, because 
    // the CW_USEDEFAULT constant gives zero values for buttons. 
    505,         // starting x position 
    420,         // starting y position 
    100,        // button width 
    40,        // button height 
    hwnd,       // parent window 
    (HMENU) IDC_BUTTON1,       // menu 
    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), 
    NULL);      // pointer not needed
    
    
    
    
    // Окошко ввода EditControl
    
    hEditBox1=CreateWindow(
    "EDIT", 
    NULL, 
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT, 
    500, 
    100, 
    150, 
    35, 
    hwnd, 
    (HMENU)IDC_EDIT1, 
    hThisInstance,
    NULL);    
    SetDlgItemText(hwnd, IDC_EDIT1, (LPSTR)"12345");
    
     
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   
    switch (message)                  /* handle the messages */
    {
      
       case WM_CREATE:      
	  //memset(&lf,0,sizeof(lf));	
	  //lf.lfHeight=70;
	  //lstrcpy(lf.lfFaceName,lFace);
	  //hFont=CreateFontIndirect(&lf);
	  

	  	
         break;
      
       case WM_KEYDOWN: // работа с клавиатурой, опрос
	  switch(wParam)
	  {
		case VK_ESCAPE: // нажата кнопка ESC
			DestroyWindow(hwnd);//SendMessage(hwnd,WM_CLOSE,0,0);
			break;
	  }
	  break;


       case WM_COMMAND:
           switch( wParam )
           {
             case IDM_FILENEW:
             case IDM_FILEOPEN:
             case IDM_FILESAVE:
             case IDM_FILESAVEAS:
             case IDM_FILEPRINT:
             case IDM_FILEPAGESETUP:
             case IDM_FILEPRINTSETUP:

             case IDM_EDITUNDO:
             case IDM_EDITCUT:
             case IDM_EDITCOPY:
             case IDM_EDITPASTE:
             case IDM_EDITDELETE:
                  MessageBox( hwnd, (LPSTR) "Function Not Yet Implemented.",
                              (LPSTR) szClassName,
                              MB_ICONINFORMATION | MB_OK );
                  return 0;

             case IDM_HELPCONTENTS:
                  WinHelp( hwnd, (LPSTR) "HELPFILE.HLP",
                           HELP_CONTENTS, 0L );
                  return 0;

             case IDM_HELPSEARCH:
                  WinHelp( hwnd, (LPSTR) "HELPFILE.HLP",
                           HELP_PARTIALKEY, 0L );
                  return 0;

             case IDM_HELPHELP:
                  WinHelp( hwnd, (LPSTR) "HELPFILE.HLP",
                           HELP_HELPONHELP, 0L );
                  return 0;

             case IDM_FILEEXIT:
			if( MessageBox( hwnd, (LPSTR) "Realy?",
                              (LPSTR) "Yes/No",
                              MB_YESNO | MB_ICONQUESTION )==IDYES) SendMessage( hwnd, WM_CLOSE, 0, 0L );
                  return 0;


             case IDM_HELPABOUT:
                  MessageBox (NULL, "About..." , "Windows example version 0.01", 1);
                  return 0;
                  
             case IDC_BUTTON1:
			GetDlgItemText(hwnd, IDC_EDIT1, txt, 256);
			SetDlgItemText(hwnd, IDC_EDIT1, (LPSTR)"");
			SetFocus(hEditBox1);
			MessageBox( hwnd, txt,(LPSTR) "Yes/No",MB_OK | MB_ICONINFORMATION );
			//MessageBox( hwnd, (LPSTR) "Wayyy? Yes!",(LPSTR) "Yes/No",MB_OK | MB_ICONINFORMATION );
			SetDlgItemText(hwnd, IDC_EDIT1, (LPSTR)"29");
                  return 0;       
             case IDC_EDIT1:
			GetDlgItemText(hwnd, IDC_EDIT1, txt, 256);
			SetDlgItemText(hwnd, IDC_EDIT1, (LPSTR)"");
			SetFocus(hEditBox1);
			//MessageBox( hwnd, txt,(LPSTR) "Yes/No",MB_OK | MB_ICONINFORMATION );
                  return TRUE; 
		    break;		               

           }
           break;
 
 
      case WM_PAINT:
           hdc=BeginPaint(hwnd,&pc);
           

	    	    
	    // .... TO DO

	    EndPaint(hwnd,&pc);          
           break;
	  
      case WM_CLOSE:
           DeleteObject(hFont);
	    DestroyWindow( hwnd );
           return 0;	  

      case WM_LBUTTONDOWN:
	    //MessageBox(hwnd,(LPSTR)"ddd\nShift",(LPSTR)"xxx!", MB_OK | MB_ICONEXCLAMATION);
      break;

      case WM_NOTIFY:
	    MessageBox(hwnd,(LPSTR)"ddd\nShift",(LPSTR)"xxx!", MB_OK | MB_ICONEXCLAMATION);
      break;
	  
       case WM_DESTROY:
            DeleteObject(hFont);
	     PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
  
       default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
