#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3
typedef struct _queue
{
    int vec[CAPACITY];
    int size;
    int head, tail;
}queue;


void enqueue(queue *q, int givenkey)
{
    if(q->size == CAPACITY)
    {
        printf("overflow\n");
    }else
    {
        q->vec[q->tail] = givenkey;
        (q->size)++;
        q->tail = (++(q->tail))%CAPACITY;
    }
}

int dequeue(queue *q)
{
    if(q->size == 0)
    {
        printf("underflow ");
        return -1;
    }else
    {
        int val = q->vec[q->head];
        (q->size)--;
        q->head = (++(q->head))%CAPACITY;

        return val;
    }
}

void afisez(queue q)
{
    int i = q.head;
    int k=0;

    while(k < q.size)
    {
        printf("%d ",q.vec[i]);
        i = (++i)%CAPACITY;
        k++;
    }

    printf("\n");
}


int main()
{
    queue q={0};

    printf("%d\n",dequeue(&q));
    enqueue(&q,1);
    enqueue(&q,2);
    printf("%d\n",dequeue(&q));
    enqueue(&q,3);
    enqueue(&q,4);
    afisez(q);
    enqueue(&q,5);
    printf("%d\n",dequeue(&q));
    enqueue(&q,5);
    afisez(q);
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    afisez(q);
    enqueue(&q,7);
    afisez(q);

    return 0;
}
