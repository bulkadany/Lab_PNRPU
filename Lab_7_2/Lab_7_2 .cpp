//a1*a2 +  a2*a3 + a3*a4 + ...

#include <iostream>
using namespace std;

void sum(int n, int first, ...)
{
	int S = 0, m = 0;
	int *p = &first;
	while (n--)
	{
		m = *p;
		p++;
		m *= *p;
		S += m;
	}
	cout << S;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Результат с 5 параметрами: ";
	sum(5, 1, 2, 3, 4, 5);
	cout << "\n" << "Результат с 10 параметрами: ";
	sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	cout << "\n" << "Результат с 12 параметрами: ";
	sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	cout << endl;
}