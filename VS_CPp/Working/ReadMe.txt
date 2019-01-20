Знайди у своєму проекті файл ресурсів 
Наприклад, Program.rc
Відкрий його у блокноті

Знайди розділ
/////////////////////////////////////////////////////////////////////////////
//
// Dialog
//

IDD_PROGRAM_DIALOG DIALOGEX

заміни на це

/////////////////////////////////////////////////////////////////////////////
//
// Dialog
//

IDD_PROGRAM_DIALOG DIALOGEX 0, 0, 280, 161
STYLE DS_SETFONT | DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU
EXSTYLE WS_EX_APPWINDOW
CAPTION "Program"
FONT 16, "Trebuchet MS", 400, 0, 0xCC
BEGIN
END


Знайди розділ
/////////////////////////////////////////////////////////////////////////////
//
// DESIGNINFO
//

#ifdef APSTUDIO_INVOKED
GUIDELINES DESIGNINFO

заміни на це

/////////////////////////////////////////////////////////////////////////////
//
// DESIGNINFO
//

#ifdef APSTUDIO_INVOKED
GUIDELINES DESIGNINFO
BEGIN
    IDD_PROGRAM_DIALOG, DIALOG
    BEGIN
        LEFTMARGIN, 7
        RIGHTMARGIN, 273
        TOPMARGIN, 7
        BOTTOMMARGIN, 154
    END
END
#endif    // APSTUDIO_INVOKED


Збережи зміни у файлі ресурсів.

Перезавантаж проект. Бажаю успіху.