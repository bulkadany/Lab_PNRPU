#include <iostream> 
 
using namespace std; 
 
struct state_t // 
{ 
 string name; 
 string capital; 
 double population; 
 double area; 
}; 
struct List 
{ 
 state_t data; 
 List* next; 
}; 
List* readFile() 
{ 
 List* first, * p; 
 first = NULL; 
 
 FILE* fp; 
 if ((fp = fopen("data.dat", "rb")) == NULL) 
 { 
 perror("\nОшибка при открытии файла data.dat"); 
 exit(0); 
 } 
 fclose(fp); 
 
 p = new List; 
 if (!feof(fp)) 
 { 
 if (fread(&p->data.name, sizeof(string), 1, fp) != 1) 
 { 
 perror("\nОшибка при открытии файла data.dat"); 
 exit(0); 
 } 
 cout « p->data.name; 
 exit(0); 
 } 
 cout « "Чтение окончено" « endl; 
 return first; 
} 
 
void saveFile(List* first) { 
 if (first == NULL) { 
 cout « "Список пуст" « endl; 
 } 
 else { 
 List* p = first; 
 
 FILE* fp; 
 if ((fp = fopen("data.dat", "wb")) == NULL) { 
 perror("\nОшибка при открытии файла data.dat"); 
 exit(0); 
 } 
 rewind(fp); 
 
 while (!feof(fp) && p != NULL) { 
 fwrite(&p->data.name, sizeof(string), 1, fp); 
 fwrite(&p->data.capital, sizeof(string), 1, fp); 
 fwrite(&p->data.population, sizeof(string), 1, fp); 
 fwrite(&p->data.area, sizeof(float), 1, fp); 
 p = p->next; 
 } 
 fclose(fp); 
 } 
} 
 
List* make() 
{ 
 List* first, * p; 
 first = NULL; 
 p = new List; 
 
 p->data.name = "Россия"; 
 p->data.capital = "Москва"; 
 p->data.population = 146748590; 
 p->data.area = 17098246; 
 p->next = NULL; 
 
 first = p; 
 
 List* h = new List; 
 p->next = h; 
 p = p->next; 
 p->data.name = "Испания"; 
 p->data.capital = "Мадрид"; 
 p->data.population = 47431256; 
 p->data.area = 505990; 
 p->next = NULL; 
 return first; 
 
 List* h = new List; 
 p->next = h; 
 p = p->next; 
 p->data.name = "Германия"; 
 p->data.capital = "Берлин"; 
 p->data.population = 83149300; 
 p->data.area = 357578; 
 p->next = NULL; 
 return first; 
 
 List* h = new List; 
 p->next = h; 
 p = p->next; 
 p->data.name = "Франция"; 
 p->data.capital = "Париж"; 
 p->data.population = 67408000; 
 p->data.area = 640679; 
 p->next = NULL; 
 return first; 
 
 List* h = new List; 
 p->next = h; 
 p = p->next; 
 p->data.name = "Дания"; 
 p->data.capital = "Копенгаген"; 
 p->data.population = 5837213; 
 p->data.area = 43094; 
 p->next = NULL; 
 return first; 
 
 List* h = new List; 
 p->next = h; 
 p = p->next; 
 p->data.name = "Япония"; 
 p->data.capital = "Токио"; 
 p->data.population = 125961625; 
 p->data.area = 377944; 
 p->next = NULL; 
 return first; 
} 
 
void del(List*& first) { 
 if (first == NULL) { 
 cout « "Список пуст" « endl; 
 } 
 else { 
 List* p = first; 
 string population; 
 cout « "Введите государство, которое будет удалено:" « endl; 
 cin » population; 
 while (p->data.population == population) { 
 List* q = p->next; 
 first = p->next; 
 delete q; 
 p = first; 
 cout « "Найден элемент" « endl; 
 } 
 while (p->next != NULL) { 
 if (p->next->data.population == population) { 
 List* q = p->next; 
 p->next = p->next->next; 
 delete q; 
 } 
 else 
 p = p->next; 
 } 
 } 
} 
 
void add(List*& first, int count) { 
 if (first == NULL) { 
 cout « "Список пуст" « endl; 
 } 
 else { 
 cout « "Добавление элементов" « endl; 
 List* p = first; 
 int size = 0; 
 while (p->next != NULL) { 
 p = p->next; 
 size++; 
 } 
 p = first; 
 for (int i = 1; i < size; i++) { 
 p = p->next; 
 } 
 
 for (int i = 1; i <= count; i++) { 
 List* h = new List; 
 List* q = p; 
 p->next = h; 
 p = p->next; 
 
 cout « "Введите название страны: "; 
 cin » p->data.name; 
 
 cout « "Введите столицу: "; 
 cin » p->data.capital; 
 
 cout « "Введите численность населения: "; 
 cin » p->data.population; 
 
 cout « "Введите площадь государства: "; 
 cin » p->data.areae; 
 
 p->next = NULL; 
 } 
 } 
} 
 
void print(List* first) { 
 if (first == NULL) { 
 cout « "Список пуст" « endl; 
 } 
 else { 
 List* p = first; 
 while (p != NULL) { 
 cout « "Страна: " « p->data.name « " | "; 
 cout « "Столица: " « p->data.capital « " | "; 
 cout « "Численность: " « p->data.population « " | "; 
 cout « "Площадь: " « p->data.area « endl; 
 p = p->next; 
 } 
 } 
} 
 
int main() 
{ 
 setlocale(LC_ALL, "Russian"); 
 system("chcp 1251"); 
 
 List* list = make(); 
 
 cout « "Актуальный список" « endl; 
 print(list); 
 cout « endl; 
 
 del(list); 
 
 cout « "Актуальный список" « endl; 
 print(list); 
 cout « endl; 
 
 add(list, 2); 
 
 cout « "Актуальный список" « endl; 
 print(list); 
 cout « endl; 
 
 return 0; 
}