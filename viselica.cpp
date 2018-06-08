/*Реализовать виселицу */
#include <iostream>
#include <Windows.h>
#include <time.h>
#define N 256

using namespace std;
class Visel
{
	char* word;
	char sim;
public:
	static int num;
	Visel()
	{
		word = new char('\0');
	}
	Visel(const Visel& ob)
	{
		word = new char[strlen(ob.word) + 1];
		strcpy(word, ob.word);
	}
	~Visel()
	{
		if (word)
		{
			delete word;
		}
		word = NULL;
	}
	char get(char s)
	{
		sim = s;
		return sim;
	}
	void show()
	{
		cout << word << endl;
	}
	void getWord()
	{
		FILE* in;
		char buffer[N];
		int kol = 0;
		struct slovo
		{
			char sl[N];
		};
		if (fopen_s(&in, "data.txt", "r") != NULL)
		{
			cout << " Не удалось открыть файл для чтения \n";
			system("pause");
			exit(0);
		}
		while (fgets(buffer, N, in) != NULL)
		{
			kol++;
		}
		fseek(in, 0L, SEEK_SET);
		slovo* slv = new slovo[kol];
		for (int i = 0; i < kol; i++) {
			fgets(buffer, N, in);
			char* tmp;
			tmp = new char[strlen(buffer) + 1];
			strcpy(tmp, buffer);
			strcpy(slv[i].sl, tmp);
		}
		int i = rand() % 5;
		word = new char[strlen(slv[i].sl) + 1];
		strcpy(word, slv[i].sl);
		delete[]slv;
		fclose(in);
	}
	void play()
	{
		char* name = new char[strlen(word) + 1];
		strcpy(name, word);
		for (int i = 0; i < strlen(name) - 1; i++)
		{
			name[i] = '*';
		}
		char alfavit[] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я','\0' };
		cout << "\n";
		int len = strlen(word) - 1;
		int kol = 0;
		int i;
		while (num > 0 && kol != len)
		{
			system("cls");
			bool flag = false;
			cout << name << endl;
			for (i = 0; i < 33; i++)
			{
				cout << " " << alfavit[i];
			}
			cout << endl;
			cout << " Количество попыток = " << num << endl;
			cout << " Введите букву : ";
			cin >> sim;
			cin.ignore();
			for (i = 0; i < len; i++)
			{
				for (int j = 0; j < 33; j++)
				{
					if (alfavit[j] == sim)
					{
						alfavit[j] = ' ';
					}
				}
				if (word[i] == sim)
				{
					name[i] = sim;
					kol++;
					flag = true;
				}
			}
			if (flag == false)num--;
		}
		if (kol == len)
		{
			system("cls");
			cout << word << endl;
			cout << " Количество попыток = " << num << endl;
			for (i = 0; i < 33; i++)
			{
				cout << " " << alfavit[i];
			}
			cout << endl;
			cout << " Вы выиграли \n";
		}
		if (kol < (len - 1))
		{
			cout << " Вы проиграли \n";
			cout << " Загаданное слово : " << word << endl;
		}
	}
};
int Visel::num = 8;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	Visel ob;
	char key;
	do
	{
		ob.getWord();
		ob.play();
		cout << " Продолжить ? д/н \n";
		cout << " Ваш выбор : ";
		cin >> key;
		cin.ignore();
		if (Visel::num == 0)Visel::num = 8;

	} while (key != 'н');
	system("pause");
}
