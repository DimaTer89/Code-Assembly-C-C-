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
	HANDLE hHeap = NULL;
	int elem = 0;
	int key = 0;
	int j = 0;
	int* arr = NULL;
	int* arr_1 = NULL;
	int size_masiv;
	int size_memory = 4096;
	FILE* in=NULL, *out=NULL;
	hHeap = HeapCreate(HEAP_NO_SERIALIZE, size_memory, size_memory);
	if (!hHeap)
	{
		cout << " Куча не выделилась \n";
		system("pause");
		exit(0);
	}
	do
	{
		system("cls");
		cout << " 1 - Заполнить массив \n";
		cout << " 2 - Вывести массив на экран \n";
		cout << " 3 - Записать массив в файл \n";
		cout << " 4 - Вывести массив из файла \n";
		cout << " 5 - Сформировать новый массив, в который записать старый в перевёрнутой форме. Результат вывести на экран \n";
		cout << " 6 - Выход\n";
		cout << " ===> ";
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
			if (!arr)
			{
				cout << " Массив не сформирован.\n";
				system("pause");
				break;
			}
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
			if (!arr)
			{
				cout << " Массив не сформирован.\n";
				system("pause");
				break;
			}
			if (!(in = fopen("data.txt", "w")))
			{
				cout << " Не удалось открыть файл \n";
				system("pause");
				break;
			}
			for (int i = 0; i < size_masiv; i++)
			{
				fprintf(in, "%d ", arr[i]);
			}
			fclose(in);
			cout << " Данные успешно записаны \n";
			system("pause");
			break;
		case 4:
			arr = NULL;
			if (size_masiv > 0)
			{
				size_masiv = 0;
			}
			if (!(out = fopen("data.txt", "r")))
			{
				cout << " Не удалось открыть файл \n";
				system("pause");
				break;
			}
			while ((fscanf(out, "%d ", &elem))!=EOF)
			{
				if (!out)
					break;
				size_masiv++;
			}
			fseek(out, 0L, SEEK_SET);
			arr = (int*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, size_masiv * sizeof(int));
			if (!arr)
			{
				cout << " Память не выделена \n";
				system("pause");
				break;
			}
			for (int i = 0; i < size_masiv; i++)
			{
				fscanf(out, "%d ", &arr[i]);
			}
			fclose(out);
			cout << " Данные успешно считаны \n";
			system("pause");
			break;


		case 5:
			if (!arr)
			{
				cout << " Массив не сформирован.\nДля продолжения нажмите Enter...  ";
				system("pause");
				break;
			}
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
			if (!HeapFree(hHeap, NULL, arr_1))
			{
				cout << " Ошибка освобождения памяти \n";
				system("pause");
			}
			system("pause");
			break;
		case 6:
			if (!HeapFree(hHeap, NULL, arr))
			{
				cout << " Ошибка освобождения памяти \n";
				system("pause");
			}
			if (!HeapDestroy(hHeap))
			{
				cout << " Ошибка удаления памяти \n";
				system("pause");
			}
			cout << " До свидания\n";
			system("pause");
			break;
		default:
			cout << " Данного функции нет в меню\n";
		}

	} while (key != 6);
	return 0;
}
