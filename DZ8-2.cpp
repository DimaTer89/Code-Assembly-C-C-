/*Создать абстрактный базовый класс с виртуальной функцией - площадь. Создать 
  производные классы: прямоугольник, круг, прямоугольный треугольник, 
  трапеция со своими функциями площади. Для провер¬ки определить массив
  ссылок на абстрактный класс, которым присваиваются адреса различных 
  объектов. Площадь трапеции: S=(a+b)h/2.*/
#include <iostream>
#include <Windows.h>

using namespace std;

class SquareFigura
{
protected:
	double a;
	double b;
	double h;
public:
	SquareFigura()
	{
		a = b = h = 0;
	}
	void toGetData(double a = 0, double b = 0, double h = 0)
	{
		this->a = a;
		this->b = b;
		this->h = h;
	}
	virtual void Square() = 0;
};
class rectangle :public SquareFigura
{
public:
	void Square()
	{
		cout << " Площадь = " << a * b << endl;
	}
};
class triangle :public SquareFigura
{
public:
	void Square()
	{
		cout << " Площадь = " << 0.5*a*b << endl;
	}
};
class rightTriangle :public SquareFigura
{
public:
	void Square()
	{
		cout << " Площадь = " << 0.5*a*b << endl;
	}
};
class trapeze :public SquareFigura
{
public:
	void Square()
	{
		cout << " Площадь = " << (a+b)*h / 2. << endl;
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double side1;
	double side2;
	double height;
	int menu = 0;
	SquareFigura* ptr[4];
	rectangle rectangle;
	triangle triangle;
	rightTriangle rightTriangle;
	trapeze trapeze;
	ptr[0] = &rectangle;
	ptr[1] = &triangle;
	ptr[2] = &rightTriangle;
	ptr[3] = &trapeze;
	do
	{
		system("cls");
		cout << " 1 - Вычислить площадь прямоугольника \n";
		cout << " 2 - Вычислить площадь треугольника \n";
		cout << " 3 - Вычислить площадь прямоугольного треугольника \n";
		cout << " 4 - Вычислить площадь трапеции \n";
		cout << " 0 - Выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		switch(menu)
		{
		case 1:
			system("cls");
			cout << " Площадь прямоугольника \n";
			cout << " Введите длину : ";
			cin >> side1;
			cout << " Введите ширину : ";
			cin >> side2;
			ptr[0]->toGetData(side1, side2);
			ptr[0]->Square();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << " Площадь треугольника \n";
			cout << " Введите длину основания : ";
			cin >> side1;
			cout << " Введите высоту : ";
			cin >> height;
			ptr[1]->toGetData(side1, height);
			ptr[1]->Square();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << " Площадь прямоугольного треугольника \n";
			cout << " Введите длину 1 катета : ";
			cin >> side1;
			cout << " Введите длину 2 катета : ";
			cin >> side2;
			ptr[2]->toGetData(side1, side2);
			ptr[2]->Square();
			system("pause");
			break;
		case 4:
			system("cls");
			cout << " Площадь трапеции \n";
			cout << " Введите длину 1 основания : ";
			cin >> side1;
			cout << " Введите длину 2 основания : ";
			cin >> side2;
			cout << " Введите высоту : ";
			cin >> height;
			ptr[3]->toGetData(side1, side2,height);
			ptr[3]->Square();
			system("pause");
			break;
		case 0:
			cout << " До свидания \n";
			system("pause");
			break;
		default:
			cout << " Ошибка, неверно выбрано меню \n";
			system("pause");
			break;
		}
	} while (menu != 0);
	return 1;
}
