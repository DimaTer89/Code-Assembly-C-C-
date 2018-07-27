#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void paint(int n)
{
	if (n == 1)
	{
		cout << "\t__";
	}
	if (n == 2)
	{
		cout << "   __\n"
			<< "  |\n";
	}
	if (n == 3)
	{
		cout << "   __\n"
			<< "  |  |\n";
	}
	if (n == 4)
	{
		cout << "   __\n"
			<< "  |  |\n"
			<<  "   --\n";
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num = 0;
	cout << endl << endl;
	num = 1;
	paint(num);
	cout << endl << endl;
	num = 2;
	paint(num);
	num = 3;
	paint(num);
	num = 4;
	paint(num);
	system("pause");
}
