#include <iostream>
#include <map>
#include <string>
#define N 255

using namespace std;

struct stek
{
	char elem;
	int prior;
	stek* next;
};
struct stekInt
{
	double elem;
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
	void pop(double n);
	double push();
	void deleteStekInt();
	void show();
};
void StekInt::pop(double n)
{
	stekInt* tmp = new stekInt;
	tmp->elem = n;
	tmp->next = head;
	head = tmp;
}
double StekInt::push()
{
	if (!head)return 99999;
	double data = head->elem;
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
	stek * head;
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
			tmp = head->next;
			str += push();
			head = tmp;
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
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	tmp = NULL;
	head = NULL;
	delete tmp;
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
	string strn;
public:
	reversePolishEntry(string stroka) :stroka(stroka) {};
	~reversePolishEntry()
	{
		st.deleteStek();
	}
	bool analysString(string str);
	void analys(string& str);
	string& getStr() { return strn; }
	double Calc(string str,map<char,double> ob);
	double sum(double a, double b, char s);
	void deleteSt() { st.deleteStek(); }
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
			if (!tmp.getHead())
				return false;
			else
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
double reversePolishEntry::Calc(string str, map<char,double> ob)
{
	int len = str.length();
	StekInt st;
	map<char, double>::iterator iter;
	for (int i = 0; i < len; i++)
	{
		if (str.at(i) == '*' || str.at(i) == '/' || str.at(i) == '+' || str.at(i) == '-')
		{
			double n2;
			double n1;
			n2 = st.push();
			n1 = st.push();
			st.pop(sum(n1, n2, str.at(i)));
			continue;
		}
		else
		{
			iter = ob.find(str.at(i));
			st.pop(iter->second);
		}
	}
	return st.push();
}
double reversePolishEntry::sum(double a, double b, char s)
{
	switch (s)
	{
	case '*':
		return a * b;
	case '/':
		if (b == 0)
		{
			cout << " На ноль делить нельзя \n";
			system("pause");
			exit(0);
		}
		else
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

void reversePolishEntry::analys(string& str)
{
	int prior = 0;
	string temp;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str.at(i) >= 'a')
		{
			temp += str.at(i);
		}
		if (str.at(i) == '*' || str.at(i) == '/')
		{
			int prior = 3;
			st.stekOb(temp, prior);
			st.pop(str.at(i));
		}
		if (str.at(i) == '+' || str.at(i) == '-')
		{
			int prior = 2;
			st.stekOb(temp, prior);
			st.pop(str.at(i));
		}
		if (str.at(i) == '(')
		{
			st.pop(str.at(i));
		}
		if (str.at(i) == ')')
		{
			st.brackets(temp);
		}
	}
	if (st.empty())
	{
		stek* tmp = st.getHead();
		while (tmp)
		{

			temp += tmp->elem;
			tmp = tmp->next;
		}
		delete tmp;
		st.deleteStek();
	}
	strn = temp;
}
char* strg(string str)
{
	char* string;
	int len = str.length();
	string = new char[len];
	int i;
	for (i = 0; i < len; i++)
	{
		string[i] = str.at(i);
	}
	string[i] = 0;
	return string;
}
string& changeStr(string& str)
{
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str.at(i) == '/' || str.at(i) == '*' || str.at(i) == '+' || str.at(i) == '-' || str.at(i) == '(' || str.at(i) == ')')
			str.at(i) = ' ';


	}
	return str;
}
void un_min(string& str,map<char,double>& ob)
{
	map<char,double>::iterator iter;
	char* str_c = (char*)str.c_str();
	int len = strlen(str_c);
	for (int i = 0; i < len;i++)
	{
		if (str_c[i] == '-')
		{
			if (str_c[i - 1] == '+' || str_c[i - 1] == '/' || str_c[i - 1] == '-' || str_c[i - 1] == '*'||str_c[i-1]=='('||!str_c[i-1])
			{
				for (int j = i; j < len; j++)
				{
					if (str_c[j] >= 'a'&&str_c[j] <= 'z')
					{
						iter = ob.find(str_c[j]);
						iter->second *= -1;
						break;
					}
				}
				for (int j = i; j < len; j++)
				{
					str_c[j] = str_c[j + 1];
				}
				len--;
			}
		}
	}
	string tmp;
	for (int i = 0; i < len; i++)
	{
		tmp += str_c[i];
	}
	str = tmp;
	str_c = NULL;
	delete str_c;
}
void udal(string& str)
{
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		if (str.at(i) >= '0'&&str.at(i) <= '9')
			str.at(i) = '!';
		if (str.at(i) == ',')
			str.at(i) = '!';
	}
	char* strC = (char*)str.c_str();
	int size = strlen(strC);
	for (int i = 0; i < size;)
	{
		if (strC[i] == strC[i + 1])
		{
			for (int j = i; j < size; j++)
			{
				strC[j] = strC[j + 1];
			}
			size--;
		}
		else
		{
			i++;
		}
	}
	string strFin;
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (strC[i] == '!')
		{
			strFin += 'a' + j;
			j++;
		}
		else
		{
			strFin += strC[i];
		}
	}
	str = strFin;
	strC = NULL;
	delete strC;
}
int main()
{
	setlocale(LC_ALL, "rus");
	char key = 'y';
	char buff[N];
	char* word, *next;
	double elem;
	string str, str_ex;
	map<char, double> d_map;
	while (key == 'y')
	{
		system("cls");
		cout << " Введите строку : ";
		getline(cin, str);
		str_ex = str;
		changeStr(str);
		strcpy(buff, strg(str));
		word = strtok_s(buff, " ", &next);
		int i = 0;
		while (word)
		{

			elem = (double)atof(word);
			d_map.insert(pair<char, double>('a' + i, (double)elem));
			i++;
			word = strtok_s(NULL, " ", &next);
		}
		reversePolishEntry ob(str_ex);
		if (ob.analysString(str_ex))
		{
			udal(str_ex);
			map<char, double>::iterator iter;
			iter = d_map.begin();
			un_min(str_ex, d_map);
			iter = d_map.begin();
			ob.analys(str_ex);
			cout << " Результат : " << ob.Calc(ob.getStr(), d_map) << endl;
			d_map.clear();
			cout << " Продолжить расчёты : y/n ";
			cin >> key;
			cin.ignore();
		}
		else
		{
			cout << " Строка составлена не верно \n";
			system("pause");
		}
	}
	return 0;
}
