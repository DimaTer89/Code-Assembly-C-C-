/*Разработать приложение, имитирующее очередь печати принтера.
Должны быть клиенты, посылающие запросы на принтер, у каждого из которых есть свой приоритет. 
Каждый новый клиент попадает в очередь в зависимости от своего приоритета. Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди.
Предусмотреть вывод статистики на экран.*/
#include <iostream>
#include <Windows.h>
using namespace std;
struct client
{
	char position[128];
	int prior;
	int time;
	client* next,*prev;
 };
class printer
{
	client* head;
	client* tail;
	client* headStat;
	client* tailStat;
public:
	printer()
	{
		head = NULL;
		tail = NULL;
		headStat = NULL;
		tailStat = NULL;
	}
	printer(const printer& ob)
	{

	}
	void addQueque(char* s, int prior, int time);
	void stat(char* s, int prior, int time);
	void showQueque();
	void showStat();
};
void printer::addQueque(char* s, int prior, int time)
{
	client* tmp = new client;
	strcpy(tmp->position, s);
	tmp->prior = prior;
	tmp->time = time;
	tmp->next = NULL;
	if (head != NULL)
	{
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		tmp->prev = NULL;
		head = tmp;
		tail = tmp;
	}
}

void printer::showQueque()
{
	client* tmp = head;
	while (tmp)
	{
		cout << " Должность : "<<tmp->position << endl;
		cout << " Приоритет : " << tmp->prior << endl;
		cout << " Время печати(мин) : " << tmp->time << endl;
		tmp = tmp->next;
		cout << endl;
	}
}
void printer::stat(char* s, int prior, int time)
{
	client* tmp = new client;
	client* temp = headStat;
	bool flag = false;
	while (temp)
	{
		if (strcmp(temp->position, s) == 0)
		{
			flag = true;
			temp->time += time;
			break;
		}
		temp = temp->next;
	}
	if (flag == false)
	{
		strcpy(tmp->position, s);
		tmp->prior = prior;
		tmp->time = time;
		tmp->next = NULL;
		if (headStat != NULL)
		{
			tmp->prev = tailStat;
			tailStat->next = tmp;
			tailStat = tmp;
		}
		else
		{
			tmp->prev = NULL;
			headStat = tmp;
			tailStat = tmp;
		}
	}
}
void printer::showStat()
{
	client* tmp = headStat;
	while (tmp)
	{
		cout << " Должность : " << tmp->position << endl;
		cout << " Время печати(мин) : " << tmp->time << endl;
		tmp = tmp->next;
		cout << endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu = 0;
	char name[128];
	int prior;
	int time;
	printer ob;
	do
	{
		system("cls");
		cout << " 1 - Добавить клиента \n";
		cout << " 2 - Показать всех клиентов \n";
		cout << " 3 - Статистика печати \n";
		cout << " 0 - Выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		cin.ignore();
		switch (menu)
		{
		case 1:
			cout << " Введите должность клиента ( директор, менеджер, охраник) : ";
			gets_s(name, 128);
			cout << " Введите приоритет ( 1,2,3) :";
			cin >> prior;
			cout << " Введите время печати ( в минутах ) : ";
			cin >> time;
			ob.addQueque(name, prior, time);
			ob.stat(name, prior, time);
			break;
		case 2:
			system("cls");
			cout << " Все клиенты  \n";
			ob.showQueque();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << " Статистика \n";
			ob.showStat();
			system("pause");
			break;
		case 0:
			cout << " До свидания ! \n";
			break;
		}

	} while (menu != 0);
	system("pause");
}
========================================
	while (tmp)
			{
				if (tmp->prior < prior)
					tmp = tmp->next;
				else
					break;
			}
		elem->next = tmp->next;
		tmp->next = elem;
		tmp->next->prev = elem;
		elem->prev = tmp;
=====================================
	#include<iostream>
#include <Windows.h>
using namespace std;
struct client
{
	char name[50];
	int prior;
	int time;
	client* next,*prev;
};

class printer
{
	client* head,*tail;
public:
	printer()
	{
		head = tail = NULL;
	}
	printer(const printer& ob)
	{

	}
	
	int push(char* str, int prior, int time);
	
	void show();
};
int printer::push(char* str,int prior,int time)
{
	client* new_cell = new client;
	strcpy(new_cell->name, str);
	new_cell->prior = prior;
	new_cell->time = time;
	if (head == NULL)
	{
		new_cell->next = NULL;
		new_cell->prev = NULL;
		head = tail = new_cell;
		return 1;
	}
	if (head!=NULL&&head->prior > new_cell->prior)
	{
		new_cell->next = head;
		head->prev = new_cell;
		new_cell->prev = NULL;
		new_cell = head;
		return 1;
	}
	if (head!=NULL&& tail->prior <= new_cell->prior)
	{
		new_cell->next = NULL;
		new_cell->prev = tail;
		tail->next = new_cell;
		tail = new_cell;
		
		return 1;
	}
	if (tail->prior > new_cell->prior)
	{
		client* after_me = tail;
		while (after_me!=head&&after_me->prior > new_cell->prior)
		{
			after_me = after_me->prev;
		}
		new_cell->next = after_me->next;
		after_me->next = new_cell;
	    after_me->next->prev = new_cell;
		new_cell->prev = after_me;
		return 1;
	}
}

void printer::show()
{
	client* tmp = head;
	while (tmp)
	{
		cout << " Должность : " << tmp->name << endl;
		cout << " Время : " << tmp->time << endl;
		tmp = tmp->next;
		cout << endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char name[50];
	int time;
	int prior;
	int menu;
	printer ob;
	do
	{
		system("cls");
		cout << " 1 - Добавить клиента \n";
		cout << " 2 - Показать всех клиентов \n";
		cout << " 3 - Статистика печати \n";
		cout << " 0 - Выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		cin.ignore();
		switch (menu)
		{
		case 1:
			cout << " Введите должность клиента ( директор, менеджер, охраник) : ";
			gets_s(name, 128);
			if (strcmp(name, "директор") == 0)
				prior = 1;
			if (strcmp(name, "менеджер") == 0)
				prior = 2;
			if (strcmp(name, "охранник") == 0)
				prior = 3;
			cout << " Введите время : ";
			cin >> time;
			ob.push(name, prior, time);
			break;
		case 2:
			system("cls");
			cout << " Все клиенты  \n";
			ob.show();
			system("pause");
			break;
		case 3:

		case 0:
			cout << " До свидания ! \n";
			break;
		}

	} while (menu != 0);
	system("pause");
	return 1;
}

