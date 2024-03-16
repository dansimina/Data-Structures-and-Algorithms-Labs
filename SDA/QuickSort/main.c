#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partitionare(int a[], int l, int r)
{
    int pivot = a[r];

    int sm = l;

    for(int i = l; i < r; i++)
        if(a[i] <= pivot)
    {
        swap(&a[sm], &a[i]);
        sm++;
    }

    swap(&a[sm],&a[r]);

    return sm;
}

void quickSort(int a[], int l, int r)
{
    if(l >= r)
        return;

    int poz = partitionare(a, l, r);

    quickSort(a, l, poz - 1);
    quickSort(a, poz + 1, r);
}

int main()
{

    int a[] = {5, 4, 1, 3, 2};
    quickSort(a, 0, 4);

    for(int i = 0; i < 5; i++)
        printf("%d ",a[i]);
    return 0;
}
