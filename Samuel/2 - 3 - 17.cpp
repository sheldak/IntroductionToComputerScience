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

int length(node *a){
    if(a == nullptr)
        return 0;
    node *b = a->next;
    int len = 1;
    while(a != b){
        b = b->next;
        len++;
    }
    return len;
}

int erase(node *a, node *b){
    int res = 0;

    while(a->val < a->next->val)
        a = a->next;
    while(b->val < b->next->val)
        b = b->next;

    int a_len = length(a);
    int b_len = length(b);

    bool a_first = true;
    bool b_first = true;

    while(a_len >= 1 && b_len >= 1){
        if((b->val > b->next->val && !b_first) || (a->val > a->next->val && !a_first))
            break;

        if(a->next->val == b->next->val){
            node *r = a->next;

            if(a_len >= 2)
                a->next = a->next->next;
            else
                a = nullptr;
            delete r;
            a_len--;


            node *p = b->next;
            if(b_len >= 2)
                b->next = b->next->next;
            else
                b = nullptr;
            delete p;
            b_len--;


            res++;
        }
        else if(a->next->val > b->next->val){
            b = b->next;
            b_first = false;
        }
        else{
            a = a->next;
            a_first = false;
        }
    }
    return res;
}


void c2_3_17() {

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

    add_end(second, 1);
    add_end(second, 3);
    add_end(second, 6);
    add_end(second, 12);

    // ----- WYPISYWANIE -----
    node *current = first;
    int x = 5;
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

    current = second;
    x = 4;    // pierwsze x wyrazow
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

    // -------------------------


    add_cycle(first, 0);
    add_cycle(second, 0);
    cout<<erase(first->next->next, second->next)<<endl;
}