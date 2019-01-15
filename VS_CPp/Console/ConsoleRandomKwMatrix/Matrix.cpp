#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	int A[100][100];
	int n, k, i;
	char z;
	n = 12;

	do
	{
		system("cls");
		cout << "\n\n\t вадратна матриц€ A[N;N]\n\n";
		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				A[k][i] = 10 + rand() % 89;
				printf("%4i", A[k][i]);
			}
			cout << "\n";
		}

		cout << "\n\n\tпродовжити (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << "\n\n\t";
	system("pause");
	return 0;
}