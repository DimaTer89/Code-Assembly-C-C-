//Заполнить вектор длинной 10 квадратами целых чисел и вывести его в выходной  поток. 
#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>


using namespace std;

int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num;
	int len=10;
	vector<int> vek;
	cout <<" Fill in the data : \n ";
	for (int i = 0; i < len; i++)
	{
		cout <<" Enter elem № " << i + 1 << " : ";
		cin >> num;
		vek.push_back(num);
	}
	vector<int>vek2(vek);
	for (int i = 0; i < len; i++)
	{
		vek2[i] = vek[i] * vek[i];
	}
	cout << " Perfect square : \n";
	for (int i = 0; i < len; i++)
	{
		cout << vek[i] << " = " << vek2[i] << endl;
	}
	system("pause");
	return 1;
}
