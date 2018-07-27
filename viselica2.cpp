#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void paint(int n)
{
	if (n == 1)
	{
		cout << "   __\n";
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
			<< "  |__|\n";
			
	}
	if (n == 5)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "    |\n"
			<< "    |\n";
	}
	if (n == 6)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\n"
			<< "    |\n";
	}
	if (n == 7)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n";
	}
	if (n == 8)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n"
			<< "   /\n ";
	}
	if (n == 9)
	{
		cout << "  ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n"
			<< "   / \\\n ";
	}
	if (n == 10)
	{
		cout<< "   |\n"
			<< "   _|_\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n"
			<< "   / \\\n ";
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
	num = 5;
	paint(num);
	num = 6;
	paint(num);
	num = 7;
	paint(num);
	num = 8;
	paint(num);
	num = 9;
	paint(num);
	num = 10;
	paint(num);
	system("pause");
}
