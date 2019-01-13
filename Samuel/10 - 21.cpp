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

void add_cycle(node *&head, int pos){   // dodawanie cyklu
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

int before_cycle(node *head){
    if(head == nullptr)
        return 0;

    int len = 0;        // odleglosc do miejsca spotkania wskaznikow
    node *a = head;
    node *b = head->next;

    while(a != b){
        if(b->next == nullptr || b->next->next == nullptr)
            return 0;

        a = a->next;
        len++;
        b = b->next->next;
    }

    int cycle_len = 1;      // dlugosc cyklu
    b = b->next;
    while(a != b) {
        b = b->next;
        cycle_len++;
    }

    node *c = head;
    node *d = head->next;

    int res = 0;            // liczba elementow przed cyklem
    int rem = len+cycle_len;        // minimalna liczba nextow ktore potrzebujemy zeby stwierdzic czy c jest w cyklu
    while(c != d){
        while(rem>0){
            if(c==d)
                return res;

            rem--;
            d = d->next;
        }
        c = c->next;
        d = c->next;
        res++;
        rem = len+cycle_len-res;
    }
    return res;
}


void c10_21() {

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

    current = first;
    int x = 100;    // pierwsze x wyrazow
    if (current != nullptr) {
        cout << "{" << current->val;
        current = current->next;
        if (current == nullptr)
            cout << "}" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr && x>0) {
            cout << current->val << ", ";
            current = current->next;
            x--;
        }

        if (current != nullptr)
            cout << current->val << "}" << endl;
    } else
        cout << "{}" << endl;

    cout<<before_cycle(first);
}