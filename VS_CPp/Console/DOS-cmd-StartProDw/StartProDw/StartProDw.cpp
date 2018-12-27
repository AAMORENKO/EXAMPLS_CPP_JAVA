#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

#include <string>
#include <fstream>

#include <iostream>

using namespace std;

#define proga "StartProDw.exe"
#define vdroot "R"

static char m_AppPath[_MAX_PATH], p_buffer[_MAX_PATH], ex_path[_MAX_PATH];
static char n_path[_MAX_PATH];

int zhr, drive, curdrive;

string pth, tmp;

void main()
{
    STARTUPINFO szi;
    PROCESS_INFORMATION pci;
	LPTSTR szCmdline;

	static char m_vdx[_MAX_PATH] = "C:\\windows\\system32\\subst R: C:\\LHOST";
	static char d_vdx[_MAX_PATH] = "C:\\windows\\system32\\subst R: /D";
	static char pvd[_MAX_PATH] = "R:\\";
	static char lhost_dir[_MAX_PATH] = "C:\\LHOST";
	static char host_dir[_MAX_PATH] = "C:\\windows\\system32\\drivers\\etc\\";
	static char mainhost_dir[_MAX_PATH] = "C:\\LHOST\\denwer\\scripts\\main\\";
	static char resthost_dir[_MAX_PATH] = "C:\\LHOST\\denwer\\scripts\\reserve\\";

	static char kill_host[_MAX_PATH] = "del hosts.*";
    static char copy_host[_MAX_PATH] = "copy c:\\LHOST\\denwer\\scripts\\main\\hosts.* C:\\windows\\system32\\drivers\\etc\\hosts.*";
	static char restore_host[_MAX_PATH] = "copy c:\\LHOST\\denwer\\scripts\\reserve\\hosts.* C:\\windows\\system32\\drivers\\etc\\hosts.*";
	
	static char mail_start[_MAX_PATH] = "C:\\LHOST\\denwer\\tools\\sendmail\\sendmail_daemon_start.exe";
	static char mail_stop[_MAX_PATH] = "c:\\LHOST\\denwer\\tools\\sendmail\\sendmail_daemon_stop.exe";
	

	WCHAR apache_start[_MAX_PATH] = L"C:\\LHOST\\usr\\local\\apache\\bin\\httpd.exe -k start";
	WCHAR apache_stop[_MAX_PATH] = L"C:\\LHOST\\usr\\local\\apache\\bin\\httpd.exe -k stop";
	
	WCHAR mysql_start[_MAX_PATH] = L"net start mysql";
	WCHAR mysql_stop[_MAX_PATH] = L"net stop mysql";

	static char mapache_start[_MAX_PATH] = "C:\\LHOST\\usr\\local\\apache\\bin\\ApacheMonitor.exe";
	static char mapache_stop[_MAX_PATH] = "TASKKILL /F /IM ApacheMonitor.exe /T";

	int tms=1289;

	setlocale(LC_ALL,"rus");
	

	_getcwd(m_AppPath, _MAX_PATH);
	//printf("\nтекущая директория\\>> %s\n", m_AppPath);
	pth=m_AppPath;
	
	curdrive = _getdrive();
	//printf("\nтекущий носитель %c: \n", curdrive + 'A'-1, curdrive-1);

    _chdir(pvd);
	
		cout<<endl<<endl;
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
 
	
	cout<<endl<<endl;
	//system("pause");
}