#include <C:\Users\skyst\source\repos\Class11\Zadacha_2\Pair.h>
#include <iostream>
#include <list>
#include "List.h"
#include <queue>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n, pos, a, b, key;
	cout << "Количество элементов списка:";
	cin >> n;
	List<Pair>l(n);
	l.Print();
	cout << "Позиция списка:";
	cin >> pos;
	Pair p = l.srednee(n);
	l.Add(p, pos, n);
	l.Print();
	p = l.srednee(n);
	l.vichest(p);
	l.Print();
	cout << "Диапазон от:"; cin >> a; cout << "до:"; cin >> b;
	cout << "Çíà÷åíèå first èç äèàïîçîíà:"; cin >> key;
	l.Del(n, a, b, key);
	l.Print();
}
