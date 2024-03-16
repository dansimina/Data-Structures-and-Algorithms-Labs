#include <stdio.h>
#include <stdlib.h>

/// pr1 decompunere

void sortare1(int a[], int n)
{
    int ok = 1;

    while(ok)
    {
        ok = 0;

        for(int i = 0; i < n - 1; i++)
            if(a[i] < a[i + 1])
            {
                ok = 1;
                int aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
            }
    }
}

int greedyDescompunere(int a[], int n, int sum)
{
    int cnt = 0;

    for(int i = 0; i < n && sum; i++)
        if(sum >= a[i])
        {
            cnt += sum / a[i];
            sum %= a[i];
        }

    if(sum > 0)
        return -1;

    return cnt;
}

///pr2 activitati

typedef struct
{
    char nume[20];
    int start, finish;
} activitati;

void sortare2(activitati a[], int n)
{
    int ok = 1;

    while(ok)
    {
        ok = 0;

        for(int i = 0; i < n - 1; i++)
            if(a[i].finish > a[i + 1].finish)
            {
                ok = 1;
                activitati aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
            }
    }

}

int greedyActivitati(activitati a[], int n)
{
    int cnt = 0;

    if(n == 0)
        return 0;
    cnt++;
    puts(a[0].nume);

    int lastActivity = a[0].finish;

    for(int i = 1; i < n; i++)
        if(a[i].start >= lastActivity)
    {
        cnt++;
        lastActivity = a[i].finish;
        puts(a[i].nume);
    }

    return cnt;

}

///pr4 numere

void sortare4(int a[], int n)
{
    int ok = 1;

    while(ok)
    {
        ok = 0;

        for(int i = 0; i < n - 1; i++)
            if(a[i] > a[i + 1])
            {
                ok = 1;
                int aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
            }
    }
}

int greedyNumere(int a[], int n)
{
    int t = n;
    int cost = 0, x = 0;

    for(int i = 0; i < n - 1; i++)
    {
        x = a[0] + a[1];
        cost += x;

        int i = 0;

        for(i; i < t - 2 && a[i + 2] <= x; i++)
            a[i] = a[i + 2];

        a[i] = x;
        i++;

        for(i; i < t - 1; i++)
            a[i] = a[i + 1];

        t--;

//        for(int k = 0; k < t; k++)
//            printf("%d ",a[k]);
//        printf("\n");


    }

    return cost;
}

int main()
{
    ///pr1 descompunere

//    int a[] = {1, 5, 10, 50, 100, 200, 500};
//    //int a[] = {1, 6, 10};
//    //int a[] = {2, 3};
//    int n = sizeof(a)/sizeof(int);
//
//    sortare1(a,n);
//
//    int sum;
//    scanf(" %d", &sum);
//    printf("%d",greedyDescompunere(a,n,sum));

    ///pr2 activitati

//    FILE *f = fopen("activitati.txt","r");
//    if(!f)
//        return -1;
//
//    int n = 0;
//    activitati a[100];
//
//    while(fscanf(f," %s %d %d", a[n].nume, &a[n].start, &a[n].finish) == 3)
//        n++;
//
//    sortare2(a,n);
//
//    for(int i = 0; i < n; i++)
//        printf("%s %d %d\n",a[i].nume,a[i].start,a[i].finish);
//
//    printf("%d ",greedyActivitati(a,n));

    ///pr4 numere

    int a[] = {1, 1, 1, 1, 2, 2, 3};
    int n = sizeof(a)/sizeof(int);

    sortare4(a,n);

    printf("%d ",greedyNumere(a,n));

    return 0;
}
