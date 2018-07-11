/*Задание 1.
Реализуйте класс Дробь. Необходимо хранить числитель и знаменатель в качестве переменных-членов.
Реализуйте функции-члены:
-для ввода данных в переменные-члены;
-для выполнения арифметических операций (сложение, вычитание, умножение, деление).
*/


#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Drob
{
	int chisl;
	int znamen;
	int NOD(int x, int y)
	{
		if (y == 0)
			return x;
		return NOD(y, x%y);
	}
public:
	void input(int c, int z)
	{
		chisl = c;
		znamen = z;
		reduct(peredacha());
	}
	void mult(int x, int y)
	{
		chisl *= x;
		znamen *= y;
		reduct(peredacha());
		
	}
	void div(int x, int y)
	{
		chisl *= y;
		znamen *= x;
		reduct(peredacha());
		
	}
	void sum(int x, int y)
	{
		if (znamen != y)
		{
			chisl = ((y*chisl) + (x*znamen));
			znamen *= y;
		}
		else
		{
			chisl = (chisl + x);
			znamen = y;
		}
		reduct(peredacha());
	
	}
	void sub(int x, int y)
	{
		if (znamen != y)
		{
			chisl = ((y*chisl) - (x*znamen));
			znamen *= y;
		}
		else
		{
			chisl = (chisl - x);
			znamen = y;
		}
		reduct(peredacha());
		
	}
	void show()
	{
		cout << "Текущая дробь:  " << chisl << '/' << znamen << endl;
	}
	void show_chisl()
	{
		cout << chisl;
	}
	void show_znamen()
	{
		cout << znamen;
	}
	int peredacha()
	{
		return NOD(chisl, znamen);
	}
	void reduct(int x)
	{
		chisl /= x;
		znamen /= x;
	}
	void redux()
	{
		int count = 0;
		int chis=0;
		int znam = 0;
		count = chisl / znamen;
		chis=chisl - znamen*count;
		znam = znamen;
		cout << count << " " << chis << "/" << znam << endl;
    }
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");

	int a, b, m;
	char c = 'y';
	cout << "Введите числитель:" << endl;
	cin >> a;
	cout << "Введите знаменатель:" << endl;
	cin >> b;
	Drob obj;
	obj.input(a, b);
	do
	{
		//obj.reduct(obj.peredacha());
		cout << " Текущая дробь : ";
		obj.redux();
		cout << "1 - Сумма" << endl;
		cout << "2 - Вычитание" << endl;
		cout << "3 - Умножение" << endl;
		cout << "4 - Деление" << endl;
		cout << "Выберите действие:" << '\n';
		cin >> m;
		switch (m)
		{
		case 1:
			cout << "Введите числитель" << endl;
			cin >> a;
			cout << "Введите знаменатель" << endl;
			cin >> b;
			obj.sum(a, b);
			break;
		case 2:
			cout << "Введите числитель" << endl;
			cin >> a;
			cout << "Введите знаменатель" << endl;
			cin >> b;
			obj.sub(a, b);
			break;
		case 3:
			cout << "Введите числитель" << endl;
			cin >> a;
			cout << "Введите знаменатель" << endl;
			cin >> b;
			obj.mult(a, b);
			break;
		case 4:
			cout << "Введите числитель" << endl;
			cin >> a;
			cout << "Введите знаменатель" << endl;
			cin >> b;
			obj.div(a, b);
			break;
		default:
			cout << "Ошибка! Неккоректный выбор!" << endl;
		}
		cout << "Результат:  ";
		obj.redux();
		cout << "Продолжить работы?(y/n)" << endl;
		cin >> c;
	} while (c != 'n');
	return 0;
}
==============================================
