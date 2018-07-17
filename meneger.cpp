#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

const int size_1 = 255;

//Функция, которая убирает лишние слеши и пробелы справа
void RemoveRSpacesAndRSlashes(char* str)
{
	int index = strlen(str) - 1;
	while (str[index] == '\\' || str[index] == ' ')
	{
		index--;
	}
	//копирование строк c ограничением длины,strncpy(destination,source,n);
	//destination – указатель на строку в которую будут скопированы данные.
	//source – указатель на строку источник копируемых данных.
	// n–ограничение длинны копирования
	strncpy(str, str, index);
	str[index + 1] = '\0';
}

//Функция для показа текущей директории
void ShowCurrentDir(char path[], char temp[])
{
	strcat(temp, path);
	printf("%s>", temp);
}
void RenameFile()
{
	char oldName[50], newName[50];
	//В oldName запомним существующее имя
	cout << "Введите существующее наименование файла:";
	cin >> oldName;
	//В newName запомним  новое имя
	cout << "Введите новое наименование файла:";
	cin >> newName;
	//Произведем переименование и проверку результата
	if (rename(oldName, newName) != 0)
		cout << "Ошибка!!! Не удалось переименовать файл. Проверьте правильность ввода наименований файла...\n\n";
	else
		cout << "Ok...\n\n";
}
void RemoveFile()
{
	char Name[50];
	//Получаем имя и путь к удаляемому файлу
	cout << "Введите существующее наименование файла:";
	cin >> Name;
	//Удаляем файл и проверяем результат
	if (remove(Name) != 0)
		cout << "Ошибка!!! Не удалось удалить файл. Проверьте правильность ввода наименования файла..\n";
	else
		cout << "Ok...\n";
}
void RenameDirectory()
{
	char oldName[50], newName[50];
	//В одной переменной запомним
	//существующее имя (oldName),
	cout << "Введите существующее наименование директория:";
	cin >> oldName;
	//А в другой новое имя(newName)
	cout << "Введите новое наименование директория:";
	cin >> newName;
	//Произведем переименование и проверку результата
	if (rename(oldName, newName) != 0)
		cout << "Ошибка!!! Не удалось переименовать директорий.\n\n";
	else
		cout << "Ok...\n\n";
}

