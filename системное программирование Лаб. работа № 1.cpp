/*Поток main должен выполнить следующие действия:
1. Создать массив целых чисел, размер и элементы которого вводятся с
консоли.
2. Создать поток worker.
(Поток worker должен найти значение суммы нечётных элементов массива и минимального элемента.)
3. Найти минимальный и максимальный элементы массива и вывести их на консоль.
После каждого сравнения элементов «спать» 7 миллисекунд.
4. Дождаться завершения потока worker.
5. Подсчитать количество элементов в массиве, значение которых больше среднего
значения элементов массива, и вывести его на консоль.
6. Завершить работу.*/
#include <Windows.h>
#include <iostream>
volatile int size_1;
volatile int min_1;
using namespace std;

DWORD WINAPI worker(LPVOID *arr)
{
	int sum = 0;
	for (int i = 0; i < size_1; i++)
	{
		Sleep(12);
		if ((int)arr[i] % 2 != 0 && (int)arr[i] != min_1)
			sum += (int)arr[i];
	}
	sum += min_1;
	cout << " Cуммы нечётных элементов массива и минимального элемента =  " << sum << endl;
	return 0;
}
int min_elem(int* arr)
{
	min_1 = arr[0];
	for (int i = 0; i < size_1; i++)
	{
		if (min_1 >(int)arr[i])
		{
			min_1 = (int)arr[i];
		}
		Sleep(7);
	}
	return min_1;
}
int max_elem(int* arr)
{
	int max = arr[0];
	for (int i = 0; i < size_1; i++)
	{
		if (max <(int)arr[i])
		{
			max = arr[i];
		}
		Sleep(7);
	}
	return max;
}
double med_elem(int* arr)
{
	int score = 0;
	double sum = 0;
	for (int i = 0; i < size_1; i++)
	{
		sum += arr[i];
	}
	return (double)sum / size_1;
}
int Count(double elem, int* arr)
{
	int count = 0;
	for (int i = 0; i < size_1; i++)
	{
		if (elem < arr[i])
			count++;
	}
	return count;
}
int main(void)
{
	system("cls");
	int size;
	int* arr;
	HANDLE hThread;
	DWORD IdThread;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " Введите размер массива : ";
	cin >> size;
	size_1 = size;
	arr = new int[size];
	cout << " Заполните массив \n";
	for (int i = 0; i < size_1; i++)
	{
		cout << " Элемент № " << i + 1 << " : ";
		cin >> arr[i];
	}
	system("cls");
	cout << " Вывод массива : ";
	for (int i = 0; i < size_1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)worker, (LPVOID*)arr, 0, &IdThread);
	if (hThread == NULL)
		return GetLastError();
	cout << " Минимальный элемент в массиве = " << min_elem(arr) << endl;
	cout << " Максимальный элемент в массиве = " << max_elem(arr) << endl;
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	cout << " Среднее значение массива = " << med_elem(arr) << endl;
	cout << " Количество элементов больших среднего значения = " << Count(med_elem(arr), arr) << endl;
	system("pause");
	return 0;
}
