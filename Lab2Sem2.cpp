#include <iostream>
#include <iomanip>
using namespace std;
void printMatrix(double** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setprecision(3) << arr[i][j] << "  ";
		}
		cout << endl;
	}
}
//реализован доступ по приведенному индексу, функция выводит на экран матрицу с 2 задания
void printMatrix2(double* arr, const int m, const int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setprecision(3) << *(arr + i*m +j) << "  ";
		}
		cout << endl;
	}
}
//поиск минимального елемента в 1 задании
double minElement(double** arr, int m, int n, int* x, int* y) {
	double min = 1000000;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] <= min) {
				min = arr[i][j];
				*x = i;
				*y = j;
			}
		}

	}
	return min;
}
//поиск значимого элемента в 2 задании
void valuableElement(double* a, const int m, const int n, double* sums, double* valuableElements) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (*(a + i * n + j) <= sums[i]) {
				valuableElements[i*m +j] = *(a + i * n + j);				
			}
		}
	}
}
//нахождение суммы каждого рядка матрици для 2 задания
void sum(double* a, const int m, const int n, double* sums) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sums[i] += *(a + i * n + j);
		}
	}
}
//выводит на экран вектор из важных элементов
void printVector(double* a, const int m) {
	for (int i = 0; i < m; i++) {
		if (a[i] != 1000000) {
			cout << a[i] << " ";
		}		
	}
	cout << endl;
}
//количество важных элементов из 2 задания
int valElCount(double* a, const int m) {
	int c = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] != 1000000) {
			c +=1;
		}
	}
	return c;
}
//печатает индексы минимального элемента на экран (1 задание)
void indexesOfMinElement(int x, int y) {
	cout << "with indexes[" << x << "][" << y << "]";
}
//меняет матрицу в соответствии с условием 1 задания
void ChangeMatrix(double** arr, int m, int n, int x, int y) {
	for (int i = x; i < m; i++) {
		if ((i + 1) < m) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = arr[i + 1][j];
			}
		}
	}
	for (int i = 0; i < m; i++) {		
			for (int j = y; j < n; j++) {
				if ((j + 1) < n) {
					arr[i][j] = arr[i][j + 1];
				}				
			}		
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == m - 1) {
				arr[i][j] = 0;
			}
			if (j == n - 1) {
				arr[i][j] = 0;
			}
		}
	}
}
int main()
{
	cout << "Array of random numbers" << endl;
	C:
	cout << "Choose difficulty level(1 or 2):" << endl;
	int d = 1;
	int m, n;
	cin >> d;	
	cout << "Enter integer value of heigth(m) of matrix: " << endl;
	cin >> m;
	cout << "Enter integer value of width(n) of matrix: " << endl;
	cin >> n;
// для 1 задания
	if (d == 1)
	{

		double** inputMatrix = new double* [m];
		for (int i = 0; i < m; i++) {
			inputMatrix[i] = new double[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << "Enter any integer number" << endl;
				cin >> inputMatrix[i][j];
			}

		}
		cout << "Initial matrix: " << endl;
		printMatrix(inputMatrix, m, n);
		int x, y;
		double min = minElement(inputMatrix, m, n, &x, &y);
		cout << "The last minimal element of the matrix: " << min << endl;
		indexesOfMinElement(x, y);
		ChangeMatrix(inputMatrix, m, n, x, y);
		cout << "Cghanged matrix: " << endl;
		printMatrix(inputMatrix, m, n);
		for (int i = 0; i < m; i++) {
			delete[] inputMatrix[i];
		}
		delete[] inputMatrix;
	}
	//для 2 задания
	else if (d == 2) {
		//получить элементы массива от пользователя
		double* a = (double*)malloc(m * n * sizeof(double));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << "Enter any integer number" << endl;
				cin >> *(a+i*m+j);
			}
		}
		printMatrix2(a, m, n);
		double* sums = (double*)malloc(m*sizeof(double));
		for (int o = 0; o < m; o++) {
			sums[o] = 0;
		}
		double* valuableElements = (double*)malloc(m * n * sizeof(double));
		for (int o = 0; o < m*n; o++) {
			valuableElements[o] = 1000000;
		}
		
		sum(a, m, n, sums);
		cout << "Sums of each row" << endl;
		printVector(sums, m);
		valuableElement(a, m, n, sums, valuableElements);
		cout << "Vector of valuable elements" << endl;
		printVector(valuableElements, (m*n));
		cout << "Amount of valuable elements: " << valElCount(valuableElements, (m * n));
		free(a);
		free(sums);
	}
	else goto C;//чтобы пользовватель выбрал 1 или 2 задание
}