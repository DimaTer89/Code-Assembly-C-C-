#include <iostream>
#include <Windows.h>
 
using namespace std;

int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double* d_arr;
	int size = 0;
	cout << " Введите размер массива : ";
	cin >> size;
	d_arr = new double[size];
	cout << " Введите элементы массива \n";
	for (int i = 0; i < size; i++)
	{
		cout << " Элемент № " << i + 1;
		cin >> d_arr[i];
	}
	cout << " Размер массива = " << size << endl;
	cout << " Исходный массив \n";
	for (int i = 0; i < size; i++)
	{
		cout << d_arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}
