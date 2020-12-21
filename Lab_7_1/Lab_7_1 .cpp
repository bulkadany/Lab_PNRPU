#include <iostream>
using namespace std;

int F(int a, int b)
{
	cout << "\n\nРезультат умножения целых чисел: " << a * b << endl;
	return 0;
}

double F(double a, double b)
{
	cout << "\n" << "Результат умножения комплексных чисел: " << a * b << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int a, b;
	double c, d;
	
	cout << "Введите два целых множителя: ";
	cin >> a >> b;
	
	cout << "\nВведите два комплексных множителя: ";
	cin >> c >> d;
	
	F(a, b); F(c, d);
}