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
#include <windows.h>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(int argc, char* argv[])
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	shared_ptr<string> films[5];
	for (int i = 0; i < 5; i++)
	{
		cout << " Введите фильм : ";
		getline(cin, str);
		films[i] = shared_ptr<string>(new string(str));
	}
	shared_ptr<string> pwin;
	pwin = films[3];   // films[3] теряет право собственности
	cout << "Номинант на лучший фильм\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "Победитель- " << *pwin << "!\n";
	system("pause");
	return 0;
}

