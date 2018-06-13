/*1.Создайте класс Computer. Необходимо хранить следующие данные:
    Тип процессора;
    Оперативная память (тип, объём);
    Жёсткий диск (тип, объём);
    Видеокарта;
    Монитор (тип, размер экрана);
    Производитель;
    Месяц и год выпуска.
    Гарантийный срок.
  2. Создать массив объектов. Ввод данных осуществить через клавиатуру.
  3. Вывести: 
  a) список компьютеров с заданным типом процессора; 
  b) список компьютеров с требуемым объёмом оперативной памяти и объёмом жёсткого диска больше или раной заданной;
  c) подсчитать количество компьютеров с мониторами, размер экрана которых равен 22”.
  4. При необходимости используйте:
     - перегруженные конструкторы;
     - конструктор копирования;
     - константные функции-члены (например, для отображения информации о Типе процессора и т.д.).
  5. Иметь возможность сохранять данные в файл и считывать из него.*/
#include <iostream>
#include <Windows.h>
#define N 64
using namespace std;
class PC
{
	char* proc;
	char* ozu;
	int volume_ozu;
	char* hard;
	int volume_hard;
	char* videokard;
	char* monitor;
	int size_monitor;
	char* proiz;
	char* month_year;
	char* garantia;
public:
	static int mon_kol;
	PC()
	{
		proc = new char('\0');
		ozu = new char('\0');
		volume_ozu = 1;
		hard = new char('\0');
		volume_hard = 1;
		videokard = new char('\0');
		monitor = new char('\0');
		size_monitor = 1;
		proiz = new char('\0');
		month_year = new char('\0');
		garantia = new char('\0');
	}
	void init(char* pro, char* oz, int size_ozu, char* had, int size_hard, char* video, char* mon, int size_mon, char* proz, char* mon_yer, char* garant)
	{
		proc = new char[strlen(pro) + 1];
		strcpy(proc, pro);
		ozu=new char[strlen(oz)+1];
		strcpy(ozu, oz);
		volume_ozu=size_ozu;
		hard=new char[strlen(had)+1];
		strcpy(hard, had);
		volume_hard=size_hard;
		videokard=new char[strlen(video)+1];
		strcpy(videokard, video);
		monitor=new char[strlen(mon)+1];
		strcpy(monitor, mon);
		size_monitor=size_mon;
		proiz=new char[strlen(proz)+1];
		strcpy(proiz, proz);
		month_year=new char[strlen(mon_yer)+1];
		strcpy(month_year, mon_yer);
		garantia=new char[strlen(garant)+1];
		strcpy(garantia, garant);
	}
	/*PC(const PC& ob)
	{
		proc = new char[strlen(ob.proc) + 1];
		strcpy(proc, ob.proc);
		ozu = new char[strlen(ob.ozu) + 1];
		strcpy(ozu, ob.ozu);
		volume_ozu = ob.volume_ozu;
		hard = new char[strlen(ob.hard) + 1];
		strcpy(hard, ob.hard);
		volume_hard = ob.volume_hard;
		videokard = new char[strlen(ob.videokard) + 1];
		strcpy(videokard, ob.videokard);
		monitor = new char[strlen(ob.monitor) + 1];
		strcpy(monitor, ob.monitor);
		size_monitor = ob.size_monitor;
		proiz = new char[strlen(ob.proiz) + 1];
		strcpy(proiz, ob.proiz);
		month_year = new char[strlen(ob.month_year) + 1];
		strcpy(month_year, ob.month_year);
		garantia = new char[strlen(ob.garantia) + 1];
		strcpy(garantia, ob.garantia);
	}*/
	char* CPU()
	{
		return proc;
	}
	~PC()
	{
		if (proc)
			delete proc;
		proc = NULL;
		if (ozu)
			delete ozu;
		ozu = NULL;
		if (hard)
			delete hard;
		hard = NULL;
		if (videokard)
			delete videokard;
		videokard = NULL;
		if (monitor)
			delete monitor;
		monitor = NULL;
		if (proiz)
			delete proiz;
		proiz = NULL;
		if (month_year)
			delete month_year;
		month_year = NULL;
		if (garantia)
			delete garantia;
		garantia = NULL;
	}
	void show();
};
 void PC::show()
 {
	 cout << "====================================\n";
	 cout << " Тип процессора : " << proc << endl;
	 cout << " Оперативная память (тип, объём) : " << ozu << ", " << volume_ozu << endl;
	 cout << " Жёсткий диск(тип, объём) : " << hard << ", " << volume_hard << endl;
	 cout << " Видеокарта : " << videokard << endl;
	 cout << " Монитор(тип, размер экрана) : " << monitor << ", " << size_monitor << endl;
	 cout << " Производитель : " << proiz << endl;
	 cout << " Месяц и год выпуска : " << month_year << endl;
	 cout << " Гарантийный срок : " << garantia << endl;
	 cout << "=====================================\n";
 }
 int PC::mon_kol = 0;
 int main()
 {
	 SetConsoleCP(1251);
	 SetConsoleOutputCP(1251);
	 char CPU[N];
	 char ozu[N];
	 int size_ozu;
	 char hard[N];
	 int size_hard;
	 char video[N];
	 char monitor[N];
	 int size_mon;
	 char maker[N];
	 char month_year[N];
	 char garant[N];
	 int kol;
	 int menu;
	 cout << " Введите количество данных о компьютерах : ";
	 cin >> kol;
	 PC* komp = new PC[kol];
	 for (int i = 0; i < kol; i++)
	 {
		 system("cls");
		 cin.ignore();
		 cout << " Тип процессора : ";
		 gets_s(CPU, N);
		 cout << " Оперативная память (тип) : ";
		 gets_s(ozu, N); 
		 cout << " Оперативная память (объём в мегабайтах) : ";
		 cin >> size_ozu;
		 cin.ignore();
		 cout << " Жёсткий диск(тип) : ";
		 gets_s(hard, N); 
		 cout << " Жёсткий диск(объём в гигабайтах) : ";
		 cin >> size_hard;
		 cin.ignore();
		 cout << " Видеокарта : ";
		 gets_s(video, N);
		 cout << " Монитор(тип) : ";
		 gets_s(monitor, N);
		 cout << " Монитор(размер экрана в дюймах) : ";
		 cin >> size_mon;
		 if (size_mon == 22)PC::mon_kol++;
		 cin.ignore();
		 cout << " Производитель : ";
		 gets_s(maker,N);
		 cout << " Месяц и год выпуска : ";
		 gets_s(month_year,N);
		 cout << " Гарантийный срок : ";
		 gets_s(garant,N);
		 komp[i].init(CPU, ozu, size_ozu, hard, size_hard, video, monitor, size_mon, maker, month_year, garant);
		 cin.ignore();
	 }
	 do
	 {
		 system("cls");
		 cout << " 1 - Список компьютеров с заданным типом процессора \n";
		 cout << " 2 - Список компьютеров с требуемым объёмом оперативной памяти и объёмом жёсткого диска больше или раной заданной\n";
		 cout << " 3 - Подсчитать количество компьютеров с мониторами, размер экрана которых равен 22 \n";
		 cout << " 4 - Показать данные \n";
		 cout << " 5 - Сохранить данные в файл \n";
		 cout << " 6 - Загрузить данные из файла \n";
		 cout << " 7 - выход \n";
		 do
		 {
			 cin >> menu;
			 if (menu < 1 || menu>7)cout << " Ошибка, читайте внимательнее меню \n";
		 } while (menu < 1 || menu>7);
		 switch (menu)
		 {
		 case 1:
			 char name_cpu[N];
			 cout << " Введите искомый тип процессора : ";
			 gets_s(name_cpu, N);
			 for (int i = 0; i < kol; i++)
			 {
				
				 if (strcmp(komp[i].CPU(), name_cpu) == 0)
					 komp[i].show();
			 }
			 system("pause");
			 break;
		 case 2:
			 break;
		 case 3:
			 cout << " Компьютеров с монитором , размер которых равен 22 = " << PC::mon_kol << endl;
			 break;
		 case 4:
			 for (int i = 0; i < kol; i++)
			 {
				 komp[i].show();
			 }
			 system("pause");
			 break;
		 case 5:
			 break;
		 case 6:
			 break;
		 case 7:
			 cout << " До свидания \n";
			 system("pause");
			 break;
		 }
	 } while (menu != 7);
	 delete[]komp;
	 system("pause");
 }
 
