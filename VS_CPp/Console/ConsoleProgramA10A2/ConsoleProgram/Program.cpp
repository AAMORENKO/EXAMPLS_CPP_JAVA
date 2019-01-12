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
	cout << "\n\tÏðàêòè÷åñêàÿ ðàáîòà. ÒÅÌÀ: Äâiéêîâå êîäóâàííÿ. \n";

	inf.open("data.txt", ios::in);
	if (!inf) return 0;
	otf.open("sol.txt", ios::out);
	if (!otf) return 0;

	k = 1;
	while (!inf.eof())
	{
		inf >> n;
		
		printf("\n\t%3i) äåñÿòêîâå ÷èñëî: %i", k, n);
		otf << "äåñÿòêîâå ÷èñëî: " << n << "    ";

		i = 0;
		while (n > 0)
		{
			m = n % 2;
			n = n / 2;
			if (m == 1) z[i] = '1'; else z[i] = '0';
			i++;
		}

		cout << " \täâiéêîâèé çàïèñ ÷èñëà: ";
		otf << "  \täâiéêîâèé çàïèñ ÷èñëà: ";

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