//Показ на экран содержимого папки
bool ShowDir(char path[])
{
	//Показ содержимого текущей директории
	_finddata_t find;
	char pathfind[MAX_PATH];
	strcpy(pathfind, path);
	strcat(pathfind, "\\*.*");
	char info[MAX_PATH];
	//Начало Поиска
	int result = _findfirst(pathfind, &find);
	//Очистка экрана
	system("cls");
	int flag = result;
	if (flag == -1)
	{
		strcpy(info, "Такой Директории Нет");
		printf("%s\n", info);
		return false;
	}
	while (flag != -1)
	{
		if (strcmp(find.name, ".") && strcmp(find.name, ".."))
		{
			//Проверяем Директория это или Нет
			find.attrib&_A_SUBDIR ? strcpy(info, " Каталог ") :
				strcpy(info, " Файл ");
			printf("%30s %10s\n", find.name, info);
		}
		//Продолжаем Поиск
		flag = _findnext(result, &find);
	}
	ShowCurrentDir(path, info);
	//Очищаем ресурсы, выделенные под поиск
	_findclose(result);
	return true;
}
void CopyFile()
{

}
void main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu = 0;
	char info[MAX_PATH];
	//В данной переменной будет храниться
	//путь к Директории
	char path[MAX_PATH];
	//В данной переменной будет команда, введенная
	//пользователем
	char action[size_1];
	//Временная переменная
	char temp[MAX_PATH];
	//Получаем Путь к текущей Директории
	GetCurrentDirectoryA(sizeof(path), path);
	bool flag = true;
	//Показ содержимого текущей директории
	ShowDir(path);
	do
	{
		cout << " \n 1 - вывод каталого-файловой структуры диска\n";
		cout << " 2 - переименование файлов\n";
		cout << " 3 - переименование каталогов\n";
		cout << " 4 - удаление файлов\n";
		cout << " 5 - удаление каталогов\n";
		cout << " 6 - копирование файлов\n";
		cout << " ===> ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << " Введите диск : ";
			cin.ignore();
			//Ввод команды пользователя
			gets_s(action, size_1);
			//Убираем пробелы и слэши справа
			RemoveRSpacesAndRSlashes(action);
			//Переход в корневой каталог
			//if (!strcmpi(action, "root"))
			//{
				path[2] = '\0';
				ShowDir(action);
			//}
			//Проверка на желание пользователя выйти
			/*else
				if (!strcmpi(action, "exit"))
				{
					flag = false;
				}
			//Проверка на команду cd
				else
					//Функция strnicmp() осуществляет лексикографическое сравнение не более чем count символов из двух строк,
					//она не делает различия между буквами верхнего и нижнего регистров.
					if (!strnicmp(action, "cd", 2))
					{
						//Показ содержимого текущей директории
						if ((!strcmpi(action, "cd")))
						{
							//Показ Директории
							ShowDir(path);
						}
						//Команда cd была дана с параметрами
						else
							if (!strnicmp(action, "cd ", 3))
							{
								//Находим индекс параметра
								//функция size_t strspn(const char* str,const char* sym)
								//осуществляет определение максимальной длины участка строки,
								//содержащего только указанные символы.
								//str – указатель на строку, в которой ведется поиск.
								//sym – указатель на строку с набором символов, которые должны входить в участок строки str.
								//Возвращаемое значение: длина начального участка строки, содержащая только символы, указанные в аргументе sym.
								int index = strspn(action + 2, " ");
								if (index)
								{
									//Проверка на полный путь к Директории
									if (strchr(action + index + 2, ':'))
									{
										//Попытка отобразить содержимое
										//Директории
										if (ShowDir(action + index + 2))
										{
											strcpy(path, action + index + 2);
										}
										else
										{
											//Произошла Ошибка
											ShowCurrentDir(path, temp);
										}
									}
									//Поднимаемся в родительский каталог
									else
										if (!strcmp(action + index + 2, ".."))
										{
											char* result = strrchr(path, '\\');
											if (result)
											{
												int delta = result - path;
												strncpy(temp, path, delta);
												temp[delta] = '\0';
											}
											else
											{
												strcpy(temp, path);
											}
											if (ShowDir(temp))
											{
												strcpy(path, temp);
											}
											else
											{
												//Произошла Ошибка
												ShowCurrentDir(path, temp);
											}
										}
									//Показ Директории
										else
											if (!strcmp(action + index + 2, "."))
											{
												ShowDir(path);
											}
											else
												if (!strcmp(action + index + 2, "/"))
												{
													ShowDir(path);
												}
												else
												{
													//Был Дан неполный путь
													strcpy(temp, path);
													strcat(temp, "\\");
													strcat(temp, action + index + 2);
													//Попытка отобразить содержимое
													//Директории
													if (ShowDir(temp))
													{
														strcpy(path, temp);
													}
													else
													{
														//Произошла Ошибка
														ShowCurrentDir(path, temp);
													}
												}
								}
								else
								{
									//Показ Директории
									ShowDir(path);
								}
							}
							else
							{
								//Показ Директории
								ShowDir(path);
							}
					}
					else
					{
						strcpy(info, "Такой команды программа не предусматривает. Для продолжения - любая клавиша.");
						printf("%s\n", info);
						getch();
						//Показ Директории
						ShowDir(path);
					}*/
			break;
		case 2:
			RenameFile();
			break;
		case 3:
			RenameDirectory();
			break;
		case 4:
			RemoveFile();
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			cout << " Неверно выбрано меню \n";
			system("pause");
		}
	} while (flag);
	system("pause");
}
