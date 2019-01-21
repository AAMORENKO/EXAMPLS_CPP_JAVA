#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	system("color 17");

	int n, m, A[1000], s;
	char z;
	do
	{
		system("cls");
		cout << "\n\n\tПорiвняння кiлькостi учнiв за зростом, що меншi за M:\n\n\t";

		cout << "Введiть число учнiв N=";
		cin >> n;
		cout << "\n\tВведiть число M=";
		cin >> m;
		cout << endl << endl;

		s = 0;
		for (int k = 0; k < n; k++)
		{
			A[k] = 150 + rand() % (189-150+1);
			printf("\tA[%i]=%i\n", k + 1, A[k]);
			if (A[k]<= m) s ++;
		}

		if (s >0)
			cout << "\n\n\tРезультат: таких учнiв: " << s;
		else
			cout << "\n\n\tРезультат: таких учнiв не знайдено!";

		cout << endl << endl << "\tПродовжити (y/n)? >> ";
		cin >> z;
	} while (z != 'n');

	return 0;
}