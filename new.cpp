#include <windows.h>
#include <iostream>
#include <malloc.h>

using namespace std;

class SomeClass
{
	int some;
public:
	SomeClass(int x = 1)
	{
		some = x;
		
	}
	~SomeClass()
	{
		
	}
	SomeClass* input(SomeClass* p1)
	{
		for (int i = 0; i<3; i++)
		{
			cout << "Элемент [" << i << "]=";
			cin >> p1[i].some;
		}
		return this; 
	}
	void Show()
	{
		cout << "some=" << some << "\n";
	}
	static void* p;
	void* operator new(size_t size);
	void operator delete(void*);
	void* operator new[](size_t fullsize);
	void operator delete[](void*);
};

void* SomeClass::operator new(size_t size)
{
	
	if (p)
	{
		return p;
	}
	else
	{
		p = malloc(size);
		return p;
	}
}

void* SomeClass::operator new[](size_t fullsize)
{
	if (p)
	{
		return p;
	}
	else
	{
		p = malloc(fullsize);
		return p;
	}
}
void SomeClass::operator delete(void* )
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void SomeClass::operator delete[](void*)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}
void* SomeClass::p = NULL;
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SomeClass* p = new SomeClass(25);
	p->Show();
	delete p;
	SomeClass* r = new SomeClass[3];
	cout << "Массив объектов после создания:" << endl;
	for (int i = 0; i<3; i++)
		r[i].Show();
	r->input(r);
	cout << endl;
	cout << "Массив объектов после ввода данных:" << endl;
	for (int i = 0; i<3; i++)
		r[i].Show();
	delete[]r;
	system("pause");
}
