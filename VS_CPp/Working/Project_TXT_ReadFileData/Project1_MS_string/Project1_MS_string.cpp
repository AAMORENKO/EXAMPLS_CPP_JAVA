#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream inf;
int k, n;
string ms;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");
	cout << "\n\n\tТЕМА: Обчислення кiлькостi iнформацiї у файлi.\n\n";

	k = n = 0;
	inf.open("data.txt", ios::in);
	if (!inf) return 0;

	while (!inf.eof())
	{
		getline(inf, ms);
		k += ms.size();
		cout << ms << "\n";
		n++;
	}

	inf.close();

	
	cout << "\n\n\tКiлькiсть зчитаних знакiв: " << k;
	cout << "\n\n\tКiлькiсть строк: " << n;
	cout << "\n\n\tКiлькiсть iнформацiї: " << (double)k / 1024 << " Кбайт";

	cout << "\n\n\t";
	system("pause");
	return 0;
}