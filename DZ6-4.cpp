/*Реализовать базу данных ГАИ по штрафным квитан¬циям с помощью бинарного дерева. Ключом будет служить номер автомашины, значением узла – 
список правонарушений. Если квитанция добавляется в первый раз, то в дереве появляется новый узел, а в списке - данные по правонарушению; если нет, то данные заносятся в существующий список. 
Необходимо также реализовать следующие операции:
- Полная распечатка базы данных (по номерам машин и списку правонарушений, числящихся за ними).
- Распечатка данных по заданному номеру.*/
#include<iostream>
#include <Windows.h>
#define N 256
#define M 32

using namespace std;
struct offense
{
	char* wrong;
	offense* next;
};
class list
{
	offense* head, *tail;
public:
	list()
	{
		head = tail = NULL;
	}
	list(const list& ob)
	{

	}
	~list()
	{
		delList();
	}
	void addList(char* key);
	void show();
	void delList();
};
void list::addList(char* key)
{
	offense* tmp = new offense;
	tmp->wrong = new char[strlen(key) + 1];
	strcpy(tmp->wrong, key);
	tmp->next = NULL;
	if (head != NULL)
	{
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		head = tail = tmp;
	}
}
void list::show()
{
	cout << " Нарушения : \n";
	offense* tmp = head;
	while (tmp)
	{
		cout <<"\t"<<"     "<< tmp->wrong << endl;
		tmp = tmp->next;
	}
	cout << endl;
}
void list::delList()
{
	offense* del;
	while (head)
	{
		del = head->next;
		delete head;
		head = del;
	}
}
struct gai
{
	char* numberName;
	gai* left;
	gai* right;
	list temp;
};
class treeGai
{
	gai* root;
public:
	
	treeGai()
	{
		root = NULL;
	}
	treeGai(const treeGai& ob)
	{

	}
	~treeGai()
	{
		del(root);
	}
	void addTree(char* number, char* wrong, gai*& root);
	gai*& getRoot();
	void show(gai* root);
	void del(gai*& root);
	void search(gai* root,char* number);
};
void treeGai::search(gai* root,char* number)
{
	if (strcmp(root->numberName, number) == 0)
	{
		cout << " Номер автомобиля : " << root->numberName << endl;
		root->temp.show();
	}
	if (strcmp(root->numberName, number) < 0)
	{
		if (root->left == NULL)
			cout << " Автомобиля нет в базе данных \n";
		else
			search(root->left, number);
	}
	if (strcmp(root->numberName, number) > 0)
	{
		if (root->right == NULL)
			cout << " Автомобиля нет в базе данных \n";
		else
			search(root->right, number);
	}
}
void treeGai::del(gai*& root)
{
	if (root != NULL)
	{
		del(root->left);
		del(root->right);
		delete root;
		root = NULL;
	}
}
void treeGai::show(gai* root)
{
	if (root != NULL)
	{
		show(root->left);
		cout << " Номер автомобиля : " << root->numberName << endl;
		root->temp.show();
		show(root->right);
	}
}
void treeGai::addTree(char* number,char* wrong,gai*& root)
{
	if (root == NULL)
	{
		root = new gai;
		root->numberName =new char[strlen(number)+1];
		strcpy(root->numberName, number);
		root->temp.addList(wrong);
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (strcmp(root->numberName, number) < 0)
		{
			addTree(number, wrong, root->left);
			return;
		}
		if (strcmp(root->numberName, number) > 0)
		{
			addTree(number, wrong, root->right);
			return;
		}
		if (strcmp(root->numberName, number) == 0)
			root->temp.addList(wrong);
	}
}
gai*& treeGai::getRoot()
{
	return root;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char numberName[M];
	char offense[N];
	char name[M];
	int menu;
	treeGai ob;
	do
	{
		system("cls");
		cout << " 1 - ввести данные о правонарушении \n";
		cout << " 2 - полная распечатка базы данных \n";
		cout << " 3 - распечатка данных по заданному номеру \n";
		cout << " 0 - выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			cin.ignore();
			cout << " Введите номер автомобиля : ";
			gets_s(numberName, M);
			cout << " Введите правонарушение : ";
			gets_s(offense, N);
			ob.addTree(numberName,offense,ob.getRoot());
			break;
		case 2:
			system("cls");
			cout << " Полная база данных \n";
			ob.show(ob.getRoot());
			system("pause");
			break;
		case 3:
			system("cls");
			cin.ignore();
			cout << " Введите номер автомобиля : ";
			gets_s(name, M);
			ob.search(ob.getRoot(), name);
			system("pause");
			break;
		case 0:
			cout << " До свидания \n";
			system("pause");
			break;
		default:
			cout << " Ошибка, неверно выбрано меню \n";
		}
	} while (menu != 0);
}
