#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int key;
    struct _node* next;
}node;

node* create(int givenkey)
{
    node* p = malloc(sizeof(node));
    p->next = NULL;
    p->key = givenkey;

    return p;
}

void push(node** first, int givenkey)
{
    node *p = create(givenkey);
    if(*first == NULL)
        *first = p;
    else
    {
        p->next = *first;
        *first = p;
    }
}

int pop(node** first)
{
    if(*first == NULL)return -1;

    int val = (*first)->key;
    node* p = *first;
    *first = (*first)->next;

    free(p);

    return val;

}

int main()
{
    node *first = NULL;

    printf("%d\n",pop(&first));
    push(&first, 1);
    push(&first, 2);
    printf("%d\n",pop(&first));
    push(&first, 3);
    printf("%d\n",pop(&first));
    printf("%d\n",pop(&first));
    printf("%d\n",pop(&first));
    push(&first, 4);
    printf("%d\n",pop(&first));
    printf("%d\n",pop(&first));


    return 0;
}
