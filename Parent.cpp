#include <iostream>
#include <windows.h>
#include <fstream>


using namespace std;

class Parent
{
public:
	int num;              // номер зачётки
	char fam[30];         // фамилия студента
	char first_name[30];  // имя студента 
	char second_name[30]; // отчество студента
	double grade;  	      // средний бал 
	void get_Data();
	void show_Data();
};
void Parent::get_Data()
{
	cout << " Введите номер зачётки : ";
	cin >> num;
	cout << " Введите фамилию : ";
	cin >> fam;
	cout << " Введите имя : ";
	cin >> first_name;
	cout << " Введите отчество : ";
	cin >> second_name;
	cout << " Введите средний балл : ";
	cin >> grade;
}
void Parent::show_Data()
{
	cout << " Введите номер зачётки : "<< num<<endl;
	cout << " Введите фамилию : "<<fam<<endl;
	cout << " Введите имя : "<<first_name<<endl;
	cout << " Введите отчество : "<<second_name<<endl;
	cout << " Введите средний балл : "<<grade<<endl;
}
int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Parent ob;
	ofstream write_file;
	write_file.open("D:\\C+\\Parent\\Release\\group.DAT", ios::binary|ios::out|ios::app);
	char key = 'д';
	while (key == 'д')
	{
		ob.get_Data();
		write_file.write((const char*)&ob, sizeof(Parent));
		cout << " Добавить студента : д/н ";
		cin >> key;
		if (key == 'н')
			break;
	}
	write_file.close();
	system("pause");
	return 0;
}
===================================================
	#include <iostream>
#include <windows.h>
#include <fstream>


using namespace std;

struct emp
{
	int num;              // номер зачётки
	char fam[30];         // фамилия студента
	char first_name[30];  // имя студента 
	char second_name[30]; // отчество студента
	double grade;         // средний бал
	void get_Data();
	void show_Data();
};

void emp::get_Data()
{
	cout << " Введите номер зачётки : ";
	cin >> num;
	cout << " Введите фамилию : ";
	cin >> fam;
	cout << " Введите имя : ";
	cin >> first_name;
	cout << " Введите отчество : ";
	cin >> second_name;
	cout << " Введите средний балл : ";
	cin >> grade;
}
void emp::show_Data()
{
	cout << " Введите номер зачётки : "<< num<<endl;
	cout << " Введите фамилию : "<<fam<<endl;
	cout << " Введите имя : "<<first_name<<endl;
	cout << " Введите отчество : "<<second_name<<endl;
	cout << " Введите средний балл : "<<grade<<endl;
}
int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	emp ob;
	ofstream write_file;
	char num[5];
	char fam[30];
	char first_fam[30];
	char sec_fam[30];
	char grade[4];
	char path[255];
	strcpy(path, "D:\\C+\\Parent\\Release\\group.DAT");
	strcat(path, " -");
	write_file.open("D:\\C+\\Parent\\Release\\group.DAT", ios::binary|ios::out|ios::trunc);
	char key = 'д';
	while (key == 'д')
	{
		ob.get_Data();
		write_file.write((const char*)&ob, sizeof(emp));
		cout << " Добавить студента : д/н ";
		cin >> key;
		if (key == 'н')
			break;
	}
	write_file.close();
	cout << " Введите номер зачётки : ";
	cin >> num;
	strcat(path, num);
	strcat(path, " -");
	cout << " Введите фамилию : ";
	cin >> fam;
	strcat(path, fam);
	strcat(path, " -");
	cout << " Введите имя : ";
	cin >> first_fam;
	strcat(path, first_fam);
	strcat(path, " -");
	cout << " Введите отчество : ";
	cin >> sec_fam;
	strcat(path, sec_fam);
	strcat(path, " -");
	cout << " Введите средний балл : ";
	cin >> grade;
	strcat(path, grade);
	cout << path << endl;
	char lpszCommandLine[255];
	strcpy(lpszCommandLine, path);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	CreateProcess
	(
		NULL,
		(LPWSTR)lpszCommandLine,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
	);
	WaitForSingleObject(pi.hProcess, INFINITE);
	ifstream read_file;
	read_file.open("D:\\C+\\Parent\\Release\\group.DAT", ios::binary);
	if (!read_file.is_open())
	{
		cout << " Не удалось открыть файл \n";
		system("pause");
		return 1;
	}
	while (read_file.read((char*)&ob, sizeof(emp)))
	{
		ob.show_Data();
	}
	system("pause");
	return 0;
}
