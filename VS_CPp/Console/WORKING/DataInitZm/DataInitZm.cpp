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

		printf("\n\tДрукування матрицi A[%2i][%2i] : \n\n", n, n);

		
		int p;
		
		p = n*n;

		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				if (k % 2 == 0)
				{
					A[k][i] = p;
					p--;
				}
				else
				{
					A[k][i] = p - n + i + 1;
				}
			}
			
			if (k % 2 != 0) p -= n;
		}
		
		
		
		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}


		printf("\n\n\tДругий варiант заповнення матрицi:\n\n");

		p = 1;

		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				if (k % 2 == 0)
				{
					A[k][i] = p;
					p++;
				}
				else
				{
					A[k][i] = p + n - i - 1;
				}
			}

			if (k % 2 != 0) p += n;
		}



		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}

		printf("\n\n\tТретiй варiант заповнення матрицi:\n\n");

		i =n*n;
		p = n/2;

		for (k = 1; k <= p; k++)
		{
			for (int j = k - 1; j < n - k + 1; j++) A[k - 1][j] = i--;
			for (int j = k; j < n - k + 1; j++) A[j][n-k] = i--;
			for (int j = n-k - 1; j >= k - 1; --j) A[n-k][j] = i--;
			for (int j = n - k - 1; j >= k; j--) A[j][k-1] = i--;
		}
		if (n % 2 == 1) A[p][p] = 1;


		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}


		printf("\n\n\tЧетвертий варiант заповнення матрицi:\n\n");

		i = 1;
		p = n / 2;

		for (k = 1; k <= p; k++)
		{
			for (int j = k - 1; j < n - k + 1; j++) A[k - 1][j] = i++;
			for (int j = k; j < n - k + 1; j++) A[j][n - k] = i++;
			for (int j = n - k - 1; j >= k - 1; --j) A[n - k][j] = i++;
			for (int j = n - k - 1; j >= k; j--) A[j][k - 1] = i++;
		}
		if (n % 2 == 1) A[p][p] = n*n;


		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}



		cout << "\n\n\tПродовжити (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}