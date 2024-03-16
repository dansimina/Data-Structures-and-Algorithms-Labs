#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int key;
    struct node *left, *right;
}NodeT;

NodeT* create(int givenkey)
{
    NodeT* p = malloc(sizeof(NodeT));
    p->key = givenkey;
    p->left = p->right = NULL;
}

NodeT* insertR(NodeT* t, NodeT* newNode)
{
    if(t == NULL)
        return newNode;

    if(newNode->key < t->key)
        t->left = insertR(t->left,newNode);
    else
        t->right = insertR(t->right,newNode);

    return t;
}

void insertA(NodeT** t, NodeT* newNode)
{
    if(*t == NULL){
        *t = newNode;
        return;
    }

    if(newNode->key < (*t)->key)
        insertA(&((*t)->left),newNode);
    else
        insertA(&((*t)->right),newNode);
}

void inorder(NodeT* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

void preorder(NodeT* root)
{
    if(root == NULL)
        return;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NodeT* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}

int main()
{
    NodeT* root = NULL;

    NodeT* t = create(3);
    root = insertR(root,t);

    NodeT* k = create(4);
    root = insertR(root,k);

    NodeT* p = create(1);
    root = insertR(root,p);

    NodeT* q = create(2);
    root = insertR(root,q);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
