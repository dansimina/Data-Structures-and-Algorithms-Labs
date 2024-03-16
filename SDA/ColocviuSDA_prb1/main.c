#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n, m;
    int *noduri;
    int **liste;

    int *start;
    int *finish;
    int *viz;
} graf;

typedef struct _node
{
    int x;
    struct _node *next;
} node;

node* create(int val)
{
    node* p = malloc(sizeof(node));
    p->x = val;
    p->next = NULL;

    return p;
}

void insertFirst(node **first, int val)
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
    for(int i = 0; i < g.n; i++)
    {
        printf("%d) ",g.noduri[i]);
        for(node* p = g.liste[i]; p != NULL; p = p->next)
        {
            printf("%d ",g.noduri[p->x]);
        }
        printf("\n");
    }
}

void dfs(graf* g, int nod, int* t)
{
    (*t)++;
    g->start[nod] = *t;
    g->viz[nod] = 1;

    printf("%d ", g->noduri[nod]);

    for(node* p = g->liste[nod]; p != NULL; p = p->next)
        if(g->viz[p->x] == 0)
            dfs(g,p->x,t);
    (*t)++;
    g->finish[nod] = *t;
}

void curatare(graf* g)
{
    for(int i = 0; i < g->n; i++)
    {
        g->start[i] = 0;
        g->finish[i] = 0;
        g->viz[i] = 0;
    }
}

int main()
{
    FILE* f = fopen("grafC.txt","r");
    if(!f)
        return -1;

    graf g;

    fscanf(f," %d %d", &g.n, &g.m);

    g.noduri = malloc(g.n * sizeof(int));
    g.start = malloc(g.n * sizeof(int));
    g.finish = malloc(g.n * sizeof(int));
    g.viz = calloc(g.n,sizeof(int));
    g.liste = calloc(g.n, sizeof(node*));

    for(int i = 0; i < g.n; i++)
        fscanf(f, " %d", &g.noduri[i]);

    for(int m = 0; m < g.m; m++)
    {
        int u, v;
        fscanf(f, "%d->%d", &u, &v);

        int i = 0;
        for(i = 0; i < g.n && u != g.noduri[i]; i++);

        int j = 0;
        for(j = 0; j < g.n && v != g.noduri[j]; j++);
        insertFirst(&g.liste[i], j);
        //printf("%d %d %d\n",u,v);
    }

    //afisare(g);
    for(int i = 0; i < g.n; i++)
    {
        printf("Parcurgerea %d:\n",i+1);
        int t = 0;
        curatare(&g);

        dfs(&g,i,&t);
        for(int j = 0; j < g.n; j++)
            if(g.viz[j] == 0)
                dfs(&g,j,&t);

        printf("\n");
        printf("Timpii de start si finalizare:\n");
        for(int j = 0; j < g.n; j++)
        {
            printf("%d) %d %d \n", g.noduri[j], g.start[j], g.finish[j]);
        }
        printf("\n");
    }

    free(g.noduri);
    free(g.start);
    free(g.finish);
    free(g.viz);
    free(g.liste);

    return 0;
}
