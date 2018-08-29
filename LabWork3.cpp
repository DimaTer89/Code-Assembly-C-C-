#include <iostream>
#include <Windows.h>
volatile double* d_arr;
int size_1;
HANDLE hSemafore;
CRITICAL_SECTION cs;
using namespace std;

DWORD WINAPI MyThreadWork(LPVOID)
{
	int sleep;
	
	cout << " Введите время сна : ";
	cin >> sleep;
	for (int i = 0; i < size_1; i++)
	{
		bool flag = false;
		for (int j = i + 1; j < size_1; j++)
		{
			if (d_arr[j] == d_arr[i])
			{
				flag = true;
				for (int k = j; k > i; k--)
				{
					double tmp = d_arr[k];
					d_arr[k] = d_arr[k - 1];
					d_arr[k - 1] = tmp;
				}
			}
		}
		/*if (flag==false)
		{
			for (int l = i; l < size_1; l++)
			{
				double tmp = d_arr[l];
				d_arr[l] = d_arr[l + 1];
				d_arr[l + 1] = tmp;
			}
		}*/
		cout << " В потоке work обработан " << i + 1 << " элемент массива \n";
		ReleaseSemaphore(hSemafore, 1, NULL);
		Sleep(sleep);
	}
	return 0;
}
DWORD WINAPI MyThreadSumElement(LPVOID)
{
	double sum = 0;
	EnterCriticalSection(&cs);
	for (int i = 0; i < size_1; i++)
	{
		sum += d_arr[i];
	}
	LeaveCriticalSection(&cs);
	cout << " Сумма элементов массива = " << sum << endl;
	return 0;
}
int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hThread;
	HANDLE hThread_1;
	DWORD IDThread;
	DWORD IDThread_1;
	InitializeCriticalSection(&cs);
	double elem = 0;
	cout << " Введите размер массива : ";
	cin >> size_1;
	d_arr = new double[size_1];
	cout << " Введите элементы массива \n";
	for (int i = 0; i < size_1; i++)
	{
		cout << " Элемент №  " << i + 1<< " = ";
		cin >> elem;
		d_arr[i]=elem;
	}
	cout << " Размер массива = " << size_1 << endl;
	cout << " Исходный массив \n";
	for (int i = 0; i < size_1; i++)
	{
		cout << d_arr[i] << "   ";
	}
	cout << endl;
	hSemafore = CreateSemaphore(NULL, 0, size_1, NULL);
	if (hSemafore == NULL)
	{
		cout << " Семафор не создан \n";
		system("pause");
		return 1;
	}
	hThread = CreateThread(NULL, 0, MyThreadWork, NULL, 0, &IDThread);
	if (hThread == NULL)
	{
		cout << " Поток не создан \n";
		system("pause");
		return 1;
	}
	hThread_1 = CreateThread(NULL, 0, MyThreadSumElement, NULL, 0, &IDThread_1);
	if (hThread_1 == NULL)
	{
		cout << " Поток не создан \n";
		system("pause");
		return 1;
	}
	EnterCriticalSection(&cs);
	for (int i = 0; i < size_1; i++)
	{
	
		WaitForSingleObject(hSemafore, INFINITE);
		cout << " В потоке main подготовлен элемент " << i + 1 << " : " << d_arr[i] << " " << flush<<endl;
	}
	cout << " Сумма элементов массива начата \n";
	LeaveCriticalSection(&cs);
	WaitForSingleObject(hThread_1, INFINITE);
	CloseHandle(hThread);
	CloseHandle(hSemafore);
	DeleteCriticalSection(&cs);
	system("pause");
	return 1;
}
=============================================================
	#include <iostream>
#include <Windows.h>
volatile double* d_arr;
int size_1;
HANDLE hSemafore;
CRITICAL_SECTION cs;
using namespace std;

DWORD WINAPI MyThreadWork(LPVOID)
{
	int sleep;
	int num1 = 1;
	int num2 = 1;
	double* pair_number;
	double* notPair_number;
	pair_number = new double[num1];
	notPair_number = new double[num2];
	cout << " Введите время сна : ";
	cin >> sleep;
	for (int i = 0; i < size_1; i++)
	{
		for (int j = i + 1; j < size_1; j++)
		{
			if (d_arr[j] == d_arr[i])
			{
				double* tmp = new double[num1];
				for (int k = 0; k < num1; k++)
				{
					tmp[k] = d_arr[k];
				}
				delete[] pair_number;
				pair_number = new double[num1 + 1];
				for (int k = 0; k < num1; k++)
				{
					pair_number[k] = tmp[k];
				}
				delete[] tmp;
			}
			else
			{
				double* tmp = new double[num1];
				for (int k = 0; k < num1; k++)
				{
					tmp[k] = d_arr[k];
				}
				delete[] pair_number;
				notPair_number = new double[num1 + 1];
				for (int k = 0; k < num1; k++)
				{
					notPair_number[k] = tmp[k];
				}
				delete[] tmp;
			}
		}
		cout << " В потоке work обработан " << i + 1 << " элемент массива \n";
		ReleaseSemaphore(hSemafore, 1, NULL);
		Sleep(sleep);
	}
	return 0;
}
DWORD WINAPI MyThreadSumElement(LPVOID)
{
	double sum = 0;
	EnterCriticalSection(&cs);
	for (int i = 0; i < size_1; i++)
	{
		sum += d_arr[i];
	}
	LeaveCriticalSection(&cs);
	cout << " Сумма элементов массива = " << sum << endl;
	return 0;
}
int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hThread;
	HANDLE hThread_1;
	DWORD IDThread;
	DWORD IDThread_1;
	InitializeCriticalSection(&cs);
	double elem = 0;
	cout << " Введите размер массива : ";
	cin >> size_1;
	d_arr = new double[size_1];
	cout << " Введите элементы массива \n";
	for (int i = 0; i < size_1; i++)
	{
		cout << " Элемент №  " << i + 1<< " = ";
		cin >> elem;
		d_arr[i]=elem;
	}
	cout << " Размер массива = " << size_1 << endl;
	cout << " Исходный массив \n";
	for (int i = 0; i < size_1; i++)
	{
		cout << d_arr[i] << "   ";
	}
	cout << endl;
	hSemafore = CreateSemaphore(NULL, 0, size_1, NULL);
	if (hSemafore == NULL)
	{
		cout << " Семафор не создан \n";
		system("pause");
		return 1;
	}
	hThread = CreateThread(NULL, 0, MyThreadWork, NULL, 0, &IDThread);
	if (hThread == NULL)
	{
		cout << " Поток не создан \n";
		system("pause");
		return 1;
	}
	hThread_1 = CreateThread(NULL, 0, MyThreadSumElement, NULL, 0, &IDThread_1);
	if (hThread_1 == NULL)
	{
		cout << " Поток не создан \n";
		system("pause");
		return 1;
	}
	EnterCriticalSection(&cs);
	for (int i = 0; i < size_1; i++)
	{
	
		WaitForSingleObject(hSemafore, INFINITE);
		cout << " В потоке main подготовлен элемент " << i + 1 << " : " << d_arr[i] << " " << flush<<endl;
	}
	cout << " Сумма элементов массива начата \n";
	LeaveCriticalSection(&cs);
	WaitForSingleObject(hThread_1, INFINITE);
	CloseHandle(hThread);
	CloseHandle(hSemafore);
	DeleteCriticalSection(&cs);
	system("pause");
	return 1;
}
=============================================================================================
	
	
	
	#include <iostream>
