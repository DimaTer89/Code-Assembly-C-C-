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
struct stekInt
{
	int elem;
	stekInt* next;
};
class StekInt
{
	stekInt* head;
public:
	StekInt()
	{
		head = NULL;
	}
	~StekInt()
	{
		deleteStekInt();
	}
	void pop(int n);
	int push();
	void deleteStekInt();
	void show();
};
void StekInt::pop(int n)
{
	stekInt* tmp = new stekInt;
	tmp->elem = n;
	tmp->next = head;
	head = tmp;
}
int StekInt::push()
{
	if (!head)return 99999;
	int data = head->elem;
	stekInt* tmp = head;
	head = head->next;
	delete tmp;
	return data;
}
void StekInt::deleteStekInt()
{
	stekInt* tmp = NULL;
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	delete tmp;
}
void StekInt::show()
{
	stekInt* tmp = head;
	cout << " Стек : \n";
	while (tmp)
	{
		cout << tmp->elem << " ";
		tmp = tmp->next;
	}
	cout << endl;
	delete tmp;
}
class Stek
{
protected:
	stek* head;
public:
	Stek()
	{
		head = NULL;
	}
	~Stek()
	{
		deleteStek();
	}
	bool empty();
	void pop(char s);
	char push();
	void deleteStek();
	void show();
	stek* getHead();
	void stekOb(string& str, int prior);
	void brackets(string& str);
	char putElem();
};
char Stek::putElem()
{
	return head->elem;
}
stek* Stek::getHead()
{
	return head;
}
void Stek::brackets(string& str)
{
	stek* tmp = NULL;
	while (head)
	{
		if (head->elem == '(')
		{
			push();
			break;
		}
		else
		{
			tmp = head->next;
			str += push();
			head = tmp;
		}
	}
	tmp = NULL;
	delete tmp;
}
void Stek::stekOb(string& str, int prior)
{
	stek* tmp = NULL;
	while (head)
	{
		if (head->prior >= prior)
		{
			if (!head->next)
			{
				head = tmp = NULL;
				str += push();
			}
			else
			{
				tmp = head->next;
				str += push();
				head = tmp;
			}
		}
		else
			break;
	}
	tmp = NULL;
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
	if (!head)return 'f';
	stek* tmp = head;
	char data = head->elem;
	if (!head->next)
	{
		head = NULL;
		tmp = NULL;
		delete tmp;
		return data;
	}
	else
	{
		head = head->next;
		tmp = NULL;
		delete tmp;
		return data;
	}
}
void Stek::deleteStek()
{
	stek* tmp = NULL;
	try
	{
		if (head == NULL)
			throw (char*)"NULL\n";
		else
		{
			if (head->next == NULL)
			{
				return;
			}
			else
			{
				while (head)
				{
					tmp = head->next;
					delete head;
					head = tmp;
				}
				delete tmp;
				head = NULL;
				return;
			}
		}

	}
	catch (const char* s)
	{
		delete tmp;
		head = NULL;
		return;
	}

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
	string str;
public:
	reversePolishEntry(string stroka) :stroka(stroka) {};
	~reversePolishEntry()
	{
		st.deleteStek();
	}
	bool analysString(string str);
	void analys();
	string& getStr() { return str; }
	int CalcInt(string str);
	int sum(int a, int b, char s);
};
bool reversePolishEntry::analysString(string str)
{
	Stek tmp;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str.at(i) == '(')
			tmp.pop(str.at(i));
		if (str.at(i) == ')')
		{
			if (tmp.putElem() == '(')
			{
				tmp.push();
				continue;
			}
		}
	}
	if (tmp.getHead())
		return false;
	else
		return true;
}
int reversePolishEntry::sum(int a, int b, char s)
{
	switch (s)
	{
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	default:
		cout << " Error !!!\n";
		return -500;
	}
}
int reversePolishEntry::CalcInt(string str)
{
	int len = str.length();
	StekInt st;
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		if (str.at(i) == '*' || str.at(i) == '/' || str.at(i) == '+' || str.at(i) == '-')
		{
			int n2;
			int n1;
			n2 = st.push();
			n1 = st.push();
			st.pop(sum(n1, n2, str.at(i)));
			continue;
		}
		else
		{
			num = str.at(i) - '0';
			st.pop(num);
		}
	}
	return st.push();
}
void reversePolishEntry::analys()
{
	int prior = 0;
	int len = stroka.length();
	for (int i = 0; i < len; i++)
	{
		if ((stroka.at(i) >= 'a'&&stroka.at(i) <= 'z')||(stroka.at(i) >= '0'&&stroka.at(i) <= '9'))
			str += stroka.at(i);
		if (stroka.at(i) == '*' || stroka.at(i) == '/')
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
		{
			st.pop(stroka.at(i));
		}
		if (stroka.at(i) == ')')
		{
			st.brackets(str);
		}
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
		st.deleteStek();
	}
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
	if (ob.analysString(polish))
		cout << " Строка верна \n";
	else
	{
		cout << " Строка составлена не верно \n";
		exit(0);
	}
	ob.analys();
	string str = ob.getStr();
	cout << " Обратная польская запись : " <<str << endl;
	cout << " Результат : " << ob.CalcInt(str) << endl;
	system("pause");
}
