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

bool even5in8(int n){
    int exp = 1;
    int five = 0;
    while(n>0){
        if(n%8 == 5)
            five++;

        n /= 8;
        exp*=10;
    }

    return five%2==0;
}

void move(node *&a){

    if(a != nullptr && a->next != nullptr){

        node *curr = a;

        while(curr != nullptr && curr->next != nullptr)
            if(even5in8(curr->next->val)){
                node *n = new node;
                n->next = a;
                n->val = curr->next->val;

                a = n;

                node *r = curr->next;
                curr->next = curr->next->next;
                delete r;
            }
            else{
                curr = curr->next;
            }
    }
}

void c10_12() {

    node *first;
    first = new node;
    first = nullptr;

    add_end(first, 13);      // 15
    add_end(first, 42);      // 52
    add_end(first, 109);     // 155
    add_end(first, 333);     // 515
    add_end(first, 43);      // 53
    add_end(first, 367);     // 557

    // ----- WYPISYWANIE -----
    node *current = first;
    if (current != nullptr) {
        cout << "{" << current->val;
        current = current->next;
        if (current == nullptr)
            cout << "}" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr) {
            cout << current->val << ", ";
            current = current->next;
        }

        if (current != nullptr)
            cout << current->val << "}" << endl;
    } else
        cout << "{}" << endl;

    move(first);

    current = first;
    if (current != nullptr) {
        cout << "{" << current->val;
        current = current->next;
        if (current == nullptr)
            cout << "}" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr) {
            cout << current->val << ", ";
            current = current->next;
        }

        if (current != nullptr)
            cout << current->val << "}" << endl;
    } else
        cout << "{}" << endl;

// ------------------------
}