#include <stdio.h>
#include <stdlib.h>

void afisare(int n, int *a)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void permutari(int k, int n, int *a, int *f)
{
    if(k == n)
        afisare(n, a);
    else
        for(int i = 1; i <= n; i++)
            if(f[i] == 0)
    {
        f[i] = 1;
        a[k] = i;

        permutari(k+1, n, a, f);

        f[i] = 0;
    }
}

void combinari(int p, int k, int n, int *a)
{
    if(p == k)
        afisare(k, a);
    else
        for(int i = p > 0 ? a[p - 1] + 1 : 1; i <= n; i++)
    {
        a[p] = i;
        combinari(p + 1, k, n, a);
    }
}

int main()
{
//    int n;
//    scanf(" %d", &n);
//
//    int *a = calloc(n, sizeof(int));
//    int *f = calloc(n, sizeof(int));
//
//    permutari(0, n, a, f);

//    int n, k;
//    scanf(" %d %d", &n, &k);
//
//    int *a = calloc(k, sizeof(int));
//
//    combinari(0, k, n, a);

    return 0;
}
