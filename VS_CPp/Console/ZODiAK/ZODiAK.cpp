#include <iostream>

// додаткова бібліотека 
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	
	cout << "\n\tПрактическая работа. ТЕМА: Знак Зодиака. \n\n";

	int d, m, k;
	string mz[12] = { "Овен","Телец","Близнецы",
		"Рак","Лев","Дева","Весы","Скорпион",
		"Стрелец","Козерог","Водолей","Рыбы" };

	printf("\n\tВведите День D=");
	cin >> d;
	cout << "\n\t";

	printf("\n\tВведите Месяц M=");
	cin >> m;
	cout << "\n\t";

	if (((d >= 21) && (d <= 31) && (m == 3)) ||
		((d >= 1) && (d <= 20) && (m == 4)))
	{
		k = 0;
	}

	if (((d >= 21) && (d <= 30) && (m == 4)) ||
		((d >= 1) && (d <= 21) && (m == 5)))
	{
		k = 1;
	}

	if (((d >= 22) && (d <= 31) && (m == 5)) ||
		((d >= 1) && (d <= 21) && (m == 6)))
	{
		k = 2;
	}

	if (((d >= 22) && (d <= 30) && (m == 6)) ||
		((d >= 1) && (d <= 23) && (m == 7)))
	{
		k = 3;
	}

	if (((d >= 24) && (d <= 31) && (m == 7)) ||
		((d >= 1) && (d <= 23) && (m == 8)))
	{
		k = 4;
	}

	if (((d >= 24) && (d <= 31) && (m == 8)) ||
		((d >= 1) && (d <= 23) && (m == 9)))
	{
		k = 5;
	}

	if (((d >= 24) && (d <= 30) && (m == 9)) ||
		((d >= 1) && (d <= 23) && (m == 10)))
	{
		k = 6;
	}

	if (((d >= 24) && (d <= 31) && (m == 10)) ||
		((d >= 1) && (d <= 22) && (m == 11)))
	{
		k = 7;
	}

	if (((d >= 23) && (d <= 30) && (m == 11)) ||
		((d >= 1) && (d <= 21) && (m == 12)))
	{
		k = 8;
	}

	if (((d >= 22) && (d <= 31) && (m == 12)) ||
		((d >= 1) && (d <= 20) && (m == 1)))
	{
		k = 9;
	}

	if (((d >= 21) && (d <= 31) && (m == 1)) ||
		((d >= 1) && (d <= 19) && (m == 2)))
	{
		k = 10;
	}

	if (((d >= 20) && (d <= 29) && (m == 2)) ||
		((d >= 1) && (d <= 20) && (m == 3)))
	{
		k = 11;
	}

	if ((d > 31) || (d < 1) || (m >12) || (m < 1))
	{
		k = 12;
	}

	if ((d > 29) && (m == 2))
	{
		k = 12;
	}

	switch (k)
	{
	case 0: printf("\n\tЗнак Зодиака: "); std::cout << mz[0];	break;
	case 1: printf("\n\tЗнак Зодиака: "); std::cout << mz[1];	break;
	case 2: printf("\n\tЗнак Зодиака: "); std::cout << mz[2];	break;
	case 3: printf("\n\tЗнак Зодиака: "); std::cout << mz[3];	break;
	case 4: printf("\n\tЗнак Зодиака: "); std::cout << mz[4];	break;
	case 5: printf("\n\tЗнак Зодиака: "); std::cout << mz[5];	break;
	case 6: printf("\n\tЗнак Зодиака: "); std::cout << mz[6];	break;
	case 7: printf("\n\tЗнак Зодиака: "); std::cout << mz[7];	break;
	case 8: printf("\n\tЗнак Зодиака: "); std::cout << mz[8];	break;
	case 9: printf("\n\tЗнак Зодиака: "); std::cout << mz[8];	break;
	case 10: printf("\n\tЗнак Зодиака: "); std::cout << mz[10];	break;
	case 11: printf("\n\tЗнак Зодиака: "); std::cout << mz[11];	break;
	case 12: printf("\n\tТакой даты не существует."); break;
	}





	cout << endl << endl << "\t";
	system("pause");
	return 0;
}

