#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node* next;
} NodeT;

typedef struct
{
    int n, m; // nr noduri, nr muchii
    NodeT** liste; // liste[u] =  lista care stocheaza vecinii lui u
} Graf;

typedef struct _queue
{
    int CAPACITY;
    int *vec;
    int size;
    int head, tail;
} queue;

NodeT* create(int givenkey)
{
    NodeT* p = malloc(sizeof(NodeT));
    p->x = givenkey;
    p->next = NULL;

    return p;
}

void insert_first(NodeT** first, int givenkey)
{
    NodeT* p = create(givenkey);

    if(*first == NULL)
        *first = p;
    else
    {
        p->next = *first;
        *first = p;
    }

}

void display(Graf g)
{
    for(int i = 1; i <= g.n; i++)
    {
        printf("%d: ",i);
        for(NodeT* p = g.liste[i]; p != NULL; p = p->next)
        {
            printf("%d ",p->x);
        }
        printf("NULL\n");
    }
}

void enqueue(queue* q, int givenkey)
{
    if(q->size == q->CAPACITY)
        return -1;
    else
    {
        q->vec[q->tail] = givenkey;
        (q->size)++;
        (q->tail)++;
    }

}

int dequeue(queue* q)
{
    if(q->size == 0)
        return -1;
    else
    {
        int val = q->vec[q->head];
        (q->size)--;
        (q->head)++;

        return val;
    }
}

void BFS(Graf g, int s)
{
    queue c = {0};
    c.CAPACITY = g.n;
    c.vec = calloc(c.CAPACITY,sizeof(int));

    int* vizitat = calloc(g.n+1,sizeof(int));
    vizitat[s] = 1;
    enqueue(&c,s);

    while(c.size > 0)
    {

        int u = dequeue(&c);
        printf("%d ",u);

        for(NodeT* p = g.liste[u]; p != NULL; p = p->next)
        {
            if(vizitat[p->x] == 0)
            {
                vizitat[p->x] = 1;
                enqueue(&c,p->x);
            }
        }
    }

}

int main()
{
    Graf g;
    FILE* f = fopen("graf.txt","r");
    if(!f)
        return -1;

    fscanf(f," %d", &g.n);

    g.liste = calloc(g.n+1,sizeof(NodeT*));

    int u, v;
    while(fscanf(f,"%d%d",&u,&v) == 2)
    {
        g.m++;
        insert_first(&g.liste[u], v);
    }
    fclose(f);
    //display(g);
    BFS(g,1);



    return 0;
}
