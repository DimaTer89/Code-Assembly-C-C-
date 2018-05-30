/*
Модуль 2. Указатель this и конструктор копирования.

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
		   gets_s(FIO,35);
		   cout << "Введите ПРИМЕЧАНИЕ\n";
		   gets_s(PRIM,35);
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
		   gets_s(TEL,10);
		   CHELS = new CHEL[StudentsAmount];
		   cout << "\nЗаполнение жильцов\n";
		   for(int q = 0; q < StudentsAmount; q++)
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
				   for(int y1 = 0; y1 < b1; y1++)
				    {
					    cout << "заполнение кв " << y1 + 1 << "\n";
					    x.Inpspecializ(y1);
				    }
				   break;
		    }
		   case 2:/*посмотреть обьект ДОМ*/
		    {
				   system("cls");
				   if(y == 0)
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
				   if(y == 0)
				    {
					    cout << "для начала заполните обьект в первом пункте!\n";
					    break;
				    }
				   if(y != 0)
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
				   if(t == 1)
				    {
					    int a1, b1;
					    cout << "Введите номер дома\n";
					    cin >> a1;
					    cout << "количество квартир\n";
					    cin >> b1;
					    x.RED(a1, b1);
					    y++;
					    for(int y1 = 0; y1 < b1; y1++)
					     {
						     cout << "Заполнение квартиры: " << y1 + 1 << "\n";
						     x.Inpspecializ(y1);
					     }
					    break;
				    }
				   if(t == 2)/*редакт кв.*/
				    {
					    int t = 0;
					    cout << "Введите номер квартиры которую хотите редактировать\n";
					    cin >> t;
					    if(x.kolkv < t)
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
				   if(u == 1)
				    {
					    char FAMI[80];
					    int r4 = 0;
					    cout << "Введите фамилию \n";
					    gets_s(FAMI,35);
					    for(int i1 = 0; i1 <x.kolkv; i1++)/*kv*/
					     {
						     for (int i5 = 0; i5 < x.KVS[i1].StudentsAmount; i5++)/*жильцы*/
						      {
							      char FAMI2[80];
							      strcpy(FAMI2, x.KVS[i1].CHELS[i5].FIO);
							      if(strcmp(FAMI, FAMI2) == 0)
							       {
								       cout << "квартира с жильцом с заданной фамилией\n";
								       x.KVS[i1].Show();
								       r4++;
								       break;
							       }
						      }
					     }
					    if(r4 == 0)
						    cout << "такой фамилии нет\n";
					    break;
				    }
				   if(u == 2)
				    {
					    char T[80];
					    int r4 = 0;
					    cout << "Введите номер телефона \n";
					    gets_s(T,10);
					    for(int i1 = 0; i1 <x.kolkv; i1++)/*kv*/
					     {
						     char FAMI2[80];
						     strcpy(FAMI2, x.KVS[i1].TEL);
						     if(strcmp(T, FAMI2) == 0)
						      {
							      cout << "квартира с искомым номером\n";
							      x.KVS[i1].Show();
							      r4++;
							      break;
						      }
					     }
					    if(r4 == 0)
						    cout << "такой фамилии нет\n";
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
