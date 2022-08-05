#include <stdio.h>
#include <stdlib.h>

struct BNode
{
    int data;
    BNode *left;
    BNode *right;
};

BNode *CreateNode(int data)
{
    BNode *newNode = new BNode;
    if(newNode != NULL)
    {
        newNode -> data =  data;
        newNode -> left = NULL;
        newNode -> right = NULL;
    }
    return newNode;
}


struct BTree
{
    BNode *root;
};


BTree *khoiTaoCay()
{
    BTree *newTree = new BTree;
    newTree -> root = NULL;

    return newTree;
}

void nhapCay(BNode* &p, FILE* f)
{
    int data=0;
    if(!feof(f))
    {
        fscanf(f, "%d", &data);
    }
    if(data == -1)
    {
        return;
    }   
    p = CreateNode(data);
    if(p != NULL)
    {
        nhapCay(p->left,f);
        nhapCay(p->right,f);
    }
}

void duyetCayOMucChoTruoc(BNode* &root, int k)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    duyetCayOMucChoTruoc(root->right,k+1);
    duyetCayOMucChoTruoc(root->left,k+1);
}

void duyetCauTheoChieuCao(BNode* &root, int k)
{
    if(root == NULL)
    {
        return;
    }
    if(k == 0)
    {
        printf("%d ",root->data);
        return;
    }
    duyetCauTheoChieuCao(root->left,k-1);
    duyetCauTheoChieuCao(root->right,k-1);
}

void duyetToanBoCay(BNode* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    duyetToanBoCay(root->left);
    duyetToanBoCay(root->right);
}

int demNut(BNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int a = demNut(root->left);
    int b = demNut(root->right);
    return (a+b+1);
}

int demLa(BNode* &root)
{
    if(root == NULL)
    {
        return 0;
    }
    int a = demLa(root->left);
    int b = demLa(root->right);
    if(root->left == NULL && root->right == NULL)
    {
        return (a+b+1);
    }
    else
    {
        return (a+b);
    }
}

int demNhanh(BNode* &root)
{
    int tongNut = demNut(root);
    int tongLa = demLa(root);
    
    return (tongNut - tongLa - 1);
}

int tinhChieuCao(BNode* &root)
{
    if(root == NULL)
    {
        return 0;
    }
    int a = tinhChieuCao(root);
    int b = tinhChieuCao(root);

    int height = a > b ? a : b;
    return (height + 1);
}

int main()
{
    FILE *f = NULL;
    BTree *tree = khoiTaoCay();
    f = fopen("input.txt", "r");
    if(f!= NULL)
    {
        nhapCay(tree->root, f);
    }
    fclose(f);
    duyetToanBoCay(tree->root);

}