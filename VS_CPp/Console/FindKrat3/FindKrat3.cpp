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

	cout << "\n\n\tПошук елементiв матрицi, номери яких кратнi трьом:\n\n";

	
	for (k = 0; k < 100; k++)
	{
		A[k] = rand();
		if(k%3==0 && k>0) printf("A[%i]=%i\t",k, A[k]);
	}


	cout << endl << endl << "\t";
	system("pause");
	return 0;
}