#include <iostream>

using namespace std;

class iterator1
{
	friend class list; //cделали класс list дружественным
private:
	int* elem;
public:
	iterator1() { elem = 0; };
	iterator1(const iterator1& p) { elem = p.elem; };

};
class list
{
private:
	int size; //размер списка
	int* data; // указатель на динамический массив значений списка
	iterator1 beg; //указатель на первый элемент списка
	iterator1 end; //указатель на элемент следующий за последним
	iterator1 uk_elem; //указатель на нужный нам
public:
	list(int s);
	list(const list& p);
	~list();

	list& operator=(const list& p); //присваивание
	int& operator[](int index); //доступ по индексу
	int operator()(); //получение длины списка
	friend istream& operator>>(istream& in, list& p); //ввод
	friend ostream& operator<<(ostream& out, const list& p); //вывод
	void operator+(const list& p);//сложение элементов списков
	//-n переход влево к элементу с номером n
	iterator1 first() { return beg; };
	iterator1 last() { return end; };
	iterator1 operator-(int n)
	{
		end.elem -= n;
		cout << *end.elem;
		return uk_elem;
	}
};

list::list(int s)
{
	size = s;
	data = new int[size];
	data[0] = 0;
	for (int i = 1; i < size; i++)
	{
		data[i] = 0;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}

list::list(const list& p)
{
	size = p.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = p.data[i];
	}
	beg = p.beg;
	end = p.end;
}

list::~list()
{
	delete[] data;
	data = 0;
}

list&list::operator=(const list& p)
{
	if (this == &p) return *this;
	size = p.size;
	if (data != 0) delete[] data;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = p.data[i];
	}
	beg = p.beg;
	end = p.end;
	return *this;
	
}

int& list::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "Индекс меньше длины списка\n";
}

int list::operator()()
{
	return size;
}

istream& operator>>(istream& in, list& p)
{
	cout << "Заполните " << p.size << " элементов\n";
	for (int i = 0; i < p.size; i++)
	{
		in >> p.data[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const list& p)
{
	for (int i = 0; i < p.size; i++)
	{
		out << p.data[i] << ' ';
	}
	return out;
}

void list::operator+(const list& p)
{
	cout << "Введите индекс: \n";
	int index;
	cin >> index;
	data[index] += p.data[index];
	cout << "Значение: " << data[index] << endl;
}