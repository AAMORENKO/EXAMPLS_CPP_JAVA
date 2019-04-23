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
char buf[25];

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
	if (!inf) return 0;
	getline(inf, ms);
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
	for (j = 0; j < p; j++)
	{
		int cod = (char)ms[j];
		//cout << "\n\t" << cod;
		if (cod == 32)
		{
			cod = 0;
			t += "0";
		} else
		if (cod == 46)
		{
			cod = 65;
		}
		else
		{
			cod += 65;
			if (cod < 10)
			{
				t += "0";
			}
		}

		_itoa_s(cod, buf, 10);
		t += buf;

	}


	otf.open("res.txt", ios::out);
	if (!otf) return 0;
	otf << t;
	otf.flush();
	otf.close();


	cout << "\n\n\tЗакодована фраза (windows .1251):\n\n\t";
	cout << t;

	cout << "\n\n\t";
	system("pause");

	system("cls");

	cout << "\n\n\tПеревiрка закодованого тексту:\n\n\t";

	inf.open("res.txt", ios::in);
	if (!inf) return 0;
	getline(inf, ms);
	inf.close();

	cout << ms;
	cout << "\n\t - змiст кодованого тексту з файлу res.txt\n\n";

	p = ms.size();
	string z;
	z.empty();

	for (k = 0; k < p; k++)
	{
		buf[0] = ms[k];
		buf[1] = ms[k + 1];

		int cod = atoi(buf);
		z += A[cod];
		k++;
	}

	cout << "\tВаша фраза мiстить текст:\n\n\t";
	cout << z;



	cout << endl << endl << "\t";
	system("pause");
	return 0;
}
