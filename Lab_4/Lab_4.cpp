#include <iostream>            
#include <time.h>
using namespace std;

int main()
{
   setlocale(LC_ALL, "ru");
   int M[20];
   int i, N;
   bool k = false;

   
   do 
   {
   	cout << "Задайте массив" << endl;
   	cin >> N;
   }
   while (N < 0);

   srand(time(0));
   cout << "Массив:" << endl;
   for (i = 0; i < N; i++)
   {
      M[i] = rand() % 100; 
      cout << M[i] << " ";
   }
   


   cout << "\n" << "Преобразованный массив:" << endl;
   if (M[0] != 0)
      cout << M[0] << " ";

   for (i = 1; i < N; i++)
   {
      if (M[i] != 0)
      {
         if (M[i] % 2 == 1)
         cout << (M[i]) << " ";
         else
	  {
	     if ((M[i] % 2 == 0) && (k == false))
	     {
               k = true;
               cout << M[i] << " " << (M[i - 1] + 2) << " ";
            }
            else
               if (M[i] % 2 == 0)
               cout << M[i] << " ";
         }
      }
   }
   if (M[0] % 2 == 0)
   cout << "\n" << "Не существует элемента перед первым четным элементом массива " << endl << "Ищем следующий чётный элемент";
}
