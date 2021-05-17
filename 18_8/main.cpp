#include <iostream>
#include <Windows.h>
#include "list.h"

using namespace std;

int main() {
    //контролируемый блок
    setlocale(LC_ALL, "ru");
    try {
        int l;
        cout << "Введите длину списка(она должна быть не больше 3)\n";
        cin >> l;
        List list(l);
        cout << "List:" << list << endl;
        cout << "Заполните список\n";
        cin >> list;

        int index;
        cout << "Введите номер элемента: "; cin >> index;
        // Вывод элемента с номером i, если номер больше 2 или меньше 0, то //генерируется исключительная ситуация
        cout << list[index] << endl;
    }
    catch (int) {
        cout << "ERROR!!!" << endl;
    }
}
