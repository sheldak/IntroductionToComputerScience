#include <iostream>
using namespace std;

struct node{
    int val;
    node *next;
};

void add_end(node*& head, int el){

    node *p;
    node *current = head;
    p = new node;
    p->next = NULL;
    p->val = el;

    if(current != NULL){
        while(current->next != NULL)
            current = current->next;

        current->next = p;
    }
    else
        head = p;
}

bool increase(node *&head, bool deep){
    node *current = head;
    if(current == NULL)
        return false;
    if((current != NULL && current->next == NULL) || (increase(current->next, true))){
        if(current->val == 9){
            current->val = 0;
            if(!deep){
                node *p;
                p = new node;
                p->next = head;
                p->val = 1;
                head = p;
            }
            return true;
        }
        else
            current->val++;
        return false;
    }

}

void c9_4() {
    node *first;
    first = new node;
    first = NULL;

    add_end(first, 9);
    add_end(first, 9);
    add_end(first, 9);
    increase(first, false);

    // ----- WYPISYWANIE -----
    node *current = first;
    if(current != NULL) {
        cout << "{" << current->val;
        current = current->next;
        if(current == NULL)
            cout<<"}"<<endl;
        else
            cout<<", ";

        while (current != NULL && current->next != NULL) {
            cout << current->val << ", ";
            current = current->next;
        }

        if(current != NULL)
            cout << current->val << "}"<<endl;
    }
    else
        cout<<"{}"<<endl;

    // ------------------------

}