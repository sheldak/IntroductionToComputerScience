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

void add_cycle(node *&head, int pos){
    if(head != nullptr){
        node *end = head;
        node *to = head;
        while(pos >= 1){
            if(to != nullptr && to->next != nullptr)
                to = to->next;
            else
                return;
            pos--;
        }

        while(end != nullptr && end->next != nullptr)
            end = end->next;
        end->next = to;
    }
}

bool cycle(node *head){
    if(head == nullptr)
        return false;

    node *a = head;
    node *b = head->next;

    while(a != b){
        if(b->next == nullptr || b->next->next == nullptr)
            return false;

        a = a->next;
        b = b->next->next;
    }
    return true;
}


void c10_19() {

    node *first;
    first = new node;
    first = nullptr;

    add_end(first, 1);
    add_end(first, 3);
    add_end(first, 1);
    add_end(first, 3);
    add_end(first, 5);
    add_end(first, 3);
    add_end(first, 3);
    add_end(first, 9);
    add_end(first, 8);

    if (cycle(first))
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;

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

    add_cycle(first, 5);
    if (cycle(first))
        cout<<"Y";
    else
        cout<<"N";
}