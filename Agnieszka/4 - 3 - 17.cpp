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
void merge(node *a, node *b, int n){        // tworzenie y listy na n-tym indeksie listy a (dolacza tam koniec listy b)
    while(a != nullptr && a->next != nullptr && n>0){
        a = a->next;
        n--;
    }

    while(b!=nullptr && b->next != nullptr)
        b=b->next;

    b->next = a;
}

int divide(node *a, node *b){
    node *x = a;

    int res = 0;

    while(x != nullptr && x->next != nullptr){
        node *y = b;
        while(y != nullptr &&  y->next != nullptr && x->next != y->next)
            y = y->next;

        if(y == nullptr || y->next == nullptr)
            x = x->next;
        else{
            while(x->next != nullptr){
                node *r = new node;
                r->val = x->next->val;
                y->next = r;
                y = y->next;
                res++;
                x = x->next;
            }
            y->next = nullptr;
        }
    }
    return res;
}


void c4_3_17() {

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

    add_end(second, 5);
    add_end(second, 4);

    merge(first, second, 2);

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

    current = second;
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

    // -------------------------

    cout<<divide(first, second);
}