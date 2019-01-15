// cout << "\n\tПрактична работа. ТЕМА: Обробка даних у файлах. \n\n";
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream inf, otf;
string ms, t;
int k;


int main()
{
	setlocale(LC_ALL, ".1251");
	cout << "\n\tПрактична работа. ТЕМА: Обробка даних у файлах. \n\n";

	inf.open("OS_W.txt", ios::in);
	if (!inf) return 0;
	
	otf.open("sol.txt", ios::out);
	
	while (!inf.eof())
	{
		getline(inf, ms);
		cout << ms;
		
		t.empty();
		for (k = ms.size(); k >= 0; k--)
		{
			t += ms[k];
		}
		t += "\n";
	}
	
	otf << t;

	otf.flush();
	otf.close();
	
	inf.close();
	

	cout << endl << endl;

	inf.open("sol.txt", ios::in);
	if (!inf) return 0;

	while (getline(inf, ms))
	{
		cout << ms;
	}
	inf.close();


	cout << endl << endl << "\t";
	system("pause");
	return 0;
}