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

int erase(node *&a, node *&b){
    int res = 0;

    if(a != nullptr && b != nullptr){       // pierwsze takie same
        node *curr_a = a;
        node *curr_b = b;
        while(a != nullptr && b != nullptr && a->w == b->w){
            node *r = a;
            a = a->next;
            delete r;

            node *t = b;
            b = b->next;
            delete t;

            res++;
        }
        curr_b = b;
        while(a != nullptr && curr_b != nullptr && curr_b->next != nullptr){      // usuwanie pierwszego z a i innego niz pierwszy z b
            if(a->w == curr_b->next->w){
                node *r = a;
                a = a->next;
                delete r;

                node *t = curr_b->next;
                curr_b->next = curr_b->next->next;
                delete t;
                curr_b = b;

                res++;
            }
            else
                curr_b = curr_b->next;
        }

        while(curr_a != nullptr && curr_a->next != nullptr){
            while(b != nullptr && curr_a->next != nullptr && b->w == curr_a->next->w){      // usuwanie pierwszego z b i innego niz 1 z a
                node *r = curr_a->next;
                curr_a->next = curr_a->next->next;
                delete r;

                node *t = b;
                b = b->next;
                delete t;

                res++;
            }

            curr_b = b;
            while(curr_a != nullptr && curr_a->next != nullptr && curr_b != nullptr && curr_b->next != nullptr){    // usuwanie dwoch nie pierwszych
                if(curr_b->next->w == curr_a->next->w){
                    node *r = curr_a->next;
                    curr_a->next = curr_a->next->next;
                    delete r;

                    node *t = curr_b->next;
                    curr_b->next = curr_b->next->next;
                    delete t;

                    curr_b = b;
                    res++;
                }
                else
                    curr_b = curr_b->next;
            }

            if(curr_a != nullptr)
                curr_a = curr_a->next;
        }
    }

    return res;
}


void c2_3_15() {

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
