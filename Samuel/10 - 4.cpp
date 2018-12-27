#include <iostream>
using namespace std;

const int N = 1000;

struct node{
    int val;
    node *next;
};

void add_end(node*& head, int el){  // dodawanie na koniec

    node *p;
    node *current = head;
    p = new node;
    p->next = nullptr;
    p->val = el;
    if(current != nullptr){
        while(current->next != nullptr)
            current = current->next;

        current->next = p;
    }
    else
        head = p;
}

node *invert(node *a){  // odwracanie

    int t[N];
    int i=0;

    while(a != nullptr){
        t[i] = a->val;
        i++;
        a = a->next;
    }

    if(i==0)        // pusta lista
        return nullptr;

    i--;        // pierwszy element
    node *n = new node;
    n->val = t[i];
    i--;
    node *current = n;

    while(i>=0){
        node *k = new node;
        k->val = t[i];
        current->next = k;
        current = current->next;
        i--;
    }
    current = nullptr;
    return n;
}

void c10_4(){

    node *first;
    first = new node;
    first = nullptr;

    add_end(first, 7);
    add_end(first, 8);
    add_end(first, 3);
    add_end(first, 1);
    add_end(first, 9);
    add_end(first, 8);


    node *result = invert(first);


    // ----- WYPISYWANIE -----
    node *current = first;
    if(current != nullptr) {
        cout << "{" << current->val;
        current = current->next;
        if(current == nullptr)
            cout<<"}"<<endl;
        else
            cout<<", ";

        while (current != nullptr && current->next != nullptr) {
            cout << current->val << ", ";
            current = current->next;
        }

        if(current != nullptr)
            cout << current->val << "}"<<endl;
    }
    else
        cout<<"{}"<<endl;


    current = result;
    if(current != nullptr) {
        cout << "{" << current->val;
        current = current->next;
        if(current == nullptr)
            cout<<"}"<<endl;
        else
            cout<<", ";

        while (current != nullptr && current->next != nullptr) {
            cout << current->val << ", ";
            current = current->next;
        }

        if(current != nullptr)
            cout << current->val << "}"<<endl;
    }
    else
        cout<<"{}"<<endl;

    // ------------------------
}