#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    int key;
    struct nod* next;
}NodeT;

NodeT* create(int givenkey){

    NodeT* p = malloc(sizeof(NodeT));
    p->key = givenkey;
    p->next = NULL;

    return p;
}

//afisare
void afisare(NodeT* first){

    while(first != NULL){
        printf("%d ",first->key);
        first = first->next;
    }
    printf("\n");
}

//insert_first
void insert_first(NodeT** first, NodeT** last, int givenkey){
    if(*first == NULL){
        *first = *last = create(givenkey);
    }
    else{
        NodeT* p = create(givenkey);
        p->next = *first;
        *first = p;
    }
}

//cautare
NodeT* search(NodeT* first, int givenkey){

    while(first != NULL)
    {
        if(first->key == givenkey)return first;
        first = first->next;
    }

    return NULL;
}

//insert_after
void insert_after_key(NodeT** first, NodeT** last, int afterKey, int givenKey){

    NodeT* p = create(givenKey);

    if(*last != NULL && (*last)->key == afterKey){
        (*last)->next = p;
        *last = p;
        return;
    }
    else{
        NodeT *t = search(*first,afterKey);
        if(t==NULL){
                free(p);
                return;
        }
        p->next = t->next;
        t->next = p;
    }
}

void insert_last(NodeT** first, NodeT** last, int givenkey){
    //lista este goala
    if(*first == NULL){
        *first = *last = create(givenkey);
    }
    //lista contine un singur element
    //lista este generala, cel putin doua elemente
    else{
        NodeT* p = create(givenkey);
        (*last)->next = p;
        *last = p;
    }
}

void delete_first(NodeT** first, NodeT** last){

    if(*first == NULL)return;

    if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else{
        NodeT *p;
        p = *first;
        *first = (*first)->next;
        free(p);
    }
}

 void delete_last(NodeT** first, NodeT** last){

    if(*first == NULL)return;

    if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else{
        NodeT *p;
        p = *first;

        while(p->next != *last)p = p->next;
        p->next = NULL;

        free(*last);
        *last = p;
    }
 }

 void delete_key(NodeT** first, NodeT** last, int givenKey){

    if((*first)->key == givenKey){
        delete_first(first,last);
        return;
    }

    if((*last)->key == givenKey){
        delete_last(first,last);
        return;
    }

    NodeT *p, *q;
    p = *first;

    while(p != NULL && p->key != givenKey){

        q = p;
        p = p->next;
    }

    if(p==NULL)return;

    q->next = p->next;
    free(p);


 }

int main()
{
    NodeT* first=NULL;
    NodeT* last=NULL;

    for(int i=1;i<=5;i++)
    insert_first(&first,&last,i);

    afisare(first);

    delete_last(&first,&last);
    afisare(first);

    delete_first(&first,&last);
    afisare(first);

    delete_key(&first,&last,4);
    afisare(first);


//    insert_first(&first,&last,12);
//    afisare(first);
//    delete_last(&first,&last);
//    afisare(first);
//
//    insert_last(&first,&last,12);
//    afisare(first);
//    delete_first(&first,&last);
//    afisare(first);
//
//    insert_first(&first,&last,12);
//    afisare(first);
//    delete_last(&first,&last);
//    afisare(first);
//
//    delete_key(&first, &last, 5);
//    afisare(first);



//    insert_after_key(&first,&last,1,11);
//    insert_last(&first,&last,12);
//    afisare(first);
//    delete_first(&first,&last);
//    insert_last(&first,&last,11);
//    afisare(first);

    return 0;
}

//problema cu steluta
