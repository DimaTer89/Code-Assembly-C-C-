/*Создайте класс Array .
Класс Array - это класс динамического массива.
Размер массива может быть передан в качестве параметра или задан с помощью вызова функции-члена. Класс должен позволять заполнять массив значениями, отображать содержимое массива, изменять
размер массива, сортировать массив, определять минимальное и максимальное значение. Класс должен содержать набор конструкторов (конструктор копирования обязателен), деструктор.*/
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
template <class X>
class Array
{

public:
	X * arr;
	int size;
	Array()
	{
		size = 0;
		arr = new X[size];
	}
	Array(const Array& obj)
	{
		size = obj.size;
		arr = new X[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	~Array()
	{
		delete[]arr;
		arr = NULL;
	}
	void init(int n);
	void put_arr();
	void put_rand_arr();
	void show();
	void sort();
	void arr_change(int num);
	X maxElem();
	X minElem();
};

template <class X> void Array<X>::init(int n)
{
	size = n;
	arr = new X[size];
}
template <class X> void Array<X>::put_arr()
{
	int i;
	for (i = 0; i < size; i++)
	{
		system("cls");
		cout << " Введите " << i + 1 << " элемент массива : ";
		cin >> arr[i];
	}
}
template <class X> void Array<X>::put_rand_arr()
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 51 - 50;
	}
}
template <class X> void Array<X>::show()
{
	int i;
	cout << " Массив : ";
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
template <class X> void Array<X>::sort()
{
	int i;
	int k;
	for (k = size - 1; k > 0; k--)
	{
		for (i = 0; i < k; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				X tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
}
template <class X> void Array<X>::arr_change(int num)
{
	int i;
	if (num < size)
	{
		X* arr_new = new X[num];
		for (i = 0; i < num; i++)
		{
			arr_new[i] = arr[i];
		}
		delete[]arr;
		arr = arr_new;
		size = num;
	}
	if (num > size)
	{
		X* arr_new = new X[num];
		for (i = 0; i < num; i++)
		{
			arr_new[i] = arr[i];
		}
		for (i = size; i < num; i++)
		{
			arr_new[i] = rand() % 51 - 50;
		}
		delete[]arr;
		arr = arr_new;
		size = num;
	}
}
template <class X> X Array<X>::maxElem()
{
	X max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
template <class X> X Array<X>::minElem()
{
	X min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int menu;
	int choice;
	int size;
	int mas;
	int num;
	int change;
	Array<int>arr;
	Array<double>arr1;
	Array<char>arr2;
	bool flag = false;
	do
	{
		cout << " 1 - массив со значениями типа int \n";
		cout << " 2 - массив со значениями типа double \n";
		cout << " 3 - массив со значениями типа char \n";
		cout << " Ваш выбор : ";
		cin >> choice;
		if (choice < 1 || choice>3)cout << " Ошибка !!! \n";
	} while (choice < 1 || choice>3);
	
	do
	{
		system("cls");
		cout << " 1 - заполнить массив \n";
		cout << " 2 - отображать содержимое массива \n";
		cout << " 3 - изменить размер массива \n";
		cout << " 4 - сортировать массив\n";
		cout << " 5 - определить минимальное и максимальное значение.\n";
		cout << " 0 - выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			char key;
			cout << " Заполнить массив автоматически - y\n";
			cout << " Заполнить массив лично - n\n";
			cout << " Ваш выбор : ";
			cin >> key;
			if(key=='y')
			{
				if (choice == 1)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr.init(size);
					arr.put_rand_arr();
					flag = true;
					break;
				}
				if (choice == 2)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr1.init(size);
					arr1.put_rand_arr();
					flag = true;
					break;
				}
				if (choice == 3)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr2.init(size);
					arr2.put_rand_arr();
					flag = true;
					break;
				}
				break;
			}
			if (key == 'n')
			{
				if (choice == 1)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr.init(size);
					arr.put_arr();
					flag = true;
					break;
				}
				if (choice == 2)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr1.init(size);
					arr1.put_arr();
					flag = true;
					break;
				}
				if (choice == 3)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr2.init(size);
					arr2.put_arr();
					flag = true;
					break;
				}
				break;
			}
		case 2:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			if (choice == 1)
			{
				arr.show();
				system("pause");
				break;
			}
			if (choice == 2)
			{
				arr1.show();
				system("pause");
				break;
			}
			if (choice == 3)
			{
				arr2.show();
				system("pause");
				break;
			}
		case 3:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			cout << " Введите размер массива : ";
			cin >> num;
			cout << " 1 - Создать новый массив\n";
			cout<< " 2 - Изменения массива с сохранением значений \n ";
			cout << " Ваш выбор : ";
			cin >> change;
			if (change == 1)
			{
				char key;
				cout << " Заполнить массив автоматически - y\n";
				cout << " Заполнить массив лично - n\n";
				cout << " Ваш выбор : ";
				cin >> key;
				if (key == 'y')
				{
					if (choice == 1)
					{
						arr.init(num);
						arr.put_rand_arr();
						flag = true;
						break;
					}
					if (choice == 2)
					{
						arr1.init(num);
						arr1.put_rand_arr();
						flag = true;
						break;
					}
					if (choice == 3)
					{
						arr2.init(num);
						arr2.put_rand_arr();
						flag = true;
						break;
					}
					break;
				}
				if (key == 'n')
				{
					if (choice == 1)
					{
						arr.init(num);
						arr.put_arr();
						flag = true;
						break;
					}
					if (choice == 2)
					{
						arr1.init(num);
						arr1.put_arr();
						flag = true;
						break;
					}
					if (choice == 3)
					{
						arr2.init(num);
						arr2.put_arr();
						flag = true;
						break;
					}
					break;
				}
			}
			if (change == 2)
			{
				if (choice == 1)
				{
					arr.arr_change(num);
					break;
				}
				if (choice == 2)
				{
					arr1.arr_change(num);
					break;
				}
				if (choice == 3)
				{
					arr2.arr_change(num);
					break;
				}
			}
		case 4:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			if (choice == 1)
			{
				arr.sort();
				break;
			}
			if (choice == 2)
			{
				arr1.sort();
				break;
			}
			if (choice == 3)
			{
				arr2.sort();
				break;
			}
		case 5:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			cout << " 1 - максимальное значение массива \n";
			cout << " 2 - минимальное значение массива \n";
			cout << " Ваш выбор : ";
			cin >> mas;
			if (mas == 1)
			{
				if (choice == 1)
				{
					cout << " Максимальный элемент массива = " << arr.maxElem() << endl;
					system("pause");
					break;
				}
				if (choice == 2)
				{
					cout << " Максимальный элемент массива = " << arr1.maxElem() << endl;
					system("pause");
					break;
				}
				if (choice == 3)
				{
					cout << " Максимальный элемент массива = " << arr2.maxElem() << endl;
					system("pause");
					break;
				}
			}
			if (mas == 2)
			{
				if (choice == 1)
				{
					cout << " Минимальный элемент массива = " << arr.minElem() << endl;
					system("pause");
					break;
				}
				if (choice == 2)
				{
					cout << " Минимальный элемент массива = " << arr1.minElem() << endl;
					system("pause");
					break;
				}
				if (choice == 3)
				{
					cout << " Минимальный элемент массива = " << arr2.minElem() << endl;
					system("pause");
					break;
				}
			}
		case 0:
			cout << " До свидания \n";
			break;
		default :
			cout << " Ошибка !!! \n";
			system("pause");
		}

	} while (menu != 0);
	system("pause");
}
===========================================================
	/*Создайте класс Array .
Класс Array - это класс динамического массива.
Размер массива может быть передан в качестве параметра или задан с помощью вызова функции-члена. Класс должен позволять заполнять массив значениями, отображать содержимое массива, изменять
размер массива, сортировать массив, определять минимальное и максимальное значение. Класс должен содержать набор конструкторов (конструктор копирования обязателен), деструктор.*/
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

