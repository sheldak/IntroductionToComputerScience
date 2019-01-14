#include <iostream>
using namespace std;

struct node{
    int left;
    int right;
    node *next;
};

void add_end(node*& head, int left, int right){  // dodawanie na koniec

    node *p;
    node *current = head;
    p = new node;
    p->next = nullptr;
    p->left = left;
    p->right = right;
    if(current != nullptr){
        while(current->next != nullptr)
            current = current->next;

        current->next = p;
    }
    else
        head = p;
}

void merge(node *a){
    if(a != nullptr){
        node *head = a;
        while(head != nullptr && head->next != nullptr){    // przedzial do ktorego dolaczamy inne
            bool edited = true;
            while(edited){      // kilka razy przechodzimy, bo zdarza sie ze po dodanie przedzialu jakis poprzedni tez potem mozemy
                edited = false;
                node *curr = head;
                while(curr->next != nullptr){       // sprawdzamy po kolei kolejne przedzialy czy mozna dolaczyc do head
                    if(curr->next->left <= head->left && curr->next->right >= head->right){
                        head->left = curr->next->left;
                        head->right = curr->next->right;

                        node *r = curr->next;
                        curr->next = curr->next->next;
                        delete r;

                        edited = true;
                    }
                    else if(curr->next->left <= head->left && curr->next->right >= head->left) {
                        head->left = curr->next->left;

                        node *r = curr->next;
                        curr->next = curr->next->next;
                        delete r;

                        edited = true;
                    }
                    else if(curr->next->right >= head->right && curr->next->left <= head->right){
                        head->right = curr->next->right;

                        node *r = curr->next;
                        curr->next = curr->next->next;
                        delete r;

                        edited = true;
                    }
                    else{
                        curr = curr->next;
                    }
                }
            }
            head = head->next;
        }
    }
}


void c10_17() {

    node *first;
    first = new node;
    first = nullptr;

    add_end(first, 4, 9);
    add_end(first, 11, 14);
    add_end(first, 2, 5);
    add_end(first, 10, 11);
    add_end(first, 14, 22);


    // ----- WYPISYWANIE -----
    node *current = first;
    if (current != nullptr) {
        cout << "(" << "[" << current->left << ", " << current->right << "]";
        current = current->next;
        if (current == nullptr)
            cout << ")" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr) {
            cout << "[" << current->left << ", " << current->right << "]" << ", ";
            current = current->next;
        }

        if (current != nullptr)
            cout << "[" << current->left << ", " << current->right << "]" << ")" << endl;
    } else
        cout << "()" << endl;

    merge(first);

    current = first;
    if (current != nullptr) {
        cout << "(" << "[" << current->left << ", " << current->right << "]";
        current = current->next;
        if (current == nullptr)
            cout << ")" << endl;
        else
            cout << ", ";

        while (current != nullptr && current->next != nullptr) {
            cout << "[" << current->left << ", " << current->right << "]" << ", ";
            current = current->next;
        }

        if (current != nullptr)
            cout << "[" << current->left << ", " << current->right << "]" << ")" << endl;
    } else
        cout << "()" << endl;
}