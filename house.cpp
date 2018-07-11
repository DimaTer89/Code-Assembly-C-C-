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
=======================================================
	/*
Модуль 2. Указатель this и конструктор копирования.
убрать пропуск при поиске фамилии и телефона , откорретировать поиск по фамилии с точными данными по конкретной фамилии а не по квартире
Домашнее задание №1.

Задание.
Создайте программу, имитирующую многоквартирный дом.
Необходимо иметь классы “Человек”, “Квартира”, “Дом”. Класс “Квартира” содержит
динамический массив объектов класса “Человек”. Класс “Дом” содержит массив объектов класса “Квартира”.
Каждый из классов содержит переменные-члены и функции-члены,
которые необходимы для предметной области класса. Обращаем ваше внимание,
что память под строковые значения выделяется динамически. Например, для ФИО в классе “Человек”.
Не забывайте обеспечить классы различными конструкторами (конструктор копирования обязателен),
деструкторами. В main() протестировать работу полученного набора классов.
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

class CHEL
{
public:
	char* FIO;
	char* PRIM;
	CHEL()/*конструктор*/
	{
		FIO = new char[100];
		PRIM = new char[100];
	}
	~CHEL()/*деструктор*/
	{
		delete[] FIO;
		FIO = NULL;
		delete[] PRIM;
		PRIM = NULL;
	}
	CHEL(const CHEL& obj)/*конструктор копирования*/
	{
		FIO = obj.FIO;
		PRIM = obj.PRIM;
	}
	void Show()/*показать*/
	{
		cout << "ФИО                " << FIO << endl;
		cout << "ПРИМЕЧАНИЕ         " << PRIM << endl;
	}
	void Inpspecializ()/*заполнение и редактирование*/
	{
		delete[] FIO;
		FIO = NULL;
		delete[] PRIM;
		PRIM = NULL;
		FIO = new char[100];
		PRIM = new char[100];
		cout << "Введите ФИО \n";
		gets_s(FIO, 35);
		cout << "Введите ПРИМЕЧАНИЕ\n";
		gets_s(PRIM, 35);
	}
};

class KV
{
public:
	char* TEL;         /*телефон*/
	CHEL* CHELS;
	int StudentsAmount;/*количество жильцов*/
	int num;           /*номер квартиры*/
	KV()               /*констуктор*/
	{
		num = 0;
		TEL = new char[100];
		StudentsAmount = 5;
	}
	KV(const KV& obj)/*конструктор копирования*/
	{
		TEL = obj.TEL;
	}
	~KV()/*деструктор*/
	{
		delete[] CHELS;
		CHELS = NULL;
		delete[] TEL;
		TEL = NULL;
	}
	void Show()/*показать*/
	{
		cout << "номер квартиры     " << num << endl;
		cout << "количество жильцов " << StudentsAmount << endl;
		cout << "телефон            " << TEL << endl;
		for (int i = 0; i < StudentsAmount; i++)
			CHELS[i].Show();
	}
	void Inpspecializ(int i)
	{
		delete[] TEL;
		TEL = NULL;
		TEL = new char[100];
		i++;
		num = i;
		cout << "номер квартиры\n";
		cout << num << "\n";
		cout << "Введите количество жильцов\n";
		cin >> StudentsAmount;
		cin.ignore();
		cout << "Введите телефон\n";
		gets_s(TEL, 10);
		CHELS = new CHEL[StudentsAmount];
		cout << "\nЗаполнение жильцов\n";
		for (int q = 0; q < StudentsAmount; q++)
			CHELS[q].Inpspecializ();/*заполнить класс жильцы*/
		cout << "запись о квартире заполнена!\n";
	}
};

