//Заполнить двухмерный вектор таблицей умножения и вывести его в выходной поток.
#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<vector<int>> multiplication_table;
	for (int i = 2; i < 10; i++)
	{
		vector<int> data;
		for (int j = 1; j < 11; j++)
		{
			data.push_back(j*i);
		}
		multiplication_table.push_back(data);
	}
	int len = multiplication_table.size();
	for (int i = 0; i < len; i++)
	{
		int len1 = multiplication_table[i].size();
		for (int j = 0; j < len1; j++)
		{
			cout << i+2<<" * "<<j+1<< " = "<<multiplication_table[i][j]<<endl;
		}
		cout << "\t\n";
	}
	return 1;
}
