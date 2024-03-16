#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
} NodeT;

NodeT* create(int key)
{
    NodeT* q = malloc(sizeof(NodeT));
    q->key = key;
    q->left = q->right = NULL;

    return q;
}

void insert(NodeT** root, int key)
{
    if(*root == NULL)
    {
        *root = create(key);
    }
    else
    {
        NodeT* q = *root;
        while(1)
        {
            if(key < q->key)
            {
                if(q->left == NULL)
                {
                    q->left = create(key);
                    break;
                }
                else
                    q = q->left;
            }
            else if(key > q->key)
                if(q->right == NULL)
                {
                    q->right = create(key);
                    break;
                }
                else
                    q = q->right;
            else break;
        }
    }
}

NodeT *searchKey( NodeT *root, int key )
{
    if(root == NULL)return NULL;


    if(root->key == key)return root;

    NodeT * p;

    p = searchKey(root->left,key);
    if(p == NULL) p = searchKey(root->right,key);

    return p;
}

void inOrder( NodeT *q)
{
    if(q==NULL)
        return;
    inOrder(q->left);
    printf("%d ",q->key);
    inOrder(q->right);
}

void preOrder( NodeT *q)
{
    if(q==NULL)
        return;

    printf("%d ",q->key);
    preOrder(q->left);
    preOrder(q->right);
}
void postOrder( NodeT *q)
{
    if(q==NULL)
        return;

    postOrder(q->left);
    postOrder(q->right);
    printf("%d ",q->key);
}

NodeT* findMin(NodeT* node)
{
    if(node == NULL)return NULL;
    if(node -> left == NULL)return node;
    return findMin(node->left);
}

NodeT* findMax(NodeT* node)
{
    if(node == NULL)return NULL;
    if(node -> right == NULL)return node;
    return findMax(node->right);
}

NodeT* succesor(NodeT *node, NodeT *root)
{
    if(root == NULL || node == NULL)return NULL;
    if(node->right != NULL)return findMin(node->right);

    NodeT *p = root, *q = NULL;

    while(p != node)
    {
        if(node->key < p->key)
        {
            q = p;
            p = p->left;
        }
        else if(node->key > p->key)
        {
            p = p->right;
        }
    }

    return q;
}

NodeT* deleteNode(NodeT* root, int key)
{
    NodeT *q, *p, *t;

    t = root;

    while(t->key != key)
    {
        p = t;
        if(key < t->key)
            t = t->left;
        else if(key > t->key)
            t = t->right;
    }
    if(t == root)
        root = t->right;
    else
    {
        if(p->left == t)
            p->left = t->right;
        else p->right = t->right;
    }

    p = root;
    q = t->left;
    free(t);

    while(q!=NULL)
    {
        if(q->key < p->key)
        {
            if(p->left == NULL)
            {
                p->left = q;
                return root;
            }
            else
            {
                p = p->left;
            }
        }
        else if(q->key > p->key)
        {
            if(p->right == NULL)
            {
                p->right = q;
                return root;
            }
            else
            {
                p = p->right;
            }
        }
    }

    return root;
}

int main()
{
    NodeT* root = NULL;
//    insert(&root,5);
//    insert(&root,5);
//    insert(&root,3);
//    insert(&root,7);
//
//    inOrder(root);
//    printf("\n");
//    preOrder(root);
//    printf("\n");
//    postOrder(root);
//    printf("\n");
//
//    NodeT* p = searchKey(root,5);
//    if(p!=NULL)printf("\n%d ",p->key);
//
//    NodeT* mi = findMin(p);
//    printf("\n%d ",mi->key);
//
//    NodeT* mx = findMax(p);
//    printf("\n%d ",mx->key);

    insert(&root,100);
    insert(&root,200);
    insert(&root,150);
    insert(&root,210);
    insert(&root,155);
    insert(&root,160);
    insert(&root,157);
    insert(&root,208);
    insert(&root,209);
    insert(&root,207);
    insert(&root,98);
    insert(&root,99);

//    NodeT* p = searchKey(root,160);
//    if(p!=NULL)printf("\n%d ",p->key);
//
//    NodeT* q = succesor(p,root);
//    if(q!=NULL)printf("\n%d ",q->key);

//    root = deleteNode(root,100);
//    inOrder(root);

//    NodeT* p = searchKey(root,99);
//    if(p!=NULL)printf("\n%d ",p->key);
//
//    NodeT* mi = findMin(p);
//    printf("\n%d ",mi->key);
//
//    NodeT* mx = findMax(p);
//    printf("\n%d ",mx->key);

    return 0;
}
