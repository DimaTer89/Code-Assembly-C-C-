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
==========================================================
	#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>

#define FILE_NAME "zap_kniga.dat"

using namespace std;

class Zap_Kniga
{
public:
	struct Telephon
	{
		char* dom;
		char* work;
		char* mobil;
	} telephon;
	struct Fio
	{
		char* name;
		char* otch;
		char* fam;
	} fio;
	char* dopolnenie;
	Zap_Kniga()
	{
		telephon.dom = new char[15];
		telephon.work = new char[15];
		telephon.mobil = new char[15];
		fio.fam = new char[100];
		fio.name = new char[100];
		fio.otch = new char[100];
		dopolnenie = new char[100];
	}
	~Zap_Kniga()
	{
		delete[] telephon.dom;
		telephon.dom = NULL;
		delete[] telephon.work;
		telephon.work = NULL;
		delete[] telephon.mobil;
		telephon.mobil = NULL;
		delete[] fio.fam;
		fio.fam = NULL;
		delete[] fio.name;
		fio.name = NULL;
		delete[] fio.otch;
		fio.otch = NULL;
		delete[] dopolnenie;
		dopolnenie = NULL;
	}
	void Show()
	{
		cout << "Фамилия: " << fio.fam << endl;
		cout << "Имя: " << fio.name << endl;
		cout << "Отчество: " << fio.otch << endl;
		cout << "Телефоны:" << endl;
		cout << "Домашний: " << telephon.dom << endl;
		cout << "Рабочий: " << telephon.work << endl;
		cout << "Мобильный: " << telephon.mobil << endl;
		cout << "Домашний адрес: " << dopolnenie << endl;
		cout << "\n";
	}
	void Input_Fio()
	{
		cout << "Данные по ФИО: \n";
		cout << "Фамилия:";
		cin >> fio.fam;
		cout << "Имя :";
		cin >> fio.name;
		cout << "Отчество : ";
		cin >> fio.otch;
	}
	void Input_Telephon()
	{
		cout << "Данные по телефонам: \n";
		cout << "Домашний:";
		cin >> telephon.dom;
		cout << "Рабочий :";
		cin >> telephon.work;
		cout << "Мобильный : ";
		cin >> telephon.mobil;
	}
	void Input_Dopolnenie()
	{
		cin.get();
		cout << "Домашний адрес: \n";
		cin.getline(dopolnenie, 100);
	}
	Zap_Kniga* Remove(Zap_Kniga* P_ZAP_KNIGA_DELETE, int index, int* size_)
	{
		int size_delete;
		size_delete = *size_;
		if (index<0 || index>size_delete - 1)
		{
			cout << "Индекс за границами массива." << endl;
			return NULL;
		}
		Zap_Kniga* tmp;
		tmp = new Zap_Kniga[size_delete];
		for (int i = 0; i<size_delete; i++)
		{
			strcpy(tmp[i].telephon.dom, P_ZAP_KNIGA_DELETE[i].telephon.dom);
			strcpy(tmp[i].telephon.work, P_ZAP_KNIGA_DELETE[i].telephon.work);
			strcpy(tmp[i].telephon.mobil, P_ZAP_KNIGA_DELETE[i].telephon.mobil);
			strcpy(tmp[i].fio.fam, P_ZAP_KNIGA_DELETE[i].fio.fam);
			strcpy(tmp[i].fio.name, P_ZAP_KNIGA_DELETE[i].fio.name);
			strcpy(tmp[i].fio.otch, P_ZAP_KNIGA_DELETE[i].fio.otch);
			strcpy(tmp[i].dopolnenie, P_ZAP_KNIGA_DELETE[i].dopolnenie);
		}
		delete[] P_ZAP_KNIGA_DELETE;
		P_ZAP_KNIGA_DELETE = new Zap_Kniga[size_delete - 1];
		for (int i = 0, j = 0; i<size_delete; i++, j++)
		{
			if (i == index)
				i++;
			strcpy(P_ZAP_KNIGA_DELETE[j].telephon.dom, tmp[i].telephon.dom);
			strcpy(P_ZAP_KNIGA_DELETE[j].telephon.work, tmp[i].telephon.work);
			strcpy(P_ZAP_KNIGA_DELETE[j].telephon.mobil, tmp[i].telephon.mobil);
			strcpy(P_ZAP_KNIGA_DELETE[j].fio.fam, tmp[i].fio.fam);
			strcpy(P_ZAP_KNIGA_DELETE[j].fio.name, tmp[i].fio.name);
			strcpy(P_ZAP_KNIGA_DELETE[j].fio.otch, tmp[i].fio.otch);
			strcpy(P_ZAP_KNIGA_DELETE[j].dopolnenie, tmp[i].dopolnenie);
		}
		(*size_)--;
		size_delete = *size_;
		delete[] tmp;
		return P_ZAP_KNIGA_DELETE;
	}
	int Save(const char* fileName, Zap_Kniga* P_ZAP_KNIGA_SAVE, int size_)
	{
		size_t size_dannye;
		FILE* file = fopen(fileName, "w+b");
		fseek(file, 0, SEEK_SET);
		fwrite(&size_, sizeof(int), 1, file);
		for (int i = 0; i < size_; i++)
		{
			size_dannye = strlen((P_ZAP_KNIGA_SAVE + i)->fio.fam) + 1;
			fwrite(&size_dannye, sizeof(int), 1, file);
			fwrite((P_ZAP_KNIGA_SAVE + i)->fio.fam, sizeof(char), size_dannye, file);
			size_dannye = strlen((P_ZAP_KNIGA_SAVE + i)->fio.name) + 1;
			fwrite(&size_dannye, sizeof(int), 1, file);
			fwrite((P_ZAP_KNIGA_SAVE + i)->fio.name, sizeof(char), size_dannye, file);
			size_dannye = strlen((P_ZAP_KNIGA_SAVE + i)->fio.otch) + 1;
			fwrite(&size_dannye, sizeof(int), 1, file);
			fwrite((P_ZAP_KNIGA_SAVE + i)->fio.otch, sizeof(char), size_dannye, file);
			size_dannye = strlen((P_ZAP_KNIGA_SAVE + i)->telephon.dom) + 1;
			fwrite(&size_dannye, sizeof(int), 1, file);
			fwrite((P_ZAP_KNIGA_SAVE + i)->telephon.dom, sizeof(char), size_dannye, file);
			size_dannye = strlen((P_ZAP_KNIGA_SAVE + i)->telephon.work) + 1;
			fwrite(&size_dannye, sizeof(int), 1, file);
			fwrite((P_ZAP_KNIGA_SAVE + i)->telephon.work, sizeof(char), size_dannye, file);
			size_dannye = strlen((P_ZAP_KNIGA_SAVE + i)->telephon.mobil) + 1;
			fwrite(&size_dannye, sizeof(int), 1, file);
			fwrite((P_ZAP_KNIGA_SAVE + i)->telephon.mobil, sizeof(char), size_dannye, file);
			size_dannye = strlen((P_ZAP_KNIGA_SAVE + i)->dopolnenie) + 1;
			fwrite(&size_dannye, sizeof(int), 1, file);
			fwrite((P_ZAP_KNIGA_SAVE + i)->dopolnenie, sizeof(char), size_dannye, file);
		}
		fclose(file);
		return 1;
	}
	Zap_Kniga* Load(const char* fileName, int* size)
	{
		Zap_Kniga* P_ZAP_KNIGA_LOAD;
		FILE* file = fopen(fileName, "r+b");
		if (!file)
		{
			cout << "ОШИБКА! Файл с именем " << fileName << " не существует." << endl;
			return NULL;
		}
		int size_load;
		size_t size_dannye;
		fseek(file, 0, SEEK_SET);
		fread(&size_load, sizeof(int), 1, file);
		P_ZAP_KNIGA_LOAD = new Zap_Kniga[size_load];
		for (int i = 0; i<size_load; i++)
		{
			fread(&size_dannye, sizeof(int), 1, file);
			fread((P_ZAP_KNIGA_LOAD + i)->fio.fam, sizeof(char), size_dannye, file);
			//strcat((P_ZAP_KNIGA_LOAD+i)->fio.fam,"\0");
			fread(&size_dannye, sizeof(int), 1, file);
			fread((P_ZAP_KNIGA_LOAD + i)->fio.name, sizeof(char), size_dannye, file);
			//strcat((P_ZAP_KNIGA_LOAD+i)->fio.name,"\0");
			fread(&size_dannye, sizeof(int), 1, file);
			fread((P_ZAP_KNIGA_LOAD + i)->fio.otch, sizeof(char), size_dannye, file);
			//strcat((P_ZAP_KNIGA_LOAD+i)->fio.otch,"\0");
			fread(&size_dannye, sizeof(int), 1, file);
			fread((P_ZAP_KNIGA_LOAD + i)->telephon.dom, sizeof(char), size_dannye, file);
			//strcat((P_ZAP_KNIGA_LOAD+i)->telephon.dom,"\0");
			fread(&size_dannye, sizeof(int), 1, file);
			fread((P_ZAP_KNIGA_LOAD + i)->telephon.work, sizeof(char), size_dannye, file);
			//strcat((P_ZAP_KNIGA_LOAD+i)->telephon.work,"\0");
			fread(&size_dannye, sizeof(int), 1, file);
			fread((P_ZAP_KNIGA_LOAD + i)->telephon.mobil, sizeof(char), size_dannye, file);
			//strcat((P_ZAP_KNIGA_LOAD+i)->telephon.mobil,"\0");
			fread(&size_dannye, sizeof(int), 1, file);
			fread((P_ZAP_KNIGA_LOAD + i)->dopolnenie, sizeof(char), size_dannye, file);
			//strcat((P_ZAP_KNIGA_LOAD+i)->dopolnenie,"\0");
		}
		fclose(file);
		*size = size_load;
		return P_ZAP_KNIGA_LOAD;
	}
	void dir_redux(Zap_Kniga*& dir_redux, int ind)
	{
		int menu = 0;
		char fam[64];
		char domtel[30];
		char worktel[30];
		char mobtel[30];
		char adres[64];
		cout << " 1 - Изменить фамилию \n";
		cout << " 2 - Изменить домашний номер \n";
		cout << " 3 - Изменить рабочий номер \n";
		cout << " 4 - Изменить мобильный номер \n";
		cout << " 5 - Изменить адрес \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cin.ignore();
			cout << " Введите фамилию : ";
			gets_s(fam, 64);
			strcpy(dir_redux[ind].fio.fam, fam);
			break;
		case 2:
			cin.ignore();
			cout << " Введите  домашний номер: ";
			gets_s(domtel, 30);
			strcpy(dir_redux[ind].telephon.dom, domtel);
			break;
		case 3:
			cin.ignore();
			cout << " Введите рабочий номер : ";
			gets_s(worktel, 30);
			strcpy(dir_redux[ind].telephon.work, worktel);
			break;
		case 4:
			cin.ignore();
			cout << " Введите мобильный номер : ";
			gets_s(mobtel, 30);
			strcpy(dir_redux[ind].telephon.mobil, mobtel);
			break;
		case 5:
			cin.ignore();
			cout << " Введите адрес : ";
			gets_s(adres, 64);
			strcpy(dir_redux[ind].dopolnenie, adres);
			break;
		default:
			cout << " Ошибка! Введите снова \n";
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	int a = 0;
	int num = 0;
	int key = 0;
	int kol_zap = 0;
	int i;
	int num1 = -1;

	char* name_delete;
	char* otch_delete;
	char* fam_delete;

	char* name;
	char* otch;
	char* fam;

	fam_delete = new char[100];
	name_delete = new char[100];
	otch_delete = new char[100];

	fam = new char[100];
	name = new char[100];
	otch = new char[100];


	Zap_Kniga* P_ZAP_KNIGA_A;
	Zap_Kniga* P_ZAP_KNIGA_A_TMP;

	P_ZAP_KNIGA_A = new Zap_Kniga[1];

	if (!P_ZAP_KNIGA_A)
		exit(0);
	do
	{
		system("cls");
		cout << "1. Добавить клиента\n";
		cout << "2. Удалить клиента\n";
		cout << "3. Редактировать запись\n";
		cout << "4. Показать весь список\n";
		cout << "5. Записать книгу в файл\n";
		cout << "6. Считать книгу из файла\n";
		cout << "7. Выход из программы\n";
		cin >> key;
		while (getchar() != '\n');
		switch (key)
		{
		case 1:
			if (kol_zap)
			{
				P_ZAP_KNIGA_A_TMP = new Zap_Kniga[kol_zap];
				for (i = 0; i<kol_zap; i++)
				{
					strcpy(P_ZAP_KNIGA_A_TMP[i].telephon.dom, P_ZAP_KNIGA_A[i].telephon.dom);
					strcpy(P_ZAP_KNIGA_A_TMP[i].telephon.work, P_ZAP_KNIGA_A[i].telephon.work);
					strcpy(P_ZAP_KNIGA_A_TMP[i].telephon.mobil, P_ZAP_KNIGA_A[i].telephon.mobil);
					strcpy(P_ZAP_KNIGA_A_TMP[i].fio.fam, P_ZAP_KNIGA_A[i].fio.fam);
					strcpy(P_ZAP_KNIGA_A_TMP[i].fio.name, P_ZAP_KNIGA_A[i].fio.name);
					strcpy(P_ZAP_KNIGA_A_TMP[i].fio.otch, P_ZAP_KNIGA_A[i].fio.otch);
					strcpy(P_ZAP_KNIGA_A_TMP[i].dopolnenie, P_ZAP_KNIGA_A[i].dopolnenie);
				}
				delete[]P_ZAP_KNIGA_A;
				P_ZAP_KNIGA_A = new Zap_Kniga[kol_zap + 1];
				for (i = 0; i<kol_zap; i++)
				{
					strcpy(P_ZAP_KNIGA_A[i].telephon.dom, P_ZAP_KNIGA_A_TMP[i].telephon.dom);
					strcpy(P_ZAP_KNIGA_A[i].telephon.work, P_ZAP_KNIGA_A_TMP[i].telephon.work);
					strcpy(P_ZAP_KNIGA_A[i].telephon.mobil, P_ZAP_KNIGA_A_TMP[i].telephon.mobil);
					strcpy(P_ZAP_KNIGA_A[i].fio.fam, P_ZAP_KNIGA_A_TMP[i].fio.fam);
					strcpy(P_ZAP_KNIGA_A[i].fio.name, P_ZAP_KNIGA_A_TMP[i].fio.name);
					strcpy(P_ZAP_KNIGA_A[i].fio.otch, P_ZAP_KNIGA_A_TMP[i].fio.otch);
					strcpy(P_ZAP_KNIGA_A[i].dopolnenie, P_ZAP_KNIGA_A_TMP[i].dopolnenie);
				}
				delete[]P_ZAP_KNIGA_A_TMP;
			}
			P_ZAP_KNIGA_A[kol_zap].Input_Fio();
			P_ZAP_KNIGA_A[kol_zap].Input_Telephon();
			P_ZAP_KNIGA_A[kol_zap].Input_Dopolnenie();
			kol_zap++;
			break;
		case 2:
			cout << "Данные по ФИО для удаления из записной книги: \n";
			cout << "Фамилия:";
			cin >> fam_delete;
			cout << "Имя :";
			cin >> name_delete;
			cout << "Отчество : ";
			cin >> otch_delete;
			for (i = 0; i<kol_zap; i++)
			{
				if (!strcmp(P_ZAP_KNIGA_A[i].fio.fam, fam_delete) && !strcmp(P_ZAP_KNIGA_A[i].fio.name, name_delete) && !strcmp(P_ZAP_KNIGA_A[i].fio.otch, otch_delete))
				{
					num = i;
					break;
				}
			}
			P_ZAP_KNIGA_A = P_ZAP_KNIGA_A->Remove(P_ZAP_KNIGA_A, num, &kol_zap);
			cout << "Для продолжения - <Enter>\n";
			cin.get();
			break;
		case 3:
			cout << " Введите фамилию : ";
			gets_s(fam, 100);
			cout << " Введите имя : ";
			gets_s(name, 100);
			cout << " Введите отчество : ";
			gets_s(otch, 100);
			for (i = 0; i<kol_zap; i++)
			{
				if (strcmp(P_ZAP_KNIGA_A[i].fio.fam, fam)==0 && strcmp(P_ZAP_KNIGA_A[i].fio.name, name)==0 && strcmp(P_ZAP_KNIGA_A[i].fio.otch, otch)==0)
				{
					num1 = i;
					break;
				}
			}
			if (num1 == -1)
			{
				cout << " Клиент отсутствует \n";
				system("pause");
				break;
			}
			else
			{
				P_ZAP_KNIGA_A->dir_redux(P_ZAP_KNIGA_A, num1);
				break;
			}
		case 4:
			for (i = 0; i<kol_zap; i++)
			{
				P_ZAP_KNIGA_A[i].Show();
				if ((i + 1) % 3 == 0)
				{
					cout << "Для продолжения - <Enter>\n";
					cin.get();
				}
			}
			cout << "Для продолжения - <Enter>\n";
			cin.get();
			break;
		case 5:
			if (P_ZAP_KNIGA_A->Save(FILE_NAME, P_ZAP_KNIGA_A, kol_zap))
				cout << "Файл сохранен успешно." << endl;
			cout << "Для продолжения нажмите <ENTER>\n";
			cin.get();
			break;
		case 6:
			if (P_ZAP_KNIGA_A)
				delete[] P_ZAP_KNIGA_A;
			//P_ZAP_KNIGA_A=new Zap_Kniga[1];
			P_ZAP_KNIGA_A = P_ZAP_KNIGA_A->Load(FILE_NAME, &kol_zap);
			cout << "Файл считан успешно." << endl;
			cout << "Для продолжения нажмите <ENTER>\n";
			cin.get();
			break;
		case 7:
			cout << "До свидания\n";
			break;
		default:
			cout << "Выбран неправильный пункт меню\n";
			break;
		}
	} while (key != 7);
	if (P_ZAP_KNIGA_A)
		delete[] P_ZAP_KNIGA_A;
	return 0;
}
