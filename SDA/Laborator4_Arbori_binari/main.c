#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node* left;
    struct node* right;
}NodeT;

NodeT* create(int key){
    NodeT* q = malloc(sizeof(NodeT));
    q->key = key;
    q->left = q->right = NULL;

    return q;
}

NodeT* read(FILE* f){
    char s[100];
    fscanf(f," %s", s);

    if(s[0] == '#')
        return NULL;

    else{
        int x = atoi(s);
        NodeT* q = create(x);

        q->left = read(f);
        q->right = read(f);

        return q;
    }
}

void preorder(NodeT* q){
    if(q == NULL)
    {
//        printf("# ");
        return;
    }


    printf("%d ",q->key);
    preorder(q->left);
    preorder(q->right);
}

void inorder(NodeT* q){
    if(q == NULL)
        return;

    inorder(q->left);
    printf("%d ", q->key);
    inorder(q->right);
}

void postorder(NodeT* q){
    if(q == NULL)
        return;

    postorder(q->left);
    postorder(q->right);
    printf("%d ", q->key);
}

int nrFrunze(NodeT* q){
    if(q == NULL)return 0;
    if(q->left == NULL && q->right == NULL){
        printf("%d ",q->key);
        return 1;
    }

    return nrFrunze(q->left) + nrFrunze(q->right);

}

int nrNoduriInterne(NodeT* q){
    if(q == NULL)return 0;
    if(q->left == NULL && q->right == NULL){
        return 0;
    }

    return 1 + nrNoduriInterne(q->left) + nrNoduriInterne(q->right);
}

NodeT* cauta(NodeT* q, int key)
{
    if(q == NULL)return NULL;
    if(q->key == key)return q;

    NodeT* p;
    p = cauta(q->left, key);
    if(p != NULL)return p;
    p = cauta(q->right, key);
    return p;
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int inaltime(NodeT* q){
    if(q == NULL)return 0;
    if(q->left == NULL && q->right == NULL)return 0;
    return 1 + max(inaltime(q->left),inaltime(q->right));
}

void diametru(NodeT* q, int *val)
{
    if(q == NULL)
        return;

    *val = max(2 + inaltime(q->left) + inaltime(q->right),*val);
    diametru(q->left,val);
    diametru(q->right,val);
}

///celelalte parcurgeri
///cate frunze avem plus afisat
///nr noduri interne
///inaltimea unui nod
///cautat un nod cu cheia data

int main()
{
    FILE *f = fopen("arbore.txt","r");
    if(!f)return -1;

    NodeT* root = read(f);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("\n%d ",nrFrunze(root));
    printf("\n%d ",nrNoduriInterne(root));

    NodeT* p;
    p=cauta(root,2);
    printf("\n%d ", inaltime(p));
    int d = 0;
    diametru(root,&d);
    printf("\n%d ", d);
    printf("\n%d ", 2 + inaltime(root->left) + inaltime(root->right));

    return 0;
}
