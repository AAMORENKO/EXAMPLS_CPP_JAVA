// Кодування, коди клавіатури
#include <iostream>
using namespace std;

int main()
{
	system("color 1f");
	setlocale(LC_ALL, ".1251");
	cout << "\n\tÊîäóâàííÿ DOS(866)\n";
	
	setlocale(LC_ALL, ".866");
	cout << endl;
	for (int k = 32; k < 256; k++)
	{
		printf("%4i = %3c",k,char(k));
	}

	setlocale(LC_ALL, ".1251");
	cout << "\n\n\tÊîäóâàííÿ Windows(1251)\n";
	cout << endl;
	for (int k = 32; k < 256; k++)
	{
		printf("%4i = %3c", k, char(k));
	}




	cout << endl << endl<<"\t";
	system("pause");
	return 0;
}
