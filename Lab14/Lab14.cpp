# include <limits.h>
# include <string.h>
# include <stdio.h>
#include <ctime>
#include <cstdlib>
# define NO_OF_CHARS 256
#include <iostream>

using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}


void qsortRecursive(int* mas, int size) 
{
	
	int i = 0;
	int j = size - 1;

	
	int mid = mas[size / 2];

	
	do 
	{
		
		
		while (mas[i] < mid)
		{
			i++;
		}
		
		while (mas[j] > mid) 
		{
			j--;
		}

		
		if (i <= j) 
		{
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	
	if (j > 0) 
	{
		
		qsortRecursive(mas, j + 1);
	}
	if (i < size)
	{
		
		qsortRecursive(&mas[i], size - i);
	}
}
void Make_TAble(char* str, int size, int badchar[NO_OF_CHARS])

{
	int i;


	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;


	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}
int Interpol(int* arr, int size, int key)
{
	int k = size;
	int left = 0; 
	int right = size - 1; 
	int mid = 0; 
	bool found = false;
	while ((left <= right) && found != true && k != 0)
	{
		mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]); 
		if (arr[mid] < key) left = mid + 1; 
		else if (arr[mid] > key) right = mid + 1; 
		else found = true;
		k--;
	}
	if (arr[left] == key)
	{
		return left;
	}
	else if (arr[right] == key)
	{
		return right;
	}
	else if (k == 0)
	{
		return -1;
	}
}

void search(char* txt, char* pat)
{
	int m = strlen(pat);
	int n = strlen(txt);

	int badchar[NO_OF_CHARS];

	Make_TAble(pat, m, badchar);

	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		if (j < 0)
		{
			cout << "\n Подстрока совпадёт через " << s << " элемента(-ов) строки.";

			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

		}

		else
		{
			s += max(1, j - badchar[txt[s + j]]);
		}
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	char txt[100];
	char pat[50];
	cout << "Поиск Бойера-Мура: " << endl;
	cout << "Введите строку: ";
	gets_s(txt);
	cout << "Введите искомую подстроку: ";
	gets_s(pat);
	search(txt, pat);
	cout << endl;
	int N;
	srand(time(NULL));
	cout << "Введите размер массива: ";
	cin >> N;
	int* mas = new int[N];
	for (int i = 0; i < N; i++)
	{
		mas[i] = rand() % 100;
	}
	qsortRecursive(mas, N);
	cout << "Исходный массив: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << mas[i] << ' ';
	}
	int key;
	cout << endl << "Введите искомый элемент: ";
	cin >> key;
	int q = Interpol(mas, N, key);
	if (q == -1)cout << "Такого элемента нет в массиве!";
	else cout << "Номер искомого элемента: " << Interpol(mas, N, key) + 1;

}