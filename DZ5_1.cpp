#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
template <class X>
class Array
{

public:
	X * arr;
	int size;
	int lb = 0;
	int ub = size - 1;
	Array()
	{
		size = 0;
		arr = new X[size];
	}
	Array(const Array& obj)
	{
		size = obj.size;
		arr = new X[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	~Array()
	{
		delete[]arr;
		arr = NULL;
	}
	void init(int n);
	void put_arr();
	void put_rand_arr();
	void show();
	void sort();
	void arr_change(int num);
	X maxElem();
	X minElem();
	X &operator[](int i) { return arr[i]; };
	int binarySearch(X num)
	{
		int lb = 0;
		int ub = size - 1;
		
		while (lb <= ub)
		{
			int m = (lb + ub) / 2;
			if (num == arr[m])return m;
			if (num < arr[m])ub = m - 1;
			if (num > arr[m])lb = m + 1;
		}
		return -1;
	}
};
template <class X> void Array<X>::init(int n)
{
	size = n;
	arr = new X[size];
}
template <class X> void Array<X>::put_arr()
{
	int i;
	for (i = 0; i < size; i++)
	{
		system("cls");
		cout << " Введите " << i + 1 << " элемент массива : ";
		cin >> arr[i];
	}
}
template <class X> void Array<X>::put_rand_arr()
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 51 - 50;
	}
}
template <class X> void Array<X>::show()
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
template <class X> void Array<X>::sort()
{
	int i;
	int k;
	for (k = size - 1; k > 0; k--)
	{
		for (i = 0; i < k; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				X tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
}
template <class X> void Array<X>::arr_change(int num)
{
	int i;
	if (num < size)
	{
		X* arr_new = new X[num];
		for (i = 0; i < num; i++)
		{
			arr_new[i] = arr[i];
		}
		delete[]arr;
		arr = arr_new;
		size = num;
	}
	if (num > size)
	{
		X* arr_new = new X[num];
		for (i = 0; i < num; i++)
		{
			arr_new[i] = arr[i];
		}
		for (i = size; i < num; i++)
		{
			arr_new[i] = 0;
		}
		delete[]arr;
		arr = arr_new;
		size = num;
	}
}
template <class X> X Array<X>::maxElem()
{
	X max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
template <class X> X Array<X>::minElem()
{
	X min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	int menu;
	int choice;
	int size;
	int mas;
	int num;
	int change;
	int poz;
	int ielem;
	double delem;
	char chelem;

	Array<int>arr;
	Array<double>arr1;
	Array<char>arr2;
	bool flag = false;
	bool flag1 = false;
	
	do
	{
		cout << " 1 - массив со значениями типа int \n";
		cout << " 2 - массив со значениями типа double \n";
		cout << " 3 - массив со значениями типа char \n";
		cout << " Ваш выбор : ";
		cin >> choice;
		if (choice < 1 || choice>3)cout << " Ошибка !!! \n";
	} while (choice < 1 || choice>3);

	do
	{
		system("cls");
		cout << " 1 - заполнить массив \n";
		cout << " 2 - отображать содержимое массива \n";
		cout << " 3 - изменить размер массива \n";
		cout << " 4 - сортировать массив\n";
		cout << " 5 - определить минимальное и максимальное значение.\n";
		cout << " 6 - Изменить значение элемента массива \n ";
		cout << "7 - Бинарный поиск числа в массиве \n";
		cout << " 0 - Выход \n";
		cout << " Ваш выбор : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			char key;
			cout << " Заполнить массив автоматически - y\n";
			cout << " Заполнить массив лично - n\n";
			cout << " Ваш выбор : ";
			cin >> key;
			if (key == 'y')
			{
				if (choice == 1)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr.init(size);
					arr.put_rand_arr();
					flag = true;
					break;
				}
				if (choice == 2)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr1.init(size);
					arr1.put_rand_arr();
					flag = true;
					break;
				}
				if (choice == 3)
				{
					cout << " Введите размер массива : ";
					cin >> size;
					arr2.init(size);
					arr2.put_rand_arr();
					flag = true;
					break;
				}
				break;
			}
			if (key == 'n')
			{
				if (choice == 1)
				{
					cout << " Введите размер массива : ";
					cin >> size;

					arr.init(size);
					arr.put_arr();
					flag = true;
					break;
				}
				if (choice == 2)
				{
					cout << " Введите размер массива : ";
					cin >> size;

					arr1.init(size);
					arr1.put_arr();
					flag = true;
					break;
				}
				if (choice == 3)
				{
					cout << " Введите размер массива : ";
					cin >> size;

					arr2.init(size);
					arr2.put_arr();
					flag = true;
					break;
				}
				break;
			}
		case 2:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			if (choice == 1)
			{
				cout << " Массив int значений \n";
				arr.show();
				system("pause");
				break;
			}
			if (choice == 2)
			{
				cout << " Массив double значений \n";
				for (int i = 0; i < arr1.size; i++)
				{
					cout.setf(ios::left);
					cout.setf(ios::fixed, ios::floatfield);
					cout.width(7);
					cout.precision(3);
					cout << arr1[i] << "  ";

				}
				cout << endl;
				system("pause");
				break;
			}
			if (choice == 3)
			{
				cout << " Массив char значений \n";
				arr2.show();
				system("pause");
				break;
			}
		case 3:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			cout << " Введите размер массива : ";
			cin >> num;
			cout << " 1 - Создать новый массив\n";
			cout << " 2 - Изменения массива с сохранением значений \n ";
			cout << " Ваш выбор : ";
			cin >> change;
			if (change == 1)
			{
				char key;
				cout << " Заполнить массив автоматически - y\n";
				cout << " Заполнить массив лично - n\n";
				cout << " Ваш выбор : ";
				cin >> key;
				if (key == 'y')
				{
					if (choice == 1)
					{
						arr.init(num);
						arr.put_rand_arr();
						flag = true;
						flag1 = false;
						break;
					}
					if (choice == 2)
					{
						arr1.init(num);
						arr1.put_rand_arr();
						flag = true;
						flag1 = false;
						break;
					}
					if (choice == 3)
					{
						arr2.init(num);
						arr2.put_rand_arr();
						flag = true;
						flag1 = false;
						break;
					}
					break;
				}
				if (key == 'n')
				{
					if (choice == 1)
					{
						arr.init(num);
						arr.put_arr();
						flag = true;
						flag1 = false;
						break;
					}
					if (choice == 2)
					{
						arr1.init(num);
						arr1.put_arr();
						flag = true;
						flag1 = false;
						break;
					}
					if (choice == 3)
					{
						arr2.init(num);
						arr2.put_arr();
						flag = true;
						flag1 = false;
						break;
					}
					break;
				}
			}
			if (change == 2)
			{
				if (choice == 1)
				{
					arr.arr_change(num);
					flag1 = false;
					break;
				}
				if (choice == 2)
				{
					arr1.arr_change(num);
					flag1 = false;
					break;
				}
				if (choice == 3)
				{
					arr2.arr_change(num);
					flag1 = false;
					break;
				}
			}
		case 4:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			if (choice == 1)
			{
				arr.sort();
				cout << " Успешно выполнено \n";
				flag1 = true;
				system("pause");
				break;
			}
			if (choice == 2)
			{
				arr1.sort();
				cout << " Успешно выполнено \n";
				flag1 = true;
				system("pause");
				break;
			}
			if (choice == 3)
			{
				arr2.sort();
				cout << " Успешно выполнено \n";
				flag1 = true;
				system("pause");
				break;
			}
		case 5:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			cout << " 1 - максимальное значение массива \n";
			cout << " 2 - минимальное значение массива \n";
			cout << " Ваш выбор : ";
			cin >> mas;
			if (mas == 1)
			{
				if (choice == 1)
				{
					cout << " Максимальный элемент массива = " << arr.maxElem() << endl;
					system("pause");
					break;
				}
				if (choice == 2)
				{
					cout << " Максимальный элемент массива = " << arr1.maxElem() << endl;
					system("pause");
					break;
				}
				if (choice == 3)
				{
					cout << " Максимальный элемент массива = " << arr2.maxElem() << endl;
					system("pause");
					break;
				}
			}
			if (mas == 2)
			{
				if (choice == 1)
				{
					cout << " Минимальный элемент массива = " << arr.minElem() << endl;
					system("pause");
					break;
				}
				if (choice == 2)
				{
					cout << " Минимальный элемент массива = " << arr1.minElem() << endl;
					system("pause");
					break;
				}
				if (choice == 3)
				{
					cout << " Минимальный элемент массива = " << arr2.minElem() << endl;
					system("pause");
					break;
				}
			}
		case 6:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			if (choice == 1)
			{
				arr.show();
				cout << " Введите позицию изменения элемента : ";
				do
				{
					cin >> poz;
					if (poz<0 || poz>arr.size)cout << " Ошибка, введите снова : ";
				} while (poz<0 || poz>arr.size);
				cout << " Введите элемент : ";
				cin >> ielem;
				arr[poz - 1] = ielem;
				cout << " Успешно выполнено \n";
				arr.show();
				flag1 = false;
				system("pause");
				break;
			}
			if (choice == 2)
			{
				for (int i = 0; i < arr1.size; i++)
				{
					cout.setf(ios::left);
					cout.setf(ios::fixed, ios::floatfield);
					cout.width(7);
					cout.precision(3);
					cout << arr1[i] << "  ";

				}
				cout << endl;
				cout << " Введите позицию изменения элемента : ";
				do
				{
					cin >> poz;
					if (poz<0 || poz>arr1.size)cout << " Ошибка, введите снова : ";
				} while (poz<0 || poz>arr1.size);
				cout << " Введите элемент : ";
				cin >> delem;
				arr1[poz - 1] = delem;
				cout << " Успешно выполнено \n";
				for (int i = 0; i < arr1.size; i++)
				{
					cout.setf(ios::left);
					cout.setf(ios::fixed, ios::floatfield);
					cout.width(7);
					cout.precision(3);
					cout << arr1[i] << "  ";

				}
				cout << endl;
				flag1 = false;
				system("pause");
				break;
			}
			if (choice == 3)
			{
				arr2.show();
				cout << " Введите позицию изменения элемента : ";
				do
				{
					cin >> poz;
					if (poz<0 || poz>arr2.size)cout << " Ошибка, введите снова : ";
				} while (poz<0 || poz>arr2.size);
				cout << " Введите элемент : ";
				cin >> chelem;
				arr2[poz - 1] = chelem;
				cout << " Успешно выполнено \n";
				arr2.show();
				flag1 = false;
				system("pause");
				break;
			}
		case 7:
			if (flag == false)
			{
				cout << " Массив не создан \n";
				system("pause");
				break;
			}
			if (flag1 == false)
			{
				cout << " Бинарный поиск применяется в отсортированном массиве по возрастанию , для начала выполните сортировку ( см. меню )\n";
				system("pause");
				break;
			}
			if (choice == 1)
			{
				cout << " Введите искомый элемент : ";
				cin >> ielem;
				poz = arr.binarySearch(ielem);
				if (poz == -1)
				{
					cout << " Числа нет в массиве \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Элемент находиться на " << poz + 1 << " позиции \n";
					arr.show();
					system("pause");
					break;
				}
			}
			if (choice == 2)
			{
				cout << " Введите искомый элемент : ";
				cin >> delem;
				poz = arr1.binarySearch(delem);
				if (poz == -1)
				{
					cout << " Числа нет в массиве \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Элемент находиться на " << poz + 1 << " позиции \n";
					for (int i = 0; i < arr1.size; i++)
					{
						cout.setf(ios::left);
						cout.setf(ios::fixed, ios::floatfield);
						cout.width(7);
						cout.precision(3);
						cout << arr1[i] << "  ";

					}
					cout << endl;
					system("pause");
					break;
				}
			}
			if (choice == 3)
			{
				cout << " Введите искомый элемент : ";
				cin >> chelem;
				poz = arr2.binarySearch(chelem);
				if (poz == -1)
				{
					cout << " Числа нет в массиве \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Элемент находиться на " << poz + 1 << " позиции \n";
					arr2.show();
					system("pause");
					break;
				}
			}
		case 0:
			cout << " До свидания \n";
			break;
		default:
			cout << " Ошибка !!! \n";
			system("pause");
		}

	} while (menu != 0);
	system("pause");
}
