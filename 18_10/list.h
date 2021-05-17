#include <iostream>

using namespace std;


class List {
private:
    int size = 5; // Размер вектора
    int* data;// Указатель на динамический массив значений вектора

public:
    List(); // Конструктор с параметрами: выделяет память под size элементов и заполняет их значением data
    List(const List&); // Конструктор копирования
    ~List(); // Деструктор

    List& operator =(const List&); // Операция присваивания
    int& operator [](int); // Операция доступа по индексу
    int operator ()(); // Операция, возвращающая длину вектора

    friend ostream& operator <<(ostream& out, List const&);
    friend istream& operator >>(istream& in, List&);

    friend bool operator > (const List& p, const List& c)
    {
        int summ1 = 0, summ2 = 0;
        for (int i = 0; i < p.size; i++)
        {
            summ1 += p.data[i];
            summ2 += c.data[i];
        }
        if (summ1 > summ2) return true;
        else return false;
    }
    friend bool operator < (const List& p, const List& c)
    {
        int summ1 = 0, summ2 = 0;
        for (int i = 0; i < p.size; i++)
        {
            summ1 += p.data[i];
            summ2 += c.data[i];
        }
        if (summ1 < summ2) return true;
        else return false;
    }

    List operator*(const List& p)
    {
        for (int i = 0; i < p.size; i++)
        {
            data[i] = data[i] * p.data[i];
        }
        return *this;
    }

};
List::List() {

    this->size = size;
    this->data = new int[size];
    for (int i = 0; i < size; i++) this->data[i] = 0;
}

List::List(const List& list) {
    size = list.size;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = list.data[i];

}

List::~List() {
    delete[] data;
    data = 0;
}

List& List::operator =(const List& list) {
    if (this == &list) return *this;
    size = list.size;

    if (data != 0) delete[]data;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = list.data[i];



    return *this;
}

int& List::operator [](int index) {
    if (index < 0) throw 2;
    if (index >= size) throw 3;
    return data[index];
}

int List::operator ()() {
    return size;
}

ostream& operator <<(ostream& out, const List& list)
{
    for (int i = 0; i < list.size; i++) out << list.data[i] << " ";
    return out;
}

istream& operator >>(istream& in, List& list) {

    for (int i = 0; i < list.size; i++) in >> list.data[i];
    return in;
}