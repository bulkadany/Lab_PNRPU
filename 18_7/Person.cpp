#include "Person.h"
#include "Event.h"
Person::Person(void)
{
	name = "";
	age = 0;
}
Person::~Person(void)
{
}
Person::Person(string n, int a)
{
	name = n;
	age = a;
}
Person::Person(const Person& p)
{
	this->name = p.name;
	this->age = p.age;
}
void Person::set_name(string n)
{
	name = n;
}
void Person::set_age(int n)
{
	age = n;
}
Person& Person::operator=(const Person& p)
{
	if (&p == this) { return *this; }
	name = p.name;
	age = p.age;
	return*this;
}
istream& operator>>(istream& in, Person& p)
{
	cout << "name:"; in >> p.name;
	cout << "age:"; in >> p.age;
	return in;
}
ostream& operator<<(ostream& out, const Person& p)
{
	out << "name:" << p.name << endl;
	out << "age:" << p.age << endl;
	return out;
}
void Person::Show()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
}
void Person::Input()
{
	cout << "name:"; cin >> name;
	cout << "age:"; cin >> age;
}
void Person::Handle_Event(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "name:" << get_name() << endl;
			break;
		}
	}
}
