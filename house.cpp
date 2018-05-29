#include <iostream>
#include <Windows.h>
using namespace std;
class Human
{
public:
	struct FIO
	{
		char* fam;
		char* name;
		char* otch;
	}fio;
	Human()
	{
		fio.fam = new char[30];
		fio.name = new char[30];
		fio.otch = new char[30];
	}
	~Human()
	{
		delete[]fio.fam;
		fio.fam = NULL;
		delete[]fio.name;
		fio.name = NULL;
		delete[]fio.otch;
		fio.otch = NULL;
	}
	void init()
	{
		cout << " Фамилия : ";
		cin >> fio.fam;
		cout << " Имя : ";
		cin >> fio.name;
		cout << " Отчество : ";
		cin>> fio.otch;
	}
	void show()
	{
		cout << " Фамилия : " << fio.fam << endl;
		cout << " Имя : " << fio.name << endl;
		cout << " Отчество : " << fio.otch << endl;
	}
};
class Apartament
{
public:
	
	Human* chel;
	int kol_kom;
	int num;
	int stage;
	Apartament(int a,int b,int c)
	{
		chel = new Human;
		kol_kom = a;
		num = b;
		stage = c;
	}
	void show()
	{
		cout << " Фамилия : " << chel->fio.fam << endl;
		cout << " Имя : " << chel->fio.name << endl;
		cout << " Отчество : " << chel->fio.otch << endl;
		cout << " Этаж : " << this->stage << endl;
		cout << " Номер квартиры : " << this->num << endl;
		cout << " Количество комнат : " << this->kol_kom << endl;
	}
};
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol_kom;
	int kol = 0;
	int num;
	int stage;
	Human* ob;
	ob = new Human[1];
	cout << " Введите количество кoмнат в квартире , номер квартиры и этаж через пробел : ";
	cin >> kol_kom >> num >> stage;
	Apartament ob_1(kol_kom, num, stage);
	if (kol)
	{
		Human* tmp = new Human[kol];
		for (int i = 0; i < kol; i++)
		{
			strcpy(tmp[i].fio.fam, ob[i].fio.fam);
			strcpy(tmp[i].fio.name, ob[i].fio.name);
			strcpy(tmp[i].fio.otch, ob[i].fio.otch);
		}
		delete[]tmp;
		ob = new Human[kol];
		for (int i = 0; i < kol; i++)
		{
			strcpy(ob[i].fio.fam, tmp[i].fio.fam);
			strcpy(ob[i].fio.name, tmp[i].fio.name);
			strcpy(ob[i].fio.otch, tmp[i].fio.otch);
		}
		delete[]tmp;
	}
	ob[kol].init();
	kol++;
	ob_1.show();
	system("pause");
}
