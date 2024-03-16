#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    char key;
    struct _node *left, *right;
}node;

node* create(char givenkey)
{
    node* p = malloc(sizeof(node));
    p->key = givenkey;
    p->left = p->right = NULL;

    return p;
}

node* read(char s[], int* p, int n)
{
    if(*p >= n)return NULL;

    node* q = create(s[*p]);
    (*p)++;

    if(strchr("*/+-",q->key)!=NULL)
    {
        q->left = read(s,p,n);
        q->right = read(s,p,n);
    }

    return q;
}

void inOrder(node* root)
{
    if(root == NULL)return;

    inOrder(root->left);
    printf("%c ", root->key);
    inOrder(root->right);
}

int evaluateTree(node* root)
{
    if(root == NULL)return 0;

    if(strchr("*/+-",root->key)!=NULL)
    {
        if(root->key == '*')
        {
            int a = 0, b = 0;
            a = evaluateTree(root->left);
            b = evaluateTree(root->right);

            printf("%d * %d \n",a,b);

            return a * b;

        }
        else if(root->key == '/')
        {
            int a = 0, b = 0;
            a = evaluateTree(root->left);
            b = evaluateTree(root->right);

            printf("%d / %d \n",a,b);

            return a / b;

        }
        else if(root->key == '+')
        {
             int a = 0, b = 0;
            a = evaluateTree(root->left);
            b = evaluateTree(root->right);

            printf("%d + %d \n",a,b);

            return a + b;

        }
        else if(root->key == '-')
        {
            int a = 0, b = 0;
            a = evaluateTree(root->left);
            b = evaluateTree(root->right);

            printf("%d - %d \n",a,b);

            return a - b;
        }
    }

    return (root->key - '0');

}

void preOrder(node* root, char s[], char c)
{
    if(root == NULL)return;


    char aux[2];
    aux[0] = root->key;
    aux[1] = NULL;

    if(root->key == c)puts(s);
    if(strchr("*/+-",root->key)!=NULL)strcat(s,aux);

    preOrder(root->left,s,c);
    preOrder(root->right,s,c);

}

int main()
{
    char s[100] = {NULL}, c = '4', a[100] = {NULL};

    gets(s);
    int n = strlen(s);
    int p = 0;

    node* root = read(s,&p,n);

    printf("%d ",evaluateTree(root));
    printf("\n");
    preOrder(root,a,c);

    return 0;
}
