#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <list>


using namespace std;

struct emp
{
	int num;              // номер зачётки
	char fam[30];         // фамилия студента
	char first_name[30];  // имя студента 
	char second_name[30]; // отчество студента
	double grade;  	      // средний бал 
	emp* next;
};

class Parent
{
	emp* head, *tail;
public:
	Parent()
	{
		head = tail = NULL;
	}
	~Parent()
	{
		deleteList();
	}
	void addList();
	void deleteList();
	void showList();
};
void Parent::addList()
{
	int num_1;              // номер зачётки
	char fam_1[30];         // фамилия студента
	char first_name_1[30];  // имя студента 
	char second_name_1[30]; // отчество студента
	double grade_1;
	cout << " Введите номер зачётки : ";
	cin >> num_1;
	cout << " Введите фамилию студента : ";
	cin >> fam_1;
	cout << " Введите имя студента : ";
	cin >> first_name_1;
	cout << " Введите отчество студента : ";
	cin >> second_name_1;
	cout << " Введите средний балл : ";
	cin >> grade_1;
	emp* elem = new emp;
	elem->num = num_1;
	strcpy(elem->fam, fam_1);
	strcpy(elem->first_name, first_name_1);
	strcpy(elem->second_name, second_name_1);
	elem->grade = grade_1;
	if (head != NULL)
	{
		tail->next = elem;
		tail = elem;
	}
	else
	{
		head = tail = elem;
	}
}
void Parent::deleteList()
{
	emp* tmp = NULL;
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	tmp = NULL;
	delete tmp;
}
void Parent::showList()
{
	while (head)
	{
		cout << " Номер зачётки : " << head->num << endl;
		cout << " Фамилия студента : " << head->fam << endl;
		cout << " Имя студента : " << head->first_name << endl;
		cout << " Отчество студента : " << head->second_name << endl;
		cout << " Средний балл : " << head->grade << endl;
		head=head->next;
	}
	cout << endl;
}

int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Parent ob;
	char key = 'y';
	while (key == 'y')
	{
		ob.addList();
		cout << " Добавить студента : y/n ";
		cin >> key;
		if (key != 'y')
			break;
	}
	cout << " Список студентов \n";
	ob.showList();
	system("pause");
	return 0;
}
