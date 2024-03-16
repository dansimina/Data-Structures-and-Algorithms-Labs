#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int key;
    struct _node *next;
}node;

node* create(int givenkey)
{
    node* p = malloc(sizeof(node));
    p->key = givenkey;
    p->next = NULL;

    return p;
}

void insert(node** first, node** last, int givenkey)
{
    if(*first == NULL)
    {
        *first = *last = create(givenkey);
    }
    else
    {
        node* p = create(givenkey);
        if(p->key <= (*first)->key)
        {
            p->next = *first;
            *first = p;
        }else if(p->key >= (*last)->key)
        {
            (*last)->next = p;
            *last = p;
        }else
        {
            for(node* t = *first; t != *last; t = t->next)
            {
                if(p->key >= t->key && p->key <= (t->next)->key)
                {
                    p->next = t->next;
                    t->next = p;
                    break;
                }
            }
        }
    }
}

void display(node* first)
{
    if(first == NULL)printf("NULL");

    for(first; first != NULL; first = first->next)
    {
        printf("%d ",first->key);
    }
    printf("\n");
}

void combine(node** first1, node** last1, node** first2, node** last2)
{

    if(*first2 != NULL && (*first2)->key <= (*first1)->key)
    {
        node* p = *first2;
        *first2= (*first2)->next;
        p->next = *first1;
        *first1 = p;
    }

    for(node* t = *first1; t != *last1 && *first2 != NULL; t = t->next)
    {
        if((*first2)->key >= t->key && (*first2)->key <= (t->next)->key)
        {
            node* p = *first2;
            *first2 = (*first2)->next;
            p->next = t->next;
            t->next = p;
        }
    }

    while((*first2) != NULL)
    {
        node* p = *first2;
        *first2 = (*first2)->next;
        p->next = NULL;
        *last1 = p;
    }

    *last2 = *first2 = NULL;

}

int main()
{
    node *first1 = NULL, *last1 = NULL, *first2 = NULL, *last2 = NULL;

    char s[10], cmd[10];

    while(scanf(" %s",s))
    {
        if(strcmp(s,"i1") == 0 || strcmp(s,"i2") == 0 || strcmp(s,"p1") == 0 || strcmp(s,"p2") == 0 || strcmp(s,"m") == 0)
        {
            strcpy(cmd,s);
            if(strcmp(s,"p1") == 0)display(first1);
            else if(strcmp(s,"p2") == 0)display(first2);
            else if(strcmp(s,"m") == 0)combine(&first1,&last1,&first2,&last2);
        }else
        {
            if(strcmp(cmd,"i1") == 0)
            {
                insert(&first1,&last1,atoi(s));
            }
            else if(strcmp(cmd,"i2") == 0)
            {
                insert(&first2,&last2,atoi(s));
            }
        }
    }

    return 0;
}
