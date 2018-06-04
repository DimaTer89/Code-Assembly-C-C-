/*Добавить в строковый класс функцию, которая соз¬даёт строку, содержащую 
пересечение двух строк, то есть общие символы для двух строк. Например,
результатом пересечения строк "sdqcg" "rgfas34" будет строка "sg". Для 
реализации функции перегрузить оператор * (бинарное умножение).*/
#include <iostream>
#include <Windows.h>
using namespace std;

class String
{
	char* str;
public:
	String()
	{
		str = new char('\0');
	}
	String(const String& ob)
	{
		str = new char[strlen(ob.str) + 1];
		strcpy(str, ob.str);
	}
	~String()
	{
		if (str)delete str;
		str = NULL;
	}
	void get(char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	void show()
	{
		cout << " Введённая строка = "<< str << endl;
	}
	int operator *(String ob);
};
int String::operator *(String ob)
{
	int kol = 0;
	while (str)
	{
		char tmp;
		char tmp2;
		tmp=*str;
		tmp2=*ob.str;
		if (tmp==tmp2)
		{
			kol++;
		}
		str++;
		ob.str++;
	}
	return kol;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char stroka[256];
	cout << " Введите строку : ";
	gets_s(stroka, 256);
	String ob;
	ob.get(stroka);
	ob.show();
	String ob1;
	cin.ignore();
	cout << " Введите строку : ";
	gets_s(stroka, 256);
	ob1.get(stroka);
	ob1.show();
	int kol = ob*ob1;
	cout << " Одинаковых символов = "<< kol << endl;
	system("pause");
}
