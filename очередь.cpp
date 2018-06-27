/*Разработать приложение, имитирующее очередь печати принтера.
Должны быть клиенты, посылающие запросы на принтер, у каждого из которых есть свой приоритет.
Каждый новый клиент попадает в очередь в зависимости от своего приоритета. Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди.
Предусмотреть вывод статистики на экран.*/
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
struct client
{
	char position[128];
	int time;
	int prior;
	client* next, *prev;
};
class printer
{
	client* head;
	client* tail;
public:
	
	printer()
	{
		head = NULL;
		tail = NULL;
	}
	printer(const printer& ob)
	{

	}
	void addQueque(char* s,int prior,int time,client*& head,client*& tail);
	void showQueque();
	int insert(char* s, int prior,int time);
};
void printer::addQueque(char* s,int prior,int time,client*& head,client*& tail)
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
		tail = tmp;
		head = tmp;
	}
}
int printer::insert(char* s, int prior,int time)
{
	client* elem = new client;
	strcpy(elem->position, s);
	elem->prior = prior;
	elem->time = time;
	if (head == NULL)
	{
		addQueque(elem->position, elem->prior,elem->time, head, tail);
		return 1;
	}
	if (head->prior < elem->prior)
	{
		addQueque(elem->position, elem->prior,elem->time, head, tail);
		return 1;
	}
	if(tail->prior==elem->prior)
	{
		addQueque(elem->position, elem->prior,elem->time, head, tail);
		return 1;
	}
	if (head!=NULL&&head->prior == elem->prior)
	{
		client* tmp = head;
		while (tmp)
		{
			if (tmp->prior == elem->prior)
				tmp = tmp->next;
			else
				break;
		}
		elem->next = tmp;
		tmp = tmp->prev;
		tmp->next = elem;
		elem->prev = tmp;
		elem->next->prev = elem;
		return 1;
	}
	if (head != NULL&&tail->prior>elem->prior)
	{
		client* tmp = head;
		while (tmp)
		{
			if (tmp->prior < elem->prior&&tmp->prior>elem->prior)
				tmp = tmp->next;
			else
				break;
		}
		elem->next = tmp;
		tmp = tmp->prev;
		tmp->next = elem;
		elem->prev = tmp;
		elem->next->prev = elem;
		return 1;
	}
	
}
void printer::showQueque()
{
	client* tmp = head;
	while (tmp)
	{
		cout << " Должность : " << tmp->position << endl;
		cout << " Приоритет : " << tmp->prior << endl;
		cout << " Время : " << tmp->time << endl;
		tmp = tmp->next;
		cout << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(0));
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
			if (strcmp(name, "директор") == 0)
				prior = 1;
			if (strcmp(name, "менеджер") == 0)
				prior = 2;
			if (strcmp(name, "охранник") == 0)
				prior = 3;
			cout << " Введите время : ";
			cin >> time;
			ob.insert(name, prior,time);
			break;
		case 2:
			system("cls");
			cout << " Все клиенты  \n";
			ob.showQueque();
			system("pause");
			break;
		case 3:
			
		case 0:
			cout << " До свидания ! \n";
			break;
		}

	} while (menu != 0);
	system("pause");
}
