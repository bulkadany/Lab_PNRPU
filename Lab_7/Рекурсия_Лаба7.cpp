#include <iostream>
using namespace std;

void func(int s, int& k)
{
    k = 0;
    while (s > 0)
    {
        s = s / 10;
        k += 1;
    }
    return;
}

int main()
{
    int s, k;
    cout << "Enter number s ="; cin >> s;
    cout << "number of digits k=";
    func(s, k);
    cout << k << endl;
    return 0;
}