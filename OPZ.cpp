/*Написать программу, которая использует класс string
для анализа строки, содержащей математическое выражение, например, вида  (2+3)*4+1. Строка вводится с клавиатуры Программа выдает результат
вычисления выражения.*/
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;
struct stek
{
	char elem;
	int prior;
	stek* next;
};
class Stek
{
	stek* head;
public:
	Stek()
	{
		head = NULL;
	}
	bool empty();
	void pop(char s);
	char push();
	void deleteStek();
	void show();
	stek*& getHead();
	void stekOb(string& str,int prior);
	void brackets(string& str);
};
stek*& Stek::getHead()
{
	return head;
}
void Stek::brackets(string& str)
{
	stek* tmp = NULL;
	while (head&&head->elem != '(')
	{
		tmp = head->next;
		str += push();
		head = tmp;
	}
	if (head->elem == '(')
	{
		tmp = head->next;
		push();
		head = tmp;
	}
	delete tmp;
}
void Stek::stekOb(string& str,int prior)
{
	cout << prior << endl;
	stek* tmp = NULL;
	while (head&&head->prior >= prior)
	{
		tmp = head->next;
		str +=push();
		head = tmp;
	}
	delete tmp;
}
void Stek::show()
{
	stek* tmp = head;
	cout << " Стек : \n";
	while (tmp)
	{
		cout << tmp->elem << " ";
		tmp = tmp->next;
	}
	cout << endl;
	delete tmp;
}
void Stek::pop(char s)
{
	stek* tmp = new stek;
	tmp->elem = s;
	if (s == '(' || s == ')')
		tmp->prior = 1;
	if (s == '+' || s == '-')
		tmp->prior = 2;
	if (s == '*' || s == '/')
		tmp->prior = 3;
	tmp->next = head;
	head = tmp;
}
char Stek::push()
{
	if (!head)return '~';
	char data = head->elem;
	stek* tmp = head;
	head = head->next;
	delete tmp;
	return data;
}
void Stek::deleteStek()
{
	stek* tmp = NULL;
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	delete tmp;
	head = NULL;
}
bool Stek::empty()
{
	if (head)
		return true;
	else
		return false;
}
class reversePolishEntry
{
	string stroka;
	Stek st;
public:
	reversePolishEntry(string stroka) :stroka(stroka) {};
	void show() { cout << stroka << endl; }
	void analys();
};
void reversePolishEntry::analys()
{
	string str;
	int prior = 0;
	int len = stroka.length();
    for (int i = 0; i < len; i++)
	{
		if (stroka.at(i) >= 'a'&&stroka.at(i) <= 'z')
			str += stroka.at(i);
		if (stroka.at(i) == '*'||stroka.at(i)=='/') 
		{
			int prior = 3;
			st.stekOb(str, prior);
			st.pop(stroka.at(i));
		}
		if (stroka.at(i) == '+' || stroka.at(i) == '-') 
		{
			int prior = 2;
			st.stekOb(str, prior);
			st.pop(stroka.at(i));
		}
		if (stroka.at(i) == '(')
			st.pop(stroka.at(i));
		if (stroka.at(i) == ')')
			st.brackets(str);
	}
	if (st.empty())
	{
		stek* tmp = st.getHead();
		while (tmp)
		{
			
			str += tmp->elem;
			tmp = tmp->next;
		}
		delete tmp;
	}
	cout << str << endl;
}
int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string polish;
	cout << " Введите строку : ";
	getline(cin, polish);
	reversePolishEntry ob(polish);
	ob.show();
	ob.analys();
	system("pause");
}
