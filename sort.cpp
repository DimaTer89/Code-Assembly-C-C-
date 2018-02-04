setlocale(LC_ALL, "rus");
	srand(time(0));
	int a[N], b[M], c[N + M] = {};
	int *ptrA, *ptrB, *ptrC;
	int i, j, k=0;
	ptrA = a;
	cout << " Исходный массив A[n] \n";
	for (int i = 0; i < N; i++, ptrA++)
	{
		*ptrA = rand() % 41 - 20;
		cout << " " << *ptrA << "  ";
	}
	cout << endl;
	ptrB = b;
	cout << " Исходный массив B[m] \n";
	for (i = 0; i < M; i++, ptrB++)
	{
		*ptrB = rand() % 41 - 20;
		cout << " " << *ptrB << "  ";
	}
	cout << endl;
	int tmp;
	for (i = N - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
	ptrA = a;
	cout << " Отсортированный массив A[n] \n";
	for (i = 0; i < N; i++, ptrA++)
	{
		cout << " " << *ptrA << "  ";
	}
	cout << endl;
	for (i = M - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (b[j]>b[j+1])
			{
				tmp = b[j+1];
				b[j+1] = b[j];
				b[j] = tmp;
			}
		}
	}
	ptrB = b;
	cout << " Отсортированный массив B[m] \n";
	for (i = 0; i < M; i++, ptrB++)
	{
		cout << " " << *ptrB << "  ";
	}
	cout << endl;
	ptrA = a;
	ptrB = b;
	ptrC = &c[0];
	while (k<N+M)
	{
		if (*ptrA >= *ptrB) {
			*ptrC = *ptrB;
			ptrB++;
			
		}
		else {
			*ptrC = *ptrA;
			ptrA++;
		}
		k++;
		ptrC++;
	}
	
	cout << " Массив C[N+M] \n";
	for (i = 0; i < N + M; i++, ptrC++)
	{
		cout << " " << *ptrC << "  ";
	}
	cout << endl;
	system("pause");
