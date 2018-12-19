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

int num_len(node *head){
    int sum = 0;
    while(head != NULL){
        sum++;
        head = head->next;
    }
    return sum;
}

node *sum(node *a, node *b, int a_len, int b_len, bool deep){

    node *p;
    p = new node;

    if(a_len > b_len){
        p->val = a->val;

        node *n = sum(a->next, b, a_len-1, b_len, true);
        p->next = n;
    }
    else if(b_len > a_len){
        p->val = b->val;

        node *n = sum(a, b->next, a_len, b_len-1, true);
        p->next = n;
    }
    else{
        if(a_len == 0){
            delete p;
            return NULL;
        }
        else{
            p->val = a->val + b->val;

            node *n = sum(a->next, b->next, a_len-1, b_len-1, true);
            p->next = n;
        }
    }

    if(p->next != NULL && p->next->val >= 10){
        p->val += 1;
        p->next->val -= 10;
    }

    if(!deep && p != NULL && p->val >= 10){
        node *s;
        s = new node;
        s->val = 1;
        s->next = p;
        p->val -= 10;
        return s;
    }

    return p;
}


void c9_5() {
    node *first;
    first = new node;
    first = NULL;

    add_end(first, 9);
    add_end(first, 8);
    add_end(first, 7);

    node *second;
    second = new node;
    second = NULL;

    add_end(second, 3);
    add_end(second, 4);
    add_end(second, 5);

    int first_len = num_len(first);
    int second_len = num_len(second);

    node *result = sum(first, second, first_len, second_len, false);

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


    current = second;
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


    current = result;
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