#include "HomeWork.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	
 HomeWork hw;
	hw.Run();
}

void HomeWork::Run()
{
 int input;
 char c[2];

	do
  {
	 	ShowMenu();
	 	cin >> input;
   cin.getline(c, 2);
	 	if(input < 0 || input > 3)
		  {
			  cout << "Неверный ввод.\n";
			  system("pause");
			  system("cls");
			  continue;
	  	}
		 HandleMenuInput(input);
		 system("pause");
		 system("cls");
	 }
 while (input);
}

void HomeWork::ShowMenu()
{
	cout << "Домашнее задание 1 к моулю 4. Класс String (пересечение строк).\nМЕНЮ:\n";
	cout << "1 - Ввести строку1.\n";
	cout << "2 - Ввести строку2.\n";
	cout << "3 - Выполнить операцию \"пересечение двух строк\".\n";
	cout << "0 - Выход.\n";
}

void HomeWork::HandleMenuInput(int input)
{
	if (!input) return;

	switch (input)
	{
	case 1:
		string1.Fill();
		break;

	case 2:
		string2.Fill();
		break;

	case 3:
		cout << "Пересечение строк (" << string1.Get() << " * " << string2.Get() << "): " << (string1 * string2).Get() << endl;
		break;


	default:
		break;
	}
}
======================================================== 
#include "MyString.h"



MyString::MyString()
{
	_string = new char[DEFAULT_SIZE + 1];
	_size = DEFAULT_SIZE;
}


MyString::~MyString()
{
	delete[] _string;
}

MyString::MyString(int size)
{
	_string = new char[size + 1];
	_size = size;
}

MyString::MyString(char * string)
{
	_string = NULL;
	_size = 0;
	Set(string);
}

MyString::MyString(MyString & myString)
{
	Set(myString.Get());
}

char * MyString::Get()
{
	return _string;
}

void MyString::Set(char * string)
{
	if (_string) delete[] _string;
	_size = strlen(string);
	_string = new char[_size + 1];
	strcpy(_string, string);
}

int MyString::GetSize()
{
	return _size;
}

void MyString::Fill()
{
	char buff[256];
	std::cout << "Введите строку:" << std::endl;
 std::cin.getline(buff,80);
	//while (std::cin.get() != '\n');
	//std::cin >> buff;

	Set(buff);
}

void MyString::Print()
{
	std::cout << _string;
}

MyString & MyString::operator=(const MyString & string)
{
	Set(string._string);
	return *this;
}

MyString MyString::operator*(const MyString & str)
{
	MyString temp;
 char buff[80];
	int pos1 = 0, pos2 = 0;
	bool flag = false;
	while (pos1 < strlen(_string))
	{
		flag = true;
		if (strchr(str._string, _string[pos1]))
		{
			for (int i = 0; i < pos2; i++)
			{
				if (buff[i] == _string[pos1])
					flag = false;
			}
			if (flag)
			{
				buff[pos2] = _string[pos1];
				pos2++;
			}
		}
		pos1++;
	}
	buff[pos2] = '\0';
 temp=buff;
	return temp;
}
===============================================
#pragma once

#include <cstring>
#include <iostream>

#define DEFAULT_SIZE 80

class MyString
{
protected:
	char* _string;
	int _size;

public:
	MyString();
	~MyString();
	MyString(int size);
	MyString(char* string);
	MyString(MyString& myString);

	char* Get();
	void Set(char* string);
	int GetSize();

	void Fill();
	void Print();

	MyString& operator=(const MyString & string);
	MyString operator* (const MyString & str);
};
==============================================
#pragma once
#include "MyString.h"

class HomeWork
{
private:
	MyString string1, string2;

public:
	HomeWork() {  };
	~HomeWork() {  };

	void Run();
	void ShowMenu();
	void HandleMenuInput(int input);
};
========================================
