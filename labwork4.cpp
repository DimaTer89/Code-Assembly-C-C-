/*Ввести одномерный целочисленный массив размерностью N в память ПЭВМ. 
Память под массив выделить используя динамическое создание кучи при помощи системного вызова HeapCreate()и распределения памяти из кучи при помощи функция HеарАllос(). 
Вывести массив на экран по пять элементов в строке. Записать массив в файл. Вывести массив из файла на экран по пять элементов в строке. 
Сформировать новый массив, в который записать старый в обращённой (перевёрнутой форме).
Результат вывести на экран. 
Работу программы построить в виде меню.*/
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hHeap;
	int key = 0;
	int j = 0;
	int* arr = NULL;
	int* arr_1 = NULL;
	int size_memory=4096;
	int size_masiv;
	hHeap = HeapCreate(HEAP_NO_SERIALIZE, size_memory, 0);
	if (!hHeap)
	{
		cout << " Куча не выделилась \n";
		system("pause");
		exit(0);
	}
	do
	{
		cout << " 1 - Заполнить массив \n";
		cout << " 2 - Вывести массив на экран \n";
		cout << " 3 - Записать массив в файл \n";
		cout << " 4 - Вывести массив из файла \n";
		cout << " 5 - Сформировать новый массив, в который записать старый в обращённой (перевёрнутой форме). Результат вывести на экран \n";
		cout << " 6 - Выход\n";
		cin >> key;
		switch (key)
		{
		case 1:
			cout << " Введите размер массива : ";
			cin >> size_masiv;
			arr = (int*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, size_masiv * sizeof(int));
			if (!arr)
			{
				cout << " Память не выделена \n";
				system("pause");
				exit(0);
			}
			cout << " Введите массив : \n";
			for (int i = 0; i < size_masiv; i++)
			{
				cout << " Введите " << i + 1 << " элемент : ";
				cin >> *(arr + i);
			}
			break;
		case 2:
			cout << " Массив \n";
			for (int i = 0; i < size_masiv; i++)
			{
				cout.setf(ios::left);
				cout.width(5);
				cout << *(arr + i) << "   ";
				if ((i + 1) % 5 == 0)
					cout << endl;
			}
			cout << endl;
			system("pause");
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			j = 0;
			arr_1 = (int*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, size_masiv * sizeof(int));
			if (!arr_1)
			{
				cout << " Память не выделена \n";
				system("pause");
				exit(0);
			}
			
			for (int i = size_masiv - 1; i >= 0; i--)
			{
				arr_1[j] = *(arr + i);
				j++;
			}
			cout << " Новый массив \n";
			for (int i = 0; i < size_masiv; i++)
			{
				cout.setf(ios::left);
				cout.width(5);
				cout << *(arr_1 + i) << "   ";
				if ((i + 1) % 5 == 0)
					cout << endl;
			}
			cout << endl;
			system("pause");
			break;
		case 6:
			break;
		default:
			cout << " Данного функции нет в меню\n";
		}

	} while (key != 6);
	system("pause");
	return 0;
}
