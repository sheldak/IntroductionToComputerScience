// funkcje: wstawia na poczatek listy jednokierunkowej i usuwajaca element z poczatku

struct node{
    int val;
    node *next;
};

node *wstaw(node *head, int el){
    node *p;

    p = new node;
    p -> val = el;
    p -> next = head;

    return p;
}

node *usun(node *head)
{
    if(head != NULL) {
        node *p;

        p = head;
        head = head->next;

        delete p;
    }
    return head;
}

// na koniec listy

void wstaw_na_koniec(node *&start, int a){
    node *p;
    node* current = start;
    p = new node;
    p->val;
    p->next = NULL;
    if(current == NULL)
        start = p;
    else{
        while(current->next != NULL)
            current = current->next;
    }


    current->next = p;
}

// usunac ostatni

void usun_kon(node *& head){
    if(head == NULL)
        return;

    if(head->next == NULL){
        node *p = head;
        delete p;
        head = NULL;
    }
    else{
        node *curr = head;
        while(curr->next != NULL)
            curr = curr->next;
        delete curr->next;
        curr->next = NULL;
    }
}

// usunac co drugi, nie jest dokonczony

node *usun co drugi(node *head)
{
    int i=0;
    while(head->next!=NULL){
        i++;
        if(i%2==1){
            head->next = usun(head);
        }
        head = head->next;
    }

}
