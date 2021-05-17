#include "Tree.h"
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;
Tree::~Tree(void)
{
	if (beg != nullptr) { delete[]beg; }
	beg = nullptr;
}
Tree::Tree(void)
{
	beg = nullptr;
	cur = 0;
	size = 0;
}
Tree::Tree(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
void Tree::Add()
{
	Object* p;
	cout << "1.Person" << endl
		<< "2.Employee" << endl;
	int num;
	cin >> num;
	if (num == 1)
	{
		Person* a = new Person;
		a->Input();
		p = a;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else if (num == 2)
	{
		Employee* b = new Employee;
		b->Input();
		p = b;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}
void Tree::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}
void Tree::Show_unit(int a)
{
	beg[a]->Show();
}
int Tree::operator()()
{
	return cur;
}
void Tree::Del()
{
	if (cur == 0) return;
	cur--;
}
void Tree::Handle_Event(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->Handle_Event(e);
			p++;
		}
	}
}
