#include <stdio.h>
#include <stdlib.h>

#define M 7

typedef struct node
{
    int key;
    struct node *next;
}NodeT;

int h(int k)
{
    int x = k % M;
    return x >= 0 ? x : x + M;
}

NodeT* create(int key)
{
    NodeT* p = malloc(sizeof(NodeT));
    p->key = key;
    p->next = NULL;

    return p;
}

void insertElement(NodeT* hTable[M], int key)
{
    if(hTable[h(key)] == NULL)
        hTable[h(key)] = create(key);
    else
    {
        NodeT* p = create(key);
        p->next = hTable[h(key)]->next;
        hTable[h(key)]->next = p;
    }
}

NodeT* findElement(NodeT* hTable[M], int key)
{
    if(hTable[h(key)] == NULL)
        return NULL;

    NodeT* p = hTable[h(key)];

    while(p != NULL && p->key != key)
        p = p->next;

    return p;
}

void deleteElement(NodeT* hTable[M], int key)
{
    if(hTable[h(key)] == NULL)
        return;

    NodeT *q, *p;

    if(hTable[h(key)]->key == key)
    {
        q = hTable[h(key)];
        hTable[h(key)] = hTable[h(key)]->next;

        free(q);
    }
    else
    {
        q = hTable[h(key)];
        p = hTable[h(key)]->next;

        while(p != NULL && p->key != key)
        {
            q = p;
            p = p->next;
        }

        if(p == NULL)
            return;

        q->next = p->next;
        free(p);
    }
}

void afisare(NodeT* hTable[M])
{
    for(int i = 0; i < M; i++)
    {
        NodeT* p = hTable[i];

        if(p == NULL)printf("NULL");
        while(p != NULL)
        {
            printf("%d ",p->key);
            p = p->next;
        }

        printf("\n");
    }
}

int main()
{
    NodeT* hTable[M] = {NULL};

    insertElement(hTable,36);
    insertElement(hTable,14);
    insertElement(hTable,26);
    insertElement(hTable,21);
    insertElement(hTable,5);
    insertElement(hTable,19);
    insertElement(hTable,4);

    deleteElement(hTable,14);
    //insertElement(hTable,11);

//    NodeT* p = findElement(hTable,5);
//    if(p != NULL)printf("%d",p->key);
    afisare(hTable);

    return 0;
}
