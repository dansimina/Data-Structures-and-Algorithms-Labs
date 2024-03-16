#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    int key;

    struct node_type *next;
    struct node_type *prev;

} NodeDL;



NodeDL* create(int givenkey)
{
    NodeDL* p = malloc(sizeof(NodeDL));

    p->key = givenkey;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

void insert_first(NodeDL** first, NodeDL** last, int givenkey)
{
    NodeDL* p = create(givenkey);

    if(*first == NULL)
    {
        *first = *last = p;
    }else
    {
        p->next = *first;
        (*first)->prev = p;
        *first = p;
    }
}

void delete_last(NodeDL** first, NodeDL** last)
{
    if(*last == NULL)
    {
        printf("underflow\n");
    }else if(*first == *last)
    {
        free(*first);
        *first = *last = NULL;
    }else
    {
        NodeDL* p = *last;
        *last = (*last)->prev;
        (*last)->next = NULL;

        free(p);
    }
}

void afis_inv(NodeDL* last)
{
    while(last != NULL)
    {
        printf("%d ", last->key);
        last = last->prev;
    }
    printf("\n");
}

void afis(NodeDL* first)
{
    while(first != NULL)
    {
        printf("%d ", first->key);
        first = first->next;
    }
    printf("\n");
}


int main()
{

    NodeDL *first = NULL, *last = NULL;

    delete_last(&first, &last);

    for(int i=1; i<=3; i++)insert_first(&first,&last,i);
    afis_inv(last);
    delete_last(&first,&last);
    afis_inv(last);
    afis(first);
    delete_last(&first,&last);
    delete_last(&first,&last);
    delete_last(&first,&last);

    for(int i=1; i<=3; i++)insert_first(&first,&last,i);
    afis_inv(last);
    afis(first);

    return 0;
}
