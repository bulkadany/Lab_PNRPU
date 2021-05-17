#include "Employee.h"
#include "Object.h"
#include "Person.h"
#include "Tree.h"
#include "Dialog.h"
#include "Event.h"
void main()
{
	Dialog d;
	d.Execute();

	Person* a = new Person;
	a->Input();
	a->Show();

	Employee* b = new Employee;
	b->Input();
	b->Show();

	Tree t(10);
	Object* p = a;
	t.Add();
	t.Add();
	t.Show();
	t.Del();
	cout << "tree size:" << t() << endl;

}