#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	system("color 17");
	
	int n, A[1000],s1,s2;
	char z;
	do
	{
		system("cls");
		cout << "\n\n\tПорiвняння кiлькостi населення на вулицi:\n\n\t";

		cout << "Введiть кiлькiсть будинкiв на вулицi N=";
		cin >> n;

		s1 = s2 = 0;
		for (int k = 0; k < n; k++)
		{
			A[k] = 1 + rand() % 400;
			printf("\tA[%i]=%i\n", k + 1, A[k]);
			if (k % 2 != 0) s1 += A[k]; else s2 += A[k];
		}

		if (s2 >= s1)
			cout << "\n\n\tРезультат: на парнiй сторонi проживає бiльшiсть: " << s2 << "\n\tна непарнiй сторонi: " << s1;
		else
			cout << "\n\n\tРезультат: на непарнiй сторонi проживає бiльшiсть: " << s1 << "\n\tна парнiй сторонi: " << s2;

		cout << endl << endl << "\tПродовжити (y/n)? >> ";
		cin >> z;
	} while (z != 'n');

	return 0;
}