#include <iostream>

// ��������� �������� 
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	cout << "\n\n\t�����i��� ����� �� \"���i�����\"\n\n";

	int n, k, i;
	string ms, mz;

	char t[255] = "���������������������";
	// char t[255] ="�����";
	//char t[255]="������� �����i�";
	//char t[255] = "����";

	ms.empty();
	ms = t; n = ms.size();

	mz.empty();
	cout<<"\t��������� �����: "<< ms;

	for (k = n - 1; k >= 0; k--)
	{
		mz += ms[k];
	}

	cout << "\n\n\t�������� �����: " << mz;

	bool fg = true;
	for (i = 0; i < n; i++)
	{
		if (mz[i] != ms[i]) fg = false;
	}

	if (fg) cout << "\n\n\t���� ����� - ���i�����.";
	else cout << "\n\n\t���� ����� - �� � ���i�������.";

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}