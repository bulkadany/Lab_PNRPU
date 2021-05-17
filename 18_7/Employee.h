#pragma once
#include "Person.h"
#include <string>

class Employee : public Person
{
public:
	Employee(void);
	~Employee(void);
	void Show();
	void Input();
	Employee(string, int, float, string);
	Employee(const Employee&);
	float get_salary(void) { return salary; }
	string get_post(void) { return post; }
	void set_salary(float);
	void set_post(string);
	Employee& operator =(const Employee&);
protected:
	float salary;
	string post;
};


