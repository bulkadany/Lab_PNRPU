#include <iostream>
#include <time.h>
using namespace std;

void matrix_sum(int A[100][100], int rows, int cols)
{
	cout << "\n" << "Сумма двух матриц:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << A[j][i] + A[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n, i, j;
	int A[100][100];

	srand(time(0));
	cout << "Введитте размерность квадратной матрицы: ";
	cin >> n;
	cout << "\n" << "Матрица случайных чисел:" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 101;
			cout << A[i][j] << "\t";
		}
		cout << endl << endl;
	}

	cout << "\n" << "Транспонированая матрица:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[j][i] << "\t";
		}
		cout << endl << endl;
	}
	matrix_sum(A, n, n);
}
