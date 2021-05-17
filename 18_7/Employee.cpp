#include "Employee.h"

Employee::Employee(void) :Person()
{
	salary = 0;
	post = "";
}
Employee::~Employee(void)
{
}
Employee::Employee(string n, int a, float s, string p) :Person(n, a)
{
	salary = s;
	post = p;
}
Employee::Employee(const Employee& e)
{
	this->name = e.name;
	this->age = e.age;
	this->salary = e.salary;
	this->post = e.post;
}
void Employee::set_salary(float s)
{
	salary = s;
}
void Employee::set_post(string p)
{
	post = p;
}
void Employee::Show()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "salary:" << salary << endl;
	cout << "post:" << post << endl;
}

Employee& Employee::operator=(const Employee& e)
{
	if (&e == this) return *this;
	name = e.name;
	age = e.age;
	salary = e.salary;
	post = e.post;
	return *this;
}

void Employee::Input()
{
	cout << "name:"; cin >> name;
	cout << "age:"; cin >> age;
	cout << "salary:"; cin >> salary;
	cout << "post:"; cin >> post;
}

