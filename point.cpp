/*Реализуйте класс “Точка”. Необходимо хранить координаты x, y, z в переменных-членах класса.
Реализуйте функции-члены класса для ввода данных, вывода данных, реализуйте сохранение в файл и загрузку данных из файла.*/
#include <iostream>
#include <windows.h>
using namespace std;

class Point
{
	double x;
	double y;
	double z;
public:
	Point(int x = 1, int y = 1, int z = 1)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void get_in()
	{
		cout << " Введите координату x : ";
		cin >> x;
		cout << " Введите координату y : ";
		cin >> y;
		cout << " Введите координату z : ";
		cin >> z;
	}
	void show()
	{
		cout << " Координата x = " << x << endl;
		cout << " Координата y = " << y << endl;
		cout << " Координата z = " << z << endl;
	}
	void save()
	{
		FILE* out;
		if (fopen_s(&out, "point_3d.txt", "w") != NULL)
		{
			cout << " Не удалось открыть файл для записи \n";
			system("pause");
			return;
		}
		fprintf(out, " %.2f / %.2f / %.2f \n", x, y, z);
		fclose(out);
	}
	void load()
	{
		FILE* in;
		char buffer[256];
		if (fopen_s(&in, "point_3dd.txt", "r") != NULL)
		{
			cout << " Не удалось открыть файл чтения \n";
			system("pause");
			return;
		}
		fgets(buffer, sizeof(buffer), in);
		char *word, *next;
		word = strtok_s(buffer, " /", &next);
		x=atof(word);
		word = strtok_s(NULL, " /", &next);
		y = atof(word);
		word = strtok_s(NULL, " /", &next);
		z = atof(word);
		fclose(in);
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu;
	Point ob;
	do
	{
		system("cls");
		cout << " 1 - ввод данных\n";
		cout << " 2 - показ данных \n";
		cout << " 3 - сохранение данных в файл \n";
		cout << " 4 - загрузка данных из файла \n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			ob.get_in();
			break;
		case 2:
			ob.show();
			system("pause");
			break;
		case 3:
			ob.save();
			break;
		case 4:
			ob.load();
			break;
		case 0:
			break;
		default:
			cout << " Ошибка ввода !!!\n";
			system("pause");
			break;
		}
	} while (menu != 0);
	system("pause");
}
