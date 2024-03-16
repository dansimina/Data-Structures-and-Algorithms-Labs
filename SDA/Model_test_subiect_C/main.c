#include <stdio.h>
#include <stdlib.h>

#define mod 13
#define a 3

typedef struct _node
{
    int x, y;
    struct _node* next;
} node;

int hash(int x, int y)
{
    return (x << a | y) % mod;
}

node* create(int x, int y)
{
    node* p = malloc(sizeof(node));
    p->x = x;
    p->y = y;
    p->next = NULL;

    return p;
}

void insert(node* hTable[], int x, int y)
{
    node* p = create(x, y);

    if(hTable[hash(x,y)]==NULL)
        hTable[hash(x,y)] = p;
    else
    {
        p->next = hTable[hash(x,y)];
        hTable[hash(x,y)] = p;
    }
}

void deleteKey(node* hTable[], int x, int y)
{
    for(int i = 0; i < mod; i++)
    {
        if(hTable[i] != NULL)
        {
            if(hTable[i]->x == x && hTable[i]->y == y)
            {
                node* p = hTable[i];
                hTable[i] = hTable[i]->next;
                free(p);
            }
            else
                for(node *q = hTable[i], *p = hTable[i]->next; p != NULL; p = p->next)
                {
                    if(p->x == x && p->y == y)
                    {
                        q->next = p->next;
                        free(p);
                        return;
                    }
                    q = p;
                }
        }

    }
}

double fillingFactor(node* hTable[])
{
    int cnt = 0;

    for(int i = 0; i < mod; i++)
    {
        for(node* p = hTable[i]; p != NULL; p = p->next)
            cnt++;
    }

    return (double)cnt/mod;
}

void display(node* hTable[])
{
    for(int i = 0; i < mod; i++)
    {
        if(hTable[i] == NULL)
            printf("NULL");
        else
            for(node* p = hTable[i]; p != NULL; p = p->next)
                printf("(%d %d) ",p->x,p->y);

        printf("\n");
    }
}

int main()
{
    node* hTable[mod] = {NULL};

    for(int i = 1; i<=100; i+=2)
    {
        insert(hTable,i,i+1);
    }

    display(hTable);
    deleteKey(hTable,59,60);
    printf("\n");
    display(hTable);
    printf("\n");
    printf("%lf ",fillingFactor(hTable));

    return 0;
}
