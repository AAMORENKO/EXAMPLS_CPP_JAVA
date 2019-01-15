// двійкове кодування
#include <iostream>
#include <fstream>

using namespace std;

fstream inf, otf;
int k, i, n, m, p;
char z[256];

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "\n\tПрактическая работа. ТЕМА: Двiйкове кодування. \n";

	inf.open("data.txt", ios::in);
	if (!inf) return 0;
	otf.open("sol.txt", ios::out);
	if (!otf) return 0;

	k = 1;
	while (!inf.eof())
	{
		inf >> n;
		
		printf("\n\t%3i) десяткове число: %i", k, n);
		otf << "десяткове число: " << n << "    ";

		i = 0;
		while (n > 0)
		{
			m = n % 2;
			n = n / 2;
			if (m == 1) z[i] = '1'; else z[i] = '0';
			i++;
		}

		cout << " \tдвiйковий запис числа: ";
		otf << "  \tдвiйковий запис числа: ";

		for (p = strlen(z) - 1; p >= 0; p--)
		{
			cout << z[p];
			otf << z[p];
		}
		otf << endl;

		k++;
		for (p = 0; p < 256; p++) z[p] = '\0';

	}


	otf.flush();
	otf.close();
	inf.close();



	cout << endl << endl << "\t";
	system("pause");
	return 0;
}