#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int x;
    struct _node *next;
}node;

typedef struct
{
    int n;
    node** liste;
    int *tStart, *tFinish;
}graf;

typedef struct
{
    int CAPACITY;
    int size;
    int *vec;
    int head, tail;
}queue;

node* create(int givenkey)
{
    node* p = malloc(sizeof(node));
    p->x = givenkey;
    p->next = NULL;

    return p;
}

void insertFirst(node** first, int givenkey)
{
    node* p = create(givenkey);
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
        printf("%d: ", i);
        for(node* p = g.liste[i]; p != NULL; p = p->next)
            printf("%d ",p->x);
        printf("\n");
    }
}

void enqueue(queue* q, int givenkey)
{
    if(q->size == q->CAPACITY)
        return;
    q->vec[q->tail] = givenkey;
    (q->size)++;
    (q->tail)++;
}

int dequeue(queue* q)
{
    if(q->size == 0)
        return -1;

    int val = q->vec[q->head];
    (q->head)++;
    (q->size)--;

    return val;
}

void bfs(graf g, int start)
{
    queue q = {0};
    q.CAPACITY = g.n;
    q.vec = calloc(q.CAPACITY, sizeof(int));

    int *vizitat = calloc(g.n + 1, sizeof(int));

    vizitat[start] = 1;
    enqueue(&q,start);

    while(q.size > 0)
    {
        int u = dequeue(&q);
        printf("%d ", u);
        for(node* p = g.liste[u]; p != NULL; p = p->next)
            if(vizitat[p->x] == 0)
            {
                enqueue(&q, p->x);
                vizitat[p->x] = 1;
            }
    }
}

void dfs(graf* g, int u, int* t, int* viz)
{

    printf("%d ",u);

    g->tStart[u] = ++(*t);
    viz[u] = 1;

    for(node* p = g->liste[u]; p != NULL; p = p->next)
        if(viz[p->x] == 0)
            dfs(g, p->x, t, viz);

    g->tFinish[u] = ++(*t);
}

int main()
{

    FILE *f = fopen("data.txt","r");
    if(!f)
        return -1;

    graf g;
    fscanf(f," %d", &g.n);

    g.liste = calloc(g.n + 1, sizeof(node*));

    int u, v;
    while(fscanf(f," %d %d", &u, &v) == 2)
    {
        insertFirst(&g.liste[u], v);
        insertFirst(&g.liste[v], u);
    }

//    afisare(g);
    bfs(g,1);

    puts("");

    int *vizitat = calloc(g.n + 1, sizeof(int));
    g.tStart = calloc(g.n + 1, sizeof(int));
    g.tFinish = calloc(g.n + 1, sizeof(int));
    int t = 0;

    dfs(&g, 1, &t, vizitat);

    // de continuat

    return 0;
}
