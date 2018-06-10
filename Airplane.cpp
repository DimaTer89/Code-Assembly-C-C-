/*Создать класс Airplane (самолет).
    С помощью перегрузки операторов реализовать:
    - Проверка на равенство типов самолетов (операция ==);
    - Увеличение и уменьшение пассажиров в салоне самолета
      (операции ++ и -- в префиксной форме);
    - Сравнение двух самолетов по максимально возможному количеству пассажиров 
      на борту (операция>).*/
#include<iostream>
#include <Windows.h>
using namespace std;

class Airplane
{
public:
	char* airName;
	int kol_man;
	int max_man;
	Airplane()
	{
		kol_man = 1;
		max_man = 1;
		airName = new char('\0');
	}
	Airplane(const Airplane& ob)
	{
		airName = new char[strlen(ob.airName) + 1];
		strcpy(airName, ob.airName);
		kol_man = ob.kol_man;
		max_man = ob.max_man;
	}
	~Airplane()
	{
		if (airName)
			delete airName;
		airName = NULL;
	}
	void init(char* str,int kol,int max_kol)
	{
		airName = new char[strlen(str) + 1];
		strcpy(airName, str);
		kol_man = kol;
		max_man = max_kol;
	}
	void show()
	{
		cout << " Модель самолёта : " << airName << endl;
		cout << " Количество людей в самолёте = " << kol_man << endl;
		cout << " Максимальное количество людей = " << max_man << endl;
	}
	bool operator == (Airplane ob);
	bool operator > (Airplane ob);
	Airplane operator ++();
	Airplane operator --();
};
bool Airplane::operator==(Airplane ob)
{
	if (strcmp(airName, ob.airName) == 0)
		return true;
	else
		return false;
}
bool Airplane::operator>(Airplane ob)
{
	if (max_man > ob.max_man)
		return true;
	else
		return false;
}
Airplane Airplane::operator++()
{
	kol_man++;
	return *this;
}
Airplane Airplane::operator--()
{
	kol_man--;
	return *this;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char name[64];
	int kol;
	int max_kol;
	int dob_kol;

	Airplane ob1;
	Airplane ob2;
	cout << " Введите название самолёта : ";
	gets_s(name, 64);
	cout << " Введите количество пассажиров : ";
	cin >> kol;
	cout << " Введите максимальное число пассажиров : ";
	do
	{
		cin >> max_kol;
		if (max_kol < kol)cout << " Ошибка , максимальное число пассажиров меньше количество пассажиров на борту , введите снова !\n";
	} while (max_kol < kol);
	ob1.init(name, kol, max_kol);
	cout << endl;
	ob1.show();
	cout << endl;
	cin.ignore();
	cout << " Введите название самолёта : ";
	gets_s(name, 64);
	cout << " Введите количество пассажиров : ";
	cin >> kol;
	cout << " Введите максимальное число пассажиров : ";
	do
	{
		cin >> max_kol;
		if (max_kol < kol)cout << " Ошибка , максимальное число пассажиров меньше количество пассажиров на борту , введите снова !\n";
	} while (max_kol < kol);
	ob2.init(name, kol, max_kol);
	cout << endl;
	ob2.show();
	if (ob1 == ob2)cout << " Самолёты одинаковой модели \n";
	else
		cout << " Самолёты разных моделей \n";
	if (ob1 > ob2)cout << ob1.airName << " вмещает больше пассажиров чем " << ob2.airName << endl;
	else
		cout << ob2.airName << " вмещает больше пассажиров чем " << ob1.airName << endl;
	cout << " Добавить : ";
	cin >> dob_kol;
	for (int i = 0; i < dob_kol; i++)
	{
		++ob1;
	}
	ob1.show();
	for (int i = 0; i < dob_kol; i++)
	{
		--ob1;
	}
	ob1.show();
	for (int i = 0; i < dob_kol; i++)
	{
		++ob2;
	}
	ob2.show();
	for (int i = 0; i < dob_kol; i++)
	{
		--ob2;
	}
	ob2.show();
	system("pause");
}
