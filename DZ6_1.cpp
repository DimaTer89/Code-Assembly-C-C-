/*Есть строка символов, признаком конца которой является ;. В строке могут быть фигурные, круглые, квадратные скобки. Скобки могут быть открывающими и закрывающими.
Строку поместить в стек. Ввод строки предусмотреть с клавиатуры.
Необходимо проверить корректность расстановки скобок.
При этом необходимо, чтобы выполнились следующие правила:
1.Каждая открывающая скобка должна иметь справа такую же закрывающую.
Обратное также должно быть верно.
2.Открывающие и закрывающие пары скобок разных типов должны быть
правильно расположены по отношению друг к другу.
3.Пример правильной строки: ({x-y-z}*[x+2y]-(z+4x));
4.Пример неправильной строки: ([x-y-z}*[x+2y)-{z+4x)].
Если все правила соблюдены выведите информационное сообщение о корректности строки, иначе покажите строку до места возникновения первой ошибки.*/
#include <iostream>
#include <Windows.h>

using namespace std;

struct Node
{
	char elem;
	Node* next;
};

class Stek
{

public:
	Node * str;
	Node* st;
	Stek()
	{
		st = NULL;
		str = NULL;

	}
	Stek(const Stek& ob)
	{

	}
	~Stek()
	{
		clearStek(st);
		clearStek(str);
	}
	void addStek(char s, Node*& head);
	char getElemOfStek(Node*& head);
	void clearStek(Node*& head);
	void analys();
	void reserv(Node*& head);
	void show(Node*& head);
};
void Stek::show(Node*& head)
{
	Node* tmp = head;
	while (tmp)
	{
		cout << tmp->elem;
		tmp = tmp->next;
	}
	cout << endl;
}
void Stek::reserv(Node*& head)
{
	Node* tmp = NULL;
	while (head)
	{
		addStek(head->elem, tmp);
		head = head->next;
	}
	head = tmp;
}
void Stek::addStek(char s, Node*& head)
{
	Node*tmp = new Node;
	tmp->elem = s;
	tmp->next = head;
	head = tmp;
}
void Stek::clearStek(Node*& head)
{
	Node* tmp = NULL;
	while (tmp)
	{
		tmp = st->next;
		delete head;
		st = tmp;
	}
	head = NULL;
}
char Stek::getElemOfStek(Node*& head)
{
	if (!st)return 'f';
	char data = head->elem;
	Node* tmp = head;
	head = head->next;
	delete tmp;
	return data;
}
void Stek::analys()
{
	reserv(str);
	int count = 0;
	bool flag = false;
	Node* tmp = str;
	while (tmp)
	{
		if (tmp->elem == '(' || tmp->elem == '{' || tmp->elem == '[')
		{
			flag = true;
			addStek(tmp->elem, st);
		}
		if (tmp->elem == ')')
		{
			if (st == NULL && flag == false)
			{
				break;
			}
			else
			{
				if (st->elem == '(')
				{
					getElemOfStek(st);
				}
				else
				{
					break;
				}
			}

		}
		if (tmp->elem == ']')
		{
			if (st == NULL && flag == false)
			{
				break;
			}
			else
			{
				if (st->elem == '[')
				{
					getElemOfStek(st);
				}
				else
				{
					break;
				}
			}
		}
		if (tmp->elem == '}')
		{
			if (st == NULL && flag == false)
			{
				break;
			}
			else
			{
				if (st->elem == '{')
				{
					getElemOfStek(st);
				}
				else
				{
					break;
				}
			}
		}
		tmp = tmp->next;
		count++;
	}
	if (!st&&flag == true)
		cout << " Скобки расставлены верно \n";
	else
	{
		cout << " Скобки расставлены неверно : ";
		int i = 0;
		while (str&&i<count)
		{
			cout << str->elem;
			str = str->next;
			i++;
		}
		cout << endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char s = NULL;
	Stek ob;
	cout << " Введите строку : ";
	while (s != '\n'&&s != ';')
	{
		s = getchar();
		ob.addStek(s, ob.str);
	}
	ob.analys();
	system("pause");
}
