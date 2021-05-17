#include <deque>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include "list.h"

using namespace std;

typedef deque<List>turn; //определяем тип для работы с очередью

turn make_turn(int deque_size)
{
	turn deq(deque_size); //пустая очередь
	cout << "Заполните очередь\n";
	for (int i = 0; i < deq.size(); i++)
	{
		cin >> deq[i];
	}
	return deq;
}

void print_turn(turn deq)
{
	for (int i = 0; i < deq.size(); i++)
	{
		cout << deq[i] << endl;
	}
}

List search_max(turn deq)
{
	List max = deq[0];
	for (int i = 1; i < deq.size(); i++)
	{
		if (deq[i] > max)
		{
			max = deq[i];
		}
	}
	return max;
}

turn delete_elem(turn deq, int index)
{
	List* arr = new List[index];
	for (int i = 0; i < index; i++)
	{
		arr[i] = deq[0];
		deq.pop_front();
	}
	deq.pop_front();
	for (int i = index - 1; i >= 0; i--)
	{
		deq.push_front(arr[i]);
	}
	return deq;
}

turn umn_elem_max(turn deq)
{
	List max = search_max(deq);
	for (int i = 0; i < deq.size(); i++)
	{
		deq[i] = deq[i] * max;
	}
	return deq;
}



int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		deque<List> deq;

		deque<List>::iterator deq1 = deq.begin();
		cout << "Введите размер очереди\n";
		int deque_size;
		cin >> deque_size;
		deq = make_turn(deque_size);
		cout << "\nВставка максимального в начало\n";
		List max = search_max(deq);
		deq.push_front(max);
		print_turn(deq);
		cout << "\nВведите индекс для удаления\n";
		int index; cin >> index;
		deq = delete_elem(deq, index);
		print_turn(deq);
		cout << "\nУмножение каждого элемента на максимальный элемент контейнера\n";
		deq = umn_elem_max(deq);
		print_turn(deq);
	}
	catch (int)
	{
		cout << "ERROR!\n";
	}
}