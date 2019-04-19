#include <iostream>

// додаткова бібліотека 
#include <fstream>
#include <string>

using namespace std;

fstream inf, otf;
string ms, t;

int B[100];
int k, i, j, p;

char A[100];

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	A[0] = ' '; B[0] = 0;
	A[65] = '.'; B[65] = 65;

	for (k = 1; k < 65; k++)
	{
		A[k] = char(k + 191); B[k] = k;
	}
	ms.empty();
	inf.open("data.txt", ios::in);
	getline(inf,ms);
	inf.close();
	cout << "\n\tТаблиця кодiв:\n\n";

	for (i = 0; i < 66; i++)
	{
		if (i % 8 == 0)
		{
			cout << "\n\t";
		}
		if (i<10) printf("%c = 0%i\t", A[i], B[i]);
		else printf("%c = %2i\t", A[i], B[i]);
	}

	cout << "\n\n\tФраза для кодування (RUS):\n\n\t";
	cout << ms;
	p = ms.size();

	t.empty(); 
	for (j = 0; j <=p; j++)
	{
		int cod = (char)ms[j];
		cout << "\n\t" << cod;
	}
	cout << "\n\n\tЗакодована фраза (windows .1251):\n\n\t";
	cout <<t;

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}
