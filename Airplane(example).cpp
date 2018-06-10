#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

class airplane//класс для сравнения самолетов
{
	char* S;
	int len;
public:
	airplane(char* a)
	{
		len=strlen(a);
		S = new char[len + 1];
		strcpy(S, a);
	}
	~airplane()
	{
		delete[] S;
	}
	bool airplane::operator==(const airplane& op1)
		{ 
            if (strcmp(S,op1.S))
		        return false;
	        else
		        return true;
        }
};

class Airplane
{
	int x;
public:
	Airplane()
	{
		x = 0;
	}
	Airplane(int i)
	{
		x = i;
	}

	Airplane operator()(int a);

	bool Airplane::operator==(Airplane op2);
	bool Airplane::operator > (Airplane op2);
	bool Airplane::operator < (Airplane op2);
	bool Airplane::operator ++();
	bool Airplane::operator -- ();
	void show();
	void showlen();
};

// Перегрузка оператора "()".
Airplane Airplane::operator()(int a)
{
	Airplane temp;
	temp.x = x + a;
	return temp;
}

// Перегрузка оператора "==".
bool Airplane::operator == (Airplane op2)
{
	if (x == op2.x)
		return true;
	else
		return false;
}

// Перегрузка оператора ">".
bool Airplane::operator > (Airplane op2)
{
	if (x > op2.x)
		return true;
	else
		return false;
}

// Перегрузка оператора "<".
bool Airplane::operator < (Airplane op2)
{
	if (x < op2.x)
		return true;
	else
		return false;
}

// Перегрузка оператора "++".
bool Airplane::operator ++()
{
	x = ++x;
	return true;
}

// Перегрузка оператора "--".
bool Airplane::operator --()
{
	x = --x;
	return true;
}

// Отображение координат X,Y,Z.
void Airplane::show()
{
	cout << x << "\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int r1, r2, key, rr1, rr2;
	char* ty1 = new char[80];
	char* ty2 = new char[80];
	cout << "Домашнее задание 2 к модулю 4,задача 2\n";
	cout << "Создать класс Airplane(самолет). \n";
	cout << "С помощью перегрузки операторов реализовать : \n";
	cout << "- Проверка на равенство типов самолетов(операция == ); \n";
	cout << "- Увеличение и уменьшение пассажиров в салоне самолета \n";
	cout << "(операции ++ и -- в префиксной форме); \n";
	cout << "- Сравнение двух самолетов по максимально возможному количеству пассажиров \n";
	cout << "на борту(операция>). \n";
	cout << "Введите тип 1 самолета \n";
	gets(ty1);
	OemToCharA(ty1,ty1);
	cout << "Введите тип 2 самолета \n";
	gets(ty2);
	OemToCharA(ty2,ty2);
	cout << "Введите количество пассажиров 1 самолета \n";
	cin >> r1;
	while (r1 < 0)
	{
		cout << "Кол.пассажиров в самолете не может быть отрицательным\n";
		cout << "Введите правильно максимальное количество пассажиров 1 самолета \n";
		cin >> r1;
	}
	cout << "Введите количество пассажиров 2 самолета \n";
	cin >> r2;
	while (r2 < 0)
	{
		cout << "Кол.пассажиров в самолете не может быть отрицательным\n";
		cout << "Введите правильно максимальное количество пассажиров 2 самолета \n";
		cin >> r2;
	}
	cout << "Введите максимальное количество пассажиров 1 самолета \n";
	cin >> rr1;
	while (r1 > rr1)
	{
		cout << "Макс.вместимость самолета не может быть меньше кол.пассажиров в самолете\n";
		cout << "Введите правильно максимальное количество пассажиров 1 самолета \n";
		cin >> rr1;
	}
	cout << "Введите максимальное количество пассажиров 2 самолета \n";
	cin >> rr2;
	while (r2 > rr2)
	{
		cout << "Макс.вместимость самолета не может быть меньше кол.пассажиров в самолете\n";
		cout << "Введите правильно максимальное количество пассажиров 1 самолета \n";
		cin >> rr2;
	}
	system("pause");
	do
	{
		system("cls");
		cout << "1.Проверка на равенство типов самолетов\n";
		cout << "2.Сравнение двух самолетов по максимально возможному количеству пассажиров\n";
		cout << "3.Увеличение пассажиров в салоне самолета\n";
		cout << "4.Уменьшение пассажиров в салоне самолета\n";
		cout << "0.Выход\n";
		cin >> key;
		while (getchar() != '\n');
		switch (key)
		{
		case 1:
		{
				  airplane ob1(ty1);
				  airplane ob2(ty2);
				  if (ob1 == ob2)
					  cout << "Тип 1 самолета равен типу 2 самолета \n";
				  else
					  cout << "Тип 1 самолета неравен типу 2 самолета\n";
				  system("pause");
				  break;
		}
		case 2:
		{
				  Airplane ob1(rr1);
				  Airplane ob2(rr2);
				  cout << "Вместимость 1 самолета :  ";
				  ob1.show();
				  cout << "Вместимость 2 самолета :  ";
				  ob2.show();
				  if (ob1 == ob2)
					  cout << "Вместимость 1 самолета равна вместимости 2 самолета \n";
				  else
				  if (ob1 < ob2)
					  cout << "Вместимость 1 самолета меньше вместимости 2 самолета\n";
				  else
				  if (ob1 > ob2)
					  cout << "Вместимость 1 самолета больше вместимости 2 самолета\n";
				  system("pause");
				  break;
		}
		case 3:
		{
				  Airplane ob1(r1);
				  Airplane ob2(r2);
				  ob1 = ++r1;
				  ob2 = ++r2;
				  cout << "Количество пассажиров 1 самолета теперь :  ";
				  ob1.show();
				  cout << "Количество пассажиров 1 самолета теперь :  ";
				  ob2.show();
				  system("pause");
				  break;
		}
		case 4:
		{
				  Airplane ob1(r1);
				  Airplane ob2(r2);
				  ob1 = --r1;
				  ob2 = --r2;
				  cout << "Количество пассажиров 1 самолета теперь :  ";
				  ob1.show();
				  cout << "Количество пассажиров 1 самолета теперь :  ";
				  ob2.show();
				  system("pause");
				  break;
		}
		case 0:
			cout << "До свидания\n";
			break;
		default:
			cout << "Выбран неправильный пункт меню\n";
			break;
		}
	} while (key != 0);
	system("pause");
	return 0;
}
