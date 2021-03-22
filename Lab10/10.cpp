#include<iostream>
using namespace std;
int n, m;

int** make_matr()
{
	int** matr;
	int i, j;
	matr = new int* [n*m];
	for (i = 0; i < n; i++)
	{
		matr[i] = new int[m];
		for (j = 0; j < m; j++)
		{
			matr[i][j] = rand() % 100 - 50;
		}
	}
	return matr;
}

void vivod(int** a)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int** del(int** a, int ns, int ms)
{
	int i, j;
	for (i = 0; i < ns - 1; i++)
	{
		for (j = ms - 1; j < m - 1; j++)
		{
			a[i][j] = a[i][j + 1];
		}
	}
	for (i = ns - 1; i < n - 1; i++)
	{
		for (j = 0; j < ms - 1; j++)
		{
			a[i][j] = a[i + 1][j];
		}
		for (j = ms - 1; j < m - 1; j++)
		{
			a[i][j] = a[i + 1][j + 1];
		}
	}
	n = n - 1;
	m = m - 1;
	return a;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int** a;
	cout << "������� ���������� ����� �������: ";
	cin >> n;
	cout << "������� ���������� �������� �������: ";
	cin >> m;
	a=make_matr();
	cout << "������: "<<endl;
	vivod(a);
	int ns, ms;
	cout << "������� ����� ������ ��� ��������: ";
	cin >> ns;
	cout << "������� ����� ������� ��� ��������: ";
	cin >> ms;
	a = del(a, ns, ms);
	cout << "������ ����� ��������: "<<endl;
	vivod(a);
	for (int i = 0; i < n; i++)
	{
		delete a[i];
	}
		delete[] a;
	return 0;
}