#include <iostream>
#include <windows.h>
using namespace std;

class String
{
	char* str;
public:
	static int num_obj;
	String()
	{
		cout << " Конструктор по умолчанию \n";
		str = new char[80];
		cout << " Введите строку : ";
		gets_s( str,80);
		cout <<" Строка : "<< str << endl;
		num_obj++;
	}
	String(const char* s)
	{
		cout << " Конструктор с аргументами \n";
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		cout << " Строка : "<< str << endl;
		num_obj++;
	}
	String(const char* s,const char* tmp)
	{
		cout << " Конструктор для изменения строки \n";
		str = new char[strlen(s)+1];
		strcpy(str, s);
		cout << " Строка до изменения : " << str << endl;
		delete str;
		str = new char[strlen(tmp) + 1];
		strcpy(str, tmp);
		cout << " Строка после изменения : " << str << endl;
		num_obj++;
	}

	~String()
	{
		delete[] str;
		cout << " Разрушение объекта " << num_obj-- << endl;;
	}
	
	
	
};
int String::num_obj = 0;
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N=100000;
	String ob;
	char* arr;
	arr =new char[N];
	cout << " Количество объектов : " << String::num_obj << endl;
	cout << " Введите строку : ";
	gets_s(arr,N);
	String ob_1(arr);
	cout << " Количество объектов : " << String::num_obj << endl;
	cout << " Введите строку : ";
	gets_s(arr, N);
	String ob_2(" Привет , как дела ?", arr);
	cout << " Количество объектов : " << String::num_obj << endl;
	delete[] arr;
	system("pause");
}
