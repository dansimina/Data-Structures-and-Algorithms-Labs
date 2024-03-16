#include <stdio.h>
#include <stdlib.h>
#define inf 1e9
//la test doar modelul celor 3 probleme

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

/// problema resturilor

int nrMinMonede(int s, int n, int a[])
{
    int *dp = malloc((s + 1) * sizeof(int));

    dp[0] = 0;
    for(int i = 1; i <= s; i++)
        dp[i] = inf;

    for(int i = 1; i <= s; i++)
    {
        for(int j = 0; j < n; j++)
            if(i >= a[j])
        {
            dp[i] = min(dp[i], dp[i-a[j]] + 1);
        }
    }

    for(int i = 0; i <= s; i++)
        printf("%d ", dp[i]);

    int r = dp[s];

    free(dp);

    return r;

}

/// nr max de combinatii in care poate fi platita o suma

int nrCombinatiiMonede(int s, int n, int a[])
{
    int *dp = calloc((s + 1), sizeof(int));

    dp[0] = 1;

    for(int j = 0; j < n; j++)
        for(int i = 1; i <= s; i++)
        {
            if(i >= a[j])
            {
                dp[i] += dp[i-a[j]];
            }
        }

    for(int i = 0; i <= s; i++)
        printf("%d ", dp[i]);

    int r = dp[s];

    free(dp);

    return r;

}

/// problema rucsacului

// dp[i] = max(dp[i], dp[i - gk] + vk);

// dp[i] = pt greutate totala ce val max am

// fac de la cap la coada ca sa iau fiecare obiect o singura data

// la greutati zecimale inmultim cu 10 la nr zecimale

int rucsac(int n, int G, int g[], int v[])
{
    int *dp = calloc((G + 1), sizeof(int));

    for(int k = 0; k < n; k++)
    {
        for(int i = G; i >= g[k]; i--)
            dp[i] = max(dp[i], dp[i-g[k]] + v[k]);
    }

    for(int i = 0; i <= G; i++)
        printf("%d ", dp[i]);

    int r = dp[G];

    free(dp);

    return r;
}

/// subsecventa maximala ordonata strict crescator

int subsecventaMax(int n, int a[])
{
    int *dp = calloc((G + 1), sizeof(int));



    int r = dp[G];

    free(dp);

    return r;
}

int main()
{

//    int s = 12;
//    int a[] = {1, 2, 5};
//    int n = 3;
//
//    printf("\n%d ", nrMinMonede(s,n,a));
//    printf("\n%d ", nrCombinatiiMonede(s,n,a));


    int g[] = {2, 4, 8, 7};
    int v[] = {5, 6, 13, 5};

    int n = 4, G = 9;


    rucsac(n,G,g,v);


    ///Subsecventa maximala ordonata crescator de facut

    return 0;
}
