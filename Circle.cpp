/*Создайте класс Circle (окружность):
Реализуйте через перегруженные операторы;
- Проверка на равенство радиусов двух окружностей (операция ==);
- Сравнения длин двух окружностей (операция >).
- Пропорциональное изменение размеров окружности, путем изменения ее радиуса
(операция += и -=).*/
#include <iostream>
#include <Windows.h>
using namespace std;

class Circle
{
	double radius;
	double C;
public:
	Circle(double radius = 1)
	{
		this->radius = radius;
	}
	Circle circumference()
	{
		C = 2 * 3.14*radius;
		return *this;
	}
	void show()
	{
		cout << " Радиус окружности = " << radius << endl;
		cout << " Длина окружности =  " << C << endl;
	}
	bool operator == (Circle ob);
	bool operator > (Circle ob);
	bool operator < (Circle ob);
	Circle operator +=(double data);
	Circle operator-=(double data);
};
bool Circle::operator==(Circle ob)
{
	if (radius == ob.radius)
		return true;
	else
		return false;
}
bool Circle::operator>(Circle ob)
{
	if (C>ob.C)
		return true;
	else
		return false;
}
bool Circle::operator<(Circle ob)
{
	if (C<ob.C)
		return true;
	else
		return false;
}
Circle Circle::operator +=(double data)
{
	radius += data;
	return *this;
}
Circle Circle::operator -=(double data)
{
	radius -= data;
	return *this;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double radius1;
	double radius2;
	int key;
	int menu;
	int _key;
	cout << " Введите радиус первой окружности : ";
	cin >> radius1;
	cout << " Введите радиус второй окружности : ";
	cin >> radius2;
	Circle circle1(radius1);
	Circle circle2(radius2);
	circle1.circumference();
	circle2.circumference();
	do
	{
		system("cls");
		cout << " 1 - Проверка радиусов двух окружностей\n";
		cout << " 2 - Сравнение длин окружностей\n";
		cout << " 3 - Изменение длины окружности путём изменения её радиуса\n";
		cout << " 4 - Показать данные\n";
		cout << " 5 - Выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			if (circle1 == circle2)
			{
				cout << " Радиусы равны \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Радиусы не равны \n";
				system("pause");
				break;
			}
		case 2:
			if (circle1 > circle2)
			{
				cout << " Длина первой окружности больше длины второй окружности \n";
				system("pause");
				break;
			}
			else if (circle1 < circle2)
			{
				cout << " Длина первой окружности меньше длины второй окружности \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Длины обоих окружностей равны \n";
				system("pause");
				break;
			}
		case 3:
			cout << " 1 - Изменение радиуса первой окружности \n";
			cout << " 2 - Изменение радиуса второй окружности \n";
			cout << " Ваш выбор : ";
			do
			{
				cin >> key;
				if (key < 1 || key>2)cout << " Ошибка, внимательнее читайте меню, введите снова : ";
			} while (key < 1 || key>2);
			if (key == 1)
			{
				cout << " 1 - Увеличение радиуса \n";
				cout << " 2 - Уменьшение радиуса \n";
				cout << " Ваш выбор : ";
				do
				{
					cin >> _key;
					if(_key<1||_key>2)cout << " Ошибка, внимательнее читайте меню, введите снова : ";
				} while (_key < 1 || _key>2);
				if (_key == 1)
				{
					double a;
					cout << " Введите число : ";
					cin >> a;
					circle1 += a;
					circle1.circumference();
					cout << " Новые данные \n";
					circle1.show();
					system("pause");
					break;
				}
				if (_key == 2)
				{
					double a;
					cout << " Введите число : ";
					cin >> a;
					circle1 -= a;
					circle1.circumference();
					cout << " Новые данные \n";
					circle1.show();
					system("pause");
					break;
				}
			}
			if (key == 2)
			{
				cout << " 1 - Увеличение радиуса \n";
				cout << " 2 - Уменьшение радиуса \n";
				cout << " Ваш выбор : ";
				do
				{
					cin >> _key;
					if (_key<1 || _key>2)cout << " Ошибка, внимательнее читайте меню, введите снова : ";
				} while (_key < 1 || _key>2);
				if (_key == 1)
				{
					double a;
					cout << " Введите число : ";
					cin >> a;
					circle2 += a;
					circle2.circumference();
					cout << " Новые данные \n";
					circle2.show();
					system("pause");
					break;
				}
				if (_key == 2)
				{
					double a;
					cout << " Введите число : ";
					cin >> a;
					circle2 -= a;
					circle2.circumference();
					cout << " Новые данные \n";
					circle2.show();
					system("pause");
					break;
				}
			}
		case 4:
			cout << "=====================\n";
			circle1.show();
			cout << "=====================\n";
			circle2.show();
			cout << "=====================\n";
			system("pause");
			break;
		case 5:
			cout << " До свидания !\n";
			break;
		}
	} while (menu != 5);
	system("pause");
	return 0;
}
