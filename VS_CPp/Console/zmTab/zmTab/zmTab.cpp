// zmTab - заповнення таблиці змійкою
// 1 6 7 12
// 2 5 8 11
// 3 4 9 10
#include <iostream>
using namespace std;
int n, m;
int A[100][100], B[100], k, i, j, p;
char z;

int main()
{
	system("color 1f");
	setlocale(LC_ALL, ".1251");
	
	for (k = 0; k < 100; k++) B[k] = 0;

	for (k = 0; k < 100; k++)
		for (i = 0; i < 100; i++) A[k][i] = 0;

	do
	{
		system("cls");
		cout << "\n\t(n<23) n="; cin >> n;
		cout << "\n\t(m<23) m="; cin >> m;

		p = 10;
		for (i = 0; i < m; i++)
		{
			for (k = 0; k < n; k++)
			{
				A[k][i] = p; B[k + 1] = p;
				p++;
			}

			if (i % 2 != 0)
			{
				for (j = 0; j < n; j++)
				{
					A[j][i] = B[n - j];
				}
			}
		}

		cout << "\n";
		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < m; i++)
			{
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}
		
		cout << "\n\t(y/n?)>>";
		cin >> z;
	} while (z != 'n');

	cout << "\n\n\t";
	//system("pause");
	return 0;
}
