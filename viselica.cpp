/*Реализовать виселицу */
#include <iostream>
#include <Windows.h>
#include <time.h>

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
		char buffer[256];
		int kol=0;
		struct slovo
		{
			char sl[64];
		};
		if (fopen_s(&in, "data.txt", "r") != NULL)
		{
			cout << " Не удалось открыть файл для чтения \n";
			system("pause");
			return;
		}
		while (fgets(buffer, 256, in) != NULL)
		{
			kol++;
		}
		cout << kol << endl;
		fseek(in, 0L, SEEK_SET);
		slovo* slv = new slovo[kol];
		char *w, *next;
		for (int i = 0; i < kol; i++) {
			fgets(buffer, 256, in);
			w = strtok_s(buffer, "\n", &next);
			strcpy(slv[i].sl, w);
		}
		int i = rand() % 3;
		cout << i << endl;
		word = new char[strlen(slv[i].sl) + 1];
		strcpy(word, slv[i].sl);
	}
	void play()
	{
		char* name = new char[strlen(word) + 1];
		for (int i = 0; i < strlen(word); i++)
		{
			name[i] = '*';
		}
		char alfavit[] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я','\0'};
		cout << "\n";
		int kol = 0;
		int i = 0;
		while (num >= 0&&kol<strlen(word))
		{
			bool flag = false;
			cout << name << endl;
			for (int i = 0; i < 32; i++)
			{
				cout << " " << alfavit[i];
			}
			cout << endl;
			cout << " Количество попыток = " << num << endl;
			cout << " Введите букву : ";
			cin>>sim;
			for (int i = 0; i < strlen(word); i++)
			{
				if (word[i]==sim)
				{
					kol++;
					flag = true;
					name[i] = sim;
				}
			}
			if(flag==false)num--;
		}
		if (kol == strlen(word))cout << " Вы выиграли \n";
		if (kol < strlen(word))cout << " Вы проиграли \n";
	}
};
int Visel::num = 10;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	Visel ob;
	ob.getWord();
	ob.play();
	system("pause");
}
