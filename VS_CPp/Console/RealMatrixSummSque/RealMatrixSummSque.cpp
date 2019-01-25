#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	double A[100], summ;
	int n, k, i;

	summ = 0;

	cout << "\n\n\tОбчислення суми квадратiв вiд'ємних дiйсних чисел таблицi:\n\n";

	cout << "\tВведiть число (5<N<30) N=";
	cin >> n;

	cout << "\n\n";
	for (k = 0; k < n; k++)
	{
		A[k] = -99.5 + rand() *(99.5 - (-99.5))/RAND_MAX;
		printf("\tA[%i]=%6.2f\n",k, A[k]);
		if (A[k] < 0) summ += (powf(A[k], 2.0));
	}


	printf("\n\n\tСума квадратiв вiд'ємних елементiв дорiвнює: %12.2f ", summ);

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}