#include <deque>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include "pair.h"

using namespace std;

typedef deque<pair1>turn; //���������� ��� ��� ������ � ��������

turn make_turn(int deque_size)
{
	turn deq(deque_size); //������ �������
	cout << "��������� �������\n";
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
		cout << deq[i] << "  ";
	}
}

pair1 search_max(turn deq)
{
	pair1 max = deq[0];
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
	pair1* arr = new pair1[index];
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
	pair1 max = search_max(deq);
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
		deque<pair1> deq;

		deque<pair1>::iterator deq1 = deq.begin();
		cout << "������� ������ �������\n";
		int deque_size;
		cin >> deque_size;
		deq = make_turn(deque_size);
		cout << "\n������� ������������� � ������\n";
		pair1 max = search_max(deq);
		deq.push_front(max);
		print_turn(deq);
		cout << "\n������� ������ ��� ��������\n";
		int index; cin >> index;
		deq = delete_elem(deq, index);
		print_turn(deq);
		cout << "\n��������� ������� �������� �� ������������ ������� ����������\n";
		deq = umn_elem_max(deq);
		print_turn(deq);
	}
	catch (int)
	{
		cout << "ERROR!\n";
	}
}