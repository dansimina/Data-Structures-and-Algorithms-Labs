#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int x;
    struct _node* next;
}node;

typedef struct{
    int n;
    node **lista;
}graf;

typedef struct{
    int CAPACITY;
    int size;
    int *vec;
    int head, tail;
}queue;

void enqueue(queue *q, int val)
{
    if(q->size == q->CAPACITY)
        return;
    q->vec[q->tail] = val;
    (q->tail)++;
    (q->size)++;
}

int dequeue(queue *q)
{
    if(q->size == 0)
        return -1;
    int val = q->vec[q->head];
    (q->head)++;
    (q->size)--;

    return val;
}

node* create(int val)
{
    node* p = malloc(sizeof(node));
    p->x = val;
    p->next = NULL;

    return p;
}

void insertFirst(node** first, int val)
{
    node* p = create(val);
    if(*first == NULL)
        *first = p;
    else
    {
        p->next = *first;
        *first = p;
    }
}

void afisare(graf g)
{
    for(int i = 1; i <= g.n; i++)
    {
        for(node *p = g.lista[i]; p != NULL; p = p->next)
            printf("%d ", p->x);
        printf("\n");
    }
}

void bfs(graf g, int start)
{
    queue c = {0};
    c.CAPACITY = g.n;
    c.vec = calloc(g.n + 1, sizeof(int));

    int *viz = calloc(g.n + 1, sizeof(int));

    viz[start] = 1;
    enqueue(&c, start);

    while(c.size > 0)
    {
        int u = dequeue(&c);

        printf("%d ",u);

        for(node* p = g.lista[u]; p != NULL; p = p->next)
        {
            if(viz[p->x] == 0)
            {
                enqueue(&c, p->x);
                viz[p->x] = 1;
            }
        }
    }
}

int main()
{

    FILE *f = fopen("graf.txt","r");
    if(!f)
        return -1;
    graf g;

    fscanf(f," %d", &g.n);

    g.lista = calloc(g.n + 1, sizeof(node*));

    int u, v;
    while(fscanf(f," %d %d", &u, &v) == 2)
    {
        insertFirst(&g.lista[u],v);
        insertFirst(&g.lista[v],u);
    }


    //afisare(g);
    bfs(g,1);

    return 0;
}
