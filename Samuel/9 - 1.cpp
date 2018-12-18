#include <iostream>
using namespace std;

struct node{
    int val;
    node *next;
};

void add(node*& head, int el){  // dodawanie elementu w odpowiednim miejscu w zbiorze, elementy sa uporzadkowane rosnaco

    node *p;
    node *current = head;
    p = new node;       // nowy node
    p->next = NULL;
    p->val = el;

    if(current != NULL){
        if(current->val == el)      // poczatek listy
            return;
        else if(current->val > el){     // jesli nowy node na poczatku
            p->next = head;
            head = p;
        }
        else{
            while(current->next != NULL && current->next->val < el)     // szukamy odpowiedniej pozycji w zbiorze
                current = current->next;

            if(current->next != NULL && current->next->val == el)       // element juz jest
                return;
            else {
                p->next = current->next;
                current->next = p;
            }
        }

    }
    else
        head = p;       // zbior pusty
}

void erase(node *&head, int el){    // usuwanie elementu
    node *current = head;

    if(head->val == el){    // chcemy usunac pierwszy element zbioru
        node *p = head;
        head = head->next;
        delete p;
    }
    else if(current != NULL && current->next != NULL){

        while(current->next->next != NULL && current->next->val < el)   // szukamy elementu
            current = current->next;

        if(current->next->val == el){       // usuwamy
            node *p = current->next;
            current->next = current->next->next;
            delete p;
        }
    }
}

bool inset(node *head, int el){     // sprawdzanie czy element jest w zbiorze
    while(head != NULL){
        if(head->val == el)
            return true;
        head = head->next;
    }
    return false;
}

void c9_1(){
    node *first;
    first = new node;
    first = NULL;

    add(first, 1);
    add(first, 3);
    add(first, 6);
    add(first, 7);
    add(first, 3);
    add(first, 2);
    erase(first, 1);
    erase(first, 6);
    add(first, 0);

// ----- WYPISYWANIE -----
    node *current = first;
    if(current != NULL) {
        cout << "{" << current->val << ", ";
        current = current->next;


        while (current != NULL && current->next != NULL) {
            cout << current->val << ", ";
            current = current->next;
        }
        cout << current->val << "}"<<endl;
    }
    else
        cout<<"{}"<<endl;

// ------------------------

    if(inset(first, 7))
        cout<<"7: Y"<<endl;
    else
        cout<<"7: N"<<endl;

    if(inset(first, 5))
        cout<<"5: Y"<<endl;
    else
        cout<<"5: N"<<endl;
}