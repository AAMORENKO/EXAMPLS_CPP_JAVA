#include <iostream>

// ��������� ��������
#include <time.h>

using namespace std;

int main()
{
	// ��������� ���������� �����
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	//���������� ������������� ������ �������
	int A[100][100];
	int B[100];
	int n, k, i;
	int a, b, p;
	int poz, neg, maxline;
	char z;

	n = 17;
	// ������ ��� ����������� �����
	a = -99;
	b = 99;

	do
	{
		system("cls");
		printf("\n\t���������� ������i A[%2i][%2i] �i���� ����������� �������. \n\n", n, n);

		// �����������
		poz = neg = p = 0;
		for (k = 0; k < n; k++) B[k] = 0;

		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				do
				{	//���������� ����������� �� ������
					A[k][i] = a + rand() % (b - a + 1);
				} while (abs(A[k][i])<10||abs(A[k][i])>99);

				//����
				printf("%5i", A[k][i]);
				//���������
				if (A[k][i] > 0) poz++;
				//����������� ���� �����
				B[p] += A[k][i];

			}
			printf("   %2i) summ= %i", p + 1, B[p]);
			cout << "\n";
			p++;
		}
		
		
		neg = n*n - poz;
		printf("\n\n\t�i���i��� ��������: %i", poz);
		printf("\n\t�i���i��� �i�'�����: %i", neg);
		
		//����� ������ ����� � ������������ �����
		maxline = 0; int max = B[maxline];
		for (k = 0; k < n; k++)
		{
			if (max < B[k])
			{
				max = B[k];
				maxline = k;
			}
		}

		printf("\n\n\t����i���� ���� � ����� �i� ������� %i", maxline+1);

		cout << "\n\n\t���������� (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}
