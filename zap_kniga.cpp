#include <iostream>
#include <Windows.h>
using namespace std;
#define N 256

class Directory
{
public:
	struct Data
	{
		char* fam;
		char* name;
		char* secname;
		char* houseTel;
		char* workTel;
		char* mobTel;
		char* dopolnenie;
	}data;
	Directory()
	{
		data.fam = new char[30];
		data.name = new char[30];
		data.secname = new char[30];
		data.houseTel = new char[15];
		data.workTel = new char[15];
		data.mobTel = new char[15];
		data.dopolnenie = new char[20];
	}
	~Directory()
	{
		delete[]data.fam;
		data.fam = NULL;
		delete[] data.name;
		data.name = NULL;
		delete[] data.secname;
		data.secname = NULL;
		delete[] data.houseTel;
		data.houseTel = NULL;
		delete[] data.workTel;
		data.workTel = NULL;
		delete[] data.mobTel;
		data.mobTel = NULL;
		delete[] data.dopolnenie;
		data.dopolnenie = NULL;
	}
	void show()
	{
		cout << " Фамилия :" << data.fam << endl;
		cout << " Имя :" << data.name << endl;
		cout << " Отчество :" << data.secname << endl;
		cout << " Домашний телефон :" << data.houseTel << endl;
		cout << " Рабочий телефон :" << data.workTel << endl;
		cout << " Мобильный телефон :" << data.mobTel << endl;
		cout << " Профессия :" << data.dopolnenie << endl;
		cout << "\n\n";
	}
	void init()
	{
		cout << " Фамилия : ";
		cin >> data.fam;
		cout << " Имя : ";
		cin >> data.name;
		cout << " Отчество : ";
		cin >> data.secname;
		cout << " Домашний телефон : ";
		cin >> data.houseTel;
		cout << " Рабочий телефон : ";
		cin >> data.workTel;
		cout << " Мобильный телефон : ";
		cin >> data.mobTel;
		cout << " Профессия : ";
		cin>>data.dopolnenie;
	}
	Directory* dir_delete(Directory* dir_del, int& n,int ind)
	{
		int j;
		int i;
		Directory* tmp = new Directory[n];
		for (i = 0; i < n; i++)
		{
			strcpy(tmp[i].data.fam, dir_del[i].data.fam);
			strcpy(tmp[i].data.name, dir_del[i].data.name);
			strcpy(tmp[i].data.secname, dir_del[i].data.secname);
			strcpy(tmp[i].data.houseTel, dir_del[i].data.houseTel);
			strcpy(tmp[i].data.workTel, dir_del[i].data.workTel);
			strcpy(tmp[i].data.mobTel, dir_del[i].data.mobTel);
			strcpy(tmp[i].data.dopolnenie, dir_del[i].data.dopolnenie);
		}
		delete[]dir_del;
		dir_del = new Directory[n - 1];
		for (i = 0,j=0; i < n; i++,j++) {
			if (i == ind)
				i++;
			strcpy(dir_del[j].data.fam, tmp[i].data.fam);
			strcpy(dir_del[j].data.name, tmp[i].data.name);
			strcpy(dir_del[j].data.secname, tmp[i].data.secname);
			strcpy(dir_del[j].data.houseTel, tmp[i].data.houseTel);
			strcpy(dir_del[j].data.workTel, tmp[i].data.workTel);
			strcpy(dir_del[j].data.mobTel, tmp[i].data.mobTel);
			strcpy(dir_del[j].data.dopolnenie, tmp[i].data.dopolnenie);
		}
		delete[]tmp;
		n--;
		return dir_del;
	}
	void save(Directory* kniga_save, int kol, char* filename,FILE* out)
	{
		for (int i = 0; i < kol; i++)
		{
			fprintf(out, "%s / ", kniga_save[i].data.fam);
			fprintf(out, "%s / ", kniga_save[i].data.name);
			fprintf(out, "%s / ", kniga_save[i].data.secname);
			fprintf(out, "%s / ", kniga_save[i].data.houseTel);
			fprintf(out, "%s / ", kniga_save[i].data.workTel);
			fprintf(out, "%s / ", kniga_save[i].data.mobTel);
			fprintf(out, "%s \n", kniga_save[i].data.dopolnenie);
			
		}
		fclose(out);
	}
	Directory* kniga_load(FILE* in, Directory* kniga_load, int &kol)
	{
		int i;
		int score = 0;
		char buffer[N];
		char* word;
		char* next;
		Directory* tmp = new Directory[kol];
		for (i = 0; i < kol; i++)
		{
			strcpy(tmp[i].data.fam, kniga_load[i].data.fam);
			strcpy(tmp[i].data.name, kniga_load[i].data.name);
			strcpy(tmp[i].data.secname, kniga_load[i].data.secname);
			strcpy(tmp[i].data.houseTel, kniga_load[i].data.houseTel);
			strcpy(tmp[i].data.workTel, kniga_load[i].data.workTel);
			strcpy(tmp[i].data.mobTel, kniga_load[i].data.mobTel);
			strcpy(tmp[i].data.dopolnenie, kniga_load[i].data.dopolnenie);
		}
		delete[]kniga_load;
		while (fgets(buffer, N, in) != NULL)
		{
			score++;
		}
		fseek(in, 0L, SEEK_SET);
		kniga_load = new Directory[kol+score];
		for (i = 0; i < kol+score; i++)
		{
			if (i < kol)
			{
				strcpy(kniga_load[i].data.fam, tmp[i].data.fam);
				strcpy(kniga_load[i].data.name, tmp[i].data.name);
				strcpy(kniga_load[i].data.secname, tmp[i].data.secname);
				strcpy(kniga_load[i].data.houseTel, tmp[i].data.houseTel);
				strcpy(kniga_load[i].data.workTel, tmp[i].data.workTel);
				strcpy(kniga_load[i].data.mobTel, tmp[i].data.mobTel);
				strcpy(kniga_load[i].data.dopolnenie, tmp[i].data.dopolnenie);
			}
			if(i>=kol)
			{
				fgets(buffer, N, in);
				word = strtok_s(buffer, " / ", &next);
				strcpy(kniga_load[i].data.fam, word);
				word = strtok_s(NULL, " / ", &next);
				strcpy(kniga_load[i].data.name, word);
				word = strtok_s(NULL, " / ", &next);
				strcpy(kniga_load[i].data.secname, word);
				word = strtok_s(NULL, " / ", &next);
				strcpy(kniga_load[i].data.houseTel, word);
				word = strtok_s(NULL, " / ", &next);
				strcpy(kniga_load[i].data.workTel, word);
				word = strtok_s(NULL, " / ", &next);
				strcpy(kniga_load[i].data.mobTel, word);
				word = strtok_s(NULL, " / ", &next);
				strcpy(kniga_load[i].data.dopolnenie, word);
			}
		}
		fclose(in);
		delete[]tmp;
		kol += score;
		return kniga_load;
	}
};
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fam_del[30];
	char name_del[30];
	char otch_del[30];
	char telephone[15];
	char filename[30];
	int kol = 0;
	int key=0;
	int num=0;
	int phone = 0;
	int i;
	FILE* in;
	FILE* out;
	Directory* kniga;
	Directory* kniga_tmp;
	kniga = new Directory[1];
	do
	{
		system("cls");
		cout << " 1 - добавить абонента \n";
		cout << " 2 - удалить абонента \n";
		cout << " 3 - поиск абонента \n";
		cout << " 4 - показать всех абонентов \n";
		cout << " 5 - сохранить абонентов в файл \n";
		cout << " 6 - загрузить абонентов из файла \n";
		cout << " 0 - выход \n";
		cin >> key;
		switch (key)
		{
		case 1:
			if (kol)
			{
				kniga_tmp = new Directory[kol];
				for (i = 0; i < kol; i++)
				{
					strcpy(kniga_tmp[i].data.fam, kniga[i].data.fam);
					strcpy(kniga_tmp[i].data.name, kniga[i].data.name);
					strcpy(kniga_tmp[i].data.secname, kniga[i].data.secname);
					strcpy(kniga_tmp[i].data.houseTel, kniga[i].data.houseTel);
					strcpy(kniga_tmp[i].data.workTel, kniga[i].data.workTel);
					strcpy(kniga_tmp[i].data.mobTel, kniga[i].data.mobTel);
					strcpy(kniga_tmp[i].data.dopolnenie, kniga[i].data.dopolnenie);
				}
				delete[] kniga;
				kniga = new Directory[kol + 1];
				for (i = 0; i < kol; i++) {
					strcpy(kniga[i].data.fam, kniga_tmp[i].data.fam);
					strcpy(kniga[i].data.name, kniga_tmp[i].data.name);
					strcpy(kniga[i].data.secname, kniga_tmp[i].data.secname);
					strcpy(kniga[i].data.houseTel, kniga_tmp[i].data.houseTel);
					strcpy(kniga[i].data.workTel, kniga_tmp[i].data.workTel);
					strcpy(kniga[i].data.mobTel, kniga_tmp[i].data.mobTel);
					strcpy(kniga[i].data.dopolnenie, kniga_tmp[i].data.dopolnenie);
				}
				delete[] kniga_tmp;
			}
			kniga[kol].init();
			kol++;
			break;
		case 2:
			cout << " Введите фамилию абонента : ";
			cin >> fam_del;
			cout << " Введите имя абонента : ";
			cin >> name_del;
			cout << " Введите отчество абонента : ";
			cin >> otch_del;
			for (i = 0; i < kol; i++)
			{
				if (strcmp(kniga[i].data.fam, fam_del) == 0&&strcmp(kniga[i].data.name, name_del) == 0 && strcmp(kniga[i].data.secname, otch_del) == 0)
				{
					num = i;
					break;
				}
			}
			kniga=kniga->dir_delete(kniga, kol, num);
			break;
		case 3:
			cout << " 1 - поиск абонента по ФИО\n";
			cout << " 2 - поиск абонента по домашнему номеру телефона \n";
			cin >> phone;
			switch (phone)
			{
			case 1:
				cout << " Введите фамилию абонента : ";
				cin >> fam_del;
				cout << " Введите имя абонента : ";
				cin >> name_del;
				cout << " Введите отчество абонента : ";
				cin >> otch_del;
				for (i = 0; i < kol; i++)
				{
					if (strcmp(kniga[i].data.fam, fam_del) == 0 && strcmp(kniga[i].data.name, name_del) == 0 && strcmp(kniga[i].data.secname, otch_del) == 0)
					{
						kniga[i].show();
					}
				}
				system("pause");
				break;
			case 2:
				cout << " Введите домашний номер абонента : ";
				cin >> telephone;
				for (i = 0; i < kol; i++)
				{
					if (strcmp(kniga[i].data.houseTel, telephone) == 0)
					{
						kniga[i].show();
					}
				}
				system("pause");
				break;
			}
			break;
		case 4:
			for (i = 0; i < kol; i++)
			{
				kniga[i].show();
			}
			system("pause");
			break;
		case 5:
			cout << " Введите имя файла для записи : ";
			cin >> filename;
			if (fopen_s(&out, filename, "w") != NULL) {
				cout << " Файла с именем " << filename << " не существует \n";
				system("pause");
				break;
			}
			kniga->save(kniga, kol, filename, out);
			break;
		case 6:
			cout << " Введите имя файла для чтения : ";
			cin >> filename;
			if (fopen_s(&in, filename, "r") != NULL)
			{
				cout << " Файла с именем "<<filename<<" не существует \n";
				system("pause");
				break;
			}
			cout << " этого сообщения не должно быть \n";
			kniga = kniga->kniga_load(in, kniga, kol);
			break;
		case 0:
			cout << " До свидания \n";
			break;
		default: cout << " Неверное действие \n ";
		}
	} while (key != 0);
	delete[]kniga;
	system("pause");
}
