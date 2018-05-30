#include <iostream>
#include <windows.h>
#define N 128
using namespace std;
static int num_jil = 0;
class Human
{
public:
	struct man
	{
		char* person;
		char* profess;
	}body;
	Human()
	{
		body.person = new char[N];
		body.profess = new char[N];
	}
	Human(const Human& ob)
	{
		body.person = ob.body.person;
		body.profess = ob.body.profess;
	}
	~Human()
	{
		delete[]body.person;
		body.person = NULL;
		delete[]body.profess;
		body.profess = NULL;
	}
	void init()
	{
		delete[]body.person;
		body.person = NULL;
		delete[]body.profess;
		body.profess = NULL;
		body.person = new char[N];
		body.profess = new char[N];
		while (cin.get() != '\n');
		cout << " Введите ФИО : ";
		cin.getline(body.person,N);
		cout << " Введите профессию : ";
		cin.getline(body.profess,N);
	}
	void show()
	{
		cout << " ФИО : " << body.person << endl;
		cout << " Профессия : " << body.profess << endl;
	}
};
class Flat
{
public:
	Human* soul;
	int kol_kom;
	int stage;
	int num_kv;
	int kol_jil;
	Flat()
	{
		
		kol_kom=0;
		stage=0;
		kol_jil=0;
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
		int i;
		cout << " Введите количество комнат : ";
		cin>>kol_kom;
		cout << " Введите этаж : ";
		cin >> stage;
		while (cin.get() != '\n');
		
		soul = new Human[kol_jil];
		for (i = 0; i < kol_jil; i++)
		{
		    cout << " Квартирант № " << i + 1 << endl;
			soul[i].init();
		}
	}
	void show()
	{
			cout << " Количество комнат : " << kol_kom << endl;
			cout << " Номер квартиры : " << num_kv << endl;
			cout << " Этаж : " << stage << endl;
			for (int i = 0; i < kol_jil; i++)
			{
				soul[i].show();
			}
		
	}

};
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol_jil;
	int kol;
	Flat* ob_1;
	cout << " Введите количество жильцов : ";
	cin >> kol_jil;
	ob_1 = new Flat[kol_jil];
	ob_1->init();
	ob_1->show();
	system("pause");
}
