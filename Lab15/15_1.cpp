#include <iostream>
using namespace std;
int n;
struct country 
{
	string name;
	int size;
};
void sort(country* arr,int left,int right)
{
	int d;
	string f;
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (arr[i].size > arr[(left + right) / 2].size && i < right)
			i++;
		while (arr[j].size < arr[(left + right) / 2].size && j > left)
			j--;
		if (i <= j)
		{
			d = arr[i].size;
			arr[i].size = arr[j].size;
			arr[j].size = d;
			f = arr[i].name;
			arr[i].name = arr[j].name;
			arr[j].name = f;
			i++;
			j--;
		}
		if (i < right)
		{
			sort(arr, i, right);
		}
		if (j > left)
		{
			sort(arr, left, j);
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
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
	sort(st, 0, n - 1);
	cout << "После сортировки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Название страны "<< i + 1 << " : "<< st[i].name;
		cout << endl;
		cout << "Числленность населения " << i + 1 << " страны: " << st[i].size;
	}
}