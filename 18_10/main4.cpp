
#include <C:\Users\skyst\source\repos\Class11\Zadacha_2\Pair.h>


#include <iostream>


#include <list>


#include <queue>


using namespace std;






typedef queue<Pair>pq;


typedef list<Pair>lis;






pq make_pq(int n)


{


	pq q;


	Pair p;


	for (int i = 0; i < n; i++)


	{


		cin >> p;


		q.push(p);


	}


	return q;


}






lis copy_pq_to_list(pq q)


{


	lis l;


	while (!q.empty())


	{


		l.push_back(q.front());


		q.pop();


	}


	return l;


}






pq copy_list_to_pq(lis l)


{


	pq q;


	for (auto i = l.begin(); i != l.end(); ++i) q.push(*i);


	return q;


}






void Print(pq q)


{


	lis l;


	while (!q.empty())


	{


		l.push_back(q.front());


		cout << q.front();


		q.pop();


	}


	cout << endl;


	q = copy_list_to_pq(l);


}






Pair Srednee(pq q, int n)


{


	lis l = copy_pq_to_list(q);


	Pair sum;


	while (!q.empty())


	{


		sum = sum + q.front();


		q.pop();


	}


	Pair p(sum / n, sum / n);


	return p;


}






void Add(pq& q, Pair e1, int pos, int& n)


{


	lis l;


	Pair p;


	int i = 1;


	while (!q.empty())


	{


		p = q.front();


		if (i == pos)


		{


			l.push_back(e1);


			n++;


		}


		l.push_back(p);


		q.pop();


		i++;


	}


	q = copy_list_to_pq(l);


}






void vichest(pq& q, Pair p)


{


	Pair temp;


	int sum = p.get_second();


	lis l;


	while (!q.empty())


	{


		temp = q.front();


		l.push_back(temp - sum);


		q.pop();


	}


	q = copy_list_to_pq(l);


}






void Del(pq& q, int& n, int a, int b, int key)


{


	lis l = copy_pq_to_list(q);


	auto i = l.begin();


	auto j = l.begin();


	advance(i, a);


	advance(j, b);


	for (i; i != j; ++i)


	{


		if (i->get_first() == key)


		{


			break;


		}


	}


	if (i != --j)


	{


		l.erase(i);


		n--;


	}


	q = copy_list_to_pq(l);


}






int main()


{


	setlocale(LC_ALL, "ru");


	Pair p;


	pq q;


	int n, pos, a, b, key;


	cout << "Количество элементов списка:";


	cin >> n;


	q = make_pq(n);


	Print(q);


	p = Srednee(q, n);


	cout << "Позиция в списке:";


	cin >> pos;


	Add(q, p, pos, n);


	Print(q);


	p = Srednee(q, n);


	vichest(q, p);


	Print(q);


	cout << "Диапозон от:"; cin >> a; cout << "до:"; cin >> b;


	cout << "Значение из диапозона:"; cin >> key;


	Del(q, n, a, b, key);


	Print(q);






}
