/*Создайте класс Student, который будет содержать информацию о студенте.
  С помощью механизма наследования, реализуйте класс Aspirant, производный от  
  Student. Аспирант - это студент, который готовится к защите кандидатской работы.*/
#include <iostream>
#include <Windows.h>
#include <time.h>
#define N 128

using namespace std;

class Student
{
protected:
	char* secName;
	char* name;
	char* otch;
	char* pulpit;
public:
	Student()
	{
		secName = new char('\0');
		name = new char('\0');
		otch = new char('\0');
		pulpit = new char('\0');
	}
	~Student()
	{
		delete[]secName;
		delete[]name;
		delete[]otch;
		delete[]pulpit;
	}
	void get(char* secname, char* name, char* otch, char* kaf);
	void show();
};
void Student::get(char* secname, char* name, char* otch, char* kaf)
{
	secName = new char[strlen(secname) + 1];
	this->name = new char[strlen(name) + 1];
	this->otch = new char[strlen(otch) + 1];
	pulpit = new char[strlen(kaf) + 1];
	strcpy(secName, secname);
	strcpy(this->name, name);
	strcpy(this->otch, otch);
	strcpy(pulpit, kaf);
}
void Student::show()
{
	cout << " Фамилия : " << secName << endl;
	cout << " Имя : " << name << endl;
	cout << " Отчество : " << otch << endl;
	cout << " Кафедра : " << pulpit << endl;
}
class Aspirant:public Student
{
	bool exam1;
	bool exam2;
	bool exam3;
public:
	Aspirant()
	{
		exam1 = false;
		exam2 = false;
		exam3 = false;
	}
	bool getExam1()
	{
		return exam1;
	}
	bool getExam2()
	{
		return exam2;
	}
	bool getExam3()
	{
		return exam3;
	}
	void exam();
};
void Aspirant::exam()
{
	exam1 = rand() % 2;
	exam2 = rand() % 2;
	exam3 = rand() % 2;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(0));
	int count;
	int menu;
	bool flag = false;
	bool aspir;
	char secname[N];
	char name[N];
	char otch[N];
	char kaf[N];
	Aspirant* stud;
	system("cls");
	do
	{
		system("cls");
		cout << " 1 - Заполнить группу студентов \n";
		cout << " 2 - Вывести группу на экран \n";
		cout << " 3 - Вывести аспирантов на экран \n";
		cout << " 0 - Выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			if (flag == true)
			{
				cout << " Группа заполнена \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Введите количество студентов : ";
				cin >> count;
				cin.ignore();
				stud = new Aspirant[count];
				for (int i = 0; i < count; i++)
				{
					system("cls");
					cout << " Студент № " << i + 1 << endl;
					cout << " Введите фамилию : ";
					gets_s(secname, N);
					cout << " Введите имя : ";
					gets_s(name, N);
					cout << " Введите отчество : ";
					gets_s(otch, N);
					cout << " Введите кафедру : ";
					gets_s(kaf, N);
					stud[i].get(secname, name, otch, kaf);
				}
				flag = true;
				break;
			}
		case 2:
			system("cls");
			if (flag == false)
			{
				cout << " Группа не сформирована \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Группа студентов \n";
				for (int i = 0; i < count; i++)
				{
					cout << "============\n";
					stud[i].show();
					cout << "============\n";
				}
				system("pause");
				break;
			}
		case 3:
			system("cls");
			if (flag == false)
			{
				cout << " Группа не сформирована, не кому становиться аспирантами \n";
				system("pause");
				break;
			}
			else
			{
				aspir = false;
				for (int i = 0; i < count; i++)
				{
					stud[i].exam();
				}
				cout << " Поздравляем следующих студентов со сдачей экзамена и переводом в аспиранты \n";
				for (int i = 0; i < count; i++)
				{
					if (stud[i].getExam1() && stud[i].getExam2() && stud[i].getExam3())
					{
						cout << "==========\n";
						stud[i].show();
						cout << "==========\n";
						aspir = true;
					}
				}
				if (!aspir)
				{
					cout << " Увы, поздравлять не кого \n";
				}
				system("pause");
				break;
			}
		case 0:
			cout << " До свидания \n";
			break;
		default:
			cout << " Ошибка неверно выбрано меню \n";
		}
	} while (menu != 0);
	system("pause");
}
