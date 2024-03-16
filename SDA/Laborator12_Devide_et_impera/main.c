#include <stdio.h>
#include <stdlib.h>

int cautareBinara(int a[], int p, int q, int val)
{
    if(p > q)
        return -1;

    int m = (p + q)/ 2;

    if(val == a[m])
        return m;

    if(val < a[m])
        return cautareBinara(a, p, m - 1, val);
    else
        return cautareBinara(a, m + 1, q, val);
}

void interclasare(int a[], int s, int m, int f)
{
    int ia = s;
    int ib = m + 1;

    int* c = malloc((f - s + 1) * sizeof(int));
    int ic = 0;


    while(ia <= m && ib <= f)
    {
        if(a[ia] < a[ib])
            c[ic++] = a[ia++];
        else
            c[ic++] = a[ib++];
    }

    while(ia <= m)
        c[ic++] = a[ia++];
    while(ib <= f)
        c[ic++] = a[ib++];

    for(int i = 0; i < ic; i++)
        {
            a[i + s] = c[i];
        }

    free(c);
}

void mergeSort(int a[], int p, int q)
{
    if(p == q)
        return;

    int m = (p + q) / 2;
    mergeSort(a, p, m);
    mergeSort(a, m + 1, q);

    interclasare(a, p, m, q);

}

int sortarePartiala(int a[], int n, int pivot)
{
    int *aux = malloc(n * sizeof(int));

    int poz = 0;
    int k = 0;

    for(int i = 0; i < n; i++)
        if(a[i] <= pivot)
            aux[k++] = a[i];

    poz = k;

    for(int i = 0; i < n; i++)
        if(a[i] > pivot)
            aux[k++] = a[i];

    for(int i = 0; i < n; i++)
        a[i] = aux[i];
    free(aux);

    return poz;
}

void quickSort(int a[], int l, int r)
{
    if(l >= r)
        return;

    int poz = rand() % (r - l + 1) + l;
    int pivot = a[poz];

    poz = sortarePartiala(a + l, r - l + 1, pivot);

    quickSort(a, l, l + poz - 1);
    quickSort(a, l + poz + 1, r);
}

int main()
{
    int a[] = {5, 4, 1, 3, 2, 2};

///Cautare binara
//    for(int i = -5; i <= 10; i++)
//        printf("%d ",cautareBinara(a,0,6,i));

    //interclasare(a,0,2,3,6);

///Merge sort
//    mergeSort(a,0,5);
//    for(int i = 0; i < 6; i++)
//        printf("%d ",a[i]);

///Quick sort
    quickSort(a, 0, 5);
    for(int i = 0; i < 6; i++)
        printf("%d ",a[i]);

    return 0;
}
