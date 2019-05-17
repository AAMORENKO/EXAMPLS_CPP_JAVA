#include <iostream>

// ��������� �������� 
#include <time.h>

#define roz 289

using namespace std;

int main()
{
	// ��������� ���������� �����
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	// ������ ������i
	int A[roz], B[roz * roz], C[roz * roz];
	int n, k, i, p, sum;

	n = roz;
	int a = 10;
	int b = 99;


	system("cls");
	printf("\n\t���������� ������i A[%i] �i���� �������. \n\n", n);

	for (k = 0; k < n; k++)
	{
		A[k] = a + rand() % (b - a + 1);
		//printf("%i  ", A[k]);
	}
	p = 0;
	for (k = 0; k < sqrt(n); k++)
	{
		cout << "\t";
		for (i = 0; i < sqrt(n); i++)
		{
			printf("%4i", A[p]);
			p++;
		}
		cout << "\n";
	}

	cout << "\n\n\tB���i�� ����� ��� ������ M=";
	int m;
	cin >> m;

	for (i = 0; i < n*n; i++)
	{
		B[i] = -1;
		C[i] = -1;
	}
	p = 0;

	for (k = 0; k < n - 1; k++)
	{
		for (i = k + 1; i < n; i++)
		{
			sum = A[k] + A[i];
			if (sum == m)
			{
				B[p] = A[k];
				C[p] = A[i];
				p++;
			}
		}
	}
	cout << "\n\n\t��������� ������:\n";
	bool fg = false;
	for (k = 0; k < n*n; k++)
	{
		if (B[k] + C[k] == m)
		{
			printf("\n\t%i+%i=%i", B[k], C[k], m);
			fg = true;
		}
	}

	if (!fg)
	{
		cout << "\n\t����� ��� �� ��������!";
	}

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}
