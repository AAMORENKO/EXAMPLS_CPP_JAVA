#include <iostream>

// додаткова бібліотека 
#include <time.h>

using namespace std;

int main()
{
	// генератор випадкових чисел
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	// розміри матрицi
	int A[100][100];
	int n, k, i;
	char z;

	n = 5;
	int a = -99;
	int b = 99;

	do
	{
		system("cls");
		printf("\n\tЗаповнення матрицi A[%2i][%2i] цiлими двозначними числами. \n\n", n, n);

		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				do
				{
					A[k][i] = a + rand() % (b - a + 1);
				} while (abs(A[k][i])<10 || abs(A[k][i])>99);
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}

		int poz = 0;
		int neg = 0;
		long sump = 0;
		long dobn = 1;
		cout << "\n\n\tПередруковка матрицi:\n\n";
		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				if ((n - k - 1) != i) printf("%5i", A[k][i]);
				else {
					printf("    *");
					if (A[k][i] > 0)
					{
						poz++;
						sump += A[k][i];
					}
					else
					{
						neg++;
						dobn *= A[k][i];
					}
				}
			}
			cout << "\n";
		}

		printf("\n\n\tДодатних: %i", poz);
		printf("\n\tСума додатних: %i", sump);
		printf("\n\tВiд'ємних: %i", neg);
		printf("\n\tДобуток вiд'ємних: %i", dobn);


		cout << "\n\n\tПродовжити (y/n)? ";
		cin >> z;
	} while (z != 'n');


	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}