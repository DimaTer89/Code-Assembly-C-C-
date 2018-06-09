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
	char* str1;
	int len;
public:
	String()
	{
		str = new char('\0');
		str1 = new char('\0');
	}
	String(const String& ob)
	{
		str = new char[strlen(ob.str) + 1];
		strcpy(str, ob.str);
		str1 = new char[strlen(ob.str) + 1];
		strcpy(str, ob.str);
	}
	~String()
	{
		if (str)delete str;
		str = NULL;
		if (str1)delete str;
		str1 = NULL;
	}
	void get(char* s)
	{
		len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
	void show()
	{
		cout << " Введённая строка = "<< str << endl;
	}
	void Showrez()
	{
		cout << " Общая строка = " << str1 << endl;
	}
	String& operator *(String& ob);
	String& operator=(String& ob);
};
String& String::operator *(String& ob)
{
	int tmp = 1;
	len = strlen(str) + 1;
	ob.len = strlen(ob.str) + 1;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < ob.len; j++)
		{
			if (str[i] == ob.str[j])
			{
				tmp++;
			}
		}
	}
	str1 = new char[tmp];
	str1[0] = '\0';
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < ob.len; j++)
		{
			if (str[i] == ob.str[j])
			{
				strncat(str1,&str[i],1);
			}
		}
	}
	return *this;
}
String& String::operator=(String&ob)
{
	if (str)
		delete[] str;
	if (str1)
		delete[] str1;
	str = new char[strlen(ob.str) + 1];
	str1 = new char[strlen(ob.str1) + 1];
	strcpy(str, ob.str);
	strcpy(str1, ob.str1);
	len = ob.len;
	return *this;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char stroka[256];
	cout << " Введите строку : ";
	gets_s(stroka, 256);
	String ob1;
	ob1.get(stroka);
	ob1.show();
	String ob2;
	cout << " Введите строку : ";
	gets_s(stroka, 256);
	ob2.get(stroka);
	ob2.show();
	String ob3;
	ob3 = ob1*ob2;
	ob3.Showrez();
	system("pause");
}
