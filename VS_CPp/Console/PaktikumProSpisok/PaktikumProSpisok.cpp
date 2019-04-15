#include <iostream>

// додаткова бібліотека 
#include <fstream>

using namespace std;

fstream inf, otf;

struct Result //придумав назву структурі
{
	char *fam[25];  //Прізвище
	int mark;		//Оцінка
};


int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");
	cout << "\n\tРезультати перевiрки:\n";

	char Name[12][25];
	int dig[12];

	// читання списку класу
	int p = 0;
	inf.open("class.txt", ios::in);
	if (!inf) return 0;
	while (!inf.eof())
	{
		inf >> Name[p];
		p++;
	}
	inf.close();

	// читання списку оцінок
	p = 0;
	inf.open("marks.txt", ios::in);
	if (!inf) return 0;
	while (!inf.eof())
	{
		inf >> dig[p];
		p++;
	}
	inf.close();

	double sr, sum;
	sr = sum = 0; // обчислення середнього балу
	for (int k = 0; k < p; k++)
	{
		printf("\n\t%2i) %s\t%i", k + 1, Name[k], dig[k]);
		sum += dig[k];
	}
	sr = sum / p;

	printf("\n\n\tсереднiй бал оцiнок: %2.0f", sr);

	int max = dig[0];
	int min = dig[0];

	for (int i = 1; i < p; i++)// пошук максимального і мінімального балів
	{
		if (dig[i] > max) max = dig[i];
		if (dig[i] < min) min = dig[i];
	}

	printf("\n\tмаксимальний бал: %i", max);
	printf("\n\tмiнiмальний бал: %i", min);

	// вибірка учнів
	cout << "\n\tпрiзвища учнiв з максимальним балом: ";
	for (int t = 0; t < p; t++)
	{
		if (dig[t] > 9) printf("%s, ", Name[t]);
	}
	// вибірка учнів
	cout << "\n\tпрiзвища учнiв з мiнiмальним балом: ";
	for (int t = 0; t < p; t++)
	{
		if (dig[t] <4) printf("%s, ", Name[t]);
	}

	int count = 0;
	for (int k = 0; k < p; k++)// вибірка учнів
	{
		if (dig[k] > 9) count++;
	}
	printf("\n\tкiлькiсть учнiв, що вчаться на 10 балiв i вище: %i", count);

	count = 0;
	for (int k = 0; k < p; k++)// вибірка учнів
	{
		if (dig[k] < 4) count++;
	}
	printf("\n\tкiлькiсть учнiв, що мають 3 бали i нижче: %i", count);
	
	// створюю структурний список та сортую його за абеткою

	Result spisok[15]; // оголошую список у пам'яті ПК
	printf("\n\tсписок учнiв з їхнiми балами за абеткою:\n", count);

	for (int k = 0; k < p; k++) //заповнюю структуру в таблицю spisok[12]
	{
		*spisok[k].fam = Name[k];
		spisok[k].mark = dig[k];
	}

	//сортування списку за абеткою
	for (int i = 0; i<p; i++) {
		for (int j = i + 1; j<p; j++) {
			if (strcmp(*spisok[i].fam, *spisok[j].fam)>0) {
				Result tmp = spisok[i];
				spisok[i] = spisok[j];
				spisok[j] = tmp;
			}
		}
	}

	for (int k = 0; k < p; k++)//виведення результатів сортування
	{
		printf("\n\t%2i) %s\t%i", k + 1, *spisok[k].fam, spisok[k].mark);
	}

	
	cout << endl << endl << "\t";
	system("pause");
	return 0;
}