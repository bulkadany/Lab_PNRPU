#include <iostream>
using namespace std;
struct country
{
	string name;
	int size;
};
void ShellSort(country* a,int n)
{
	int h = n / 2;
	while (h > 0)
	{
		for (int i = 0; i < n - h; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (a[j].size < a[j + h].size)
				{
					int d = a[j].size;
					a[j].size = a[j+h].size;
					a[j+h].size = d;
					string f = a[j].name;
					a[j].name = a[j+h].name;
					a[j+h].name = f;
					j -= h;
				}
				else
					j = -1;
			}
		}
		h /= 2;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите кол-во стран: ";
	cin >> n;
	country* st = new country[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Название страны: ";
		cin >> st[i].name;
		cout << "Числленность населения: ";
		cin >> st[i].size;
	}
	ShellSort(st, n);
	cout << "После сортировки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Название страны " << i + 1 << " : " << st[i].name;
		cout << endl;
		cout << "Числленность населения " << i + 1 << " страны: " << st[i].size;
	}
}