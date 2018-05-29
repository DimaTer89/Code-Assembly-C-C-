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
		cin >> this->fio.fam;
		cout << " Имя : ";
		cin >> this->fio.name;
		cout << " Отчество : ";
		cin >> this->fio.otch;
	}
	void show()
	{
		cout << " Фамилия : " << fio.fam << endl;
		cout << " Имя : " << fio.name << endl;
		cout << " Отчество : " << fio.otch << endl;
	}
	Human* dob_hum(Human* ob, int &kol)
	{
		
		Human* tmp = new Human[kol];
		for (int i = 0; i < kol; i++)
		{
		strcpy(tmp[i].fio.fam, ob[i].fio.fam);
		strcpy(tmp[i].fio.name, ob[i].fio.name);
		strcpy(tmp[i].fio.otch, ob[i].fio.otch);
		}
		delete[]ob;
		ob = new Human[kol+1];
		for (int i = 0; i < kol; i++)
		{
		strcpy(ob[i].fio.fam, tmp[i].fio.fam);
		strcpy(ob[i].fio.name, tmp[i].fio.name);
		strcpy(ob[i].fio.otch, tmp[i].fio.otch);
		}
		delete[]tmp;
		ob[kol].init();
		kol++;
		return ob;
	}
};
class Apartament
{
public:

	Human* chel;
	int kol_kom;
	int num;
	int stage;
	Apartament(Human* ob,int a, int b, int c,int kol)
	{
		chel = new Human[kol];
		for (int i = 0; i < kol; i++)
		{
			strcpy(this->chel[i].fio.fam, ob[i].fio.fam);
			strcpy(this->chel[i].fio.name, ob[i].fio.name);
			strcpy(this->chel[i].fio.otch, ob[i].fio.otch);
		}
		kol_kom = a;
		num = b;
		stage = c;
	}
	void show()
	{
		cout << " Фамилия : " << this->chel->fio.fam << endl;
		cout << " Имя : " << this->chel->fio.name << endl;
		cout << " Отчество : " << this->chel->fio.otch << endl;
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
	ob->init();
	cout << " Введите количество кoмнат в квартире , номер квартиры и этаж через пробел : ";
	cin >> kol_kom >> num >> stage;
	kol++;
	Apartament ob_1(ob,kol_kom, num, stage,kol);
	kol++;
	ob_1.show();
	system("pause");
}
