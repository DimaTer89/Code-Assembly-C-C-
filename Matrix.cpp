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
	Matrix(int size = 1)
	{
		arr = new X*[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new X[size];
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
	void init(int _size);
	void show();
	X operator[](int i)
	{
		return *arr[i];
	}
	Matrix operator+(Matrix ob);
	Matrix operator-(Matrix ob);
	Matrix& operator=(Matrix ob);
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
template <class X> void Matrix<X>::show()
{
	cout << " Матрица : \n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
}
template <class X>Matrix<X>::operator+(Matrix ob)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] += ob.arr[i][j];
		}
	}
	return *this;
}
template <class X>Matrix <X>::operator-(Matrix ob)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] -= ob.arr[i][j];
		}
	}
	return *this;
}
template <class X> Matrix <X>::operator=(Matrix ob)
{
	Matrix temp;
	for (int i = 0; i < ob.size; i++)
	{
		for (int j = 0; j < ob.size; j++)
		{
			temp.arr[i][j] = ob.arr[i][j];
		}
	}
	return temp;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	int size;
	cout << " Введите размер матрицы : ";
	cin >> size;
	Matrix<int> _matrix;
	Matrix<int> _matrix2;
	Matrix<int> _matrix3;
	_matrix.init(size);
	_matrix.show();
	_matrix2.init(size);
	_matrix2.show();
	_matrix3 = _matrix + _matrix2;
	_matrix3.show();
	system("pause");
}
===================================
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
	Matrix(int size = 1)
	{
		arr = new X*[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new X[size];
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
	void init(int _size);
	void show();
	X& operator[][](int i)
	{
		return *arr[i];
	}
	Matrix operator+(const Matrix& ob)
	{
		size = ob.size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] += ob.arr[i][j];
			}
		}
		return *this;
	};
	Matrix operator-(const Matrix& ob)
	{
		size = ob.size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] -= ob.arr[i][j];
			}
		}
		return *this;
	};
	Matrix& operator = (Matrix ob)
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
template <class X> void Matrix<X>::show()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	int size;
	int menu;
	int row;
	int col;

	cout << " Введите размер матрицы : ";
	cin >> size;
	Matrix<int> _matrix;
	Matrix<int> _matrix2;
	Matrix<int> _matrix3;
	Matrix<int> _matrix4;
	_matrix.init(size);
	_matrix2.init(size);
	cout << " Матрица \n";
	_matrix.show();
	cout << " Матрица \n";
	_matrix2.show();
	do
	{
	cout << " 1 - Сложение матриц \n";
	cout << " 2 - Присваивание матриц друг другу \n";
	cout << " 3 - Транспонирование матриц \n";
	cout << " 4 - Установка и получение произвольного элемента матрицы. \n";
	cout << " 5 - Выход \n";
	cin >> menu;
	switch (menu)
		{
		case 1:
			cout << " Сумма матриц \n";
			_matrix3 = _matrix + _matrix2;
			_matrix3.show();
			break;
		case 2:
			cout << "";
			_matrix4 = _matrix2;
			_matrix4.show();
			break;
		case 4:
			cout << " Введите строку : ";
			cin >> row;
			cout << " Введите столбец : ";
			cin >> col;
			//cout << __matrix[row - 1][col-1] << endl;
		}
	} while (menu != 5);
	system("pause");
}
