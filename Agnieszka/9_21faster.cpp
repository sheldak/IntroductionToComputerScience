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
void display(node* head){
    if(head==nullptr) return;
    while(head->next!=nullptr){
        cout<<head->n<<" ";
        head=head->next;
    }
    cout<<head->n<<endl;
}
void reverse_(node *&head){
    if(head==nullptr) return;
    node *tmp = new node;
    tmp->next = nullptr;
    tmp->n = head->n;
    node *it = head->next;
    while(it!=nullptr){
        append_first(tmp, it->n);
        it=it->next;
    }
    head = tmp;
}
int length(node *head){
    int ret=0;
    while(head!=nullptr){
        ret++;
        head=head->next;
    }
    return ret;
}
bool same_val(node *head, int n, int m){ // elementy liczone od indeksu 0, n<m
    int val1, val2;
    bool ret;
    int it=0;
    while(it<n){
        head = head->next;
        it++;
    }
    val1 = head->n;
    while(it<m){
        head = head->next;
        it++;
    }
    val2 = head->n;
    return val1==val2;
}
int befCycle(node *head){
    reverse_(head);
    int n=length(head);
    for(int k=2;k<=n/2;k++){
        bool exist = true;
        for(int i=0;i<k;i++){
            if(!same_val(head, i, i+k)) exist =false;
        }
        if(exist==true){
            int i=k+k;
            while(i<n && same_val(head,i-k, i)) i++;
            return n-i;
        }
    }
    return -1;

}
int main(){
    node *lista = new node;
    lista =nullptr;
    append_first(lista, 2);
    append_last(lista, 4);
    append_last(lista, 4);
    append_last(lista, 9);
    append_last(lista, 8);
    append_last(lista, 4);
    append_last(lista, 9);
    append_last(lista, 8);
    int ans21 = befCycle(lista);
    display(lista);
    cout<<ans21;

}
