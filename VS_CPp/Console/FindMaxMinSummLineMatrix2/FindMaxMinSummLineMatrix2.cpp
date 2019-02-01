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

	// розміри матриць
	int A[100][100];
	int B[100];
	int n, k, i;
	int maxline, minline;
	int poz, neg, p;
	char z;

	n = 17;
	int a = -99;
	int b = 99;

	do
	{
		system("cls");
		printf("\n\tЗаповнення матрицi A[%2i][%2i] цiлими двозначними числами. \n\n", n, n);

		minline = maxline = 0;

		for (k = 0; k < n; k++) B[k] = 0;
		
		poz = neg = p=0;

		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				do
				{
					A[k][i] = a + rand() % (b - a + 1);
				} while (abs(A[k][i])<10||abs(A[k][i])>99);
				
				printf("%5i", A[k][i]);

				// пошук кількості додатних
				if (A[k][i] > 0) poz++;
				// обчислення сум у рядку
				B[p] += A[k][i];
				
			}
			printf("   %2i) summ= %i", p + 1, B[p]);
			cout << "\n";
			p++;
		}
		
		neg = n*n - poz;
		printf("\n\n\tКiлькiсть додатних: %i\n", poz);
		printf("\n\tКiлькiсть вiд'ємних: %i\n", neg);
		
		// пошук максимальної суми
		maxline = 0; int max = B[maxline];
		for (k = 0; k < n; k++)
		{
			if (max < B[k])
			{
				max = B[k];
				maxline = k;
			}
		}
		printf("\n\tНайбiльша сума у рядку пiд номером %i", maxline + 1);

		// пошук найменшої суми
		minline = 0; int min = B[minline];
		for (k = 0; k < n; k++)
		{
			if (min > B[k])
			{
				min = B[k];
				minline = k;
			}
		}
		printf("\n\tНайменша сума у рядку пiд номером %i", minline + 1);

		cout << "\n\n\tПродовжити (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}
