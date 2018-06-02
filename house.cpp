#include <iostream>
#include <windows.h>
#define N 128
using namespace std;
class Human
{
public:
	char* person;
	char* profess;
	Human()
	{
		person = new char[N];
		profess = new char[N];
	}
	Human(const Human& ob)
	{
		person = ob.person;
		profess = ob.profess;
	}
	~Human()
	{
		delete[]person;
		person = NULL;
		delete[]profess;
		profess = NULL;
	}
	void init()
	{
		delete[]person;
		person = NULL;
		delete[]profess;
		profess = NULL;
		person = new char[N];
		profess = new char[N];
		cout << " Введите ФИО : ";
		gets_s(person, N);
		cout << " Введите профессию : ";
		gets_s(profess, N);
	}
	void show()
	{
		cout << " ФИО : " << person << endl;
		cout << " Профессия : " << profess << endl;
	}
};
class Flat
{
public:
	Human * soul;
	int kol_kom;
	int stage;
	int kol_jil;
	int num_flat;
	double area;
	Flat()
	{
		kol_jil = kol_kom = stage = num_flat = 0;
		area = 0;
		soul = new Human[1];
	}
	Flat(const Flat& ob)
	{
		soul = ob.soul;
	}
	~Flat()
	{
		delete[] soul;
		soul = NULL;
	}
	void init()
	{
		int k;
		cout << " Введите номер квартиры : ";
		cin >> num_flat;
		cout << " Введите этаж : ";
		cin >> stage;
		cout << " Введите количество комнат : ";
		cin >> kol_kom;
		cout << " Введите площадь квартиры  : ";
		cin >> area;
		cout << " Введите количество жильцов : ";
		cin >> kol_jil;
		cin.ignore();
		soul = new Human[kol_jil];
		for (k = 0; k < kol_jil; k++)
		{
			cout << " Квартирант № " << k + 1 << endl;
			soul[k].init();
		}
	}
	void show()
	{
		cout << " Номер квартиры : " << num_flat << endl;
		cout << " Этаж : " << stage << endl;
		cout << " Количество комнат : " << kol_kom << endl;
		cout << " Площадь квартиры : " << area << endl;
		cout << " Жильцы : \n ";
		for (int i = 0; i < kol_jil; i++)
		{
			soul[i].show();
		}

	}
};
class House
{
public:
	Flat * dom;
	char* adress;
	int kol_kv;
	int num;
	House()
	{
		num = kol_kv = 0;
		dom = new Flat[1];
		adress = new char[1];
	}
	House(const House& ob)
	{
		dom = ob.dom;
		adress = ob.adress;
	}
	~House()
	{
		delete[]dom;
		dom = NULL;
		delete[]adress;
		adress = NULL;
	}
	void put(int a, int b, char* str)
	{
		num = a;
		kol_kv = b;
		adress = new char[strlen(str) + 1];
		strcpy(adress, str);
		dom = new Flat[kol_kv];
	}
	void init()
	{
		for (int i = 0; i < kol_kv; i++)
		{
			system("cls");
			cout << " Квартира " << i + 1 << endl;
			dom[i].init();
		}
	}
	void show()
	{
		cout << " =====================================\n\n";
		cout << " Дом № " << num << endl;
		cout << "\n\n";
		cout << " Адресс : " << adress << endl;
		for (int i = 0; i < kol_kv; i++)
		{
			dom[i].show();
			cout << "\n";
		}
		cout << "=======================================\n";
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x;
	int kol;
	int num;
	int menu;
	int carte;
	int num_kv;
	char adress[100];
	bool flag = false;
	House apar;

	do
	{
		system("cls");
		cout << " 1 - Заполнить дом \n";
		cout << " 2 - показать список квартир в доме \n";
		cout << " 3 - редактировать дом \n";
		cout << " 4 - поиск \n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			if (flag == false)
			{
				cout << " Введите номер дома : ";
				cin >> num;
				cin.ignore();
				cout << " Введите адрес : ";
				gets_s(adress, 100);
				cout << " Введите количество квартир : ";
				cin >> kol;
				apar.put(num, kol,adress);
				apar.init();
				flag = true;
				break;
			}
			else
			{
				cout << " Дом уже заполнен , если вас что то не устраивает , выберите пунк № 3 \n";
				system("pause");
				break;
			}
		case 2:
			if (flag == false)
			{
				cout << " Создайте сначала класс дом \n";
				system("pause");
				break;
			}
			else
			{
				apar.show();
				system("pause");
			}
			break;
		case 3:
			if (flag == false)
			{
				cout << " Создайте сначала класс дом \n";
				system("pause");
				break;
			}
			else
			{
				cout << " 1 - создать новый дом \n";
				cout << " 2 - изменить квартиру \n";
				do
				{
					cin >> carte;
					if (carte < 1 || carte>4)cout << " Ошибка!!! \n";
				} while (carte < 1 || carte>4);
				switch (carte)
				{
				case 1:
					cout << " Введите номер дома : ";
					cin >> num;
					cin.ignore();
					cout << " Введите адрес : ";
					gets_s(adress, 100);
					cout << " Введите количество квартир : ";
					cin >> kol;
					apar.put(num, kol,adress);
					apar.init();
					break;
				case 2:
					cout << " Введите номер квартиры для изменения : ";
					cin >> num_kv;
					for (int i = 0; i < kol; i++)
					{
						if (apar.dom->num_flat == num_kv)apar.dom[i].init();
					}
					break;
				}
			}
			break;
		case 4:
			if (flag == false)
			{
				cout << " Создайте сначала класс дом \n";
				system("pause");
				break;
			}
			else
			{
				cout << " 1 - поиск по ФИО \n";
				cout << " 2 - поиск по номеру квартиры \n";
				do {
					cin >> x;
					if (x < 1 || x>2)cout << " Ошибка !!! \n";
				} while (x < 1 || x>2);
				switch (x)
				{
				case 1:
					char name[30];
					cin.ignore();
					cout << " Введите фамилию : ";
					gets_s(name, 30);
					for (int i = 0; i < kol; i++)
					{
						if (strcmp(apar.dom[i].soul->person, name) == 0)
							apar.dom[i].show();
					}
					system("pause");
					break;
				case 2:
					int kv;
					cout << " Введите номер квартиры : ";
					cin >> kv;
					for (int i = 0; i < kol; i++)
					{
						if (apar.dom[i].num_flat == kv)
							apar.dom[i].show();
					}
					system("pause");
					break;
				}
				break;
			}
		case 0:
			cout << " До свидания !!! \n";
			break;
		default:
			cout << " Ошибка !!! \n";
			system("pause");
		}

	} while (menu != 0);
	system("pause");
	return 0;
}
