/*Есть строка символов, признаком конца которой является ;. В строке могут быть фигурные, круглые, квадратные скобки. Скобки могут быть открывающими и закрывающими. Строку поместить в стек. Ввод строки предусмотреть с клавиатуры.
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
	char* str;
	Node* st;
public:
	Stek()
	{
		st = NULL;
		str = new char('\0');

	}
	Stek(const Stek& ob)
	{
		str = new char[strlen(ob.str) + 1];
		strcpy(str, ob.str);
	}
	~Stek()
	{
		delete[]str;
		clearStek();
	}
	void addStek(char s);
	char getElemOfStek();
	void clearStek();
	void analys();
	void getStr(char* s);
};
void Stek::addStek(char s)
{
	Node*tmp = new Node;
	tmp->elem = s;
	tmp->next = st;
	st = tmp;
}
void Stek::clearStek()
{
	Node* tmp = NULL;
	while (tmp)
	{
		tmp = st->next;
		delete st;
		st = tmp;
	}
	st = NULL;
}
char Stek::getElemOfStek()
{
	if (!st)return 'f';
	char data = st->elem;
	Node* tmp = st;
	st = st->next;
	delete tmp;
	return data;
}
void Stek::getStr(char* s)
{
	str = new char[strlen(s) + 1];
	strcpy(str, s);
}
void Stek::analys()
{
	int len = strlen(str);
	int i = 0;
	int l = 0;
	bool flag = false;
	while (i<len&&str[i] != ';')
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			flag = true;
			addStek(str[i]);
		}
		if (str[i] == ')')
		{
			if (st == NULL&&flag == false)
			{
				l = i;
				break;
			}
			else
			{
				if (str[i] == ')'&&st->elem == '(')
				{
					getElemOfStek();
				}
				else
				{
					l = i;
					break;
				}
			}

		}
		if (str[i] == ']')
		{
			if (st == NULL && flag == false)
			{
				l = i;
				break;
			}
			else
			{
				if (str[i] == ']'&&st->elem == '[')
				{
					getElemOfStek();
				}
				else
				{
					l = i;
					break;
				}
			}
		}
		if (str[i] == '}')
		{
			if (st == NULL && flag == false)
			{
				l = i;
				break;
			}
			else
			{
				if (str[i] == '}'&&st->elem == '{')
				{
					getElemOfStek();
				}
				else
				{
					l = i;
					break;
				}
			}
		}
		if (str[i] != ')' || str[i] != '(' || str[i] != '[' || str[i] != ']' || str[i] != '{' || str[i] != '}')
		{
			l = i;
		}
		i++;
	}
	if (!st&&flag == true)
		cout << " Скобки расставлены верно \n";
	else
	{
		cout << " Скобки расставлены неверно : ";
		int i = 0;
		while (i <= l&&str[i] != ';')
		{
			cout << str[i];
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
	char str[256];
	Stek ob;
	cout << " Введите строку : ";
	gets_s(str, 256);
	ob.getStr(str);
	ob.analys();
	system("pause");
}
================================================
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
	Node* str;
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
	void addStek(char s,Node*& head);
	char getElemOfStek(Node*& head);
	void clearStek(Node*& head);
	void analys();
	void reserv(Node*& head);
	void show(Node*& head)
	{
		Node* tmp = head;
		while (tmp)
		{
			cout << tmp->elem;
			tmp = tmp->next;
		}
		cout << endl;
	}
};
void Stek::reserv(Node*& head)
{
	Node* tmp = NULL;
	while (head)
	{
		addStek(head->elem, tmp);
		head=head->next;
	}
	head = tmp;
}
void Stek::addStek(char s,Node*& head)
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
	show(str);
	int i = 0;
	int l = 0;
	bool flag = false;
	while (str&&str->elem != ';')
	{
		if (str->elem == '(' || str->elem == '{' || str->elem == '[')
		{
			flag = true;
			addStek(str->elem,st);
		}
		if (str->elem == ')')
		{
			if (st == NULL&&flag == false)
			{
				l = i;
				break;
			}
			else
			{
				if (str->elem == ')'&&st->elem == '(')
				{
					getElemOfStek(st);
				}
				else
				{
					l = i;
					break;
				}
			}

		}
		if (str->elem == ']')
		{
			if (st == NULL && flag == false)
			{
				l = i;
				break;
			}
			else
			{
				if (str->elem == ']'&&st->elem == '[')
				{
					getElemOfStek(st);
				}
				else
				{
					l = i;
					break;
				}
			}
		}
		if (str->elem == '}')
		{
			if (st == NULL && flag == false)
			{
				l = i;
				break;
			}
			else
			{
				if (str->elem == '}'&&st->elem == '{')
				{
					getElemOfStek(st);
				}
				else
				{
					l = i;
					break;
				}
			}
		}
		if (str->elem != ')' || str->elem != '(' || str->elem != '[' || str->elem != ']' || str->elem != '{' || str->elem != '}')
		{
			l = i;
		}
		str = str->next;
	}
	if (!st&&flag == true)
		cout << " Скобки расставлены верно \n";
	else
	{
		cout << " Скобки расставлены неверно : ";
		int i = 0;
		while (str&&str->elem != ';')
		{
			cout << str->elem;
			str = str->next;
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
	while (s != '\n')
	{
		s = getchar();
		cout << s;
		ob.addStek(s, ob.str);
	}
	ob.analys();
	system("pause");
}
