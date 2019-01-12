// Кількість ходів коня на шахматній дошці
#include <iostream>
#include <string>

using namespace std;

char c,z;
string misce;
int nd, w, h;

int main()
{
	system("color 1f");
	setlocale(LC_ALL, ".1251");

	nd = w = h = 0;
	misce.empty();

	cout << "\n\n\tÂâåäiòü ïîëîæåííÿ êîíÿ: ";
	getline(cin, misce);

	c = misce[0];
	switch (c)
	{
	case 'a': w = 1; break;
	case 'b': w = 2; break;
	case 'c': w = 3; break;
	case 'd': w = 4; break;
	case 'e': w = 5; break;
	case 'f': w = 6; break;
	case 'g': w = 7; break;
	case 'h': w = 8; break;
	}

	c = misce[1];
	h = atoi(&c);

	if (h == 0)
	{
		cout << "\n\tÏîëîæåííÿ êîíÿ ââåäåíî íåêîðåêòíî.";
	}
	else
	{
		if (h + 2 <= 8 && w + 1 <= 8) nd++;
		if (h + 2 <= 8 && w - 1 > 0) nd++;
		if (h - 2 > 0 && w + 1 <= 8) nd++;
		if (h - 2 > 0 && w - 1 > 0) nd++;
		if (w + 2 <= 8 && h + 1 <= 8) nd++;
		if (w + 2 <= 8 && h - 1 > 0) nd++;
		if (w - 2 > 0 && h + 1 <= 8) nd++;
		if (w - 2 > 0 && h - 1 > 0) nd++;
		cout << "\n\tÂèñíîâîê - êiëüêiñòü ïîëiâ, ùî á'º êiíü: " << nd;
	}


	cout << "\n\n\t";
	system("pause");
	return 0;
}
