#include <stdio.h>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

struct Tree
{
    Node *root;
};


Node *createNode(int data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}   


Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;

    return tree;
}


void insertNode(Tree *tree, int data)
{
    
    Node *newNode = createNode(data);
    Node *p = tree->root;
    if(tree->root == NULL)
    {
        tree->root = newNode;
        return;
    }
    while(p!=NULL)
    {
        if(p->data > data)
        {
            if(p->left == NULL)
            {
                p->left = newNode;
                return;
            }
            p = p->left;
        }
        else if(p->data < data)
        {
            if(p->right == NULL)
            {
                p->right = newNode;
                return;
            }
            p=p->right;
        }
        else
        {
            return;
        }
    }
}

void readFile(FILE *f, char *fname, Tree *tree)
{
    f = fopen(fname,"r");
    if(f!=NULL)
    {
        int data = 0;
        while(!feof(f))
        {
            fscanf(f,"%d", &data);
            insertNode(tree,data);
        }
    }
    fclose(f);
}

void LNR(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    LNR(p->left);
    printf("%d", p->data);
    LNR(p->right);
}

int main()
{
    Tree *tree = createTree();
    FILE *f = NULL;
    readFile(f,"1.txt",tree);

    LNR(tree->root);
}