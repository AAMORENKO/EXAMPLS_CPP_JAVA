#include <iostream>
#include <fstream>
using namespace std;

int n, k;
double a, x, y, e;
double res;
fstream inf, otf;

int main()
{
	setlocale(LC_ALL, "rus");
	system("color 1F");

	cout << "\n\tПрограма обчислення кореня n-го степеня\n";
	cout << "\n\tПочатковi данi з файлу data.txt :\n\n";

	inf.open("data.txt", ios::in);
	if (!inf) return 0;
	inf >> n;
	inf >> a;
	inf >> e;
	printf("\t%i\t%4.2f\t%6.4f", n,a,e);
	inf.close();

	x = 1;
	y = ((n - 1)*x + a / powf(x, (float)(n - 1))) / n;
	do
	{
		x = y;
		y = ((n - 1)*x + a / powf(x, (float)(n - 1))) / n;
	} while (fabs(y - x) > e);

	res = powf(a, (double)1 / n);
	printf("\n\n\tрезультат наближених обчислень: %16.12f\n\n\tточне значення: %16.12f", y , res);

	otf.open("res.txt", ios::out);
	if (!otf) return 0;
	otf << "file douwn";
	otf.flush();
	otf.close();

	cout << "\n\n\t";
	system("pause");
	return 0;
}
