#include <iostream>
using namespace std;

const int N = 5;

struct node{
    int val;
    node *next;
};

void init(node *&tab){      // inicjalizacja
    node *first;
    first = new node;
    first->val = 0;
    first->next = NULL;

    tab = first;        // poczatek tablicy

    node *current = tab;
    for(int i=1; i<N; i++){     // wypelnianie zerami
        node *p;
        p = new node;
        p->val = 0;
        p->next = NULL;

        current->next = p;
        current = current->next;
    }
}

int value(node *tab, int n){        // sprawdzanie wartosci pod indeksem n
    for(int i=0; i<n && i<N; i++)
        tab = tab->next;

    if(tab == NULL)
        return 0;
    else
        return tab->val;
}

void set(node *&tab, int n, int value){     // podstawienie wartosci value pod indeks n
    node *current = tab;

    for(int i=0; i<n && i<N; i++)
        current = current->next;

    if(current != NULL)
        current->val = value;
}


void c9_2() {
    node *tab;
    tab = new node;
    tab = NULL;

    init(tab);

    set(tab, 0, 3);
    set(tab, 2, 6);
    set(tab, 3, 5);
    set(tab, 4, 8);

    // ----- WYPISYWANIE -----
    node *current = tab;
    if(current != NULL) {
        cout << "[" << current->val;
        current = current->next;
        if(current == NULL)
            cout<<"]"<<endl;
        else
            cout<<", ";

        while (current != NULL && current->next != NULL) {
            cout << current->val << ", ";
            current = current->next;
        }

        if(current != NULL)
            cout << current->val << "]"<<endl;
    }
    else
        cout<<"[]"<<endl;

    // ------------------------

    cout<<"1: "<<value(tab, 1)<<endl;
    cout<<"3: "<<value(tab, 3)<<endl;
}
