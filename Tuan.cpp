#include<stdio.h>

typedef struct BNODE
{
    int info;
    BNODE *left;
    BNODE *right;
}BNODE;

BNODE* CreateNode(int x)
{
    BNODE* p = new BNODE;
    if (p != NULL)
    {
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

typedef struct BTREE
{
    BNODE *root;
}BTREE;

void Initialize(BTREE &tree)
{
    tree.root = NULL;
}

void CreateTree(BNODE* &p, FILE *f)
{
    int x = 0;
    if(!feof(f))
    {
        fscanf(f, "%d", &x);
    }
    if(x == -1)
    {
        return;
    }
    p = CreateNode(x);
    if(p != NULL)
    {
        CreateTree(p->left, f);
        CreateTree(p->right, f);
    }
}

void PrintTree(BNODE* p, int k)
{
    if(p == NULL)
    {
        return;
    }
    PrintTree(p->right, k + 1);
    printf("%d \n ", p->info);
    PrintTree(p->left, k + 1);
}

int GetHight(BNODE *p)
{
    if(p == NULL) 
    {
        return 0;
    }
    int a = GetHight(p->left);
    int b = GetHight(p->right);
    int max = a > b ? a : b;
    return (max + 1);
}

void NLR(BNODE* p) 
{
    if (p == NULL) 
    {
        return;
    }
    printf("%d\t",p->info);
    NLR(p->left);
    NLR(p->right);
}

// void LNR(BNODE* p) 
// {
//     if (p == NULL) 
//     {
//         return;
//     }
//     LNR(p->left);
//     printf("%d: \t",p->info);
//     LNR(p->right);
// }

/*void LRN(BNODE* p)
{
    if (p == NULL) 
    {
        return;
    }
    LRN(p->left);
    LRN(p->right);
    printf("%d: \t",p->info);
}*/ 

int main()
{
    FILE *f = NULL;
    BTREE tree;
    Initialize(tree);
    f = fopen("input.txt","r");
    if(f!= NULL);
    {
        CreateTree(tree.root, f);
    }
    fclose(f);
    NLR(tree.root);
}