class DOM
{
public:
	int NUMDOM;
	KV* KVS;
	int kolkv;/*кол кв*/
	DOM(int a, int b)
	{
		NUMDOM = a;
		kolkv = b;
		KVS = new KV[kolkv];
	}
	void RED(int a, int b)
	{
		NUMDOM = a;
		kolkv = b;
		KVS = new KV[kolkv];
		cout << "\nСоздана запись о Доме номер " << NUMDOM << "\n";
		cout << " на " << kolkv << " квартир(ы)\n" << endl;
	}
	~DOM()/*деструктор*/
	{
		delete[]KVS;
		KVS = NULL;
	}
	void Show()/*показать*/
	{
		cout << "\n Дом номер " << NUMDOM << "\n";
		for (int i = 0; i < kolkv; i++)
		{
			KVS[i].Show();
			cout << "\n";
		}
	}
	void Inpspecializ(int i)/*заполнить или редактировать*/
	{
		system("cls");
		KVS[i].Inpspecializ(i);/*заполнить класс жильцы*/
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");

	DOM x(0, 0);
	int y = 0;
	cout << "\t\t\tМодуль 2,домашнее задание\n";
	cout << "\t\t\tДОМ\n\n";
	int a = 1;
	while (a == 1)
	{
		int b = 0;
		cout << "1 - Создать и заполнить обьект ДОМ\n";
		cout << "2 - Посмотреть запись ДОМ\n";
		cout << "3 - Редактировать запись ДОМ\n";
		cout << "4 - Поиск\n";
		cout << "5 - Выход \n";
		cin >> b;
		while (b<1 || b>5)
		{
			cout << "БУДЬТЕ ВНИМАТЕЛЬНЫ!!!\n";
			cout << "1 - Создать и заполнить обьект ДОМ\n";
			cout << "2 - Посмотреть запись ДОМ\n";
			cout << "3 - Редактировать запись ДОМ\n";
			cout << "4 - Поиск\n";
			cout << "5 - Выход \n";
			cin >> b;
		}
		switch (b)
		{
		case 1:/*создать обьект ДОМ*/
		{
			system("cls");
			int a1, b1;
			cout << "Введите номер дома\n";
			cin >> a1;
			cout << "количество квартир\n";
			cin >> b1;
			x.RED(a1, b1);
			y++;
			for (int y1 = 0; y1 < b1; y1++)
			{
				cout << "заполнение кв " << y1 + 1 << "\n";
				x.Inpspecializ(y1);
			}
			break;
		}
		case 2:/*посмотреть обьект ДОМ*/
		{
			system("cls");
			if (y == 0)
			{
				cout << "для начала заполните обьект в первом пункте!\n";
				break;
			}
			if (y != 0)
				x.Show();
			break;
		}
		case 3:/*редактировать обьект ДОМ*/
		{
			if (y == 0)
			{
				cout << "для начала заполните обьект в первом пункте!\n";
				break;
			}
			if (y != 0)
				system("cls");
			int t = 0;
			cout << "РЕДАКТИРОВАНИЕ\n";
			cout << "1-редактировать полностью\n";
			cout << "2-редактировать отдельную квартиру\n";
			cin >> t;
			while (t<1 || t>2)
			{
				cout << "РЕДАКТИРОВАНИЕ\n";
				cout << "1-редактировать полностью\n";
				cout << "2-редактировать отдельную квартиру\n";
				cin >> t;
			}
			if (t == 1)
			{
				int a1, b1;
				cout << "Введите номер дома\n";
				cin >> a1;
				cout << "количество квартир\n";
				cin >> b1;
				x.RED(a1, b1);
				y++;
				for (int y1 = 0; y1 < b1; y1++)
				{
					cout << "Заполнение квартиры: " << y1 + 1 << "\n";
					x.Inpspecializ(y1);
				}
				break;
			}
			if (t == 2)/*редакт кв.*/
			{
				int t = 0;
				cout << "Введите номер квартиры которую хотите редактировать\n";
				cin >> t;
				if (x.kolkv < t)
				{
					cout << "такой квартиры нет!\n";
					break;
				}
				t--;/*отсчет с нуля */
				x.KVS[t].Inpspecializ(t);
				x.Show();
				break;
			}
			break;
		}
		case 4:/*поиск*/
		{
			int u = 0;
			cout << "1 поиск по фамилии\n";
			cout << "2 поиск по номеру телефона\n";
			cin >> u;
			while (u<1 || u>2)
			{
				cout << "1 поиск по фамилии\n";
				cout << "2 поиск по номеру телефона\n";
				cin >> u;
			}
			if (u == 1)
			{
				cin.ignore();
				char FAMI[80];
				int r4 = 0;
				cout << "Введите фамилию \n";
				gets_s(FAMI, 35);
				for (int i1 = 0; i1 <x.kolkv; i1++)/*kv*/
				{
					for (int i5 = 0; i5 < x.KVS[i1].StudentsAmount; i5++)/*жильцы*/
					{
						char FAMI2[80];
						strcpy(FAMI2, x.KVS[i1].CHELS[i5].FIO);
						if (strcmp(FAMI, FAMI2) == 0)
						{
							cout << "квартира с жильцом с заданной фамилией\n";
							cout << "номер квартиры: "<< x.KVS[i1].num << endl;
							cout << "номер телефона: "<< x.KVS[i1].TEL << endl;
							r4++;
							break;
						}
					}
				}
				if (r4 == 0)
					cout << "такой фамилии нет\n";
				break;
			}
			if (u == 2)
			{
				cin.ignore();
				char T[80];
				int r4 = 0;
				cout << "Введите номер телефона \n";
				gets_s(T, 10);
				for (int i1 = 0; i1 <x.kolkv; i1++)/*kv*/
				{
					char FAMI2[80];
					strcpy(FAMI2, x.KVS[i1].TEL);
					if (strcmp(T, FAMI2) == 0)
					{
						cout << "квартира с искомым номером\n";
						cout << "номер квартиры: " << x.KVS[i1].num << endl;
						r4++;
						break;
					}
				}
				if (r4 == 0)
					cout << "такого номера телефона нет\n";
				break;
			}
			break;
		}
		case 5:/*выход*/
		{
			exit(0);
		}
		}
		cout << "1-далее,2-выход\n";
		cin >> a;
		system("cls");
	}
	cout << "\nДОСВИДАНИЯ\n";
	return 0;
}
===================================================================
