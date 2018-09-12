#include <stdio.h>
#include <Windows.h>
HANDLE hSemafore_1;
HANDLE hSemafore_2;
volatile int* arr;
int size_1;

DWORD WINAPI MyThreadWork(LPVOID)
{
	int sleep;
	printf(" Введите время сна : ");
	scanf("%d", &sleep);
	for (int i = 0; i < size_1; i++)
	{
		for (int j = size_1 - 1; j > 0; j--)
		{
			for (int k = j; k < size_1; k++)
			{
				if (arr[k] > arr[k + 1])
				{
					int tmp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = tmp;
				}
			}
		}
		printf(" В потоке work подготовлен %d элемент = %d\n", i, arr[i]);
		ReleaseSemaphore(hSemafore_1, 1, NULL);
		Sleep(sleep);
	}
	return 0;
}

DWORD WINAPI MySumElement(LPVOID k)
{
	int sum = 0;
	printf(" Поток SumElement начал суммирование элементов массиво до k \n");
	for (int i = 0; i < (int)k; i++)
	{
		sum += arr[i];
	}
	printf(" Сумма элементов массива до k = %d\n", sum);
	WaitForSingleObject(hSemafore_2, INFINITE);
	return 0;
}

int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hThread_1;
	HANDLE hThread_2;
	DWORD IDThread_1;
	DWORD IDThread_2;
	int k;
	printf(" Введите размер массива : ");
	do
	{
		scanf("%d", &size_1);
		if (size_1 < 5)printf(" Введите размер не меньше 5 \n");
	} while (size_1 < 5);
	for (int i = 0; i < size_1; i++)
	{
		printf(" Введите %d элемент : ",i);
		scanf("%d", &arr[i]);
	}
	printf(" Исходный массив \n");
	for (int i = 0; i < size_1; i++)
	{
		printf(" %d  ", arr[i]);
	}
	printf("\n");
	printf(" Введите число k : ");
	do
	{
		scanf("%d", &k);
		if (k > size_1)printf(" Число k должно быть меньше чем размер массива (%d), введите снова : ", size_1);
	} while (k > size_1);
	hSemafore_1 = CreateSemaphore(NULL, 0, size_1, NULL);
	if (!hSemafore_1)
	{
		printf(" Семафор не создан \n");
		system("pause");
		return 0;
	}
	hSemafore_2 = CreateSemaphore(NULL, 0, k, NULL);
	if (!hSemafore_2)
	{
		printf(" Семафор не создан \n");
		system("pause");
		return 0;
	}
	hThread_1 = CreateThread(NULL, 0, MyThreadWork, NULL, 0, &IDThread_1);
	if (!hThread_1)
	{
		printf(" Поток не создан \n");
		system("pause");
		return 0;
	}
	hThread_2 = CreateThread(NULL, 0, MySumElement, (int*)k, 0, &IDThread_2);
	if (!hThread_2)
	{
		printf(" Поток не создан \n");
		system("pause");
		return 0;
	}
	for (int i = 0; i < size_1; i++)
	{
		if (i = (k - 1))
			ReleaseSemaphore(hSemafore_2, 1, NULL);
		printf(" Поток main подготовил %d элемент = %d \n", i, arr[i]);
		ReleaseSemaphore(hSemafore_1, 1, NULL);
	}
	CloseHandle(hThread_1);
	CloseHandle(hSemafore_1);
	CloseHandle(hThread_2);
	CloseHandle(hSemafore_2);
	return 0;
}
