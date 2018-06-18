#include <windows.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

struct Elem
{
	int OwnerPoints;   //Очки хозяина
	int OppPoints;     //Очки соперника
	char Match[10];    //Счет
	char Name[50];     //Команда
	char Opponent[50]; //Соперник
	Elem* left;
	Elem* right;
	Elem* parent;
};
class Tree
{
	//корень
	Elem* root;
public:
	Tree();
	~Tree();
	//печать от указанного узла результатов игр
	void Print_Rezultat(Elem* Node);
	//поиск от указанного узла
	Elem* Search(Elem* Node, char* key);
	//min от указанного узла
	Elem* Min(Elem* Node);
	//max от указанного узла
	Elem* Max(Elem* Node);
	//следующий для указанного узла
	Elem* Next(Elem* Node);
	//предыдущий для указанного узла
	Elem* Previous(Elem* Node);
	//вставка узла
	void Insert(Elem* z);
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(Elem* z = 0);
	//получить корень
	Elem* GetRoot();
	void tablica(Elem* Node,char comands[][50],int N);
};

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Del();
}

//Рекурсивный обход дерева для результатов игр
void Tree::Print_Rezultat(Elem* Node)
{
	char tmp_name[50];
	if (Node != 0)
	{
		Print_Rezultat(Node->left);
		if (strcmp(tmp_name, Node->Name)<0)
			system("pause");
		if (strlen(Node->Match))
			strcpy(tmp_name, Node->Name);
		cout << Node->Name << Node->Match << Node->Opponent << endl;
		cout << Node->OwnerPoints << " " << Node->OppPoints << endl;
		Print_Rezultat(Node->right);
	}
}
void Tree::tablica(Elem* Node, char comands[][50], int N)
{
	int point = 0;
	Elem* z=Node;
	for (int i = 0; i < N; i++)
	{
		while (z != 0)
		{
			if (strcmp(Node->Name, comands[i]) < 0)
			{
				z = z->left;
				if (strcmp(z->Name, comands[i]) == 0)
					point += z->OwnerPoints;
			}
			else
			{
				z = z->right;
				if (strcmp(z->Name, comands[i]) == 0)
					point += z->OwnerPoints;
			}
		}
	}
	cout << z->Name << " " << point << endl;
}
Elem* Tree::Search(Elem* Node, char* k)
{
	//Пока есть узлы и ключи не совпадают
	while (Node != 0 && strcmp(k, Node->Name) != 0)
	{
		if (strcmp(k, Node->Name)<0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}

Elem* Tree::Min(Elem* Node)
{
	//Поиск самого "левого" узла
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}

Elem* Tree::Max(Elem* Node)
{
	//Поиск самого "правого" узла
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}

Elem* Tree::Next(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//если есть правый потомок
		if (Node->right != 0)
			return Min(Node->right);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node справа
		while (y != 0 && Node == y->right)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

Elem* Tree::Previous(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//если есть левый потомок
		if (Node->left != 0)
			return Max(Node->left);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node слева
		while (y != 0 && Node == y->left)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

Elem* Tree::GetRoot()
{
	return root;
}

void Tree::Insert(Elem* z)
{
	//потомков нет
	z->left = NULL;
	z->right = NULL;
	Elem* y = NULL;
	Elem* Node = root;
	//поиск места
	while (Node != 0)
	{
		//будущий родитель
		y = Node;
		if (strcmp(z->Name, Node->Name)<0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//заполняем родителя
	z->parent = y;
	if (y == 0) //элемент первый (единственный)
		root = z;
	//чей ключ больше?
	else
		if (strcmp(z->Name, y->Name)<0)
			y->left = z;
		else
			y->right = z;
}

void Tree::Del(Elem* z)
{
	//удаление куста
	if (z != 0)
	{
		Elem* Node;
		Elem* y;
		//не 2 ребенка
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//Удаляется корневой узел?
		if (y->parent == 0)
			root = Node;
		else
			if (y == y->parent->left)
				//слева от родителя?
				y->parent->left = Node;
			else
				//справа от родителя?
				y->parent->right = Node;
		if (y != z)
		{
			//Копирование данных узла
			strcpy(z->Name, y->Name);
			strcpy(z->Opponent, y->Opponent);
			strcpy(z->Match, y->Match);
			z->OppPoints = y->OppPoints;
			z->OwnerPoints = y->OwnerPoints;
		}
		delete y;
	}
	else //удаление всего дерева
		while (root != 0)
			Del(root);
}

//Турнирная таблица
Tree tournament;
void Game(char Commands[][50], int N)
{
	int i, j;
	int p1, p2; //Счет
				//Каждая команда играет с каждой по 2 раза -
				//дома и в гостях
	int k;
	Elem* temp;
	for (k = 0; k<2; k++)
		for (i = 0; i<N - 1; i++)
		{
			for (j = i + 1; j<N; j++)
			{
				temp = new Elem;
				if (k == 0)
				{
					//1 игра
					strcpy(temp->Name, Commands[i]);
					strcpy(temp->Opponent, Commands[j]);
				}
				else
				{
					//2 игра
					strcpy(temp->Name, Commands[j]);
					strcpy(temp->Opponent, Commands[i]);
				}
				p1 = rand() % 6;
				p2 = rand() % 6;
				if (p1>p2)
				{
					temp->OwnerPoints = 3;
					temp->OppPoints = 0;
					
				}
				else
					if (p1 == p2)
					{
						temp->OwnerPoints = 1;
						temp->OppPoints = 1;
						
					}
					else
					{
						temp->OwnerPoints = 0;
						temp->OppPoints = 3;
						
					}
				//Запись счета
				sprintf(temp->Match, " %d : %d ", p1, p2);
				//Добавление записи
				tournament.Insert(temp);
			}
		}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned int)time(0));
	int menu_item_int;
	bool prodolgenie_int = true;
	const int N = 20;
	char Commands[20][50] =
	{
		"Манчестер Сити",
		"Манчестер Юнайтед",
		"Тоттенхэм Хотспур",
		"Ливерпуль",
		"Челси",
		"Арсенал",
		"Бёрнли",
		"Эвертон",
		"Лестер Сити",
		"Ньюкасл Юнайтед",
		"Кристал Пэлас",
		"Борнмут",
		"Вест Хэм Юнайтед",
		"Уотфорд",
		"Брайтон энд Хоув Альбион",
		"Хаддерсфилд Таун",
		"Саутгемптон",
		"Суонси Сити",
		"Сток Сити",
		"Вест Бромвич Альбион"
	};
	//Игра
	Game(Commands, N);
	do
	{
		system("cls");
		cout << "1: Вывод результатов игр команд английского чемпионата по футболу." << endl;
		cout << "2: Вывод турнирной таблицы команд английского чемпионата по футболу." << endl;
		cout << "3: Выход из программы." << endl;
		cout << "Введите требуемый пункт меню: ";
		cin >> menu_item_int;
		switch (menu_item_int)
		{
		case 1:
			tournament.Print_Rezultat(tournament.GetRoot());
			break;
		case 2:
			tournament.tablica(tournament.GetRoot(), Commands, N);
			system("pause");
			break;
		case 3:
			prodolgenie_int = false;
			break;
		}
	} while (prodolgenie_int);
	system("pause");
}

