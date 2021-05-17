#include <iostream>
#include "list.h"
#include "Money.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Класс-контейнер\n\n";
	cout << "Создаем два списка размерами 5, заполненных int значениями\n";
	list<int>a(5), b(5);
	cout << "Заполняем списки\n";
	cin >> a;
	cin >> b;
	cout << "Выводим списки\n";
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

	cout << "Создаем два списка размерами 5, заполненных float значениями\n";
	list<float>c(5), d(5);
	cout << "Заполняем списки\n";
	cin >> c;
	cin >> d;
	cout << "Выводим списки\n";
	cout << "a: ";
	cout << c << endl;
	cout << "b: ";
	cout << d << endl << endl;
	cout << "Доступ по индексу в списке b\nВведите индекс: ";
	cin >> in;
	cout << "Элемент с " << in << " индексом: ";
	cout << d[in] << endl << endl;
	cout << "Определение размера списка а\nРазмер списка а: ";
	cout << c() << endl << endl;
	cout << "Сложение элементов списков a[i] + b[i]\n";
	c + d;
	cout << endl;

	cout << "Создаем два списка размерами 5, заполненных double значениями\n";
	list<double>e(5), f(5);
	cout << "Заполняем списки\n";
	cin >> e;
	cin >> f;
	cout << "Выводим списки\n";
	cout << "a: ";
	cout << e << endl;
	cout << "b: ";
	cout << f << endl << endl;
	cout << "Доступ по индексу в списке b\nВведите индекс: ";
	cin >> in;
	cout << "Элемент с " << in << " индексом: ";
	cout << f[in] << endl << endl;
	cout << "Определение размера списка а\nРазмер списка а: ";
	cout << e() << endl << endl;
	cout << "Сложение элементов списков a[i] + b[i]\n";
	e + f;
	cout << endl;

	cout << "\nПользовательский класс\n\n";

	cout << "Заполним класс Money\n";
	long rub;
	int kop;
	cout << "Рубли: "; cin >> rub;
	cout << "Копейки: "; cin >> kop;
	Money q(rub,kop);
	cout << "Вывод\n";
	cout << q;

	cout << "\n\nКонтейнер, содержащий элементы пользовательского класса\n\n";
	cout << "Создаем два списка размерами 5, заполненных Money значениями\n";
	list<Money>w(5), r(5);
	cout << "Заполняем списки\n";
	cin >> w;
	cin >> r;
	cout << "Выводим списки\n";
	cout << "a: ";
	cout << w << endl;
	cout << "b: ";
	cout << r << endl << endl;
	cout << "Доступ по индексу в списке b\nВведите индекс: ";
	cin >> in;
	cout << "Элемент с " << in << " индексом: ";
	cout << r[in] << endl << endl;
	cout << "Определение размера списка а\nРазмер списка а: ";
	cout << w() << endl << endl;
	cout << "Сложение элементов списков a[i] + b[i]\n";
	w + r;
	cout << endl;

}