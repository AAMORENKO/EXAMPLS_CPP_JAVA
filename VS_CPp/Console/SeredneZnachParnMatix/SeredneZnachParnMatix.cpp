#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	system("color 1F");

	int A[100];
	int k;

	int n = 0;
	double sred = 0;

	cout << "\n\n\tОбчислення середнього значення з парних елементiв матрицi:\n\n";


	for (k = 0; k < 30; k++)
	{
		A[k] = -9999+rand()%(9999+9999);
		if (A[k] % 2 == 0)
		{
			n++;
			sred += A[k];
		}
		printf("A[%i]=%i\t", k, A[k]);
	}

	printf("\n\n\tСереднє значення парних елеметiв дорiвнює: %8.2f", sred / n);


	cout << endl << endl << "\t";
	system("pause");
	return 0;
}