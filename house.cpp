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
		gets_s(person,35);
		cout << " Введите профессию : ";
		gets_s(profess,35);
	}
	void show()
	{
		cout << " ФИО : " <<person << endl;
		cout << " Профессия : " <<profess << endl;
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
	Flat()
	{
		kol_jil = kol_kom = stage = num_flat = 0;
	}
	Flat(const Flat& ob)
	{
		soul = ob.soul;
	}
	~Flat()
	{
		delete[]soul;
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
		cout << " Введите количество жильцов : ";
		cin >> kol_jil;
		cin.ignore();
		soul = new Human[kol_jil];
		for ( k= 0; k < kol_jil; k++)
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
	int kol_kv;
	int num;
	House()
	{
		num = kol_kv = 0; 
		dom = new Flat;
	}
	~House()
	{
		delete[]dom;
		dom = NULL;
	}
	void put(int a, int b)
	{
		num = a;
		kol_kv = b;
		dom = new Flat[kol_kv];
	}
	void init()
	{
		system("cls");
		for (int i = 0; i < kol_kv; i++)
		{
			system("cls");
			cout << " Квартира " << i + 1 << endl;
			dom[i].init();
		}
	}
	void show()
	{
		cout << " =====================================\n";
		for (int i = 0; i < kol_kv; i++)
		{
			dom[i].show();
			cout << "\n\n";
		}
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
				cout << " Введите количество квартир : ";
				cin >> kol;
				apar.put(num, kol);
				apar.init();
				flag = true;
				break;
			}
			else
			{
				cout << " Дом уже заполнен , если вас что то не устраивает , выберите пунк № 3 \n";
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
			cout << " 1 - создать новый дом \n";
			cout << " 2 - изменить квартиру \n";
			cout << " 3 - добавить квартиру \n";
			cout << " 4 - удалить квартиру \n";
			do
			{
				cin >> carte;
				if (carte < 1 || carte>4)cout << " Ошибка!!! \n";
			} while (carte < 1 || carte>4);
			switch (carte)
			{
			case 1:
				if (flag == false)
				{
					cout << " Создайте сначала класс дом \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Введите номер дома : ";
					cin >> num;
					cout << " Введите количество квартир : ";
					cin >> kol;
					apar.put(num, kol);
					apar.init();
					flag = true;
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
					cout << " Введите номер квартиры для изменения : ";
					cin >> num_kv;
					for (int i = 0; i < kol; i++)
					{
						if (apar.dom->num_flat == num_kv)apar.dom[i].init();
					}
					break;
				}
				
			case 3:
				int i;
				Flat* tmp = new Flat[kol];
					for (i = 0; i<kol; i++)
					{
						strcpy(tmp[i].soul->person, apar.dom[i].soul->person);
						strcpy(tmp[i].soul->profess, apar.dom[i].soul->profess);
						tmp[i].num_flat = apar.dom[i].num_flat;
						tmp[i].kol_kom = apar.dom[i].kol_kom;
						tmp[i].kol_jil = apar.dom[i].kol_jil;
					}
					delete[] apar.dom;
					apar.dom = new Flat[kol + 1];
					for (i = 0; i < kol; i++)
					{
						strcpy(apar.dom[i].soul->person,tmp[i].soul->person);
						strcpy(apar.dom[i].soul->profess,tmp[i].soul->profess);
						apar.dom[i].num_flat = tmp[i].num_flat;
						apar.dom[i].kol_kom = tmp[i].kol_kom;
						apar.dom[i].kol_jil = tmp[i].kol_jil;
					}
					delete[]tmp;
					apar.dom[kol].init();
					kol++;
				break;
			}
			break;
		case 4:
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
