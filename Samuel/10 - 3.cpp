#include <iostream>
using namespace std;

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

node *merge_it(node *a, node *b){   // tworzenie listy iteracyjnie

    node *c = nullptr;

    if(a != nullptr || b != nullptr){   // pierwszy element

        node *n = new node;
        n->next = nullptr;

        if(a == nullptr || (b != nullptr && a->val >= b->val)){
            n->val = b->val;
            b = b->next;
        }
        else if(b == nullptr || a->val <= b->val){
            n->val = a->val;
            a = a->next;
        }

        c = n;
    }

    if(a == nullptr && b == nullptr)
        return c;

    node *current = c;

    if(a != nullptr && b != nullptr) {      // kolejne elementy
        while (a != nullptr && b != nullptr) {
            node *n = new node;
            n->next = nullptr;

            if (a->val >= b->val) {
                n->val = b->val;
                current->next = n;

                b = b->next;
            } else {
                n->val = a->val;
                current->next = n;

                a = a->next;
            }
            current = current->next;
        }
    }

    if(a == nullptr){
        while(b->next != nullptr){
            node *n = new node;
            n->next = nullptr;
            n->val = b->val;
            current->next = n;

            b = b->next;
            current = current->next;
        }
        node *n = new node;
        n->next = nullptr;
        n->val = b->val;
        current->next = n;

    }

    if(b == nullptr){
        while(a->next != nullptr){
            node *n = new node;
            n->next = nullptr;
            n->val = a->val;
            current->next = n;

            a = a->next;
            current = current->next;
        }
        node *n = new node;
        n->next = nullptr;
        n->val = a->val;
        current->next = n;
    }

    return c;
}

node *merge_rec(node *a, node *b){  // tworzenie listy rekurencyjnie
    node *n = new node;
    if(a == nullptr && b == nullptr){
        delete n;
        return nullptr;
    }
    else if(a == nullptr || (b != nullptr && a->val >= b->val)){
        n->val = b->val;
        n->next = merge_rec(a, b->next);
    }else{
        n->val = a->val;
        n->next = merge_rec(a->next, b);
    }
    return n;
}

void c10_3(){

    node *first;
    first = new node;
    first = nullptr;

    add_end(first, 7);
    add_end(first, 8);
    add_end(first, 9);

    node *second;
    second = new node;
    second = nullptr;

    add_end(second, 3);
    add_end(second, 9);
    add_end(second, 11);

    node *result_it = merge_it(first, second);
    node *result_rec = merge_rec(first, second);


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


    current = second;
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


    current = result_it;
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


    current = result_rec;
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