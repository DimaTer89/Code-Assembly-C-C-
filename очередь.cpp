#include<iostream>
#include <Windows.h>
using namespace std;
struct client
{
	char name[50];
	int prior;
	char time[10];
	client* next,*prev;
};
struct statistic
{
	int prior;
	char timeS[50];
	statistic* next;
};
	
class printer
{
	statistic* headS, *tailS;
	client* head,*tail;
public:
	printer()
	{
		head = tail = NULL;
		headS = tailS = NULL;
	}
	~printer()
	{
		clearQueque();
	}
	void push(char* str, int prior,char* time);
	void show();
	void pushS(int prior,char* time);
	void showStat();
	void clearQueque();
};
void printer::clearQueque()
{
	client *Next;
	statistic* next;
	while (head) {
		Next = head->next;
		delete head;
		head = Next;
	}
	while (headS)
	{
		next = headS->next;
		delete headS;
		headS = next;
	}
}
void printer::pushS(int prior, char* time)
{
	statistic* tmp = new statistic;
	tmp->prior = prior;
	strcpy(tmp->timeS, time);
	tmp->next = NULL;
	if (headS == NULL)
	{
		headS = tmp;
		tailS = tmp;
	}
	else
	{
		tailS->next = tmp;
		tailS = tmp;
	}
}
void printer::push(char* str,int prior,char* time)
{
	client* new_cell = new client;
	strcpy(new_cell->name, str);
	new_cell->prior = prior;
	strcpy(new_cell->time, time);
	new_cell->next = NULL;
	new_cell->prev = NULL;
	if (head == NULL)
	{
		head = tail = new_cell;
	}
	if (head!=NULL&&head->prior > new_cell->prior)
	{
		new_cell->next = head;
		head->prev = new_cell;
		new_cell->prev = NULL;
		new_cell = head;
		
	}
	if (head!=NULL&& tail->prior <= new_cell->prior)
	{
		new_cell->next = NULL;
		new_cell->prev = tail;
		tail->next = new_cell;
		tail = new_cell;
		
		
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
		
	}
}

void printer::show()
{
	client* tmp = head;
	while (tmp!=NULL)
	{
		cout << " Должность : " << tmp->name << endl;
		tmp = tmp->next;
		cout << endl;
	}
}
void printer::showStat()
{
	statistic* st = headS;
	client* tmp = head;
	while (tmp)
	{
		if (tmp->prior == 1)
		{
			cout << " Должность : " << tmp->name << endl;
			break;
		}
		tmp = tmp->next;
	}
	cout << " Время печати : ";
	while (st)
	{
		if (st->prior == 1)
			cout << st->timeS << " ";
		st = st->next;
	}
	cout << endl;
	st = headS;
	tmp = head;
	while (tmp)
	{
		if (tmp->prior == 2)
		{
			cout << " Должность : " << tmp->name << endl;
			break;
		}
		tmp = tmp->next;
	}
	cout << " Время печати : ";
	while (st)
	{
		if (st->prior == 2)
			cout << st->timeS << " ";
		st = st->next;
	}
	cout << endl;
	st = headS;
	tmp = head;
	while (tmp)
	{
		if (tmp->prior == 3)
		{
			cout << " Должность : " << tmp->name << endl;
			break;
		}
		tmp = tmp->next;
	}
	cout << " Время печати : ";
	while (st)
	{
		if (st->prior == 3)
			cout << st->timeS << " ";
		st = st->next;
	}
	cout << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char name[50];
	char time[10];
	int prior;
	int menu;
	printer ob;
	do
	{
		system("cls");
		cout << " 1 - Добавить клиента \n";
		cout << " 2 - Показать очередь клиентов \n";
		cout << " 3 - Статистика печати \n";
		cout << " 0 - Выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		cin.ignore();
		switch (menu)
		{
		case 1:
			cout << " Введите должность клиента ( директор, менеджер, охранник) : ";
			gets_s(name, 50);
			if (strcmp(name, "директор") == 0)
				prior = 1;
			if (strcmp(name, "менеджер") == 0)
				prior = 2;
			if (strcmp(name, "охранник") == 0)
				prior = 3;
			cout << " Введите время (формат - чч:мм) : ";
			gets_s(time, 10);
			ob.push(name, prior,time);
			ob.pushS(prior, time);
			break;
		case 2:
			system("cls");
			cout << " Все клиенты  \n";
			ob.show();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << " Статистика печати \n";
			ob.showStat();
			system("pause");
			break;
		case 0:
			cout << " До свидания ! \n";
			break;
		}

	} while (menu != 0);
	system("pause");
	return 1;
}
