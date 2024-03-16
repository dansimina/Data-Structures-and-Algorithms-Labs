#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    char key[10];
    struct _node *left, *right;
} node;

node* create(char givenkey[10])
{
    node* p = malloc(sizeof(node));
    strcpy(p->key,givenkey);
    p->left = NULL;
    p->right = NULL;

    return p;
}

node* read(char exp[100][10], int* n)
{
    if(*n < 0)return NULL;

    node* q = create(exp[*n]);
    (*n)--;

    if(strchr("+-*/",q->key[0]) != NULL)
    {
        q->right = read(exp,n);
        q->left = read(exp,n);
    }

    return q;

}

void inOrder(node* root)
{
    if(root == NULL)return;

    inOrder(root->left);
    if(root->key[0] == '#')printf("(");
        else printf("%s",root->key);
    inOrder(root->right);
    if(root->left != NULL && (root->left)->key[0] == '#')printf(")");
}

int main()
{

    char s[100], exp[100][10], *p;
    int n = 0;
    gets(s);

    for(p = strtok(s," "); p != NULL; p = strtok(NULL," "))
    {
        strcpy(exp[n],p);
        n++;
    }

    n--;
    node* root = read(exp,&n);
    inOrder(root);
    printf("\n");

    return 0;
}
