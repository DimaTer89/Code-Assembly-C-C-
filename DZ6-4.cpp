/*Реализовать базу данных ГАИ по штрафным квитан¬циям с помощью бинарного дерева. Ключом будет служить номер автомашины, значением узла – 
список правонарушений. Если квитанция добавляется в первый раз, то в дереве появляется новый узел, а в списке - данные по правонарушению; если нет, то данные заносятся в существующий список. 
Необходимо также реализовать следующие операции:
- Полная распечатка базы данных (по номерам машин и списку правонарушений, 
  числящихся за ними).
- Распечатка данных по заданному номеру.*/
#include<iostream>
#include <Windows.h>

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
	cout << " Нарушения : ";
	offense* tmp = head;
	while (tmp)
	{
		cout<< tmp->wrong << ", ";
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
	void addTree(char* key, char* key2, gai*& root);
	gai*& getRoot();
	void show(gai* elem);
	void del(gai*& elem);
};
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
void treeGai::addTree(char* key,char* key2,gai*& root)
{
	if (root == NULL)
	{
		root = new gai;
		root->numberName =new char[strlen(key)+1];
		strcpy(root->numberName, key);
		root->temp.addList(key2);
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (strcmp(root->numberName,key)<0)
			addTree(key,key2, root->left);
		if (strcmp(root->numberName, key)>0)
			addTree(key, key2,root->right);
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
	char numberName[50];
	char offense[128];
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
			cin.ignore();
			cout << " Введите номер машины : ";
			gets_s(numberName, 50);
			cout << " Введите правонарушение : ";
			gets_s(offense, 128);
			ob.addTree(numberName,offense,ob.getRoot());
			break;
		case 2:
			ob.show(ob.getRoot());
			system("pause");
			break;
		case 3:
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
