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
	Node* Head;
	Node* Head2;
	char* string;
public:
	Stek()
	{
		Head = NULL;
		string = new char('\0');
	}
	Stek(const Stek& ob)
	{
		string = new char[strlen(ob.string) + 1];
		strcpy(string, ob.string);
	}
	~Stek()
	{
		delete[]string;
		clearStek(Head);
		clearStek(Head2);
	}
	void showStek(Node* head);
	void addStek(char s,Node*& head);
	char getElemOfStek(Node*& head);
	void clearStek(Node*& head);
	void analys();
	void getString(char* str);
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
void Stek::getString(char* str)
{
	string = new char[strlen(str) + 1];
	strcpy(string, str);
}
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
	int len = strlen(string);
	cout << len << endl;
	for(int i=0;i<len;i++)
	{
		if (string[i] == '(' || string[i] == '{' || string[i] == '[')
		{
			addStek(string[i], Head);
		}
		else
		{
			addStek(string[i],Head2);
		}
		
	}
    cout << " Содержимое 1 стека \n";
	showStek(Head);
	revers(Head);
	cout << " Содержимое 1 стека после реверса\n";
	showStek(Head);
	cout << " Содержимое 2 стека \n";
	showStek(Head2);
	revers(Head2);
	cout << " Содержимое 2 стека после реверса \n";
	showStek(Head2);
	Node*tmp = Head;
	while (tmp)
	{
		while (Head2)
		{
			if ((tmp->elem == '('&&Head2->elem == ')') ||( tmp->elem == '['&&Head2->elem == ']') ||( tmp->elem == '{'&&Head2->elem == '}'))
			{
				getElemOfStek(Head);
				break;
			}
			Head2 = Head2->next;
		}
		tmp = tmp->next;
	}
	showStek(Head);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char string[50];
	cout << " Введите строку : ";
	gets_s(string, 50);
	cout << string << endl;
	Stek ob;
	ob.getString(string);
	ob.analys();
	system("pause");
}
