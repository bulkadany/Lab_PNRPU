#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Формируем 2 списка длиной 10,заполненные нулями\n";
	list a(10), b(10);
	cout << "Выводим списки\n";
	cout << "a: ";
	cout << a << endl;
	cout << "b: ";
	cout << b << endl << endl;
	cout << "Заполняем списки\n";
	cin >> a;
	cin >> b;
	cout << "\nВыводим списки\n";
	cout << "a: ";
	cout << a << endl;
	cout << "b: ";
	cout << b << endl << endl;
	cout << "Доступ по индексу в списке b\nВведите индекс: ";
	int in;
	cin >> in;
	cout << "Элемент с " << in << " индексом: ";
	cout << b[in] << endl << endl;
	cout << "Определение размера списка а\nРазмер списка а: ";
	cout << a() << endl << endl;
	cout << "Сложение элементов списков a[i] + b[i]\n";
	a + b;
	cout << endl;
	cout << "Переход влево к элементу с номером n\n";
	cout << "Введите n\n";
	int n;
	cin >> n;
	a - n;



}