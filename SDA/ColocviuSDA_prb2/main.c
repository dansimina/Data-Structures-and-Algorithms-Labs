#include <stdio.h>
#include <stdlib.h>

int* generare(int n)
{
    int *sir = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        sir[i] = rand()%201 - 100;
    }

    return sir;
}

int verificare(int n, int *v, int *vs)
{
    if(n == 0)
        return 0;

    int fv[201] = {0}, fvs[201] = {0}, *fvp = fv + 100, *fvsp = fvs + 100;

    fvsp[vs[0]]++;
    for(int i = 1; i < n; i++)
    {
        if(vs[i - 1] > vs[i])
            return 0;
        fvsp[vs[i]]++;
    }

    for(int i = 0; i < n; i++)
    {
        fvp[v[i]]++;
    }

    for(int i = 0; i <= 200; i++)
        if(fv[i] != fvs[i])
            return 0;
    return 1;
}

int* interclasare(int* a, int na, int* b, int nb, int* c, int nc)
{
    int *aux = malloc((na + nb + nc +1) * sizeof(int));
    int *auxp = malloc((na + nb + 1) * sizeof(int));

    int ia = 0, ib = 0, ic = 0, np = 0;

    while(ia < na && ib < nb)
        if(a[ia] < b[ib])
            auxp[np++] = a[ia++];
        else
            auxp[np++] = b[ib++];

    while(ia < na)
        auxp[np++] = a[ia++];
    while(ib < nb)
        auxp[np++] = b[ib++];

    int ip = 0, k = 0;

    while(ip < np && ic < nc)
        if(auxp[ip] < c[ic])
            aux[k++] = auxp[ip++];
        else
            aux[k++] = c[ic++];

    while(ip < np)
        aux[k++] = auxp[ip++];
    while(ic < nc)
        aux[k++] = c[ic++];

    return aux;

}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int* mergesort3(int *v, int n)
{
    if(n == 2)
    {
        if(v[0] > v[1])
        {
            swap(&v[0],&v[1]);
        }
        return v;
    }

    if(n <= 1)
        return v;

    int na, nb, nc, *a, *b, *c;
    na = n / 3;
    nb = na;
    nc = n - na - nb;
    a = mergesort3(v, na);
    b = mergesort3(v + na, nb);
    c = mergesort3(v + na + nb, nc);
    return interclasare(a, na, b, nb, c, nc);
}

int main()
{
    int n;
    scanf("%d",&n);
    int *sir = generare(n);


    printf("Sirul generat:\n");
    for(int i = 0; i < n; i++)
        printf("%d ",sir[i]);

    printf("\nSirul sortat:\n");
    int *p = mergesort3(sir,n);
    for(int i = 0; i < n; i++)
        printf("%d ",p[i]);

    printf("\nVerificare: %d\n",verificare(n,sir,p));

    return 0;
}
