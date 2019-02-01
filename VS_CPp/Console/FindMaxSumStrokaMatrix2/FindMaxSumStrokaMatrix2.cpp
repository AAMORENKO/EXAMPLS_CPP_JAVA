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

	//визначення максимального розміру матриць
	int A[100][100];
	int B[100];
	int n, k, i;
	int a, b, p;
	int poz, neg, maxline;
	char z;

	n = 17;
	// відрізок для генерування чисел
	a = -99;
	b = 99;

	do
	{
		system("cls");
		printf("\n\tЗаповнення матрицi A[%2i][%2i] цiлими двозначними числами. \n\n", n, n);

		// ініціалізація
		poz = neg = p = 0;
		for (k = 0; k < n; k++) B[k] = 0;

		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				do
				{	//заповнення випадковими за умовою
					A[k][i] = a + rand() % (b - a + 1);
				} while (abs(A[k][i])<10||abs(A[k][i])>99);

				//друк
				printf("%5i", A[k][i]);
				//підрахунок
				if (A[k][i] > 0) poz++;
				//знаходження суми рядка
				B[p] += A[k][i];

			}
			printf("   %2i) summ= %i", p + 1, B[p]);
			cout << "\n";
			p++;
		}
		
		
		neg = n*n - poz;
		printf("\n\n\tКiлькiсть додатних: %i", poz);
		printf("\n\tКiлькiсть вiд'ємних: %i", neg);
		
		//пошук номера рядка з максимальною сумою
		maxline = 0; int max = B[maxline];
		for (k = 0; k < n; k++)
		{
			if (max < B[k])
			{
				max = B[k];
				maxline = k;
			}
		}

		printf("\n\n\tНайбiльша сума у рядку пiд номером %i", maxline+1);

		cout << "\n\n\tПродовжити (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}
