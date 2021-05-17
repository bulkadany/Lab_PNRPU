#include <iostream>
#include <istream>

using namespace std;

class pair1
{
public:
	int first;
	int second;

	pair1() { first = 0; second = 0; };
	pair1(long a, int b) { first = a; second = b; };
	pair1(const pair1& p) { first= p.first; second = p.second; };
	~pair1() {};
	pair1& operator=(const pair1& p)//Операция присваивания
	{
		if (&p == this) return *this;
		first = p.first;
		second = p.second;
	}
	pair1 operator*(pair1& k)
	{
		first *= k.first;
		second *= k.second;
		return *this;
	}

	friend bool operator > (const pair1& p, const pair1& c)
	{
		if ((p.first + p.second) > (c.first + c.second)) return true;
		else return false;
	}
	friend bool operator < (const pair1& p, const pair1& c)
	{
		if ((p.first + p.second) < (c.first + c.second)) return true;
		else return false;
	}
	friend ostream& operator <<(ostream& out, const pair1& p)
	{
		return(out << p.first << "," << p.second);
	}
	friend istream& operator >> (istream& in, pair1& p)
	{
		cout << "Первое число: "; in >> p.first;
		cout << "Второе число: "; in >> p.second;
		return in;
	}

};

