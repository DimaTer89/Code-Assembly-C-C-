#include <stdio.h>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	HMODULE hDll;
	void(*flipAnArray)(int*, int);
	hDll = LoadLibrary(L"labwork5.dll");
	if (!hDll)
	{
		printf("Ошибка загрузки библиотеки \n");
		return GetLastError();
	}
	int* arr;
	int size_arr;
	printf(" Введите размер массива : ");
	scanf("%d", &size_arr);
	arr = new int[size_arr];
	printf(" Инициализация массива \n");
	for (int i = 0; i < size_arr; i++)
	{
		printf(" Введите %d элемент массива : ", i + 1);
		scanf("%d", &arr[i]);
	}
	printf(" Инициализация прошла успешно \n");
	printf(" Исходный массив \n");
	for (int i = 0; i < size_arr; i++)
	{
		printf(" %d  ", arr[i]);
	}
	printf("\n");
	flipAnArray = (void(*)(int*, int))GetProcAddress(hDll, "flipAnArray");
	if (!flipAnArray)
	{
		printf(" Ошибка получения адреса функции библиотеки \n");
		system("pause");
		return 1;
	}
	flipAnArray(arr, size_arr);
	printf(" Изменённый массив \n");
	for (int i = 0; i < size_arr; i++)
	{
		printf(" %d  ", arr[i]);
	}
	printf("\n");
	if (!FreeLibrary(hDll))
	{
		printf(" Ошибка закрытия библиотеки \n");
		system("pause");
		return 1;
	}
	system("pause");
	return 0;
}
=================================================
#include <stdio.h>
#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReson, LPVOID lpReserved)
{
	switch (dwReson)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return true;
}

extern "C" _declspec(dllexport) void flipAnArray(int* arr, int size_arr)
{
	int* ptr;
	int* endPtr;
	int tmp;
	ptr = arr;
	endPtr = (arr + size_arr - 1);
	while (ptr < endPtr)
	{
		tmp = *ptr;
		*ptr = *endPtr;
		*endPtr = tmp;
		ptr++;
		endPtr--;
	}
}
================================================
