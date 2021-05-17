#include <iostream>
#include <fstream>

using namespace std;

class Money
{
	long rub;
	int kop;
public:
	Money() { rub = 0; kop = 0; };
	Money(long a, int b) { rub = a; kop = b; };
	Money(const Money& p) { rub = p.rub; kop = p.kop; };
	~Money() {};
	Money& operator=(const Money& p)//Операция присваивания
	{
		if (&p == this) return *this;
		rub = p.rub;
		kop = p.kop;
	}

	friend bool operator > (const Money& p, const Money& c)
	{
		if ((p.rub * 100 + p.kop) > (c.rub * 100 + c.kop)) return true;
		else return false;
	}
	friend bool operator < (const Money& p, const Money& c)
	{
		if ((p.rub * 100 + p.kop) < (c.rub * 100 + c.kop)) return true;
		else return false;
	}
	friend bool operator ==(const Money& p, const Money& c)
	{
		if ((p.rub * 100 + p.kop) == (c.rub * 100 + c.kop)) return true;
		else return false;
	}
	friend istream& operator >>(istream& in, Money& p)
	{
		cout << "Рубли: "; in >> p.rub;
		cout << "Копейки: "; in >> p.kop;
		return in;
	};

	friend ostream& operator <<(ostream& out, const Money& p)
	{
		return(out << p.rub << "," << p.kop << endl);
	}

	Money& operator++()
	{
		kop++;
		return *this;
	}

	Money operator/(int k)
	{
		Money tmp;
		long q = (rub * 100 + kop) / k;
		tmp.rub = q / 100;
		tmp.kop = q % 100;
		return tmp;
	}

	Money operator++(int)
	{
		kop++;
		return *this;
	}

	friend fstream& operator>>(fstream& fin, Money& p)
	{
		fin >> p.rub; 
		fin >> p.kop;
		return fin;
	};

	friend fstream& operator<<(fstream& fout, const Money& p)
	{
		fout << p.rub << "\n" << p.kop << "\n";
		return fout;
	};

};

int make_file(const char* file_name)
{
	fstream stream(file_name, ios::out | ios::trunc); //открыть для записи
	if (!stream) return -1;//ошибка открытия файла

	int n; //количество элементов
	Money p;
	cout << "Введите количество элементов\n"; cin >> n;
	cout << "Введите " << n << " элементов\n\n";
	for (int i = 0; i < n; i++)
	{
		cin >> p; //Ввод атрибутов объекта из стандартного потока
		stream << p << "\n"; //запись объекта в файловый поток
	}
	stream.close();//закрытие потока
	return n;//возвращение количества элементов
}

int print_file(const char* file_name)
{
	fstream stream(file_name, ios::in); //открытие файла для чтения
	if (!stream) return -1;//ошибка открытия файла
	Money p; int i = 0;
	while (stream >> p)
	{
		cout << p;
		i++;
	}
	stream.close();//закрытие файла
	return i;
}

int del_file(const char* file_name, Money tmp)
{
	fstream temp("temp", ios::out);//открытие для записи
	fstream stream(file_name, ios::in);//открытие для чтения
	if (!stream) return -1;//ошибка открытия файла
	Money p; int i = 0;
	while (stream >> p)//пока идет чтение файла
	{
		if (stream.eof()) break; //проверка на конец файла
		i++;
		if (p < tmp) temp << p; //если элемент меньше заданного значения то записываем его в файл temp
	}
	stream.close(); temp.close();
	remove(file_name); //удаляем старый файл
	rename("temp", file_name);//переименовать temp
	return i;
}

int um_zap_file(const char* file_name, Money tmp)
{
	fstream temp("temp", ios::out);
	fstream stream(file_name, ios::in);
	if (!stream) return -1;
	Money p; int i = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p == tmp)
		{
			p = p / 2;
			temp << p;
		}
		else temp << p;
	}
	stream.close(); temp.close();
	remove(file_name); //удаляем старый файл
	rename("temp", file_name);//переименовать temp
	return i;
}

int add_file(const char* file_name, int number, int col, Money*arr)
{
	fstream temp("temp", ios::out);
	fstream stream(file_name, ios::in);
	if (!stream) return -1;
	Money p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (i == number)
		{
			temp << p;
			for (int j = 0; j < col; j++)
			{
				temp << arr[i];
				l++;
			}
		}
		else temp << p;
	}
	stream.close(); temp.close();
	remove(file_name); //удаляем старый файл
	rename("temp", file_name);//переименовать temp
	return l;
}