class Array
{

public:
	int* arr;
	int size;
	Array()
	{
		size = 0;
		arr = new int[size];
	}
	Array(const Array& obj)
	{
		size = obj.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	~Array()
	{
		delete[]arr;
		arr = NULL;
	}
	void init(int n);
	void put_arr();
	void put_rand_arr();
	void show();
	void sort();
	void sort1();
	void arr_change(int num,int i);
	int maxElem();
	int minElem();
};

void Array::init(int n)
{
	size = n;
	arr = new int[size];
}
void Array::put_arr()
{
	int i;
	for (i = 0; i < size; i++)
	{
		system("cls");
		cout << " Введите " << i + 1 << " элемент массива : ";
		cin >> arr[i];
	}
}
void Array::put_rand_arr()
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 51 - 50;
	}
}
void Array::show()
{
	int i;
	cout << " Массив : ";
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Array::sort()
{
	int i;
	int k;
	int* tmp = new int[size];
	for (int j = 0; j < size; j++)
	{
		tmp[j] = arr[j];
	}
	for (k = size - 1; k > 0; k--)
	{
		for (i = 0; i < k; i++)
		{
			if (tmp[i] > tmp[i + 1])
			{
				int temp = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = temp;
			}
		}
	}
	cout << " Отсортированный массив \n";
	for (i = 0; i < size; i++)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;
	system("pause");
	delete[]tmp;
}
void Array::sort1()
{
	int i;
	int k;
	int* tmp = new int[size];
	for (int j = 0; j < size; j++)
	{
		tmp[j] = arr[j];
	}
	for (k = size - 1; k > 0; k--)
	{
		for (i = 0; i < k; i++)
		{
			if (tmp[i] < tmp[i + 1])
			{
				int temp = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = temp;
			}
		}
	}
	cout << " Отсортированный массив \n";
	for (i = 0; i < size; i++)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;
	system("pause");
	delete[]tmp;
}
void Array::arr_change(int num,int key)
{
	int i;
	if (num < size)
	{
		int* arr_new = new int[num];
		for (i = 0; i < num; i++)
		{
			arr_new[i] = arr[i];
		}
		delete[]arr;
		arr = arr_new;
		size = num;
	}
	if (num > size&&key==1)
	{
		int* arr_new = new int[num];
		for (i = 0; i < num; i++)
		{
			arr_new[i] = arr[i];
		}
		for (i = size; i < num; i++)
		{
			arr_new[i] = rand() % 51 - 50;
		}
		delete[]arr;
		arr = arr_new;
		size = num;
	}
	else
	{
		int* arr_new = new int[num];
		for (i = 0; i < num; i++)
		{
			arr_new[i] = arr[i];
		}
		for (i = size; i < num; i++)
		{
			cout << " Введите " << i + 1 << " элемент массива : ";
			cin >> arr_new[i];
		}
		delete[]arr;
		arr = arr_new;
		size = num;
	}
}
int Array::maxElem()
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
int Array::minElem()
{
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(0));
	int menu;
	int size;
	int mas;
	int num;
	int change;
	int key = 0;
	Array arr;
	bool flag = false;
	do
	{
		system("cls");
		cout << " 1 - заполнить массив \n";
		cout << " 2 - отображать исходного массива \n";
		cout << " 3 - изменить размер массива \n";
		cout << " 4 - сортировать массив по возрастанию \n";
		cout << " 5 - сортировать массив по убыванию \n";
		cout << " 6 - определить минимальное и максимальное значение.\n";
		cout << " 0 - выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			char key;
			cout << " Заполнить массив автоматически - y\n";
			cout << " Заполнить массив собственноручно - n\n";
			cout << " Ваш выбор : ";
			cin >> key;
			if (key == 'y')
			{
				cout << " Введите размер массива : ";
				cin >> size;
				arr.init(size);
				arr.put_rand_arr();
				flag = true;
				break;
			}
			if (key == 'n')
			{
				
					cout << " Введите размер массива : ";
					cin >> size;
					arr.init(size);
					arr.put_arr();
					flag = true;
					break;
				
			}
		case 2:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			
				arr.show();
				system("pause");
				break;
			
			
		case 3:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			cout << " Введите размер массива : ";
			cin >> num;
			cout << " 1 - Создать новый массив\n";
			cout << " 2 - Изменения массива с сохранением значений \n ";
			cout << " Ваш выбор : ";
			cin >> change;
			if (change == 1)
			{
				char key;
				cout << " Заполнить массив автоматически - y\n";
				cout << " Заполнить массив собственноручно - n\n";
				cout << " Ваш выбор : ";
				cin >> key;
				if (key == 'y')
				{
					
						arr.init(num);
						arr.put_rand_arr();
						flag = true;
						break;
					
				}
				if (key == 'n')
				{
					
						arr.init(num);
						arr.put_arr();
						flag = true;
						break;
					
				}
			}
			if (change == 2)
			{
				if (num > arr.size)
				{
					cout << " 1 - дополнение массива случайными числами \n";
					cout << " 2 - дополнение массива вручную \n";
					cout << " Ваш выбор : ";
					cin >> key;
					arr.arr_change(num, key);
					cout << " Успешно выполнено \n";
					system("pause");
					break;
				}
				else
				{
					arr.arr_change(num, key);
					cout << " Успешно выполнено \n";
					system("pause");
					break;
				}
				
			}
		case 4:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			
				arr.sort();
				break;
		case 5:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}

			arr.sort1();
			break;
		case 6:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			cout << " 1 - максимальное значение массива \n";
			cout << " 2 - минимальное значение массива \n";
			cout << " Ваш выбор : ";
			cin >> mas;
			if (mas == 1)
			{
				
					cout << " Максимальный элемент массива = " << arr.maxElem() << endl;
					system("pause");
					break;
				
			}
			if (mas == 2)
			{
				
					cout << " Минимальный элемент массива = " << arr.minElem() << endl;
					system("pause");
					break;
				
			}
		case 0:
			cout << " До свидания \n";
			break;
		default:
			cout << " Ошибка !!! \n";
			system("pause");
		}

	} while (menu != 0);
	system("pause");
}
