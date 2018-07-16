#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>

using namespace std;

//Функция копирования файла
bool CopyFile(char* source, char* destination)
{
	const int size = 65536;
	FILE* src=NULL;
	FILE* dest=NULL;
	FILE* tmp = NULL;
	int realsize;
	if (strcmp(source, destination) == 0)
	{
		if (!(src = fopen(source, "rb")))
		{
			return false;
		}
		char* data = new char[size];
		if (!data)
			return false;
		if (!(tmp = fopen(destination, "wb")))
		{
			delete[]data;
			return false;
		}
		while (!feof(src))
		{
			realsize = fread(data, sizeof(char), size, src);
			fwrite(data, sizeof(char), realsize, tmp);
		}
		fclose(src);
		fclose(tmp);
		while (!feof(tmp))
		{
			realsize = fread(data, sizeof(char), size, tmp);
			fwrite(data, sizeof(char), realsize, src);
		}
		fclose(tmp);
		fclose(src);
		return true;
	}
	else
	{
		if (!(src = fopen(source, "rb")))
			return false;
		//выделение памяти под буффер
		char* data = new char[size];
		if (!data)
			return false;
		//Открытие файла, куда будет производиться копирование
		if (!(dest = fopen(destination, "wb")))
		{
			delete[]data;
			return false;
		}
		while (!feof(src))
		{
			//Чтение данных из файла
			realsize = fread(data, sizeof(char), size, src);
			//Запись данных в файл
			fwrite(data, sizeof(char), realsize, dest);
		}
		//Закрытие файлов
		fclose(src);
		fclose(dest);
		return true;
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	//_MAX_PATH - Константа, определяющая
	//максимальный размер пути.
	//Даная константа содержится в stdlib.h

	char source[_MAX_PATH];
	char destination[_MAX_PATH];
	char answer[20];

	cout << "\nВведите путь к копируемому файлу и его наименование : \n";
	//Получение пути к первому файлу
	cin.getline(source, _MAX_PATH);
	//Проверка Существует ли файл
	if (_access(source, 0) == -1)
	{
		cout << "\nУказан неверный путь или наименование файла\n";
		system("pause");
		return;
	}
	cout << "\nВведите путь к новому файлу и его наименование:\n";
	//Получение пути к второму файлу
	cin.getline(destination, _MAX_PATH);
	//Проверка на существование файла
	if (_access(destination, 0) == 0)
	{
		cout << "\nТакой Файл уже существует перезаписать его(1-Да/2-Нет)?\n";
		cin.getline(answer, 20);
		if (!strcmp(answer, "2"))
		{
			cout << "\nОперация отменена\n";
			system("pause");
			return;
		}
		else
			if (strcmp(answer, "1"))
			{
				cout << "\nНеправильный ввод\n";
				system("pause");
				return;
			}
		if (_access(destination, 2) == -1)
		{
			cout << "\nНет доступа к новому файлу.\n";
			system("pause");
			return;
		}
	}
	//Копирование файла
	if (!CopyFile(source, destination))
		cout << "\nОшибка при работе	с файлами при копировании\n";
	system("pause");
}
===================================================================
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#include <sys\locking.h>
#include <string.h>
#include <ctype.h>

using namespace std;

//Максимальная длина слова
#define MAX_WORD_LENGTH 21
//Количество попыток
int Tries = 10;
//Количество угаданных слов
int CountWords = 0;
//Загрузка слова
bool LoadWord(FILE* fie, char* word)
{
	int i = 0;
	char s[MAX_WORD_LENGTH] = { 0 };
	//Количество слов в файле
	static int count = -1;
	if (count == -1)
	{
		//Подсчет количества слов
		while (!feof(fie))
		{
			fgets(s, MAX_WORD_LENGTH, fie);
			count++;
		}
		//Слов нет?
		if (count == 0)
			return false;
		//Возврат головки чтения-записи в начало файла
		fseek(fie, 0, 0);
	}
	//Случайное слово
	int n = rand() % count;
	//Поиск слова
	while (i <= n)
	{
		fgets(s, MAX_WORD_LENGTH, fie);
		i++;
	}
	//Определяем длину слова
	int wordlen = strlen(s);
	//Минимальная длина слова 2 буквы
	if (wordlen <= 1)
		return false;
	//Убираем Enter (2 байта 13 10)
	if (s[wordlen - 1] == 10)
		s[wordlen - 2] = 0;
	else
		if (s[wordlen - 1] == 13)
			s[wordlen - 1] = 0;
	//Копируем слово
	strcpy(word, s);
	//Получаем дескриптор файла
	int hFile = _fileno(fie);
	//Вычисляем размер файла
	int size = _filelength(hFile);
	//Блокировка файла
	fseek(fie, 0, 0);
	_locking(hFile, _LK_NBLCK, size);
	return true;
}

//Игра
void Game(char* word)
{
	//Перевод в большие буквы
	_strupr(word);
	int len = strlen(word);
	//Строка-копия
	char* copy = new char[len + 1];
	memset(copy, '*', len);
	copy[len] = 0;
	//Алфавит + пробелы
	char letters[52];
	int i, j = 0;
	for (i = 0; i<26; i++)
	{
		letters[j++] = i + 'A';
		letters[j++] = ' ';
	}
	//Замыкающий ноль
	letters[51] = 0;
	//Буква
	char letter;
	char* pos;
	bool replace = false;
	do
	{
		//Очистка экрана
		system("cls");
		cout << copy << endl << endl;
		cout << letters << endl << endl;
		cout << "Count of tries: " << Tries << endl
			<< endl;
		cout << "Input any letter:\t";
		cin >> letter;
		//Звуковой сигнал
		Beep(500, 200);
		//if(letter >= 'A' && letter <= 'Z'
		//|| letter >= 'a' && letter <= 'z')
		//Буква?
		if (!isalpha(letter))
		{
			cout << "It's not a letter" << endl;
			//Задержка на 1 секунду
			Sleep(1000);
			continue;
		}
		//Перевод буквы в большую
		letter = toupper(letter);
		//Поиск буквы в алфавите
		pos = strchr(letters, letter);
		//Такая буква уже была
		if (pos == 0)
		{
			cout << "This letter have been already pressed" << endl;
			Sleep(1000);
			continue;
		}
		else
		{
			//Убираем букву из алфавита
			pos[0] = ' ';
		}
		//Поиск буквы в слове
		for (i = 0; i<len; i++)
		{
			if (word[i] == letter)
			{
				copy[i] = letter;
				replace = true;
			}
		}
		if (replace == false)
			Tries--;
		else
			replace = false;
		//Условие победы
		if (strcmp(word, copy) == 0)
		{
			system("cls");
			cout << copy << endl << endl;
			cout << letters << endl << endl;
			cout << "Count of tries: " << Tries <<
				endl << endl;
			cout << "Congratulation !!!" << endl;
			CountWords++;
			break;
		}
	} while (Tries != 0);
	delete[]copy;
}

void main()
{
	//Открываем файл на чтение в двоичном режиме
	FILE* f = fopen("words.txt", "rb");
	//Если файл не открылся
	if (f == 0)
	{
		//Ошибка
		perror("Open");
		return;
	}
	srand(time(0));
	char Word[20];
	//Пытаемся загрузить слово
	if (!LoadWord(f, Word))
	{
		//Если неудачно
		cout << "Error !!!" << endl;
		fclose(f);
		return;
	}
	char answer;
	//Играем, пока не надоест
	do
	{
		Game(Word);
		//Если попыток не осталось, то выход
		if (Tries == 0)
		{
			cout << "Count of words: " << CountWords << endl;
			cout << "Bye-bye" << endl;
			break;
		}
		//Если остались
		cout << "Continue ??? (Y/N)\t";
		cin >> answer;
		//Еще играем?
		if (answer == 'Y' || answer == 'y')
			if (!LoadWord(f, Word))
			{
				cout << "Error !!!" << endl;
				fclose(f);
				return;
			}
	} while (answer == 'Y' || answer == 'y');
	//получаем дескриптор
	int hFile = _fileno(f);
	//Разблокировка файла
	int size = _filelength(hFile);
	fseek(f, 0, 0);
	_locking(hFile, _LK_UNLCK, size);
	fclose(f);
}
===============================================
