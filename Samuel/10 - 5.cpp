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

node *sortt(node *a){   // sortowanie jak w tresci zadania

    node *n[10];
    node *curr[10];

    for(int i=0; i<10; i++){
        curr[i] = nullptr;
        n[i] = nullptr;
    }

    while(a != nullptr){        // podzial na 10 list
        node *k = new node;
        k->val = a->val;
        if(n[(a->val)%10] == nullptr){
            n[(a->val)%10] = k;
            curr[(a->val)%10] = n[(a->val)%10];
        }
        else{
            curr[(a->val)%10]->next = k;
            curr[(a->val)%10] = curr[(a->val)%10]->next;
        }
        a = a->next;
    }

    node *res = nullptr;
    node *current = nullptr;

    for(int i=0; i<10; i++){    // sortowanie list niemalejaco
        if(n[i] != nullptr){
            if(res == nullptr){
                node *p = new node;
                p->val = n[i]->val;
                n[i] = n[i]->next;

                res = p;
                current = res;
            }

            while(n[i] != nullptr){
                node *r = new node;
                r->val = n[i]->val;

                current->next = r;
                current = current->next;
                n[i] = n[i]->next;
            }

        }
    }
    return res;
}

void c10_5(){

    node *first;
    first = new node;
    first = nullptr;

    add_end(first, 7);
    add_end(first, 8);
    add_end(first, 3);
    add_end(first, 1);
    add_end(first, 9);
    add_end(first, 10);
    add_end(first, 19);
    add_end(first, 18);
    add_end(first, 28);
    add_end(first, 17);

    node *result = sortt(first);

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