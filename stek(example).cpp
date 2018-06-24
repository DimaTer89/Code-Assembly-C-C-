//                                   Курс.Объектно - ориентированное программирование на C++.
//                                           Модуль 6. Динамические структуры данных.
//                                                   Домашнее задание № 1.
// Есть строка символов, признаком конца которой является; .
// В строке могут быть фигурные, круглые, квадратные скобки.Скобки могут быть открывающими и закрывающими.
// Строку поместить в стек.Ввод строки предусмотреть с клавиатуры.
// Необходимо проверить корректность расстановки скобок.
// При этом необходимо, чтобы выполнились следующие правила:
//   1. Каждая открывающая скобка должна иметь справа такую же закрывающую. Обратное также должно быть верно.
//   2. Открывающие и закрывающие пары скобок разных типов должны быть правильно расположены по отношению друг к другу.
//   3. Пример правильной строки: ({ x - y - z }*[x + 2y] - (z + 4x));
//   4. Пример неправильной строки: ([x - y - z}*[x + 2y) - {z + 4x)].
// Если все правила соблюдены выведите информационное сообщение о корректности строки, иначе покажите строку до места возникновения первой ошибки.

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "Stack.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	Stack ST;
	unsigned char c='a';

	cout << "Введите строку:\n";
	// пока стек не заполнится
	while (c != '\n')
	{
		c = getchar();
		ST.Push(c);
		cout << c;
	}
	cout << "\n\n";
	cout << "Извлечение данных из стека:\n";

	// пока стек не освободится
	ST.Check_Bracket();
	cout << "\n\n";
	system("pause");
}
================================
#include <iostream>
#include "Stack.h"
#include <string.h>
#include <time.h>
using namespace std;

Stack::Stack()
{
	//Изначально стек пуст
	top = EMPTY;
	br_o = br_c = EMPTY;
}

bool Stack::IsEmpty()
{
	//Пуст?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	//Полон?
	return top == FULL;
}

int Stack::GetCount()
{
	//Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(unsigned char c)
{
	//Если в стеке есть место, то увеличиваем указатель
	//на вершину стека и вставляем новый элемент
	if (!IsFull()) {
		st[top++] = c;
	}
}

int Stack::Pop()
{
	//Если в стеке есть элементы, то возвращаем
	//верхний и уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[--top];
	else
		//Если в стеке элементов нет
		return 0;
}

void Stack::Check_Bracket()
{
	unsigned char c;
	br_o = br_c = -1;
	for (int i = 0; i < top; i++) {
		c = st[i];
		if (c == '(' || c == '{' || c == '[') {
			cout << c;
			bracket_open[++br_o]=c;
		}
		else if (c == ')' || c == '}' || c == ']') {
			if (c == ')') {
				if (bracket_open[br_o] != '(') {
					while (bracket_open[br_o] != '(' || br_o >= 0)
						br_o--;
				}
				if (br_o >= 0) {
					br_o--;
					cout << c;
					bracket_open[br_o] = ' ';
				}
				else break;
			}
			if (c == '}') {
				while (bracket_open[br_o] != '{' || br_o >= 0)
					br_o--;
				if (br_o >= 0) {
					cout << c;
					bracket_open[br_o] = ' ';
				}
				else break;
			}
			if (c == ']') {
				while (bracket_open[br_o] != '[' || br_o >= 0)
					br_o--;
				if (br_o >= 0) {
					cout << c;
					bracket_open[br_o] = ' ';
				}
				else break;
			}
		}
		else if (c == ';') break;
		else cout << c;
	}
}
==============================
#pragma once
class Stack
{
	//Нижняя и верхняя границы стека
	enum
	{
		EMPTY = 0,
		FULL = 20
	};
	//Массив для хранения данных
	unsigned char st[FULL];
	unsigned char bracket_open[FULL];
	unsigned char bracket_close[FULL];
	//Указатель на вершину стека строки
	int top;
	//Указатель на вершину стека скобок
	int br_o, br_c;
public:
	//Конструктор
	Stack();
	//Добавление элемента
	void Push(unsigned char c);
	//Извлечение элемента
	int Pop();
	void Check_Bracket();
	//Проверка существования элементов в стеке
	bool IsEmpty();
	//Проверка на переполнение стека
	bool IsFull();
	//Количество элементов в стеке
	int GetCount();
};
=========================
