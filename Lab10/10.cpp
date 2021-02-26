#include <iostream>
#include <Windows.h>

using namespace std;
struct Node
{
    int data;   
    Node* next; 
};
struct Node2
{  
    char* data; 
    Node2* next; 
    Node2* prev; 
};



Node* make_list(int n);
Node2* make_list2(int n);

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Îäíîàïðàâëåíûé ñïèñîê\n\n";
    int n;
    cout << "Ââåäèòå äëèíó ñïèñêà";
    cin >> n;
    Node* list = make_list(n);
    bool dltd = false;
    if (list->data % 2 == 0)
    {
        Node* kakto = list;
        list = list->next;
        delete kakto;
        dltd = true;
        n--;
    }
    Node* nazvanie = list;
    for (int i = 2; i <= n && !dltd; i++)
    {
        
        if (nazvanie->next->data % 2 == 0)
        {
            Node* kakto = nazvanie->next;
            nazvanie->next = nazvanie->next->next; 
            delete kakto; 
            dltd = true;
            n--;
        }                                 
        nazvanie = nazvanie->next;        
    }
    nazvanie = list;

    for (int i = 1; i <= n; i++)
    {
        cout << nazvanie->data << ' ';
        nazvanie = nazvanie->next;
    }
    cout << "\n\nÄâóíàïðàâëåíûé ñïèñîê\n\n";
    cout << "Ââåäèòå äëèíó ñïèñêà\n";
    cin >> n;
    Node2* list2 = make_list2(n);
    Node2* nazvanie2 = list2;
    int number;
    char al;
    do
    {
        cout << "Ââåäèòå íîìåð ýëåìåíòà\n";
        cin >> number;
    } while (number > n);
    cout << "Ââåäèòå ýëåìåíò\n";
    cin >> al;

    for (int i = 1; i < number; i++)
    {
        nazvanie2 = nazvanie2->next;
    }
    Node2* zap = nazvanie2;
    Node2* new_al = new Node2;
    new_al->data = &al;
    new_al->next = zap;
    new_al->prev = zap->prev;
    zap->prev = new_al;
    zap->prev->prev->next = new_al;
    n++;


    for (int i = 1; i <= n; i++)
    {
        cout << *(list2->data) << ' ';
        if (list2->next != NULL)
        {
            list2 = list2->next;
            delete list2->prev;
        }
        else
        {
            delete list2;
        }
        
    }
}


Node* make_list(int n)
{ 
    Node* beg = NULL, * p, * r;

    p = new Node;
    cin >> p->data;
    beg = p;

    for (int i = 2; i <= n; i++)
    {
        r = new Node;     
        cin >> r->data;   
        p->next = r;      
        r->next = NULL;   
        p = r;
    }
    return beg;
}

Node2* make_list2(int n)
{ 
    Node2* beg = NULL, * p, * r;

    p = new Node2;
    p->data = new char;
    cin >> *(p->data);
    
    beg = p;
    p->prev = NULL;

    for (int i = 2; i <= n; i++)
    {
        r = new Node2;
        r->data = new char;
        cin >> *(r->data);   
        p->next = r;      
        r->next = NULL;     
        r->prev = p;
        p = r;

    }
    return beg;
}