#include <Windows.h>
volatile double* d_arr;
int size_1;
HANDLE hSemafore;
CRITICAL_SECTION cs;
using namespace std;

DWORD WINAPI MyThreadWork(LPVOID)
{
	int sleep;
	int num1 = 1;
	int num2 = 1;
	double* pair_number;
	double* notPair_number;
	pair_number = new double[num1];
	notPair_number = new double[num2];
	cout << " Введите время сна : ";
	cin >> sleep;
	for (int count = 0; count < size_1; count++)
	{
		for (int i = 0; i < size_1; i++)
		{
			for (int j = i + 1; j < size_1; j++)
			{
				if (d_arr[j] == d_arr[i])
				{
					double* tmp = new double[num1];
					for (int k = 0; k < num1; k++)
					{
						tmp[k] = d_arr[k];
					}
					delete[] pair_number;
					pair_number = new double[num1 + 1];
					for (int k = 0; k < num1; k++)
					{
						pair_number[k] = tmp[k];
					}
					delete[] tmp;
					num1++;
				}
				else
				{
					double* tmp = new double[num2];
					for (int k = 0; k < num2; k++)
					{
						tmp[k] = d_arr[k];
					}
					delete[] notPair_number;
					notPair_number = new double[num2 + 1];
					for (int k = 0; k < num2; k++)
					{
						notPair_number[k] = tmp[k];
					}
					delete[] tmp;
					num2++;
				}
			}
			cout << " В потоке work обработан " << i + 1 << " элемент массива \n";
			ReleaseSemaphore(hSemafore, 1, NULL);
			Sleep(sleep);
		}
	}
	return 0;
}
DWORD WINAPI MyThreadSumElement(LPVOID)
{
	double sum = 0;
	EnterCriticalSection(&cs);
	for (int i = 0; i < size_1; i++)
	{
		sum += d_arr[i];
	}
	LeaveCriticalSection(&cs);
	cout << " Сумма элементов массива = " << sum << endl;
	return 0;
}
int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hThread;
	HANDLE hThread_1;
	DWORD IDThread;
	DWORD IDThread_1;
	InitializeCriticalSection(&cs);
	double elem = 0;
	cout << " Введите размер массива : ";
	cin >> size_1;
	d_arr = new double[size_1];
	cout << " Введите элементы массива \n";
	for (int i = 0; i < size_1; i++)
	{
		cout << " Элемент №  " << i + 1<< " = ";
		cin >> elem;
		d_arr[i]=elem;
	}
	cout << " Размер массива = " << size_1 << endl;
	cout << " Исходный массив \n";
	for (int i = 0; i < size_1; i++)
	{
		cout << d_arr[i] << "   ";
	}
	cout << endl;
	hSemafore = CreateSemaphore(NULL, 0, size_1, NULL);
	if (hSemafore == NULL)
	{
		cout << " Семафор не создан \n";
		system("pause");
		return 1;
	}
	hThread = CreateThread(NULL, 0, MyThreadWork, NULL, 0, &IDThread);
	if (hThread == NULL)
	{
		cout << " Поток не создан \n";
		system("pause");
		return 1;
	}
	hThread_1 = CreateThread(NULL, 0, MyThreadSumElement, NULL, 0, &IDThread_1);
	if (hThread_1 == NULL)
	{
		cout << " Поток не создан \n";
		system("pause");
		return 1;
	}
	EnterCriticalSection(&cs);
	for (int i = 0; i < size_1; i++)
	{
	
		WaitForSingleObject(hSemafore, INFINITE);
		cout << " В потоке main подготовлен элемент " << i + 1 << " : " << d_arr[i] << " " << flush<<endl;
	}
	cout << " Сумма элементов массива начата \n";
	LeaveCriticalSection(&cs);
	WaitForSingleObject(hThread_1, INFINITE);
	CloseHandle(hThread);
	CloseHandle(hSemafore);
	DeleteCriticalSection(&cs);
	system("pause");
	return 1;
}
