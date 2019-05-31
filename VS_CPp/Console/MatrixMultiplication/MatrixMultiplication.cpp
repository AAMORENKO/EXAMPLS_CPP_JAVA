#include <iostream>
#include <fstream>
using namespace std;

int n, m, q, p;
int A[20][20], B[20][20],C[20][20];
fstream inf, otf;

int main()
{
	setlocale(LC_ALL, "rus");
	system("color 1F");

	cout << "\n\tПрограма множення матриць AxB=C\n";
	cout << "\n\tПочатковi данi з файлу data.txt :\n\n";

	inf.open("data.txt", ios::in);
	if (!inf) return 0;

	inf >> n; inf >> m; p = n;
	printf("\n\tЗаповнення матрицi A[%i][%i] цiлими числами. \n\n", n,m);
	for(int k=0;k<n;k++)
	{
		cout << "\n\t";
		for (int i = 0; i < m; i++)
		{
			inf >> A[k][i];
			printf("%4i", A[k][i]);
		}
	}

	inf >> n; inf >> m; q = m;
	printf("\n\n\tЗаповнення матрицi B[%i][%i] цiлими числами. \n\n", n, m);
	for (int k = 0; k<n; k++)
	{
		cout << "\n\t";
		for (int i = 0; i < m; i++)
		{
			inf >> B[k][i];
			printf("%4i", B[k][i]);
		}
	}
	inf.close();
	
	printf("\n\n\tРезультат множення матриць С[%i][%i]\n\n", p, q);
	for (int k = 0; k<p; k++)
	{
		for (int i = 0; i < q; i++)
		{
			C[k][i] = 0;
			for(int j=0;j<n;j++) C[k][i]+=A[k][j]*B[j][i];
		}
	}
	for (int k = 0; k<p; k++)
	{
		cout << "\n\t";
		for (int i = 0; i < q; i++)
		{
			inf >> C[k][i];
			printf("%5i", C[k][i]);
		}
	}

	otf.open("res.txt", ios::out);
	if (!otf) return 0;
	for (int k = 0; k<p; k++)
	{
		for (int i = 0; i < q; i++)
		{
			otf << C[k][i] << "\t";
		}
		otf << "\n";
	}
	otf.flush();
	otf.close();

	cout << "\n\n\t";
	system("pause");
	return 0;
}