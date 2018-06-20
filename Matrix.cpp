/*Создать класс для работы с матрицами. Предусмот¬реть следующие функции
для работы с матрицами:
- сложения матриц;
- умножения матриц;
- транспонирования матриц;
- присваивания матриц друг другу;
- установка и получение произвольного элемента матрицы.
Необходимо перегрузить соответствующие операторы.*/
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

template<class X>
class Matrix
{
public:
	X** arr;
	int size;
	Matrix()
	{
		size = 1;
		arr = new X*[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new X[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix& ob)
	{
		size = ob.size;
		arr = new X*[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new X[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = ob.arr[i][j];
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < size; i++)
		{
			delete[]arr[i];
		}
		delete[]arr;
		arr = NULL;
	}
	void init_hand(int _size);
	void init(int _size);
	void show();
	X maxElem();
	X minElem();
	X& operator[](int i)
	{ 
		return *arr[i];
	};
	submasint& operator[](int i)
	{
		return arrint[i];
	}

	Matrix operator+(const Matrix& ob)
	{
		size = ob.size;
		Matrix tmp(*this);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				tmp.arr[i][j] = arr[i][j] + ob.arr[i][j];
			}
		}
		return tmp;
	};
	Matrix operator-(const Matrix& ob)
	{
		size = ob.size;
		Matrix tmp(*this);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				tmp.arr[i][j] = arr[i][j] - ob.arr[i][j];
			}
		}
		return tmp;
	};
	Matrix operator = (const Matrix& ob)
	{
		size = ob.size;
		arr = new X*[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new X[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = ob.arr[i][j];
			}
		}
		return *this;
	};
};
template<class X> void Matrix<X>::init(int _size)
{
	size = _size;
	arr = new int*[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 5;
		}
	}
}
template<class X> void Matrix<X>::init_hand(int _size)
{
	size = _size;
	arr = new int*[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " строка \n";
		for (int j = 0; j < size; j++)
		{
			cout << j + 1 << " элемент : ";
			cin>>arr[i][j];
		}
	}
}
template <class X> void Matrix<X>::show()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout.setf(ios::left);
			cout.setf(ios::fixed);
			cout.width(3);
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
}
template<class X> X Matrix<X>::maxElem()
{
	X maxElem = arr[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (maxElem < arr[i][j])
				maxElem = arr[i][j];
		}
	}
	return maxElem;
}
template<class X> X Matrix<X>::minElem()
{
	X minElem = arr[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (minElem < arr[i][j])
				minElem = arr[i][j];
		}
	}
	return minElem;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	cout << " Здравствуйте, Вас приветсвует програма для работы с матрицами.\n Матрицы в данной программе представлены в классическом варианте, \n";
	cout << " где число строк и число столбцов совпадает. Для всех матриц задаётся один размер в начале программы.\n Приятной работы.\n";
	system("pause");
	system("cls");
	int size;
	int menu;
	int choice;
	int row=0;
	int col = 0;
	bool flag = false;

	cout << " Введите размер матрицы : ";
	cin >> size;
	Matrix<int> _matrix;
	Matrix<int> _matrix2;
	Matrix<int> _matrix3;
	do
	{
		system("cls");
		cout << " 1 - заполнение матрицы с клавиатуры\n";
		cout << " 2 - заполнение случайными значениями\n";
		cout << " 3 - отображение матрицы\n";
		cout << " 4 - сложения матриц\n";
		cout << " 5 - вычитание матриц\n";
		cout << " 6 - умножения матриц\n";
		cout << " 7 - деление матриц\n";
		cout << " 8 - транспонирования матриц\n";
		cout << " 9 - присваивания матриц друг другу\n";
		cout << " 10 - установка произвольного элемента матрицы\n";
		cout << " 11 - получение произвольного элемента матрицы\n";
		cout << " 12 - максимальное значение элемента матрицы\n";
		cout << " 13 - минимальное значение элемента матрицы\n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			if (flag == true)
			{
				cout << " Матрицы заполнены \n";
				system("pause");
				break;
			}
			else
			{
				_matrix.init_hand(size);
				_matrix2.init_hand(size);
				flag = true;
				cout << " Успешно выполнено \n";
				system("pause");
				break;
			}
		case 2:
			if (flag == true)
			{
				cout << " Матрицы заполнены \n";
				system("pause");
				break;
			}
			else
			{
				_matrix.init(size);
				_matrix2.init(size);
				flag = true;
				cout << " Успешно выполнено \n";
				system("pause");
				break;
			}
		case 3:
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Матрицы № 1 \n";
				_matrix.show();
				cout << " Матрица № 2 \n";
				_matrix2.show();
				cout << " Матрица № 3 \n";
				_matrix3.show();
				system("pause");
				break;
			}
		case 4:
			system("cls");
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Сумма матриц \n";
				_matrix3 = _matrix + _matrix2;
				cout << " Матрицы № 1 \n";
				_matrix.show();
				cout << " Матрица № 2 \n";
				_matrix2.show();
				cout << " Матрица № 3 \n";
				_matrix3.show();
				system("pause");
				break;
			}
		case 5:
			system("cls");
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				cout << "Вычитание матриц \n";
				_matrix3 = _matrix - _matrix2;
				cout << " Матрицы № 1 \n";
				_matrix.show();
				cout << " Матрица № 2 \n";
				_matrix2.show();
				cout << " Матрица № 3 \n";
				_matrix3.show();
				system("pause");
				break;
			}
		case 9:
			system("cls");
			cout << " Выберите какую матрицу какой присвоить \n";
			cout << " 1 - первой - вторую \n";
			cout << " 2- второй - первой \n";
			cout << " 3 - первой - третью \n";
			cout << " 4 - третье - первую \n";
			cout << " 5 - второй - третью \n";
			cout << " 6 - третьей - вторую \n";
			do
			{
				cin >> choice;
				if (choice < 0 || choice>6)cout << " Внимательнее читайте меню \n";
			} while (choice < 0 || choice>6);
			if (choice == 1)
			{
				_matrix = _matrix2;
				cout << " Успешно выполнено \n";
				system("pause");
				break;
			}
			if (choice == 2)
			{
				_matrix2 = _matrix;
				cout << " Успешно выполнено \n";
				system("pause");
				break;
			}
			if (choice == 3)
			{
				_matrix = _matrix3;
				cout << " Успешно выполнено \n";
				system("pause");
				break;
			}
			if (choice == 4)
			{
				_matrix3 = _matrix;
				cout << " Успешно выполнено \n";
				system("pause");
				break;
			}
			if (choice == 5)
			{
				_matrix2 = _matrix3;
				cout << " Успешно выполнено \n";
				system("pause");
				break;
			}
			if (choice == 6)
			{
				_matrix3 = _matrix2;
				cout << " Успешно выполнено \n";
				system("pause");
				break;
			}
		case 11:
			cout << " Введите строку : ";
			cin >> row;
			cout << " Введите столбец : ";
			cin >> col;
			cout <<  " Полученный элемент : "<<_matrix[row - 1]<<endl;
			system("pause");
			break;
		case 12:
			system("cls");
			cout << " Максимальный элемент какой матрицы найти : 1 2 3 \n";
			cout << " Выш выбор : ";
			cin >> choice;
			if (choice == 1)
			{
				_matrix.show();
				cout << " Максимальный элемент первой матрицы = " << _matrix.maxElem() << endl;
				system("pause");
				break;
			}
			if (choice == 2)
			{
				_matrix2.show();
				cout << " Максимальный элемент второй матрицы = " << _matrix2.maxElem() << endl;
				system("pause");
				break;
			}
			if (choice == 3)
			{
				_matrix3.show();
				cout << " Максимальный элемент третьей матрицы = " << _matrix3.maxElem() << endl;
				system("pause");
				break;
			}
		case 13:
			system("cls");
			cout << " Минимальный элемент какой матрицы найти : 1 2 3 \n";
			cout << " Выш выбор : ";
			cin >> choice;
			if (choice == 1)
			{
				cout << " Минимальный элемент первой матрицы = " << _matrix.minElem() << endl;
				system("pause");
				break;
			}
			if (choice == 2)
			{
				cout << " Минимальный элемент второй матрицы = " << _matrix2.minElem() << endl;
				system("pause");
				break;
			}
			if (choice == 3)
			{
				cout << " Минимальный элемент третьей матрицы = " << _matrix3.minElem() << endl;
				system("pause");
				break;
			}
		case 0:
			cout << " До свидания !!!\n";
			system("pause");
			break;
		default:
			cout << " Ошибка. Данного пункта нет в меню \n";
		}
	} while (menu != 0);
}

