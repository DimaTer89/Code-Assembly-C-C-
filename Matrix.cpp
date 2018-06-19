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
	Matrix(int size=1)
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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	int size;
	cout << " Введите размер матрицы : ";
	cin >> size;
	Matrix<int> _matrix;
	_matrix.init(size);
	_matrix.show();
	system("pause");
}
