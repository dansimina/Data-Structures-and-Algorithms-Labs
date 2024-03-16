#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// permutarile multimii {1, 2, ..., n}

void bt(int k, int n, int *X)
{
    // am terminat de construit solutia

    if(k == n)
    {
        for(int i = 0; i < n; i++)
            printf("%d ",X[i]);
        puts("");
        return;
    }

    //incercam sa punem fiecare element posibil pe pozitia k
    for(int x = 1; x <= n; x++)
    {
        X[k] = x;

        //verificarea solutiei partiale
        int ok = 1;
        for(int i = 0; i < k; i++)
            if(X[i] == X[k])
                ok = 0;

        if(ok)
            bt(k + 1, n, X);
    }
}

void permutariA_B(int k, int a, int b, int *X, int *cnt)
{
    // am terminat de construit solutia

    int n = b - a + 1;

    if(k == n)
    {
        for(int i = 0; i < n; i++)
            printf("%d ",X[i]);
        puts("");

        (*cnt) ++;

        return;
    }

    //incercam sa punem fiecare element posibil pe pozitia k
    for(int x = a; x <= b; x++)
    {
        X[k] = x;

        //verificarea solutiei partiale
        int ok = 1;
        for(int i = 0; i < k; i++)
            if(X[i] == X[k])
                ok = 0;

        if(ok)
            permutariA_B(k + 1, a, b, X, cnt);
    }
}

void siruriDescresc(int k, int n, int m, int *X, int *cnt)
{
    // am terminat de construit solutia

    if(k == n)
    {
        for(int i = 0; i < n; i++)
            printf("%d ",X[i]);
        puts("");

        (*cnt) ++;

        return;
    }

    //incercam sa punem fiecare element posibil pe pozitia k
    for(int x = 1; x <= m; x++)
    {
        X[k] = x;

        //verificarea solutiei partiale
        int ok = 1;
        for(int i = 0; i < k; i++)
            if(X[i] <= X[k])
                ok = 0;

        if(ok)
            siruriDescresc(k + 1, n, m, X, cnt);
    }
}

int verif(char a)
{
    char v[] = "aeiou";

    if(strchr(v,a) != NULL)
        return 1;
    return 0;

}

void stringuriInCareAlterneazaVcuC(int k, int n, char *X, int *cnt)
{
    // am terminat de construit solutia

    if(k == n)
    {
        puts(X);

        (*cnt)++;

        return;
    }

    //incercam sa punem fiecare element posibil pe pozitia k
    for(char x = 'a'; x <= 'z'; x++)
    {
        X[k] = x;

        //verificarea solutiei partiale
        int ok = 1;
        if(k > 0 && verif(X[k]) == verif(X[k-1]))
           ok = 0;

        if(ok)
            stringuriInCareAlterneazaVcuC(k + 1, n, X, cnt);
    }
}

int main()
{
//    int n = 10;
//    int X[n];
//    bt(0, n, X);

//    int a = 2, b = 4;
//    int X[b - a + 1];
//    int cnt = 0;
//    permutariA_B(0, a, b, X,&cnt);
//    printf("\n%d",cnt);
//
    int n = 3;
    int m = 5;
    int X[n];
    int cnt = 0;
    siruriDescresc(0,n,m,X,&cnt);
    printf("\n%d",cnt);

//    int n = 3;
//    char X[n];
//    int cnt = 0;
//    stringuriInCareAlterneazaVcuC(0,n,X,&cnt);
//    printf("\n%d",cnt);

    return 0;
}
