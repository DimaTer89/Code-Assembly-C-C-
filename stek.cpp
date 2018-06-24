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
	
public:
	Node* st;
	Node* st_os;
	Node* st_zs;
	Stek()
	{
		st = NULL;
		st_os = NULL;
		st_zs = NULL;
		
	}
	Stek(const Stek& ob)
	{
		
	}
	~Stek()
	{
		
		clearStek(st);
		clearStek(st_os);
		clearStek(st_zs);
	}
	void showStek(Node* head);
	void addStek(char s,Node*& head);
	char getElemOfStek(Node*& head);
	void clearStek(Node*& head);
	void analys();
	void revers(Node*& head)
	{
		Node* tmp = NULL;
		while (head)
		{
			addStek(head->elem, tmp);
			head = head->next;
		}
		head = tmp;
	}
};
void Stek::showStek(Node* head)
{
	Node* tmp = head;
	while (tmp)
	{
		cout << tmp->elem << " ";
		tmp = tmp->next;
	}
	cout << endl;
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
	Node* tmp=NULL;
	while (tmp)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	head = NULL;
}
char Stek::getElemOfStek(Node*& head)
{
	if (!head)return 0;
	char data = head->elem;
	Node* tmp = head;
	head = head->next;
	delete tmp;
	return data;
}
void Stek::analys()
{
	char c;
	Node* tmp = st;
	while (tmp)
	{
		c = tmp->elem;
		if (c == '(' || c == '{' || c == '[')
		{
			cout << c;
			addStek(c, st_os);
		}
		else if (c == ')' || c == '}' || c == ']')
		{
			if (c == ')')
			{
				if (st_os->elem != '(')
				{
					Node* temp = st_os;
					while (temp->elem != '(' || tmp != 0)
					{
						temp = temp->next;
					}

				}
				if (st_os != 0)
				{
					addStek(' ', st_os);
				}
				else break;
			}
			if (c == '}') {
				{
					Node* temp = st_os;
					while (temp->elem != '(' || tmp != 0)
					{
						temp = temp->next;
					}

				}
				if (st_os != 0) {
					addStek(' ', st_os);
				}
				else break;
			}
			if (c == ']') {
				{
					Node* temp = st_os;
					while (temp->elem != '(' || tmp != 0)
					{
						temp = temp->next;
					}

				}
				if (st_os != 0) {
					addStek(' ', st_os);
				}
				else break;
			}
			else if (c == ';')break;

			tmp = tmp->next;
		}
	}
	/*cout << endl;
	cout << " Стек октрывающих скобок \n";
	showStek(st_os);
	cout << " Стек закрывающих скобок \n";
	showStek(st_zs);*/
	
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char s=NULL;
	Stek ob;
	cout << " Введите строку : ";
	while (s != '\n')
	{
		s = getchar();
		ob.addStek(s, ob.st);
		cout << s << " ";
	}
	cout << endl;
	ob.showStek(ob.st);
	ob.analys();
	system("pause");
}
