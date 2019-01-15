#include <iostream>
using namespace std;

struct node{
    int w;
    node *next;
};

void add_end(node*& head, int el){  // dodawanie na koniec

    node *p;
    node *current = head;
    p = new node;
    p->next = nullptr;
    p->w = el;
    if(current != nullptr){
        while(current->next != nullptr)
            current = current->next;

        current->next = p;
    }
    else
        head = p;
}

int erase(node *&a, node*&b){
    int res =0;

    node *p = new node; // wartowniki
    p->next = a;
    a = p;

    node *q = new node;
    q->next = b;
    b = q;

    while(a != nullptr && a->next != nullptr){  // przesuwanie a
        b = q;
        while(a->next != nullptr && b->next != nullptr){    // przesuwanie b
            if(a->next->w == b->next->w){
                node *r = a->next;
                a->next = a->next->next;
                delete r;

                node *t = b->next;
                b->next = b->next->next;
                delete t;

                res++;
                b = q;
            }
            else
                b = b->next;
        }
        a=a->next;
    }

    a = p;
    a = a->next;
    delete p;

    b = q;
    b = b->next;
    delete q;

    return res;
}

void c2_3_15a() {

    node *first;
    first = new node;
    first = nullptr;

    add_end(first, 1);
    add_end(first, 3);
    add_end(first, 6);
    add_end(first, 9);
    add_end(first, 12);

    node *second;
    second = new node;
    second = nullptr;

    add_end(second, 12);
    add_end(second, 3);
    add_end(second, 7);
    add_end(second, 6);
    add_end(second, 1);

    // ----- WYPISYWANIE -----
    node *current = first;
    if (current != nullptr) {
        cout << "{" << current->w;
        current = current->next;
        if (current == nullptr)
            cout << "}" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr) {
            cout << current->w << ", ";
            current = current->next;
        }

        if (current != nullptr)
            cout << current->w << "}" << endl;
    } else
        cout << "{}" << endl;

    current = second;
    if (current != nullptr) {
        cout << "{" << current->w;
        current = current->next;
        if (current == nullptr)
            cout << "}" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr) {
            cout << current->w << ", ";
            current = current->next;
        }

        if (current != nullptr)
            cout << current->w << "}" << endl;
    } else
        cout << "{}" << endl;

    // -------------------------

    cout<<erase(first, second)<<endl;

    current = first;
    if (current != nullptr) {
        cout << "{" << current->w;
        current = current->next;
        if (current == nullptr)
            cout << "}" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr) {
            cout << current->w << ", ";
            current = current->next;
        }

        if (current != nullptr)
            cout << current->w << "}" << endl;
    } else
        cout << "{}" << endl;

    current = second;
    if (current != nullptr) {
        cout << "{" << current->w;
        current = current->next;
        if (current == nullptr)
            cout << "}" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr) {
            cout << current->w << ", ";
            current = current->next;
        }

        if (current != nullptr)
            cout << current->w << "}" << endl;
    } else
        cout << "{}" << endl;
}