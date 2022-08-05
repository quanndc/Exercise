#include<stdio.h>

typedef struct BNODE
{
    int info;
    BNODE *left;
    BNODE *right;
}BNODE;

BNODE* CreateNode(int x)
{
    BNODE *p = new BNODE;
    if(p != NULL)
    {
        p->info = x; 
        p->left = NULL;
        p->right = NULL;
    } 
    return p;
}

typedef struct BSTREE
{
    BNODE*root;
}BSTREE;

void Initialize(BSTREE &tree)
{
    tree.root = NULL;
}

int InsertNode(BNODE *&p, int &x)
{
    if(p != NULL)
    {
        if(p->info == x)
        {
            return 0;
        }
        else
        {
            if(p->info > x)
            {
                return InsertNode(p->left, x);
            }
            else 
            {
                if(p->info < x)
                {
                    return InsertNode(p->right, x);
                }
            }
        }
    }
    else 
    {
        p = CreateNode(x);
        if(p == NULL)
        {
            return -1;
        }
        return 1;
    }
}

void CreateBSTree(BNODE * &p, FILE *f)
{
    while(true)
    {
        int x = 0;
        if(!feof(f))
        {
            fscanf(f, "%d", &x);
        }
        if(x == -1)
        {
            break;
        }
        InsertNode(p, x);
    }
}

void LNR(BNODE *p)
{
    if(p == NULL)
    {
        return;
    }
    LNR(p->left);
    printf("%d  ", p->info);
    LNR(p->right);
}

void NLR(BNODE *p)
{
    if(p == NULL)
    {
        return;
    }
    printf("%d  ", p->info);
    NLR(p->left);
    NLR(p->right);
}

void LRN(BNODE *p)
{
    if(p == NULL)
    {
        return;
    }
    LRN(p->left);
    LRN(p->right);
    printf("%d  ", p->info);
}

BNODE* SearchNode(BNODE* p, int x) // tim phan tu X
{
    if(p == NULL)
    {
        return NULL;
    }
    if (p->info == x) 
    {
        return p; 
    }
    if (p->info > x)
    {
        return SearchNode(p->left, x);    
    }
    if (p->info < x) 
    {
        return SearchNode(p->right, x);
    }
}

int CountNodeGoc(BNODE *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    return 1;
}
int CountNode(BNODE *p) // dem Node 
{
    if( p == NULL)
    {
        return 0;
    }
    int a = CountNode(p->left);
    int b = CountNode(p->right);
    return(a + b + 1);
}

int CountLeaf(BNODE*p) // dem Node lá
{
    if(p == NULL)
    {
        return 0;
    }
    int a = CountLeaf(p->left);
    int b = CountLeaf(p->right);
    if(p->left == NULL && p->right == NULL)
    {
        return(a + b +1);
    }
    else
    {
        return(a + b);
    }
}

int CountBranchNode(BNODE*p) // dem Node Trung gian
{
    int allNodes = CountNode(p);
    int leafNodes = CountLeaf(p);
    return allNodes - leafNodes -1; 
}

void TongDuongDiTrong(BNODE *&p, int &sum, int count)
{
    if(p == NULL);
    {
        return;
    }
    sum += count;
    TongDuongDiTrong(p->left, sum, count+1);
    TongDuongDiTrong(p->right, sum, count+1);
}

void AddNode(BNODE* &p, int x) // them Node
{
    do
    {
        printf("\n Nhap phan tu can them: ");
        scanf("%d",&x);
        if(x <= 0)
        {
            printf("Phai la so nguyen duong. Yeu cau nhap lai.");
        }
        
    }while(x<=0);
    InsertNode(p,x);
}

int Sum(BNODE *p) // tong gia tri cac Node trong cay
{
    if(p == NULL) 
    {
        return 0;
    }
    else
    {
        return (Sum(p->left) + Sum(p->right) + p->info);
    }
}

void SearchStandFor(BNODE *&q, BNODE* &sf)
{
    if (sf->left != NULL)
    { 
        SearchStandFor(q, sf->left);
    }
    else 
    {
        q->info = sf->info;
        q = sf;
        sf = sf->right;
    }
}

bool DeleteNode(BNODE* &p, int x) // xoa phan tu x
{
    if (p == NULL) 
    {
        return false;
    }
    if (p->info > x) 
    {
        return DeleteNode(p->left, x);
    }
    if (p->info < x) 
    {
        return DeleteNode(p->right, x);
    }
    if (p->info == x) 
    {
        BNODE* q = p;
        if (p->left == NULL && p->right == NULL) 
        {
            p = NULL;
        }
        else 
        {
            if (p->left == NULL)  
            {
                p = p->right;
            }
            else
            {
                if (p->right == NULL) 
                {
                    p = p->left;
                }
                else 
                {
                    SearchStandFor(q, p->right); 
                    delete q;
                    return true;
                }
            }

        }
    }
}

int main()
{
    FILE* f;
    BNODE BNODE;
    BSTREE tree;
    Initialize(tree);
    f = fopen("input2.txt","r");
    if(f!= NULL)
    {
        CreateBSTree(tree.root, f);
    }
    fclose(f);

    printf("\n LNR: ");
    LNR(tree.root);

    printf("\n NLR: ");
    NLR(tree.root);

    printf("\n LRN: ");
    LRN(tree.root);

    int x=0; // tim phan tu X
    printf("\n Nhap Phan Tu X can tim: ");
    scanf("%d",&x);
    if(SearchNode (tree.root, x) == NULL)
    {
        printf(" Phan tu ko ton tai trong cay.");
    }
    else
    {
        printf(" Phan tu co ton tai trong cay.");
    }

    printf("\n So Node Goc tren cay : %d \n",CountNodeGoc(tree.root));

    printf("\n So Node tren cay : %d \n",CountNode(tree.root));

    printf("\n So la tren cay : %d \n",CountLeaf(tree.root));

    printf("\n So Node trung gian tren cay : %d \n",CountBranchNode(tree.root));

    int sum1 = 0;
    TongDuongDiTrong(tree.root,sum1,0);
    printf("\n Tong duong di ngoai: %d", sum1);

    AddNode(tree.root,x); // Them Node
    printf(" Cay sau khi them la: ");
    LNR(tree.root);

    printf("\n Tong gia tri cac Node trong cay: %d", Sum(tree.root)); //tong gia tri cac Node trong cay
    
    int a;// xoa phan tu x
    printf("\n Nhap phan tu can xoa: ");
    scanf("%d",&a);
    DeleteNode(tree.root, a);
    printf("\n Cay sau khi xoa: ");
    LNR(tree.root);
    
}   

