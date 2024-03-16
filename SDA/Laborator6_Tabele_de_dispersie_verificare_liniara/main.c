#include <stdio.h>
#include <stdlib.h>

#define M 7

int h0(int k)
{
    int x = k % M;
    return x >= 0 ? x : x + M;
}

int h(int k, int i)
{
    return (h0(k) + i) % M;
}

typedef struct _node
{
    int key;
}node;

node* create(int givenkey)
{
    node* p = malloc(sizeof(node));
    p->key = givenkey;

    return p;
}

void insertElement(node* hTable[M], int key)
{
    int i;
    for(i = 0; i < M && hTable[h(key,i)] != NULL;i++);
    if(i < M)hTable[h(key,i)] = create(key);
}

node* findElement(node* hTable[M], int key)
{
    for(int i = 0; i < M; i++)
    {
        if(hTable[h(key,i)] != NULL && hTable[h(key,i)]->key == key) return hTable[h(key,i)];
    }
    return NULL;
}

int main()
{
    node* hTable[M] = {NULL};

    //19, 36, 5, 21, 4, 26, 14

    insertElement(hTable,19);
    insertElement(hTable,36);
    insertElement(hTable,5);
    insertElement(hTable,21);
    insertElement(hTable,4);
    insertElement(hTable,26);
    insertElement(hTable,14);

    for(int i = 0; i < M; i++)
        if(hTable[i] != NULL)
            printf("%d ",hTable[i]->key);
        else
            printf("NULL ");

    if(findElement(hTable,19) != NULL)printf("\n%d ",findElement(hTable,19)->key);

    return 0;
}
