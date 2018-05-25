#include <iostream>
#include <windows.h>

using namespace std;

class drobi
{
	int chis;
	int znam;
	
public:
	drobi(int a, int b)
	{
		chis = a;
		znam = b;
	}
	void show() 
	{
		if (znam == 1)cout << chis << endl;
		else
		   cout << chis << "/" << znam<<endl;
	}
	void redux() {
		int num = 1;
		while (num <= chis && num <= znam) {
			if (chis%num == 0 && znam%num == 0) {
				chis /= num;
				znam /= num;
				num = 1;
			}
			num++;
		}
	}
	void sum(int chis1, int znam1) {
		if (znam == znam1) {
			chis += chis1;
		}
		else {
			chis = chis * znam1 + znam * chis1;
			znam *= znam1;
		}
		redux();
	}
	void minus(int chis1, int znam1) {
		if (znam == znam1) {
			chis -= chis1;
		}
		else {
			chis = chis * znam1 - znam * chis1;
			znam *= znam1;
		}
		redux();
	}
	void umnoj(int chis1, int znam1)
	{
		chis *= chis1;
		znam *= znam1;
		redux();
	}
	void delen(int chis1,int znam1) {
		chis *= znam1;
		znam *= chis1;
		redux();
	}
};
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int chis, znam, chis1, znam1;
	char menu;
	int num;
	cout << " Введите числитель : ";
	cin >> chis;
	cout << " Введите знаменатель : ";
	do {
		cin >> znam;
		if (znam == 0)cout << " Введите снова , знаменатель не может быть равен нулю . ";
	} while (znam == 0);
	drobi drob(chis, znam);
	do {
		cout << " Текущая дробь : ";
		drob.redux();
		drob.show();
		cout << " 1 - сложение дробей \n";
		cout << " 2 - вычитание дробей \n";
		cout << " 3 - умножение дробей \n";
		cout << " 4 - деление дробей \n";
		cin >> num;
		switch (num) {
		case 1:
			cout << " Введите числитель : ";
			cin >> chis1;
			cout << " Введите знаменатель : ";
			do {
				cin >> znam1;
				if(znam1==0)cout << " Введите снова , знаменатель не может быть равен нулю . ";
			} while (znam1 == 0);
			drob.sum(chis1, znam1);
			cout << " Результат = ";
			drob.show();
			break;
		case 2:
			cout << " Введите числитель : ";
			cin >> chis1;
			cout << " Введите знаменатель : ";
			do {
				cin >> znam1;
				if (znam1 == 0)cout << " Введите снова , знаменатель не может быть равен нулю . ";
			} while (znam1 == 0);
			drob.minus(chis1, znam1);
			cout << " Результат = ";
			drob.show();
			break;
		case 3:
			cout << " Введите числитель : ";
			cin >> chis1;
			cout << " Введите знаменатель : ";
			do {
				cin >> znam1;
				if (znam1 == 0)cout << " Введите снова , знаменатель не может быть равен нулю . ";
			} while (znam1 == 0);
			drob.umnoj(chis1, znam1);
			cout << " Результат = ";
			drob.show();
			break;
		case 4:
			cout << " Введите числитель : ";
			cin >> chis1;
			cout << " Введите знаменатель : ";
			do {
				cin >> znam1;
				if (znam1 == 0)cout << " Введите снова , знаменатель не может быть равен нулю . ";
			} while (znam1 == 0);
			drob.delen(chis1, znam1);
			cout << " Результат = ";
			drob.show();
			break;
		};
		cout << " Продолжить : y/n ";
		cin >> menu;
	} while (menu != 'n');
	system("pause");
}





=============================================
	#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>
//сделать поиск по фамилии имени отчеству и по телефону (какому)
//исправить ошибку с обработкой файла
//если данных нет, то при записи в файл писать что данных нет
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

	char* name_delete;
	char* otch_delete;
	char* fam_delete;

	fam_delete = new char[100];
	name_delete = new char[100];
	otch_delete = new char[100];

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
		cout << "3. Найти клиента\n";
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
			char* firstname;
			char* name;
			char* secondname;
			firstname = new char[100];
			name = new char[100];
			secondname = new char[100];
			cout << " Введите фамилию : ";
			cin >> firstname;
			cout << " Введите имя : ";
			cin >> name;
			cout << " Введите отчество : ";
			cin >> secondname;
			for (i = 0; i < kol_zap; i++) {
				if (!strcmp(P_ZAP_KNIGA_A[i].fio.fam, firstname)&& !strcmp(P_ZAP_KNIGA_A[i].fio.name, name)&& !strcmp(P_ZAP_KNIGA_A[i].fio.otch, secondname)) {
					P_ZAP_KNIGA_A[i].Show();
				}
			}
			system("pause");
			break;
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
	system("pause");
	return 0;
}
