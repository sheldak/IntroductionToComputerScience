#include <iostream>
using namespace std;
struct node{
    int n;
    node *next;
};
void append_first(node *&head, int n){
        node *p=new node;
        p->next = head;
        p->n = n;
        head = p;
}
void append_last(node *&head, int n){
        node *p = new node;
        p->next =nullptr;
        p->n = n;
        node *curr = head;
        if(curr!=nullptr){ // if list not empty
            while(curr->next != nullptr)
                curr= curr->next;
            curr->next=p;
        }
        else{
            head = p;
        }
}
int get_val(node *head, int n){
    int val;
    for(int i=0;i<=n;i++){
        val = head->n;
        head = head->next;
    }
    return val;
}
bool exCycle(node *head){
    if(head == nullptr) return false;
    if(head->next == nullptr) return false;
    node *ptr1 = head;
    node *ptr2 = head;
    while(ptr2->next->next!=nullptr){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
        if(ptr1==ptr2) return true;
    }
    return false;

}
int main(){
    node *lista = new node;
    lista =nullptr;
    append_first(lista, 2);
    append_last(lista, 4);
    append_last(lista, 6);
    append_last(lista, 8);
    append_last(lista, 3);
    append_last(lista, 9);
    node *curr = lista;
    while(curr->next != nullptr)
            curr= curr->next;
    curr->next=lista;
    bool ans19 = exCycle(lista);
    cout<<ans19;

}
