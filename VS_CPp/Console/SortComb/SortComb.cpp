#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	system("color 1F");

	int A[100],B[100],C[200];
	int n, k, i;

	cout << "\n\n\tОб'єднуємо впорядкованi матрицi в одну:\n\n\t";

	n = 0;
	for (k = 0; k < 10; k++)
	{
		A[k] = 10 + rand() % 89;
		B[k] = 10 + rand() % 89;
		C[n] = A[k]; C[n + 1] = B[k];
		n += 2;
	}


	bool sort = false;

	do
	{
		sort = false;
		for (i = 0; i < 9; i++)
		{
			if (A[i] > A[i + 1])
			{
				int sw = A[i];
				A[i] = A[i + 1];
				A[i + 1] = sw;
				sort = true;
			}
		}

	} while (sort);


	do
	{
		sort = false;
		for (i = 0; i < 9; i++)
		{
			if (B[i] > B[i + 1])
			{
				int sw = B[i];
				B[i] = B[i + 1];
				B[i + 1] = sw;
				sort = true;
			}
		}

	} while (sort);


	do
	{
		sort = false;
		for (i = 0; i < 19; i++)
		{
			if (C[i] > C[i + 1])
			{
				int sw = C[i];
				C[i] = C[i + 1];
				C[i + 1] = sw;
				sort = true;
			}
		}

	} while (sort);



	for (k = 0; k < 10; k++)
	{
		printf("%4i", A[k]);
	}

	cout << "\n\n\t";
	for (k = 0; k < 10; k++)
	{
		printf("%4i", B[k]);
	}

	cout << "\n\n\t";
	for (k = 0; k < 20; k++)
	{
		printf("%4i", C[k]);
	}


	cout << endl << endl << "\t";
	system("pause");
	return 0;
}