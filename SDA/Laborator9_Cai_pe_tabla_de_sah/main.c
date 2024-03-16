#include <stdio.h>
#include <stdlib.h>

void afis(int n, int m, int **X)
{
    FILE* f = fopen("saritura_calului1.out","w");

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <=m; j++)
            fprintf(f,"%d ", X[i][j]);

        fprintf(f,"\n");
    }
}

void bt(int k, int x, int y, int n, int m, int **X, int *ok)
{
    if(k == n * m && (*ok) == 0)
    {
        afis(n , m , X);
        *ok = 1;
    }
    else if(X[x][y] == 0 && (*ok) == 0)
    {
        X[x][y] = ++k;

        int dl[] = {-2, -2, 2, 2, -1, -1, 1, 1};
        int dc[] = {-1, 1, -1, 1, -2, 2, -2, 2};

        for(int i = 0; i < 8; i++)
        {
            if(x + dl[i] >= 1 && x + dl[i] <= n && y + dc[i] >= 1 && y + dc[i] <= m)
                bt(k, x + dl[i], y + dc[i], n, m, X, ok);
        }

        X[x][y] = 0;
    }

}

int main()
{

    int n, m, x, y;

    FILE* f = fopen("saritura_calului1.in","r");
    if(!f)
        return -1;

    fscanf(f," %d %d %d %d", &n, &m, &x, &y);

    int **X = (int**)calloc((n + 1), sizeof(int*));
    for(int i = 0; i <= n; i++)
        X[i] = (int*)calloc((m + 1), sizeof(int));

    int ok = 0;
    bt(0, x, y, n, m, X, &ok);

    for(int i = 0; i <= n; i++)
        free(X[i]);
    free(X);

    return 0;
}
