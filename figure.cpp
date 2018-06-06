/*Создайте класс для подсчета площади геометрических фигур.
Класс должен предоставлять функциональность для подсчета площади треугольника по разным формулам, площади прямоугольника, площади квадрата, площади ромба. 
Функции-члены для подсчета площади должны быть реализованы с помощью статических функций-членов.
Также класс должен считать количество подсчетов площади и возвращать это значение с помощью статической функции-члена.*/
#include <iostream>
#include <windows.h>

using namespace std;

class CalcOfgeoSh
{
	static double camp1;
	static double camp2;
	static double camp3;
public :
	static int count;
	static double place1();
	static double place2();
	static double place3();
	static double place4();
	static double place5();
	static double place6();
};
double CalcOfgeoSh::place1()
{
	cout << " Введите одну сторону прямоугольника : ";
	cin >>camp1;
	cout << " Введите вторую строну прямоугольника : ";
	cin >> camp2;
	double res;
	res = camp1*camp2;
	count++;
	return res;
}
double CalcOfgeoSh::place2()
{
	cout << " Введите сторону квадрата : ";
	cin >> camp1;
	double res;
	res = camp1*camp1;
	count++;
	return res;
}
double CalcOfgeoSh::place3()
{
	cout << " Введите первую диагональ ромба : ";
	cin >> camp1;
	cout << " Введите вторую диагональ ромба : ";
	cin >> camp2;
	double res;
	res = 0.5*camp1*camp2;
	count++;
	return res;
}
double CalcOfgeoSh::place4()
{
	cout << " Введите сторону основания треугольника : ";
	cin >> camp1;
	cout << " Введите высоту прямоугольника : ";
	cin >> camp2;
	double res;
	res = 0.5*camp1*camp2;
	count++;
	return res;
}
double CalcOfgeoSh::place5()
{
	cout << " Введите 1 сторону треугольника : ";
	cin >> camp1;
	cout << " Введите 2 сторону треугольника : ";
	cin >> camp2;
	cout << " Введите 3 сторону треугольника : ";
	cin >> camp3;
	double p;
	double s;
	double res;
	p = 0.5*(camp1 + camp2 + camp3);
	s = p*(p - camp1)*(p - camp2)*(p - camp3);
	res = sqrt(s);
	count++;
	return res;
}
double CalcOfgeoSh::place6()
{
	cout << " Введите 1 сторону треугольника : ";
	cin >> camp1;
	cout << " Введите 2 сторону прямоугольника : ";
	cin >> camp2;
	double res;
	res = 0.5*camp1*camp2;
	count++;
	return res;
}
int CalcOfgeoSh::count = 0;
double CalcOfgeoSh::camp1=0;
double CalcOfgeoSh::camp2=0;
double CalcOfgeoSh::camp3=0;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	int menu;
	do
	{
		system("cls");
		cout << " 1 - Площадь прямоугольника \n";
		cout << " 2 - Площадь квадрата \n";
		cout << " 3 - Площадь ромба \n";
		cout << " 4 - Площадь треугольника \n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << " Площадь прямоугольника = " << CalcOfgeoSh::place1() << endl;
			cout << " Подсчётов = " << CalcOfgeoSh::count << endl;
			system("pause");
			break;
		case 2:
			cout << " Площадь квадрата = " << CalcOfgeoSh::place2() << endl;
			cout << " Подсчётов = " << CalcOfgeoSh::count << endl;
			system("pause");
			break;
		case 3:
			cout << " Площадь ромба = " << CalcOfgeoSh::place3() << endl;
			cout << " Подсчётов = " << CalcOfgeoSh::count << endl;
			system("pause");
			break;
		case 4:
			cout << " Выберите метод \n";
			cout << " 1 - по высоте и основанию \n";
			cout << " 2 - по трём сторонам \n";
			cout << " 3 - прямоугольного треугольника \n";
			int key;
			cin >> key;
			switch (key)
			{
			case 1:
				cout << " Площадь треугольника = " << CalcOfgeoSh::place4() << endl;
				cout << " Подсчётов = " << CalcOfgeoSh::count << endl;
				system("pause");
				break;
			case 2:
				cout << " Площадь треугольника = " << CalcOfgeoSh::place5() << endl;
				cout << " Подсчётов = " << CalcOfgeoSh::count << endl;
				system("pause");
				break;
			case 3:
				cout << " Площадь треугольника = " << CalcOfgeoSh::place6() << endl;
				cout << " Подсчётов = " << CalcOfgeoSh::count << endl;
				system("pause");
				break;
			default:
				cout << " Ошибка !!! \n";
				system("pause");
				break;
			}
						
		case 0:
			cout << " До свидания .\n";
			break;
		}
	} while (menu != 0);
	system("pause");
	return 0;
}
