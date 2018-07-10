// Демонстрация использования средства динамической
// идентификации типов. 
#include <windows.h>
#include <iostream> 
#include <cstdlib>
#include <time.h>

using namespace std;

class figure
{
protected:
	double x, y;
public:
	figure(double i, double j)
	{
		x = i;
		y = j;
	}
	virtual double area() = 0;
};

class triangle :public figure
{
public:
	triangle(double i, double j) :figure(i, j)
	{
	}
	virtual double area()
	{
		return x*0.5*y;
	}
};

class rectangle :public figure
{
public:
	rectangle(double i, double j) :figure(i, j)
	{
	}
	virtual double area()
	{
		return x*y;
	}
};

class circle :public figure
{
public:
	circle(double i, double j = 0) :figure(i, j)
	{
	}
	virtual double area()
	{
		return 3.14159268*x*x;
	}
};

// Фабрика объектов класса figure.
figure* factory()
{
	switch (rand() % 3)
	{
	case 0:
		double rad;
		cout << " *****Площадь круга***** \n";
		cout << " Введите радиус круга : ";
		do
		{
			cin >> rad;
			if (rad < 1)
				cout << " Значение должно быть больше нуля, введите снова : ";
		} while (rad < 1);
		return new circle(rad);
		break;
	case 1:
		double base, height;
		cout << " *****Площадь треугольника***** \n";
		cout << " Введите длину основания : ";
		do
		{
			cin >> base;
			if (base < 1)
				cout << " Значение должно быть больше нуля, введите снова : ";
		} while (base < 1);
		cout << " Введите высоту : ";
		do
		{
			cin >>height;
			if (height < 1)
				cout << " Значение должно быть больше нуля, введите снова : ";
		} while (height < 1);
		return new triangle(base, height);
		break;
	case 2:
		double side1, side2;
		cout << " *****Площадь прямоугольника***** \n";
		cout << " Введите длину первой стороны : ";
		do
		{
			cin >> side1;
			if (side1 < 1)
				cout << " Значение должно быть больше нуля, введите снова : ";
		} while (side1 < 1);
		cout << " Введите длину второй стороны : ";
		do
		{
			cin >> side2;
			if (side2 < 1)
				cout << " Значение должно быть больше нуля, введите снова : ";
		} while (side2 < 1);
		return new rectangle(side1, side2);
		break;
	}
	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");

	srand((unsigned)time(NULL));
	figure* p;  // указатель на базовый класс
	int i;
	int t = 0;
	int r = 0;
	int c = 0;
	// генерируем и подсчитываем объекты
	for (i = 0; i<10; i++)
	{
		p = factory();  // генерируем объект
		cout << "Объект имеет тип " << typeid(*p).name();
		cout << ". ";
		// учитываем этот объект
		if (typeid(*p) == typeid(triangle))
			t++;
		if (typeid(*p) == typeid(rectangle))
			r++;
		if (typeid(*p) == typeid(circle))
			c++;
		// отображаем площадь фигуры
		cout << "Площадь равна " << p->area() << endl;
	}
	cout << endl;
	cout << "Сгенерированы следующие объекты:\n";
	cout << " треугольников: " << t << endl;
	cout << " прямоугольников: " << r << endl;
	cout << " кругов: " << c << endl;
	system("pause");
	return 0;
}
