// приклади матриць
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	cout << "\n\tÏðàêòè÷åñêàÿ ðàáîòà. ÒÅÌÀ: Îáðîáêà äàíèõ â òàáëèöÿõ. \n\n";

	int A[1000];
	int M[50][50];
	int k, i, j, p;

	for (k = 0; k < 15; k++)
	{
		A[k] = rand() % 10;
		printf("A[%2i]=%3i\n",k, A[k]);
	}
	cout << endl << endl;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			p = -1;
			for (k = 0; k < rand() % 10; k++) p *= (-1);
			M[i][j] = p*  rand() % 100;
			printf("%4i", M[i][j]);
		}
		cout << endl;
	}


	cout << endl << endl << "\t";
	system("pause");
	return 0;
}
