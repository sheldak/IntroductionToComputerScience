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

void *lesser(node *a){          // usuwanie elementow mniejszych o tych poprzedzajacych
    if(a != nullptr && a->next != nullptr){
        node *curr = a;

        int last_val = curr->val;
        while(curr != nullptr && curr->next != nullptr){
            if(last_val > curr->next->val){     // nastepny jest mniejszy
                last_val = curr->next->val;

                node *r = curr->next;
                curr->next = curr->next->next;
                delete r;
            }
            else{                               // nastepny nie jest mniejszy
                last_val = curr->next->val;
                curr = curr->next;
            }
        }
    }
}



void c10_9(){

    node *first;
    first = new node;
    first = nullptr;

    add_end(first, 5);
    add_end(first, 4);
    add_end(first, 6);
    add_end(first, 7);
    add_end(first, 3);
    add_end(first, 1);
    add_end(first, 4);
    add_end(first, 6);
    add_end(first, 9);
    add_end(first, 3);
    add_end(first, 1);

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

    lesser(first);

    current = first;
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