#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	cout << "\n\n\tПослiдовнiсть чисел Фiбоначi\n\n";

	long a1, a2, a3;
	int n;

	a1 = 1; 
	a2 = 1;
	a3 = a2 + a1;

	n = 4;
	printf("%8i %8i %8i", a1, a2, a3);

	while (n < 45)
	{
		a1 = a2;
		a2 = a3;
		a3 = a2 + a1;
		printf("%16i", a3);
		n++;
	}



	cout << "\n\n\t";
	system("pause");
	return 0;
}