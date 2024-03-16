#include <stdio.h>
#include <stdlib.h>

// ciclu timpul start e mai mic si nu e timp final
// ex (2) 4/13, (5) 2/...

typedef struct{
    int n;
    int** A;
    int* viz;
    int* start;
    int* finish;
}Graf;

void dfs(int u, Graf *g, int* t)
{
    g->viz[u] = 1;
    g->start[u] = ++(*t);

    printf("%d ", u);

    for(int i = 1; i <= g->n; i++)
        if(g->A[u][i] == 1 && g->viz[i] == 0)
            dfs(i,g,t);
    g->finish[u] = ++(*t);
}

void drum(int u, int v, Graf* g, int t)
{
    g->viz[u] = t;
    if(u == v)
        return;

    for(int i = 1; i <= g->n; i++)
        if(g->A[u][i] == 1 && g->viz[i] == 0)
        {
            drum(i,v,g,t+1);
            if(g->viz[v] == 0 || (g->viz[v] != 0 && g->viz[i] > g->viz[v]))
            {
                g->viz[i] = -1;
            }
        }
}

int ciclu(int u, Graf *g, int* t)
{
    g->viz[u] = 1;
    g->start[u] = ++(*t);

    int r = 0, k = 0;

    for(int i = 1; i <= g->n; i++)
        if(g->A[u][i] == 1 && g->viz[i] == 0)
            r = ciclu(i,g,t);
        else if(g->A[u][i] == 1)
        {
            if(g->start[i] > 0 && g->finish[i] == 0)
                k = 1;
        }
    g->finish[u] = ++(*t);

    return r + k;
}

void drumuriMultiple(int u, Graf *g)
{
    g->viz[u] = 1;

    for(int i = 1; i <= g->n; i++)
        if(g->A[u][i] == 1 && g->viz[i] == 0)
            drumuriMultiple(i,g);
        else if(g->A[u][i] == 1)
            (g->viz[i])++;
}

int main()
{
    FILE* f = fopen("graf.txt", "r");
    if(!f)
        return -1;

    Graf g = {0};
    fscanf(f," %d", &g.n);
//    printf("nr noduri %d\n",g.n);

    g.viz = calloc(g.n + 1, sizeof(int));
    g.start = calloc(g.n + 1, sizeof(int));
    g.finish = calloc(g.n + 1, sizeof(int));

    g.A = calloc(g.n + 1, sizeof(int*));
    for(int i = 1; i <= g.n; i++)
        g.A[i] = calloc(g.n + 1, sizeof(int));

    int u, v;

    while(fscanf(f," %d %d", &u, &v) == 2)
    {
        g.A[u][v] = 1;
    }

    for(int i = 1; i <= g.n; i++)
    {
        for(int j = 1; j<= g.n; j++)
        {
            printf("%d ", g.A[i][j]);
        }
        printf("\n");
    }
///1
//    int t = 0;
//    dfs(9, &g, &t);

//    printf("\n");
//    for(int i = 1; i <= g.n; i++)
//    {
//        printf("%d %d %d\n",i, g.start[i],g.finish[i]);
//    }

///2
//    int x = 1, y = 8;
//    drum(x, y, &g, 1);
//    int* drum = calloc(g.n + 1, sizeof(int));
//    for(int i = 1; i <= g.n; i++)
//    {
//        //printf("%d ", g.viz[i]);
//        if(g.viz[i]>0)
//        {
//            drum[g.viz[i]] = i;
//            if(g.viz[i] == g.viz[y])drum[g.viz[i]] = y;
//        }
//    }
//
//    for(int i = 1; i <= g.n; i++)
//        if(drum[i]>0)printf("%d ",drum[i]);

///3

//    int t = 0, ok = 0;
//
//    for(int i = 1; i<= g.n ;i++)
//        if(g.viz[i] == 0)
//    {
//        ok += ciclu(i,&g,&t);
//    }
//
//    if(ok > 0)
//        printf("DA");
//    else
//        printf("NU");

///4
//    int x = 1, y = 2;
//    drumuriMultiple(x, &g);
//
//    for(int i = 1; i <= g.n; i++)
//        printf("%d ", g.viz[i]);
//
//    if(g.viz[y] > 1)
//        printf("DA");
//    else
//        printf("NU");

    free(g.viz);
    free(g.start);
    free(g.finish);
    for(int i = 1; i <= g.n; i++)
        free(g.A[i]);
    free(g.A);

    return 0;
}
