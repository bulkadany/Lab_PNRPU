#include <iostream>

using namespace std;

class Money
{
public:
	long rub;
	int kop;

	Money() { rub = 0; kop = 0; };
	Money(long a, int b) { rub = a; kop = b; };
	Money(const Money& p) { rub = p.rub; kop = p.kop; };
	~Money() {};
	Money& operator=(int p)//Операция присваивания
	{
		rub = 0;
		kop = 0;
		return *this;
	};

	friend istream& operator>> (istream& in, Money& p)
	{
		cout << "Рубли: "; cin >> p.rub;
		cout << "Копейки: "; cin >> p.kop;
		return in;
	}

	friend ostream& operator<< (ostream& out, const Money& p)
	{
		out << p.rub << ',' << p.kop << "  ";
		return out;
	}
	Money operator+(const Money& p)
	{
		long q = rub * 100 + kop + p.rub*100 + p.kop;
		long rub1 = q / 100;
		int kop1 = q % 100;
		Money tmp(rub1, kop1);
		return tmp;
	}
};