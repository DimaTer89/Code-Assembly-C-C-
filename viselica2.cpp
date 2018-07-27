#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void paint(int n)
{
	if (n == 9)
	{
		cout << "   __\n";
	}
	if (n == 8)
	{
		cout << "   __\n"
			<< "  |\n";
	}
	if (n == 7)
	{
		cout << "   __\n"
			<< "  |  |\n";
	}
	if (n == 6)
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
	if (n == 4)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\n"
			<< "    |\n";
	}
	if (n == 3)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n";
	}
	if (n == 2)
	{
		cout << "   ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n"
			<< "   /\n ";
	}
	if (n == 1)
	{
		cout << "  ___\n"
			<< "  |___|\n"
			<< "   /|\\\n"
			<< "    |\n"
			<< "   / \\\n ";
	}
	if (n == 0)
	{
		cout << "   |\n"
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
	int num = 10;
	cout << endl << endl;
	num--;
	paint(num);
	cout << endl << endl;
	num--;
	paint(num);
	num--;
	paint(num);
	num--;
	paint(num);
	num--;
	paint(num);
	num--;
	paint(num);
	num--;
	paint(num);
	num--;
	paint(num);
	num--;
	paint(num);
	num--;
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

