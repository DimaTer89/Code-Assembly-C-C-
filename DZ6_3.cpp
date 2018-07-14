/*Задача носит имя Иосифа Флавия - известного историка I века. Существует легенда, что Иосиф выжил и стал известным благодаря своему математическому дару.
В ходе иудейской войны он, будучи в составе отряда из 41 иудейского война, был загнан римлянами в пещеру. Отряд, в котором состоял Иосиф,
обладал неимоверно сильным боевым духом и, не желая сдаваться в плен, войны предпочли самоубийство. 
Они встали в круг и последовательно начали убивать каждого третьего из живых до тех пор, пока не останется ни одного человека. 
Иосиф же не разделял чаяний сослуживцев. Чтобы не быть убитым, Иосиф вычислил "спасительные места" на которое поставил себя и своего товарища.
... и лишь поэтому мы знаем его историю*/
#include <iostream>
#include <Windows.h>

using namespace std;

struct flavia
{
	int position;
	bool flag;
	flavia* next;
};

class cunningJew
{
	int kol;
	flavia* head, *tail;
public:
	cunningJew()
	{
		head = tail = NULL;
		kol = 0;
	}
	cunningJew(const cunningJew& ob)
	{

	}
	~cunningJew()
	{
		clearSpisok();
	}
	void addSpisok(int i);
	void addJew();
	void killJew(int step);
	void clearSpisok();
	int life();
	void survive();
	void push(int kol);
};
void cunningJew::push(int kol)
{
	head = tail = NULL;
	this->kol = kol;
}
void cunningJew::addSpisok(int i)
{
	flavia* elem = new flavia;
	elem->flag = true;
	elem->position = i;
	elem->next = NULL;
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
void cunningJew::clearSpisok()
{
	flavia* tmp=NULL;
	while (head)
	{
		tmp = head->next;
		delete head;
		head=tmp;
	}
}
void cunningJew::addJew()
{
	for (int i = 1; i <= kol; i++)
	{
		addSpisok(i);
	}
}
void cunningJew::killJew(int step)
{
	int count = 0;
	flavia* tmp;
	while (life() >= step)
	{
		tmp = head;
		while (tmp)
		{
			if (tmp->flag)
			{
				count++;
			}
			if (tmp->flag&&count==step)
			{
				tmp->flag = false;
				count = 0;
			}
			tmp = tmp->next;
		}
	}
	survive();
}
int cunningJew::life()
{
	int life = 0;
	flavia* tmp = head;
	while (tmp)
	{
		if (tmp->flag)
			life++;
		tmp = tmp->next;
	}
	return life;
}
void cunningJew::survive()
{
	cout << " Выжившие места : ";
	flavia* tmp = head;
	while (tmp)
	{
		if (tmp->flag)
			cout << tmp->position << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num;
	int step;
	char key;
	cunningJew flavia;
	do
	{
		system("cls");
		cout << " Введите количество бойцов в армии Флавия : ";
		cin >> num;
		cout << " Введите шаг убийства ( каждый n-ый умирает ) : ";
		cin >> step;
		flavia.push(num);
		flavia.addJew();
		flavia.killJew(step);
		cout << " Продолжить  (y/n) :";
		cin >> key;
		if (key == 'y')
			flavia.clearSpisok();
		if (key == 'n')
			cout << " До свидания \n";
			 
	} while (key != 'n');
	system("pause");
	return 1;
}
//16. 31 ---- 41/3
//1. 7 ----- 9/3
//5. 10 ----- 12/3
==========================================================
	/*Задача носит имя Иосифа Флавия - известного историка I века. Существует легенда, что Иосиф выжил и стал известным благодаря своему математическому дару.
В ходе иудейской войны он, будучи в составе отряда из 41 иудейского война, был загнан римлянами в пещеру. Отряд, в котором состоял Иосиф,
обладал неимоверно сильным боевым духом и, не желая сдаваться в плен, войны предпочли самоубийство. 
Они встали в круг и последовательно начали убивать каждого третьего из живых до тех пор, пока не останется ни одного человека. 
Иосиф же не разделял чаяний сослуживцев. Чтобы не быть убитым, Иосиф вычислил "спасительные места" на которое поставил себя и своего товарища.
... и лишь поэтому мы знаем его историю*/
#include <iostream>
#include <Windows.h>

using namespace std;

struct flavia
{
	int position;
	bool flag;
	flavia* next;
};

class cunningJew
{
	int kol;
	flavia* head, *tail;
public:
	cunningJew()
	{
		head = tail = NULL;
		kol = 0;
	}
	cunningJew(const cunningJew& ob)
	{

	}
	~cunningJew()
	{
		clearSpisok();
	}
	void addSpisok(int i);
	void addJew();
	void killJew(int step);
	void clearSpisok();
	int life();
	void survive();
	void push(int kol);
};
void cunningJew::push(int kol)
{
	head = tail = NULL;
	this->kol = kol;
}
void cunningJew::addSpisok(int i)
{
	flavia* elem=NULL;
	elem = new flavia;
	try
	{
		if (!elem)
			throw (char*)" Память не выделилась \n";
		else
		{
			elem->flag = true;
			elem->position = i;
			elem->next = NULL;
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
	}
	catch (const char* s)
	{
		cout << s;
		system("pause");
		exit(0);
	}
}
void cunningJew::clearSpisok()
{
	try
	{
		throw(char*)" Память освобождена \n";
	}
	catch(const char* s)
	{
		flavia* tmp = NULL;
		while (head)
		{
			tmp = head->next;
			delete head;
			head = tmp;
		}
		cout << s;
		system("pause");
	}
}
void cunningJew::addJew()
{
	for (int i = 1; i <= kol; i++)
	{
		addSpisok(i);
	}
}
void cunningJew::killJew(int step)
{
	int count = 0;
	flavia* tmp;
	while (life() >= step)
	{
		tmp = head;
		while (tmp)
		{
			if (tmp->flag)
			{
				count++;
			}
			if (tmp->flag&&count==step)
			{
				tmp->flag = false;
				count = 0;
			}
			tmp = tmp->next;
		}
	}
	survive();
}
int cunningJew::life()
{
	int life = 0;
	flavia* tmp = head;
	while (tmp)
	{
		if (tmp->flag)
			life++;
		tmp = tmp->next;
	}
	return life;
}
void cunningJew::survive()
{
	cout << " Выжившие места : ";
	flavia* tmp = head;
	while (tmp)
	{
		if (tmp->flag)
			cout << tmp->position << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num=0;
	int step=0;
	char key='y';
	cunningJew flavia;
	while(key=='y')
	{
		system("cls");
		try
		{
			try
			{
				cout << " Введите количество бойцов в армии Флавия : ";
				cin >> num;
				if (num < 2)
					throw num;
			}
			catch (int num)
			{
				if (num < 2)
				{
					cout << " Количество воинов должно быть больше 1 \n";
					system("pause");
					continue;
				}
			}
			try
			{
				cout << " Введите шаг убийства ( каждый n-ый умирает ) : ";
				cin >> step;
				if (step < 2)
					throw step;

			}
			catch (int step)
			{
				if(step<2)
					cout << " Шаг убийства должен быть больше 1 \n";
					system("pause");
					continue;
				

			}
			if (step > num)
				throw step;
		}
		catch(int step)
		{
			if(step>num)
			cout << " Шаг убийства больше количества воинов \n";
			system("pause");
			continue;
		}
		flavia.push(num);
		flavia.addJew();
		flavia.killJew(step);
		cout << " Продолжить  (y/n) :";
		cin >> key;
		if (key == 'y')
			flavia.clearSpisok();
		if (key == 'n')
			cout << " До свидания \n";
			 
	}
	return 1;
}
//16. 31 ---- 41/3
//1. 7 ----- 9/3
//5. 10 ----- 12/3
