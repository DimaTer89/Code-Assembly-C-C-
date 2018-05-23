#include <iostream>
#include <windows.h>

using namespace std;

class drobi
{
	int chis1;
	int chis2;
	int znam1;
	int znam2;
public:
	drobi(int a, int b, int c, int d)
	{
		chis1 = a;
		znam1 = b;
		chis2 = c;
		znam2 = d;
	}
	void show(char c) 
	{
		cout << chis1 << "/" << znam1 << c << chis2 << "/" << znam2 << "=";
	}
	//void sum(int, int, int, int);
	//void minus(int, int, int, int);
	void umnoj();
	//void del(int, int, int, int);
};
void drobi::umnoj()
{
	chis1 *= chis2;
	znam1 *= znam2;
	cout << chis1 << "/" << znam1 << endl;
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int chis1, znam1, chis2, znam2;
	cout << " Введите числитель и знаменатель первой дроби через пробел : ";
	cin >> chis1 >> znam1;
	cout << " Введите числитель и знаменатель второй дроби через пробел : ";
	cin >> chis2 >> znam2;
	drobi drob(chis1, znam1, chis2, znam2);
	drob.show('*');
	drob.umnoj();
	system("pause");
}
