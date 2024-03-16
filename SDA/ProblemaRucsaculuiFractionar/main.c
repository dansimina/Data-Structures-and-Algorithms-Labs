#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double G, V;
} data;

void swap(data *a, data *b)
{
    data aux = *a;
    *a = *b;
    *b = aux;
}

int partitionare(data *a, int l, int r)
{
    double pivot = a[r].V / a[r].G;
    int sm = l;

    for(int i = l; i < r; i++)
        if(a[i].V / a[i].G >= pivot)
    {
        swap(&a[sm], &a[i]);
        sm ++;
    }

    swap(&a[sm], &a[r]);

    return sm;
}

void quickSort(data *a, int l, int r)
{
    if(l >= r)
        return;

    int poz = partitionare(a, l, r);

    quickSort(a, l, poz - 1);
    quickSort(a, poz + 1, r);
}

int main()
{
    int n, GMax;

    scanf(" %d %d", &n, &GMax);

    data* a = (data*)malloc(n * sizeof(data));

    for(int i = 0; i < n; i++)
        scanf(" %lf %lf", &a[i].G, &a[i].V);

    quickSort(a, 0, n - 1);

    double sumG = 0, sumV = 0;

    for(int i = 0; i < n && sumG < GMax; i++)
    {
        if(sumG + a[i].G <= GMax)
        {
            sumG += a[i].G;
            sumV += a[i].V;
        }else {
            sumV += (GMax - sumG) * (a[i].V / a[i].G);
            sumG = GMax;
        }
    }


    printf("%g ",sumV);

    return 0;
}
