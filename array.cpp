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
	void init(int n)
	{
		size = n;
		arr = new int[size];
	}
	void put_arr()
	{
		int i;
		for (i = 0; i < size; i++)
		{
			system("cls");
			cout << " Введите " << i + 1 <<" элемент массива : ";
			cin >> arr[i];
		}
	}
	void put_rand_arr()
	{
		int i;
		for (i = 0; i < size; i++)
		{
			arr[i] = rand() % 51 - 50;
		}
	}
	void show()
	{
		int i;
		cout << " Массив : ";
		for (i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void sort()
	{
		int i;
		int k;
		for (k = size - 1; k > 0; k--)
		{
			for (i = 0; i < k; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					int tmp = arr[i];
					arr[i] = arr[i+1];
					arr[i + 1] = tmp;
				}
			}
		}
	}
	/*void arr_change(Array obj, int& size,int num)
	{
		int i;
		int j;
		int* arr_new=new int[num];
		for (i = 0,j=0; i < num; i++,j++)
		{
			arr_new[j] = arr[i];
		}
		delete[]arr;
		arr = arr_new;
		size = num;
		
	}*/
	int maxElem()
	{
		int max = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > max)max = arr[i];
		}
		return max;
	}
	int minElem()
	{
		int min = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (arr[i] < min)min = arr[i];
		}
		return min;
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	Array obj;
	int size;
	cout << " Введите размер массива : ";
	cin >> size;
	obj.init(size);
	obj.put_rand_arr();
	obj.show();
	cout << " Максимальный элемент массива = " << obj.maxElem() << endl;
	cout << " Минимальный элемент массива = " << obj.minElem() << endl;
	obj.sort();
	obj.show();
	system("pause");
}
