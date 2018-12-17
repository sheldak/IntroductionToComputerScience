#include <iostream>
using namespace std;

struct node{
    int val;
    node *next;
};


void add_start(node *&head, int el){
    node *p;
    p = new node;
    p->next = head;
    p->val = el;
    head = p;
}


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


void erase_start(node *&head){

    if(head != NULL){
        node *t = head;
        head = head->next;
        delete t;
    }
}


void erase_end(node *head){

    if(head != NULL && head->next != NULL){

        while(head->next->next != NULL)
            head = head->next;

        delete head->next;
        head->next = NULL;
    }
}


void erase_every_other(node *head){

    int i=1;

    while(head != NULL && head->next != NULL){
        i++;

        if(i%2==0){
            if(head->next->next != NULL) {
                node *p = head->next;
                head->next = head->next->next;
                delete p;
                i++;
            }
            else{
                delete head->next;
                head->next = NULL;
            }

        }
        head = head->next;
    }
}

void c9_0(){
    node *first;
    first = new node;
    first = NULL;
    add_end(first,2);
    add_start(first,1);
    add_end(first,3);
    add_end(first,4);
    add_end(first,5);
    add_end(first,6);
    add_end(first,7);
    erase_every_other(first);
    while(first != NULL) {
        cout << first->val << endl;
        first = first->next;
    }
}
