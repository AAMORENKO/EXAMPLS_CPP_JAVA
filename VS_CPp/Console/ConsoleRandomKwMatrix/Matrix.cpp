//���������� ��������� ������� ����������� ������ �������

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	system("color 1F");

	int A[100][100];
	int n, k, i;
	char z;

	n = 17;
	do
	{
		system("cls");
		printf("\n\t���������� ��������� ������i A[%2i][%2i] ����������� �i���� �������. \n\n", n, n);

		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				A[k][i] = 10 + rand() % 89;
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}
		cout << "\n\n\t���������� (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}