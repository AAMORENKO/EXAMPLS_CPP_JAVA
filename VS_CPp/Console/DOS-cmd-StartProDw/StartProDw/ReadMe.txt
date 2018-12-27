
	
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


// ---------------------------------------------------------------

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

 

Output example:

 

Available drives in this machine are:

A: C: E: F: G: J: K:

Type drive letter to check: c

Current directory on that drive is:

C:\Program Files\Microsoft Visual Studio 8\Common7\IDE

Current working directory is: F:\vc2005project\cplus\cplus

Directory \testdir was successfully created

Volume in drive F is hd0c

Volume Serial Number is 98DB-52B1

Directory of F:\testdir

12/10/2006 09:55 PM <DIR> .

12/10/2006 09:55 PM <DIR> ..

0 File(s) 0 bytes

2 Dir(s) 8,647,696,384 bytes free

Directory \testdir was successfully removed

Change directory........

Volume in drive C has no label.

Volume Serial Number is 6476-59E1

Directory of C:\Windows\System32\config

12/10/2006 09:10 PM 1,024 default.LOG

12/10/2006 09:10 PM 1,024 SAM.LOG

12/10/2006 09:20 PM 1,024 SECURITY.LOG

12/10/2006 09:55 PM 24,576 software.LOG

12/10/2006 09:16 PM 1,024 system.LOG

07/17/2005 04:55 AM 1,024 TempKey.LOG

07/17/2005 04:56 AM 1,024 userdiff.LOG

7 File(s) 30,720 bytes

0 Dir(s) 703,168,512 bytes free

Press any key to continue . . .

 



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




