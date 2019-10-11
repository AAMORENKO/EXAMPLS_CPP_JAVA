#include <iostream>
#include <fstream>

using namespace std;

fstream inf,otf;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	int V[30], B[30];
	int p = 0;
	
	inf.open("data.txt", ios::in);
	if (!inf) return 0;
	otf.open("res.txt", ios::out);
	if (!inf) return 0;
	while (!inf.eof())
	{
		inf >> V[p];
		B[p] = V[p];
		cout << V[p] << " ";
		p++;
	}
	inf.close();
	cout << "\n";
	
	/*int min, sw, g;
	
	for (int k = 0; k < 5; k++)
	{
		min = B[k]; g = k;
		for (int i = k; i < 6; i++)
		{
			if (min > B[i])
			{
				min = B[i];
				g = i;
			}
		}
		sw = B[k];
		B[k] = B[g];
		B[g] = sw;
	}*/

	/*int n = 6;
	p = n - 1;
	while (p > 0)
	{
		int m = 0;
		for (int i = 0; i <= p; i++)
		{
			if (B[i] > B[m]) m = i;
		}
		int sw = B[m];
		B[m] = B[p];
		B[p] = sw;
		p--;
	}*/

	
	int n = 6;
	p = n - 1;
	while (p > 0)
	{
		bool m = true;
		for (int i = 0; i < p; i++)
		{
			if (B[i] > B[i + 1]) 
			{
				int sw = B[m];
				B[m] = B[p];
				B[p] = sw;;
				m = false;
			}
		}
		
		p--;
	}

	for (int k = 0; k < 6; k++)
	{
		cout << B[k] << " ";
		otf << B[k] << " ";

	}
	otf.flush();
	otf.close();


	cout << endl << endl << "\t";
	system("pause");
	return 0;
}
