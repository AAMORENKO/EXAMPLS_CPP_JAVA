#include <iostream>
#include <fstream>
using namespace std;

int n, m , q, p;
int a[25];
fstream inf, otf;

int main()
{
	setlocale(LC_ALL, "rus");
	system("color 1F");
	
	cout << "\n\tПрограма перетворення ланцюгового дробу\n";
	cout << "\n\tПочатковi данi з файлу data.txt :\n\n";
	
	
	inf.open("data.txt", ios::in);
	if (!inf) return 0;
	
	p = 0; a[0] = 1;
	p++;
	while (!inf.eof())
	{
		inf >> a[p];
		printf("\t%i", a[p]);
		p++;
	}
	inf.close();
	p--;
	printf("\tусього p=%i", p);

	m =1; n = a[p];
	while (p >1)
	{
		q = n;
		p--;
		n = a[p] * n + m;
		m = q;
		printf("\n\n\tm=%i; n=%i", m, n);
	}

	otf.open("res.txt", ios::out);
	if (!otf) return 0;
	otf << m<<" "<<n;
	otf.flush();
	otf.close();

	cout << "\n\n\t";
	system("pause");
	return 0;
}