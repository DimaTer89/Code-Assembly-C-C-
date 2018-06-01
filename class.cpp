#include <windows.h>
#include <iostream>
#include <malloc.h>

using namespace std;

class SomeClass
{
	int some;
public:
	//конструктор с параметрами
	//по умолчанию
	SomeClass(int x = 1)
	{
		some = x;
		cout << "\nКонструктор!!!\n";
	}
	~SomeClass()
	{
		cout << "\nДеструктор!!!\n";
	}
	SomeClass* input(SomeClass* p1)
	{
		for (int i = 0; i<3; i++)
		{
			cout << "Элемент [" << i << "]=";
			cin >> p1[i].some;
		}
		return this; // возврат скрытого указателя this (адреса начала массива объектов)
	}
	void Show()
	{
		cout << "some=" << some << "\n";
	}
	//перегруженные операторы new и delete,
	//здесь также используются дополнительные
	//параметры, передаваемые внутрь операторов
	static void* p;
	void* operator new(size_t size);
	void operator delete(void* ptr);
	//перегруженные операторы new[] и delete[]
	void* operator new[](size_t fullsize);
	void operator delete[](void*);
};

void* SomeClass::operator new(size_t size)
{
	
	if (p)
	{
		cout << "\nОшибка выделения памяти под объект!!!\n";
		return p;
	}
	else
	{
		p = malloc(size);
		cout << "\nНовая память под объект выделена успешно!!!\n";
		return p;
	}
	
}

void* SomeClass::operator new[](size_t fullsize)
{
	
	if (p)
	{
		cout << "\nОшибка выделения памяти под массив объектов!!!\n";
		return p;
	}
	else
	{
		p = malloc(fullsize);
		cout << "\nНовая память под массив объектов выделена успешно!!!\n";
		return p;
	}
	
}
void SomeClass::operator delete(void*)
{
	free(p);
	cout << "\nПамять под объект освобождена\n";
}

void SomeClass::operator delete[](void*)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
	cout << "\nПамять под массив объектов освобождена\n";
}
void* SomeClass::p = NULL;
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*
	Вызывается оператор
	new( size_t size,char* str="New")
	на место size будет подставлен размер класса
	SomeClass, а str получит значение по умолчанию
	т.е. "New"
	*/
	SomeClass* p = new SomeClass(25);
	p->Show();
	/*
	Вызывается оператор delete(void* ptr) на место
	ptr будет подставлен адрес памяти, выделенной
	под объект р
	*/
	delete p;
	/*
	Вызывается оператор
	new[](size_t size,char* str="New[]")
	на место size будет подставлен размер класса
	SomeClass, умноженный на количество запрашиваемых
	элементов, а str получит значение по умолчанию
	т.е. "New[]"
	*/
	SomeClass* r = new SomeClass[3];
	cout << "Массив объектов после создания:" << endl;
	for (int i = 0; i<3; i++)
		r[i].Show();
	r->input(r);
	cout << endl;
	cout << "Массив объектов после ввода данных:" << endl;
	for (int i = 0; i<3; i++)
		r[i].Show();
	/*
	Вызывается оператор delete[](void* ptr)
	на место ptr будет подставлен адрес памяти
	выделенной под объект r
	*/
	delete[]r;
	system("pause");
}
