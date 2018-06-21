#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

template<class X>
class Matrix
{
public:
	X * * arr;
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
	X getElem(int row, int col);
	void putElem(int row, int col, X num);
	Matrix transPon(Matrix& ob)
	{
		size = ob.size;
		Matrix tmp(*this);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				tmp.arr[i][j] = arr[j][i];
			}
		}
		return tmp;
	};
	Matrix operator *(const Matrix& ob)
	{
		size = ob.size;
		Matrix tmp(*this);
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				tmp.arr[i][j] = 0;
				for (int k = 0; k<size; k++)
					tmp.arr[i][j] += arr[i][k] * ob.arr[k][j];
			}
		}
		return tmp;
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
	arr = new X*[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new X[size];
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
	arr = new X*[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new X[size];
	}
	for (int i = 0; i < size; i++)
	{
		system("cls");
		cout << i + 1 << " строка \n";
		for (int j = 0; j < size; j++)
		{
			cout << j + 1 << " элемент : ";
			cin >> arr[i][j];
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
			cout.setf(ios::fixed, ios::floatfield);
			cout.width(7);
			cout.precision(3);
			cout << arr[i][j] << " ";
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
			if (minElem > arr[i][j])
				minElem = arr[i][j];
		}
	}
	return minElem;
}
template <class X> X Matrix<X>::getElem(int row, int col)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == (row - 1) && j == (col - 1))
			{
				return arr[i][j];
			}
		}
	}
}template <class X> void Matrix<X>::putElem(int row, int col, X num)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == (row - 1) && j == (col - 1))
			{
				arr[i][j] = num;
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	cout << " Здравствуйте, Вас приветсвует програма для работы с матрицами.\n Матрицы в данной программе представлены в классическом варианте, \n";
	cout << " где число строк и число столбцов совпадает. Создаётся три матрицы( две заполняются, \n третья иницилизиуется по умолчанию конструктором )";
	cout<< " \n Выбор типа данных остаётся за вами. \n Для всех матриц задаётся один размер в начале программы.\n Приятной работы.\n";
	system("pause");
	system("cls");
	int size;
	int menu;
	int key;
	int choice;
	int row = 0;
	int col = 0;
	int num = 0;
	bool flag = false;

	Matrix<int> _matrix;
	Matrix<int> _matrix2;
	Matrix<int> _matrix3;

	Matrix<double> _Dmatrix;
	Matrix<double> _Dmatrix2;
	Matrix<double> _Dmatrix3;

	Matrix<char> _Cmatrix;
	Matrix<char> _Cmatrix2;
	Matrix<char> _Cmatrix3;
	system("cls");
	cout << " 1 - Матрицы с данными типа int \n";
	cout << " 2 - Матрицы с данными типа double \n";
	cout << " 3 - Матрицы с данными типа char \n";
	cin >> key;
	do
	{
		system("cls");
		cout << " 1 - заполнение матрицы с клавиатуры\n";
		cout << " 2 - заполнение случайными значениями\n";
		cout << " 3 - отображение матрицы\n";
		cout << " 4 - сложения матриц\n";
		cout << " 5 - вычитание матриц\n";
		cout << " 6 - умножения матриц\n";
		cout << " 7 - транспонирования матриц\n";
		cout << " 8 - присваивания матриц друг другу\n";
		cout << " 9 - установка произвольного элемента матрицы\n";
		cout << " 10 - получение произвольного элемента матрицы\n";
		cout << " 11 - максимальное значение элемента матрицы\n";
		cout << " 12 - минимальное значение элемента матрицы\n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			if (key == 1)
			{
				if (flag == true)
				{
					cout << " Матрицы заполнены \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Введите размер матрицы : ";
					cin >> size;
					_matrix.init_hand(size);
					_matrix2.init_hand(size);
					flag = true;
					cout << " Успешно выполнено \n";
					system("pause");
					break;
				}
			}
			if (key == 2)
			{
				if (flag == true)
				{
					cout << " Матрицы заполнены \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Введите размер матрицы : ";
					cin >> size;
					_Dmatrix.init_hand(size);
					_Dmatrix2.init_hand(size);
					flag = true;
					cout << " Успешно выполнено \n";
					system("pause");
					break;
				}
			}
			if (key == 3)
			{
				if (flag == true)
				{
					cout << " Матрицы заполнены \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Введите размер матрицы : ";
					cin >> size;
					_Cmatrix.init_hand(size);
					_Cmatrix2.init_hand(size);
					flag = true;
					cout << " Успешно выполнено \n";
					system("pause");
					break;
				}
			}
			
		case 2:
			if (key == 1)
			{
				if (flag == true)
				{
					cout << " Матрицы заполнены \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Введите размер матрицы : ";
					cin >> size;
					_matrix.init(size);
					_matrix2.init(size);
					flag = true;
					cout << " Успешно выполнено \n";
					system("pause");
					break;
				}
			}
			if (key == 2)
			{
				if (flag == true)
				{
					cout << " Матрицы заполнены \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Введите размер матрицы : ";
					cin >> size;
					_Dmatrix.init(size);
					_Dmatrix2.init(size);
					flag = true;
					cout << " Успешно выполнено \n";
					system("pause");
					break;
				}
			}
			if (key == 3)
			{
				if (flag == true)
				{
					cout << " Матрицы заполнены \n";
					system("pause");
					break;
				}
				else
				{
					cout << " Введите размер матрицы : ";
					cin >> size;
					_Cmatrix.init(size);
					_Cmatrix2.init(size);
					flag = true;
					cout << " Успешно выполнено \n";
					system("pause");
					break;
				}
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
				if (key == 1)
				{
					system("cls");
					cout << " Матрицы № 1 \n";
					_matrix.show();
					cout << " Матрица № 2 \n";
					_matrix2.show();
					cout << " Матрица № 3 \n";
					_matrix3.show();
					system("pause");
					break;
				}
				if (key == 2)
				{
					system("cls");
					cout << " Матрицы № 1 \n";
					_Dmatrix.show();
					cout << " Матрица № 2 \n";
					_Dmatrix2.show();
					cout << " Матрица № 3 \n";
					_Dmatrix3.show();
					system("pause");
					break;
				}
				if (key == 3)
				{
					system("cls");
					cout << " Матрицы № 1 \n";
					_Cmatrix.show();
					cout << " Матрица № 2 \n";
					_Cmatrix2.show();
					cout << " Матрица № 3 \n";
					_Cmatrix3.show();
					system("pause");
					break;
				}
				
			}
		case 4:
			
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				if (key == 1)
				{
					system("cls");
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
				if (key == 1)
				{
					system("cls");
					cout << " Сумма матриц \n";
					_Dmatrix3 = _Dmatrix + _Dmatrix2;
					cout << " Матрицы № 1 \n";
					_Dmatrix.show();
					cout << " Матрица № 2 \n";
					_Dmatrix2.show();
					cout << " Матрица № 3 \n";
					_Dmatrix3.show();
					system("pause");
					break;
				}
				if (key == 1)
				{
					system("cls");
					cout << " Сумма матриц \n";
					_Cmatrix3 = _Cmatrix + _Cmatrix2;
					cout << " Матрицы № 1 \n";
					_Cmatrix.show();
					cout << " Матрица № 2 \n";
					_Cmatrix2.show();
					cout << " Матрица № 3 \n";
					_Cmatrix3.show();
					system("pause");
					break;
				}
			}
		case 5:
			
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				if (key == 1)
				{
					system("cls");
					cout << " 1 - вычесть из 1 матрицу 2 \n";
					cout << " 2 - вычесть из 2 матрицу 1 \n";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>2)cout << " Ошибка, выберите от 1 до 2 включительно \n";
					} while (choice < 1 || choice>2);
					if (choice == 1)
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
					if (choice == 2)
					{
						cout << "Вычитание матриц \n";
						_matrix3 = _matrix2 - _matrix;
						cout << " Матрицы № 1 \n";
						_matrix.show();
						cout << " Матрица № 2 \n";
						_matrix2.show();
						cout << " Матрица № 3 \n";
						_matrix3.show();
						system("pause");
						break;
					}
				}
				if (key == 2)
				{
					system("cls");
					cout << " 1 - вычесть из 1 матрицу 2 \n";
					cout << " 2 - вычесть из 2 матрицу 1 \n";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>2)cout << " Ошибка, выберите от 1 до 2 включительно \n";
					} while (choice < 1 || choice>2);
					if (choice == 1)
					{
						cout << "Вычитание матриц \n";
						_Dmatrix3 = _Dmatrix - _Dmatrix2;
						cout << " Матрицы № 1 \n";
						_Dmatrix.show();
						cout << " Матрица № 2 \n";
						_Dmatrix2.show();
						cout << " Матрица № 3 \n";
						_Dmatrix3.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << "Вычитание матриц \n";
						_Dmatrix3 = _Dmatrix2 - _Dmatrix;
						cout << " Матрицы № 1 \n";
						_Dmatrix.show();
						cout << " Матрица № 2 \n";
						_Dmatrix2.show();
						cout << " Матрица № 3 \n";
						_Dmatrix3.show();
						system("pause");
						break;
					}
				}
				if (key == 3)
				{
					system("cls");
					cout << " 1 - вычесть из 1 матрицу 2 \n";
					cout << " 2 - вычесть из 2 матрицу 1 \n";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>2)cout << " Ошибка, выберите от 1 до 2 включительно \n";
					} while (choice < 1 || choice>2);
					if (choice == 1)
					{
						cout << "Вычитание матриц \n";
						_Cmatrix3 = _Cmatrix - _Cmatrix2;
						cout << " Матрицы № 1 \n";
						_Cmatrix.show();
						cout << " Матрица № 2 \n";
						_Cmatrix2.show();
						cout << " Матрица № 3 \n";
						_Cmatrix3.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << "Вычитание матриц \n";
						_Cmatrix3 = _Cmatrix2 - _Cmatrix;
						cout << " Матрицы № 1 \n";
						_Cmatrix.show();
						cout << " Матрица № 2 \n";
						_Cmatrix2.show();
						cout << " Матрица № 3 \n";
						_Cmatrix3.show();
						system("pause");
						break;
					}
				}
				
			}
		case 6:
			if (flag == false)
			{
				cout << " Матрицы не созданы \n";
				system("pause");
				break;
			}
			else
			{
				if (key == 1)
				{
					system("cls");
					cout << " 1 - умножить 1 матрицу на 2 \n";
					cout << " 2 - умножить 2 матрицу на 1 \n";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>2)cout << " Ошибка, выберите от 1 до 2 включительно \n";
					} while (choice < 1 || choice>2);
					if (choice == 1)
					{
						cout << "Умножеие матриц \n";
						_matrix3 = _matrix * _matrix2;
						cout << " Матрицы № 1 \n";
						_matrix.show();
						cout << " Матрица № 2 \n";
						_matrix2.show();
						cout << " Матрица № 3 \n";
						_matrix3.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Умножение матриц \n";
						_matrix3 = _matrix2 * _matrix;
						cout << " Матрицы № 1 \n";
						_matrix.show();
						cout << " Матрица № 2 \n";
						_matrix2.show();
						cout << " Матрица № 3 \n";
						_matrix3.show();
						system("pause");
						break;
					}
				}
				if (key == 2)
				{
					system("cls");
					cout << " 1 - умножить 1 матрицу на 2 \n";
					cout << " 2 - умножить 2 матрицу на 1 \n";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>2)cout << " Ошибка, выберите от 1 до 2 включительно \n";
					} while (choice < 1 || choice>2);
					if (choice == 1)
					{
						cout << "Умножеие матриц \n";
						_Dmatrix3 = _Dmatrix * _Dmatrix2;
						cout << " Матрицы № 1 \n";
						_Dmatrix.show();
						cout << " Матрица № 2 \n";
						_Dmatrix2.show();
						cout << " Матрица № 3 \n";
						_Dmatrix3.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Умножение матриц \n";
						_Dmatrix3 = _Dmatrix2 * _Dmatrix;
						cout << " Матрицы № 1 \n";
						_Dmatrix.show();
						cout << " Матрица № 2 \n";
						_Dmatrix2.show();
						cout << " Матрица № 3 \n";
						_Dmatrix3.show();
						system("pause");
						break;
					}
				}
				if (key == 3)
				{
					system("cls");
					cout << " 1 - умножить 1 матрицу на 2 \n";
					cout << " 2 - умножить 2 матрицу на 1 \n";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>2)cout << " Ошибка, выберите от 1 до 2 включительно \n";
					} while (choice < 1 || choice>2);
					if (choice == 1)
					{
						cout << "Умножеие матриц \n";
						_Cmatrix3 = _Cmatrix * _Cmatrix2;
						cout << " Матрицы № 1 \n";
						_Cmatrix.show();
						cout << " Матрица № 2 \n";
						_Cmatrix2.show();
						cout << " Матрица № 3 \n";
						_Cmatrix3.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Умножение матриц \n";
						_Cmatrix3 = _Cmatrix2 * _Cmatrix;
						cout << " Матрицы № 1 \n";
						_Cmatrix.show();
						cout << " Матрица № 2 \n";
						_Cmatrix2.show();
						cout << " Матрица № 3 \n";
						_Cmatrix3.show();
						system("pause");
						break;
					}
				}
			}
		case 7:
			if (flag == false)
			{
				cout << " Матрицы не созданы \n";
				system("pause");
				break;
			}
			else 
			{
				if (key == 1)
				{
					system("cls");
					cout << " Какую матрицу траспонировать : 1 2 3 : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, внимательней читайте меню \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Матрица до транспонирования \n";
						_matrix.show();
						_matrix = _matrix.transPon(_matrix);
						cout << " Матрица после транспонирования \n";
						_matrix.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Матрица до транспонирования \n";
						_matrix2.show();
						_matrix2 = _matrix2.transPon(_matrix2);
						cout << " Матрица после транспонирования \n";
						_matrix2.show();
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Матрица до транспонирования \n";
						_matrix3.show();
						_matrix3 = _matrix3.transPon(_matrix3);
						cout << " Матрица после транспонирования \n";
						_matrix3.show();
						system("pause");
						break;
					}
				}
				if (key == 2)
				{
					system("cls");
					cout << " Какую матрицу траспонировать : 1 2 3 : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, внимательней читайте меню \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Матрица до транспонирования \n";
						_Dmatrix.show();
						_Dmatrix = _Dmatrix.transPon(_Dmatrix);
						cout << " Матрица после транспонирования \n";
						_Dmatrix.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Матрица до транспонирования \n";
						_Dmatrix2.show();
						_Dmatrix2 = _Dmatrix2.transPon(_Dmatrix2);
						cout << " Матрица после транспонирования \n";
						_Dmatrix2.show();
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Матрица до транспонирования \n";
						_Dmatrix3.show();
						_Dmatrix3 = _Dmatrix3.transPon(_Dmatrix3);
						cout << " Матрица после транспонирования \n";
						_Dmatrix3.show();
						system("pause");
						break;
					}
				}
				if (key == 1)
				{
					system("cls");
					cout << " Какую матрицу траспонировать : 1 2 3 : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, внимательней читайте меню \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Матрица до транспонирования \n";
						_Cmatrix.show();
						_Cmatrix = _Cmatrix.transPon(_Cmatrix);
						cout << " Матрица после транспонирования \n";
						_Cmatrix.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Матрица до транспонирования \n";
						_Cmatrix2.show();
						_Cmatrix2 = _Cmatrix2.transPon(_Cmatrix2);
						cout << " Матрица после транспонирования \n";
						_Cmatrix2.show();
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Матрица до транспонирования \n";
						_Cmatrix3.show();
						_Cmatrix3 = _Cmatrix3.transPon(_Cmatrix3);
						cout << " Матрица после транспонирования \n";
						_Cmatrix3.show();
						system("pause");
						break;
					}
				}
			}
		case 8:
			
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else 
			{
				if (key == 1)
				{
					system("cls");
					cout << " Выберите какую матрицу какой присвоить \n";
					cout << " 1 - первой - вторую \n";
					cout << " 2 - первой - третью \n";
					cout << " 3 - второй - первую \n";
					cout << " 4 - второй - третью \n";
					cout << " 5 - третьей - первую \n";
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
						_matrix = _matrix3;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 3)
					{
						_matrix2 = _matrix;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 4)
					{
						_matrix2 = _matrix3;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 5)
					{
						_matrix3 = _matrix;
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
				}
				if (key == 2)
				{
					system("cls");
					cout << " Выберите какую матрицу какой присвоить \n";
					cout << " 1 - первой - вторую \n";
					cout << " 2 - первой - третью \n";
					cout << " 3 - второй - первую \n";
					cout << " 4 - второй - третью \n";
					cout << " 5 - третьей - первую \n";
					cout << " 6 - третьей - вторую \n";
					do
					{
						cin >> choice;
						if (choice < 0 || choice>6)cout << " Внимательнее читайте меню \n";
					} while (choice < 0 || choice>6);
					if (choice == 1)
					{
						_Dmatrix = _Dmatrix2;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 2)
					{
						_Dmatrix = _Dmatrix3;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 3)
					{
						_Dmatrix2 = _Dmatrix;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 4)
					{
						_Dmatrix2 = _Dmatrix3;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 5)
					{
						_Dmatrix3 = _Dmatrix;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 6)
					{
						_Dmatrix3 = _Dmatrix2;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
				}
				if (key == 3)
				{
					system("cls");
					cout << " Выберите какую матрицу какой присвоить \n";
					cout << " 1 - первой - вторую \n";
					cout << " 2 - первой - третью \n";
					cout << " 3 - второй - первую \n";
					cout << " 4 - второй - третью \n";
					cout << " 5 - третьей - первую \n";
					cout << " 6 - третьей - вторую \n";
					do
					{
						cin >> choice;
						if (choice < 0 || choice>6)cout << " Внимательнее читайте меню \n";
					} while (choice < 0 || choice>6);
					if (choice == 1)
					{
						_Cmatrix = _Cmatrix2;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 2)
					{
						_Cmatrix = _Cmatrix3;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 3)
					{
						_Cmatrix2 = _Cmatrix;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 4)
					{
						_Cmatrix2 = _Cmatrix3;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 5)
					{
						_Cmatrix3 = _Cmatrix;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
					if (choice == 6)
					{
						_Cmatrix3 = _Cmatrix2;
						cout << " Успешно выполнено \n";
						system("pause");
						break;
					}
				}
			}
			
		case 9:
			
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				if (key == 1)
				{
					system("cls");
					cout << " Установить  элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, введите число от 1 до 3 включительно \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_matrix.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _matrix.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_matrix.size)cout << " Некорректный размер, введите снова : ";
						} while (col >_matrix.size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_matrix.show();
						cout << " Матрица после изменения \n";
						_matrix.putElem(row, col, num);
						_matrix.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_matrix2.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _matrix2.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >size)cout << " Некорректный размер, введите снова : ";
						} while (col > size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_matrix2.show();
						cout << " Матрица после изменения \n";
						_matrix2.putElem(row, col, num);
						_matrix2.show();
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_matrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _matrix3.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_matrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _matrix3.size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_matrix3.show();
						cout << " Матрица после изменения \n";
						_matrix3.putElem(row, col, num);
						_matrix3.show();
						system("pause");
						break;
					}
				}
				if (key == 2)
				{
					system("cls");
					cout << " Установить  элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, введите число от 1 до 3 включительно \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Dmatrix.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Dmatrix.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Dmatrix.size)cout << " Некорректный размер, введите снова : ";
						} while (col >_Dmatrix.size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_Dmatrix.show();
						cout << " Матрица после изменения \n";
						_Dmatrix.putElem(row, col, num);
						_Dmatrix.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Dmatrix2.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Dmatrix2.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Dmatrix2.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _Dmatrix2.size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_Dmatrix2.show();
						cout << " Матрица после изменения \n";
						_Dmatrix2.putElem(row, col, num);
						_Dmatrix2.show();
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Dmatrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Dmatrix3.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Dmatrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _Dmatrix3.size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_Dmatrix3.show();
						cout << " Матрица после изменения \n";
						_Dmatrix3.putElem(row, col, num);
						_Dmatrix3.show();
						system("pause");
						break;
					}
				}
				if (key == 3)
				{
					system("cls");
					cout << " Установить  элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, введите число от 1 до 3 включительно \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Cmatrix.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Cmatrix.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Cmatrix.size)cout << " Некорректный размер, введите снова : ";
						} while (col >_Cmatrix.size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_Cmatrix.show();
						cout << " Матрица после изменения \n";
						_Cmatrix.putElem(row, col, num);
						_Cmatrix.show();
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Cmatrix2.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Cmatrix2.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Cmatrix2.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _Cmatrix2.size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_Cmatrix2.show();
						cout << " Матрица после изменения \n";
						_Cmatrix2.putElem(row, col, num);
						_Cmatrix2.show();
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Cmatrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Cmatrix3.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Cmatrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _Cmatrix3.size);
						cout << " Введите число : ";
						cin >> num;
						cout << " Матрица до изменения \n";
						_Cmatrix3.show();
						cout << " Матрица после изменения \n";
						_Cmatrix3.putElem(row, col, num);
						_Cmatrix3.show();
						system("pause");
						break;
					}
				}
			}
		case 10:
			
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				if (key == 1)
				{
					system("cls");
					cout << " Получить элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, введите число от 1 до 3 включительно \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_matrix.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _matrix.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_matrix.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _matrix.size);
						_matrix.show();
						cout << " Полученный элемент = " << _matrix.getElem(row, col) << endl;
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_matrix2.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _matrix2.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >size)cout << " Некорректный размер, введите снова \n";
						} while (col > size);
						_matrix2.show();
						cout << " Полученный элемент = " << _matrix2.getElem(row, col) << endl;
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_matrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _matrix3.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_matrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _matrix3.size);
						_matrix3.show();
						cout << " Полученный элемент = " << _matrix3.getElem(row, col) << endl;
						system("pause");
						break;
					}
				}
				if (key == 2)
				{
					system("cls");
					cout << " Получить элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, введите число от 1 до 3 включительно \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Dmatrix.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Dmatrix.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Dmatrix.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _Dmatrix.size);
						_Dmatrix.show();
						cout << " Полученный элемент = " << _Dmatrix.getElem(row, col) << endl;
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Dmatrix2.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Dmatrix2.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Dmatrix2.size)cout << " Некорректный размер, введите снова \n";
						} while (col > _Dmatrix2.size);
						_Dmatrix2.show();
						cout << " Полученный элемент = " << _Dmatrix2.getElem(row, col) << endl;
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Dmatrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Dmatrix3.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Dmatrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _Dmatrix3.size);
						_Dmatrix3.show();
						cout << " Полученный элемент = " << _Dmatrix3.getElem(row, col) << endl;
						system("pause");
						break;
					}
				}
				if (key == 3)
				{
					system("cls");
					cout << " Получить элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					do
					{
						cin >> choice;
						if (choice < 1 || choice>3)cout << " Ошибка, введите число от 1 до 3 включительно \n";
					} while (choice < 1 || choice>3);
					if (choice == 1)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Cmatrix.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Cmatrix.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Cmatrix.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _Cmatrix.size);
						_Cmatrix.show();
						cout << " Полученный элемент = " << _Cmatrix.getElem(row, col) << endl;
						system("pause");
						break;
					}
					if (choice == 2)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Cmatrix2.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Cmatrix2.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Cmatrix2.size)cout << " Некорректный размер, введите снова \n";
						} while (col > _Cmatrix2.size);
						_Cmatrix2.show();
						cout << " Полученный элемент = " << _Cmatrix2.getElem(row, col) << endl;
						system("pause");
						break;
					}
					if (choice == 3)
					{
						cout << " Введите строку : ";
						do
						{
							cin >> row;
							if (row >_Cmatrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (row > _Cmatrix3.size);
						cout << " Введите столбец : ";
						do
						{
							cin >> col;
							if (col >_Cmatrix3.size)cout << " Некорректный размер, введите снова : ";
						} while (col > _Cmatrix3.size);
						_Cmatrix3.show();
						cout << " Полученный элемент = " << _Cmatrix3.getElem(row, col) << endl;
						system("pause");
						break;
					}
				}
			}
			
		case 11:
			
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				if (key == 1)
				{
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
				}
				if (key == 2)
				{
					system("cls");
					cout << " Максимальный элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					cin >> choice;
					if (choice == 1)
					{
						_Dmatrix.show();
						cout << " Максимальный элемент первой матрицы = " << _Dmatrix.maxElem() << endl;
						system("pause");
						break;
					}
					if (choice == 2)
					{
						_Dmatrix2.show();
						cout << " Максимальный элемент второй матрицы = " << _Dmatrix2.maxElem() << endl;
						system("pause");
						break;
					}
					if (choice == 3)
					{
						_Dmatrix3.show();
						cout << " Максимальный элемент третьей матрицы = " << _Dmatrix3.maxElem() << endl;
						system("pause");
						break;
					}
				}
				if (key == 3)
				{
					system("cls");
					cout << " Максимальный элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					cin >> choice;
					if (choice == 1)
					{
						_Cmatrix.show();
						cout << " Максимальный элемент первой матрицы = " << _Cmatrix.maxElem() << endl;
						system("pause");
						break;
					}
					if (choice == 2)
					{
						_Cmatrix2.show();
						cout << " Максимальный элемент второй матрицы = " << _Cmatrix2.maxElem() << endl;
						system("pause");
						break;
					}
					if (choice == 3)
					{
						_Cmatrix3.show();
						cout << " Максимальный элемент третьей матрицы = " << _Cmatrix3.maxElem() << endl;
						system("pause");
						break;
					}
				}
			}
			
		case 12:
			
			if (flag == false)
			{
				cout << " Матрицы не заполнены \n";
				system("pause");
				break;
			}
			else
			{
				if (key == 1)
				{
					system("cls");
					cout << " Минимальный элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					cin >> choice;
					if (choice == 1)
					{
						_matrix.show();
						cout << " Минимальный элемент первой матрицы = " << _matrix.minElem() << endl;
						system("pause");
						break;
					}
					if (choice == 2)
					{
						_matrix2.show();
						cout << " Минимальный элемент второй матрицы = " << _matrix2.minElem() << endl;
						system("pause");
						break;
					}
					if (choice == 3)
					{
						_matrix3.show();
						cout << " Минимальный элемент третьей матрицы = " << _matrix3.minElem() << endl;
						system("pause");
						break;
					}
				}
				if (key == 2)
				{
					system("cls");
					cout << " Минимальный элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					cin >> choice;
					if (choice == 1)
					{
						_Dmatrix.show();
						cout << " Минимальный элемент первой матрицы = " << _Dmatrix.minElem() << endl;
						system("pause");
						break;
					}
					if (choice == 2)
					{
						_Dmatrix2.show();
						cout << " Минимальный элемент второй матрицы = " << _Dmatrix2.minElem() << endl;
						system("pause");
						break;
					}
					if (choice == 3)
					{
						_Dmatrix3.show();
						cout << " Минимальный элемент третьей матрицы = " << _Dmatrix3.minElem() << endl;
						system("pause");
						break;
					}
				}
				if (key == 3)
				{
					system("cls");
					cout << " Минимальный элемент какой матрицы найти : 1 2 3 \n";
					cout << " Выш выбор : ";
					cin >> choice;
					if (choice == 1)
					{
						_Cmatrix.show();
						cout << " Минимальный элемент первой матрицы = " << _Cmatrix.minElem() << endl;
						system("pause");
						break;
					}
					if (choice == 2)
					{
						_Cmatrix2.show();
						cout << " Минимальный элемент второй матрицы = " << _Cmatrix2.minElem() << endl;
						system("pause");
						break;
					}
					if (choice == 3)
					{
						_Cmatrix3.show();
						cout << " Минимальный элемент третьей матрицы = " << _Cmatrix3.minElem() << endl;
						system("pause");
						break;
					}
				}
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


=========================================================
	#include "stdafx.h"
#include <iostream>
using namespace std;

class MMassiveInt
{
private:
    class submasint;// подкласс строк матрицы (объявление)
    int row, col; // количества строк и колонок матрицы
    submasint *arrint; // указатель на массив подкласса строк матрицы
    class submasint// подкласс строк матрицы (реализация)
    {
    public:
        int *sarrint;
        // конструктор по умолчанию необходим для создания массива указателей на класс подстрок матрицы
        submasint() {}
        submasint(int size)
        {
            sarrint = new int[size]; // создание массива целочисленных данных
            for (int i = 0; i < size; i++)//инициализация полей нулями
            {
                sarrint[i] = 0;
            }
        }
        int & operator [] (int i) // оператор [] возвращает ссылку на int
        {
            return sarrint[i];
        }
        // деструктор не нужен, если если его поставить, то строки матрицы будут 
        // удаляться до того, как заполнится вся матрица
        //      ~submasint()   
        //{
        //  if (sarrint != nullptr) delete[] sarrint;
        //}
    };

public:
    MMassiveInt(const int rows, const int cols) //класс матрица целых чисел
    {
        rows < 1 ? row = 1: row = rows; // защита от ввода количества строк или столбцов менее 1
        cols < 1 ? col = 1: col = cols;
        // создание массива указателей с использованием конструктора по умолчанию (без параметров)
        arrint = new submasint [row]; 
        for (int i = 0; i < row; i++)
        {
            // создания строк матрицы. если у подкласса строк матрицы будет деструктор,
            // то строки будут удаляться в каждей итерации цикла
            arrint[i] = submasint(col);
        }
    }
    submasint & operator [] (int i)// оператор [] возвращает ссылку на подкласс строк матрицы
    {
        return arrint[i];
    }
    int GetCol() // метод получения количества колонок матрицы
    {
        return col;
    }
    int GetRow()// метод получения количества строк матрицы
    {
        return row;
    }
    ~MMassiveInt()
    {
        for (int i = 0; i < row; i++)
        {// удаление строк матрицы
            if (arrint[i].sarrint!=nullptr)
            delete[]  (arrint[i].sarrint);
        }
        if (arrint!=nullptr)
        delete[] arrint;// удаление массива указателей на строки матрицы
    }
};
int main()
{
    int mrow = 2, mcol = 3; // инициализация значения количество строк и столбцов матрицы
    MMassiveInt mas(mrow, mcol); // создание двумерного массива, и инициализация его полей нулями
    // вывода матрицы в консоль 
    for (int i = 0; i < mas.GetRow(); i++)
        {
            for (int k = 0; k < mas.GetCol(); k++)
            {
                cout << mas[i][k] << "\t";
            }
            cout << endl;
        }
    system("Pause");
    return 0;
}
