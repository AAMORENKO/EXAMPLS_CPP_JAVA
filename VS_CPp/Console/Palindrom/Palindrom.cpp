#include <iostream>

// додаткова бібліотека 
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	cout << "\n\n\tПеревiрка фрази на \"палiндром\"\n\n";

	int n, k, i;
	string ms, mz;

	char t[255] = "арозаупаланалапуазора";
	// char t[255] ="шалаш";
	//char t[255]="Моренко Олексiй";
	//char t[255] = "сало";

	ms.empty();
	ms = t; n = ms.size();

	mz.empty();
	cout<<"\tПочаткова фраза: "<< ms;

	for (k = n - 1; k >= 0; k--)
	{
		mz += ms[k];
	}

	cout << "\n\n\tОбернена фраза: " << mz;

	bool fg = true;
	for (i = 0; i < n; i++)
	{
		if (mz[i] != ms[i]) fg = false;
	}

	if (fg) cout << "\n\n\tДана фраза - палiндром.";
	else cout << "\n\n\tДана фраза - не є палiндромом.";

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}