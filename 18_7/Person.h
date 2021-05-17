#pragma once
#include "Object.h"
#include "Event.h"
#include <iostream>
using namespace std;

class Person :public Object
{
public:
	Person(void);
	virtual ~Person(void);
	void Show();
	void Input();
	Person(string, int);
	Person(const Person&);
	string get_name() { return name; }
	int get_age() { return age; }
	void set_name(string);
	void set_age(int);
	Person& operator =(const Person&);
	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, const Person& p);
	void Handle_Event(const TEvent& e);
protected:
	string name;
	int age;
};

