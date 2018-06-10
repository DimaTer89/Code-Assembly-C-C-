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
	bool operator < (Airplane ob);
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
bool Airplane::operator<(Airplane ob)
{
	if (max_man < ob.max_man)
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
	int menu;
	int min_kol;

	Airplane ob1;
	Airplane ob2;
	cout << " Введите название самолёта : ";
	gets_s(name, 64);
	cout << " Введите количество пассажиров : ";
	do
	{
		cin >> kol;
		if (kol < 0)cout << " Количество пассажиров должно быть положительным , введите снова \n";
	} while (kol < 0);
	cout << " Введите максимальное число пассажиров : ";
	do
	{
		cin >> max_kol;
		if (max_kol < kol)cout << " Ошибка , максимальное число пассажиров меньше количество пассажиров на борту , введите снова !\n";
	} while (max_kol < kol);
	ob1.init(name, kol, max_kol);
	cin.ignore();
	cout << " Введите название самолёта : ";
	gets_s(name, 64);
	cout << " Введите количество пассажиров : ";
	do
	{
		cin >> kol;
		if (kol < 0)cout << " Количество пассажиров должно быть положительным , введите снова \n";
	} while (kol < 0);
	cout << " Введите максимальное число пассажиров : ";
	do
	{
		cin >> max_kol;
		if (max_kol < kol)cout << " Ошибка , максимальное число пассажиров меньше количество пассажиров на борту , введите снова !\n";
	} while (max_kol < kol);
	ob2.init(name, kol, max_kol);
	do
	{
		system("cls");
		cout << " 1 - Проверка на равенство типов самолетов\n";
		cout << " 2 - Увеличение  пассажиров в салоне самолета \n";
		cout << " 3 - Уменьшение пассажиров в салоне самолета \n";
		cout << " 4 - Сравнение двух самолетов по максимально возможному количеству пассажировна борту \n";
		cout << " 5 - показать типы самолётов \n";
		cout << " 6 - выход \n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			if (ob1 == ob2)
			{
				cout << " Тип 1 самолёта равен типу 2 самолёта \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Тип 1 самолёта не равен типу 2 самолёта \n";
				system("pause");
				break;
			}
		case 2:
			int key;
			cout << " 1 - Увеличение пассажиров 1 самолёта \n";
			cout << " 2 - Увеличение пассажиров 2 самолёта \n";
			cin >> key;
			if (key == 1)
			{
				int num;
				num = ob1.kol_man;
				cout << " Введите количество пассажиров для увеличения : ";
				do
				{
					cin >> dob_kol;
					if (num + dob_kol > ob1.max_man)cout << " После увеличения в салоне пассажиров больше максимального количества : ";
				} while (num + dob_kol > ob1.max_man);
				for (int i = 0; i < dob_kol; i++)
				{
					++ob1;
				}
				break;
			}
			if (key == 2)
			{
				int num;
				num = ob2.kol_man;
				cout << " Введите количество пассажиров для увеличения : ";
				do
				{
					cin >> dob_kol;
					if (num + dob_kol > ob2.max_man)cout << " После увеличения в салоне пассажиров больше максимального количества : ";
				} while (num + dob_kol > ob2.max_man);
				for (int i = 0; i < dob_kol; i++)
				{
					++ob2;
				}
				break;
			}
		case 3:
			int keys;
			cout << " 1 - Увеличение пассажиров 1 самолёта \n";
			cout << " 2 - Увеличение пассажиров 2 самолёта \n";
			cin >> keys;
			if (keys == 1)
			{
				int num1;
				num1 = ob1.kol_man;
				cout << " Введите количество пассажиров для уменьшения : ";
				do
				{
					cin >> min_kol;
					if (num1 < min_kol)cout << " После уменьшения будет отрицальное число пассажиров , введите снова : ";
				} while (num1 < min_kol);
				for (int i = 0; i < min_kol; i++)
				{
					--ob1;
				}
				break;
			}
			if (keys == 2)
			{
				int num1;
				num1 = ob2.kol_man;
				cout << " Введите количество пассажиров для уменьшения : ";
				do
				{
					cin >> min_kol;
					if (num1 < min_kol)cout << " После уменьшения будет отрицальное число пассажиров , введите снова : ";
				} while (num1 < min_kol);
				for (int i = 0; i < min_kol; i++)
				{
					--ob2;
				}
				break;
			}
		case 4:
			if (ob1 > ob2)
			{
				cout << " На 1 самолёте вместимость больше, чем на 2 самолёте \n";
				system("pause");
				break;
			}
			else if (ob1 < ob2)
			{
				cout << " На 1 самолёте вместимость меньше, чем на 2 самолёте \n";
				system("pause");
				break;
			}
			else 
			{
				cout << " На 1 и 2 самолёте одинаковая вместимость \n";
				system("pause");
				break;
			}
			break;
		case 5:
			cout << " ===========================\n";
			ob1.show();
			cout << " ===========================\n";
			ob2.show();
			cout << " ===========================\n";
			system("pause");
			break;
		case 6:
			cout << " До свидания !\n";
			break;
		default:
			cout << " Ошибка ввода !\n";
		}
	} while (menu != 6);
	system("pause");
}
