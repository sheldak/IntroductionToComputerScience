struct node{
    int val;
    node *next;
};


void add_start(node *head, int el){
    node *p;
    p = new node;
    p->next = head;
    p->val = el;
    head = p;
}


void add_end(node*& head, int el){

    node *p;
    node *current = start;
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


void erase_start(*&head){

    if(head != NULL){
        node *t = head;
        head = head->next;
        delete t;
    }
}


void erase_end(*&head){

    if(head != NULL){
        node *current = head;

        if(current->next == NULL){
            delete current;
            head = NULL;
        }
        while (current->next != NULL)
            curernt = head->next;

        delete curernt->next;
        current  = NULL;
    }
}


void erase_every_other(*head){

    int i=1;

    while(head != NULL && head->next != NULL){
        i++;

        if(i%2==0){
            if(head->next->next != NULL) {
                node *p = head->next;
                head->next = head->next->next;
                delete p;
            }
            else{
                delete head->next->next;
                head->next = NULL;
            }

        }
        head = head->next;
    }
}