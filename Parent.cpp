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
