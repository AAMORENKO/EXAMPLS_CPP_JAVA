#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	float x1, x2, x3, y1, y2, y3, a, b, c, p, s;

	system("cls");
	cout << "\n\n\tОбчислюємо площу трикутника за координатами його вершин\n\n\t";

	cout << "\n\tВведiть координати точки А -> x1 y1 -> ";
	cin >> x1 >> y1;

	cout << "\n\tВведiть координати точки B -> x2 y2 -> ";
	cin >> x2 >> y2;

	cout << "\n\tВведiть координати точки C -> x3 y3 -> ";
	cin >> x3 >> y3;
	
	cout << "\n\n\t Знайдено довжини сторін трикутника:";

	a = sqrt(powf(fabs(x1 - x2), 2.0) + powf(fabs(y1 - y2), 2.0));
	b = sqrt(powf(fabs(x3 - x2), 2.0) + powf(fabs(y3 - y2), 2.0));
	c = sqrt(powf(fabs(x1 - x3), 2.0) + powf(fabs(y1 - y3), 2.0));
	
	printf("\n\n\ta=%8.2f\n\tb=%8.2f\n\tc=%8.2f", a, b, c);

	p = 0.5*(a + b + c);
	s = sqrt(p*(p - a)*(p - b)*(p - c));

	printf("\n\n\tПлоща трикутника дорiвнює S=%8.3f кв.од.", s);

	cout << endl << endl << "\t";
	system("pause");

	return 0; 
}
