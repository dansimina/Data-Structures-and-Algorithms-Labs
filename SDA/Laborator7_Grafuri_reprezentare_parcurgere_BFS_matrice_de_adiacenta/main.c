#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n, m;
    int** matrice;
} Graf;

typedef struct _queue
{
    int CAPACITY;
    int *vec;
    int size;
    int head, tail;
} queue;

void display(Graf g)
{
    for(int i = 1; i <= g.n; i++)
    {
        for(int j = 1; j <= g.n; j++)
        {
            printf("%d ",g.matrice[i][j]);
        }
        printf("\n");
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

        for(int i = 1; i <= g.n; i++)
            if(g.matrice[u][i] == 1)
            {
                if(vizitat[i] == 0)
                {
                    vizitat[i] = 1;
                    enqueue(&c,i);
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

    g.matrice = calloc(g.n+1,sizeof(int*));
    for(int i = 1; i <= g.n; i++)
        g.matrice[i] = calloc(g.n+1,sizeof(int));

    int u, v;
    while(fscanf(f,"%d%d",&u,&v) == 2)
    {
        g.m++;
        g.matrice[u][v] = 1;
    }
    fclose(f);
    //display(g);
    BFS(g,1);

    return 0;
}
