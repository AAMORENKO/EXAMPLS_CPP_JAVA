// Підрахунок кількості щасливих квитків

#include <iostream>
using namespace std;

int main()
{
	system("color 1f");
	setlocale(LC_ALL, ".1251");

	int k, count;
	char z;

	do {
		system("cls");

		count = 0;

		cout << "\n\tВведiть число K=";
		cin >> k;

		for (int q = 0; q < 10; q++) {
			for (int w = 0; w < 10; w++) {
				for (int e = 0; e < 10; e++) {
					for (int r = 0; r < 10; r++) {
						for (int t = 0; t < 10; t++) {
							for (int y = 0; y < 10; y++) {
								if ((q + w + e == k * (r + t + y))) count++;
							}
						}
					}
				}
			}
		}
		cout << "\n\tусього K-щасливих квиткiв: " << count;
		cout<<"\n\n\t ùå ðàç (y/n)?  ";
		cin >> z;
	} while (z != 'n');

	cout << "\n\n\t";
	//system("pause");
	return 0;
}
