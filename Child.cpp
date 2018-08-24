#include <iostream>
#include <windows.h>
#include <fstream>


using namespace std;

class Child
{
public:
	int num;              // номер зачётки
	char fam[30];         // фамилия студента
	char first_name[30];  // имя студента 
	char second_name[30]; // отчество студента
	double grade;  	      // средний бал 
	void get_Data();
	void show_Data();
	void change_data(double grade_1);
	void init(Child& ob);
};
void Child::init(Child& ob)
{
	num = ob.num;
	strcpy(fam, ob.fam);
	strcpy(first_name, ob.first_name);
	strcpy(second_name, ob.second_name);
	grade = ob.grade;
}
void Child::get_Data()
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

void Child::show_Data()
{
	cout << " номер зачётки : " << num << endl;
	cout << " фамилию : " << fam << endl;
	cout << " имя : " << first_name << endl;
	cout << " отчество : " << second_name << endl;
	cout << " средний балл : " << grade << endl;
}
void Child::change_data(double grade_1)
{
	grade = grade_1;
}
int main()
{
	system("cls");	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num = 0;
	Child ob;
	Child* ob1;
	ob1 = new Child[1];
	ifstream read_file;
	read_file.open("D:\\C+\\Parent\\Release\\group.DAT", ios::binary | ios::in);
	while (read_file.read((char*)&ob, sizeof(Child)))
	{
		if (num)
		{
			Child* tmp = new Child[num];
			for (int i = 0; i < num; i++)
			{
				tmp[i].num = ob1[i].num;
				strcpy(tmp[i].fam, ob1[i].fam);
				strcpy(tmp[i].first_name, ob1[i].first_name);
				strcpy(tmp[i].second_name, ob1[i].second_name);
				tmp[i].grade = ob1[i].grade;
			}
			delete[] ob1;
			ob1 = new Child[num + 1];
			for (int i = 0; i < num; i++)
			{
				ob1[i].num = tmp[i].num;
				strcpy(ob1[i].fam, tmp[i].fam);
				strcpy(ob1[i].first_name, tmp[i].first_name);
				strcpy(ob1[i].second_name, tmp[i].second_name);
				ob1[i].grade = tmp[i].grade;
			}
			delete[] tmp;
		}
		ob1[num].init(ob);
		num++;
	}
	read_file.close();
	cout << "======================\n";
	for (int i = 0; i < num; i++)
	{
		ob1[i].show_Data();
	}
	for (int i = 0; i < num; i++)
	{
		if (ob1[i].num == 2)
			ob1[i].change_data(9.78);
	}
	cout << "======================\n";
	for (int i = 0; i < num; i++)
	{
		ob1[i].show_Data();
	}
	ofstream write_file;
	write_file.open("D:\\C+\\Parent\\Release\\group.DAT", ios::binary);
	for (int i = 0; i < num; i++)
	{
		write_file.write((const char*)&ob1[i], sizeof(Child));
	}
	write_file.close();
	cout << " Успешно \n";
	ifstream read1_file;
	cout << "======================\n";
	read1_file.open("D:\\C+\\Parent\\Release\\group.DAT", ios::binary | ios::in);
	while (read1_file.read((char*)&ob, sizeof(Child)))
	{
		ob.show_Data();
	}
	read1_file.close();
	system("pause");
	return 0;
}
