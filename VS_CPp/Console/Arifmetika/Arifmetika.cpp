#include <iostream>

// додаткова бібліотека 
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	int d,g, k, i,p;
	char z;
	string t, ms;

	cout << "\n\n\tОбислимо значення арифметичного виразу.\n";

	cout << "\n\tВведiть вираз (наприклад: 1+2-5+8): ";
	getline(cin, ms);

	t.empty(); t = ms;
	k = t.size();

	i = 0; p = 0;
	d = (int)t[i] - '0'; i++;
	z = t[i]; i++;
	g = (int)t[i] - '0'; i++;

	if (z == '+') p = d + g;
	if (z == '-') p = d - g;
	if (z == '*') p = d * g;

	if (k > 3)
	{
		while (k > 3)
		{
			z = t[i]; i++;
			g = (int)t[i]-'0'; i++;
			if (z == '+') p += g;
			if (z == '-') p -= g;
			if (z == '*') p *= g;
			k -= 2;
		}
	}


	cout << "\n\n\tВи ввели вираз: " << ms;
	printf("\n\n\tВаш результат: %i", p);

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}

