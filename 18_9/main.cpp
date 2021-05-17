#include "Money_and_file_work.h"
#include <iostream>
#include <fstream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Money p;
	int k, c;//k - количество элементов с - выбор просто
	char f_name[30];
	Money tmp;
	do
	{
		cout << "1.Создание файла\n2.Печать файла\n3.Удаление записей больше заданного значения\n4.Уменьшение всех записей с заданным значением в 2 раза\n5.Добавление К записей после элемента с заданным номером\n6.Выход\n\n";
		cin >> c;
		cout << endl;
		switch (c)
		{
		case 1:
			cout << "Введите имя файла\n"; cin >> f_name;
			k = make_file(f_name);
			if (k < 0) cout << "Невозможно создать файл\n";
			cout << endl;
			break;
		case 2:
			cout << "Введите имя файла, который хотите напечатать\n"; cin >> f_name;
			k = print_file(f_name);
			if (k < 0) cout << "Невозможно прочитать файл\n";
			if (k == 0) cout << "Файл пустой\n";
			cout << endl;
			break;
		case 3:
			cout << "Введите имя файла\n"; cin >> f_name;
			cout << "Введите значение\n";
			cin >> tmp;
			k = del_file(f_name, tmp);
			if (k < 0) cout << "Невозможно прочитать файл\n";
			if (k == 0) cout << "Файл пустой\n";
			cout << endl;
			break;
		case 4:
			cout << "Введите имя файла\n"; cin >> f_name;
			cout << "Введите значение\n";
			cin >> tmp;
			k = um_zap_file(f_name, tmp);
			if (k < 0) cout << "Невозможно прочитать файл\n";
			if (k == 0) cout << "Файл пустой\n";
			cout << endl;
			break;
		case 5:
			cout << "Введите имя файла\n"; cin >> f_name;
			cout << "Введите номер\n";
			int number;
			cin >> number;
			cout << "Введите количество новых записей\n";
			int col;
			cin >> col;
			Money* arr = new Money[col];
			for (int i = 0; i < col; i++)
			{
				cout << "Введите " << i + 1 << " запись\n";
				cin >> arr[i];
			}
			k = add_file(f_name, number, col, arr);
			if (k < 0) cout << "Невозможно прочитать файл\n";
			if (k == 0) k = add_file(f_name, number, col, arr);
			cout << endl;
			break;
		}
	} while (c != 6);
}