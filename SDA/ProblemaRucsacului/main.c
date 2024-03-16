#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int rucsac(int n, int GMax, int *G, int *V)
{
    int *dp = (int*)calloc(GMax + 1, sizeof(int));

    for(int j = 0; j < n; j++)
    {
        for(int i = GMax; i >= G[j]; i--)
            dp[i] = max(dp[i], dp[i - G[j]] + V[j]);
    }

    int rez = dp[GMax];
    free(dp);

    return rez;
}

int main()
{
    int n, GMax;

    scanf(" %d %d", &n, &GMax);

    int *G = (int*)malloc(n * sizeof(int));
    int *V = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf(" %d %d", &G[i], &V[i]);

    printf("%d ", rucsac(n, GMax, G, V));

    free(G);
    free(V);

    return 0;
}
