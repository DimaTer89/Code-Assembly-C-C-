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
		cout << " Длина окружности =  " <<C << endl;
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
	double rad;
	Circle ob1;
	Circle ob2;
	cout << " Введите радиус первой окружности : ";
	cin >> rad;
	ob1 = rad;
	ob1.circumference();
	ob1.show();
	cout << " Введите радиус второй окружности : ";
	cin >> rad;
	ob2 = rad;
	ob2.circumference();
	ob2.show();
	if (ob1 == ob2)
		cout << " Радиусы двух окружностей равны \n";
	else
		cout << " Радиусы двух окружностей не равны \n";
	if (ob1 > ob2)
		cout << " Длина первой окружности больше второй \n";
	if(ob1<ob2)
		cout << " Длина первой окружности меньше второй \n";
	cout << " Введите число для увеличения радиуса : ";
	double x;
	cin >> x;
	ob1 += x;
	ob1.circumference();
	ob1.show();
	cout << " Введите число для уменьшения радиуса : ";
	cin >> x;
	ob2 -= x;
	ob2.circumference();
	ob2.show();
	if (ob1 == ob2)
		cout << " Радиусы двух окружностей равны \n";
	else
		cout << " Радиусы двух окружностей не равны \n";
	if (ob1 > ob2)
		cout << " Длина первой окружности больше второй \n";
	else if (ob1<ob2)
		cout << " Длина первой окружности меньше второй \n";
	else
		cout << " Длины окружности равны \n";
	system("pause");
	return 0;
}
