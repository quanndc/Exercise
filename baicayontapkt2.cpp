#include <stdio.h>

typedef struct BNODE
{
	int info;
	BNODE* left;
	BNODE* right;
}BNODE;

typedef struct
{
	BNODE* root;
}BSTREE;

BNODE* CreateNode(int x)
{
	BNODE* p = new BNODE;
	if(p != NULL)
	{
		p->info = x;
		p->left=NULL;
		p->right=NULL;
	}
	return p;
}

void Initialize(BSTREE &tree)
{
	tree.root=NULL;
}

int InsertNode(BNODE* &p, int x) 
{
	if (p != NULL)
	{
		if (p->info == x)
			return 0; 
		else if (p->info > x)
			return InsertNode(p->left, x);
		else if (p->info < x)
			return InsertNode(p->right, x);
	} 
	else
	{ 
		p = CreateNode(x);
		if (p == NULL)
		{
				return -1;
		}
		return 1; 
	}
}

void ReadfileBSTree(BNODE* &p) 
{
	FILE* f=fopen("input2.txt","r");
	while (true) 
	{
		int x=0;
		fscanf(f,"%d",&x);
		if (x == -1)
		{
			break;
		}
		InsertNode(p,x);
	}
	fclose(f);
}

void LNR(BNODE* p)
{
	if(p == NULL)
	{
		return;
	}
	LNR(p->left);
	printf("%d\t",p->info);
	LNR(p->right);
}

void NRL(BNODE* p)
{
	if(p == NULL)
	{
		return;
	}
	printf("%d\t",p->info);
	NRL(p->right);
	NRL(p->left);
}

void LRN(BNODE* p)
{
	if(p == NULL)
	{
		return;
	}

	LRN(p->left);
	LRN(p->right);
	printf("%d\t",p->info);
}

int SearchNode(BNODE* p, int x)
{
	if(p == NULL)
		return NULL;
	if(p->info == x)
		return x;
	if(p->info > x)
		return SearchNode(p->left,x);
	if(p->info < x)
		return SearchNode(p->right,x);
}

int CountGocNode(BNODE* p)
{
	if(p == NULL)
		return 0;
	if(p!=NULL)
		return 1;
}

int CountLeafNode(BNODE* p)
{
	if(p==NULL)
		return 0;
	int a=CountLeafNode(p->left);
	int b=CountLeafNode(p->right);
	if(p->left==NULL && p->right==NULL)
		return(a+b+1);
	else
		return(a+b);
}

int CountBranchNode(BNODE* p)
{
	if(p==NULL)
		return 0;
	int a=CountBranchNode(p->left);
	int b=CountBranchNode(p->right);
	if(p->left==NULL && p->right==NULL)
		return(a+b+1);
	else
		return(a+b);
}

int tongDoDaiDuongDiTrong(BNODE* p,int n)
{
	if(p == NULL)
		return 0;
	if(p->left==NULL && p->right==NULL)
		return 0;
	else
		return tongDoDaiDuongDiTrong(p->left,n+1) + tongDoDaiDuongDiTrong(p->right,n+1)+n;
}

int tongDoDaiDuongDiNgoai(BNODE* p,int n)
{
	if(p == NULL)
		return 0;
	if(p->left==NULL && p->right==NULL)
		return n;
	else
		return tongDoDaiDuongDiNgoai(p->left,n+1) + tongDoDaiDuongDiNgoai(p->right,n+1);
}

void SearchStandFor(BNODE* &q, BNODE* &sf)
{
	if(sf->left!= NULL)
		SearchStandFor(q,sf->left);
	else
	{
		q->info = sf->info;
		q=sf;
		sf = sf->right;
	}
}

bool DeleteNode(BNODE* &p, int x) 
{
	if (p == NULL)
	return false;
	if (p->info > x)
	return DeleteNode(p->left, x);
	if (p->info < x)
	return DeleteNode(p->right, x);
	if (p->info == x) 
	{
		BNODE* q = p;
		if (p->left == NULL && p->right ==NULL)
			p=NULL;
		else if(p->left == NULL)
			p=p->right;
		else if(p->right == NULL)
			p= p->left;
		else 
			SearchStandFor(q,p->right);
		delete q;
		return true;
	}
}
int CreateNode(BNODE* p)
{
	if(p==NULL)
		return 0;
	int a = CreateNode(p->left);
	int b = CreateNode(p->right);
	return (a+b+1);
}

int tinhTongCacNut(BNODE* &p)
{
	if(p!=NULL)
		return p->info + tinhTongCacNut(p->left) + tinhTongCacNut(p->right);
	else 
		return 0;
}

bool KTSoNguyenTo(int &n)
{
	if(n<2)
		return false;
	for(int i=2;i<(n-1);i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

int CountNodeSoNguyenTo(BNODE* &p)
{
	if(p == NULL)
		return 0;
	int a=CountNodeSoNguyenTo(p->left);
	int b=CountNodeSoNguyenTo(p->right);
	return(a+b+KTSoNguyenTo(p->info));
}


int main()
{
	BSTREE tree;
	//BNODE *p= tree.root;
	Initialize(tree);
	ReadfileBSTree(tree.root);
	printf("Sap xep theo LNR la:\n");
	LNR(tree.root);
	printf("\nSap xep theo NRL la:\n");
	NRL(tree.root);
	printf("\nSap xep theo LRN la: \n");
	LRN(tree.root);
	
	//cau c
	int x=0;
	printf("\nNhap gia tri x can tim:");
	scanf("%d",&x);
	int find1 = SearchNode(tree.root,x);
	if(find1)
		printf("\nTim thay %d",find1);
	else
		printf("\n Khong tim thay %d trong cay.",x);
		
	//cau d
	printf("\nDem so nut goc:%d",CountGocNode(tree.root));
	printf("\n Dem so nut la:%d",CountLeafNode(tree.root));
	printf("\n Dem so nut trung gian:%d",CountBranchNode(tree.root));
	
	// cau e	
	printf("\n");
	int n=0;
	printf("Tong do dai duong di trong la:%d",tongDoDaiDuongDiTrong(tree.root,n));
	printf("\nTong do dai duong di ngoai la:%d",tongDoDaiDuongDiNgoai(tree.root,n));
	
	// cau f
	printf("\n");
	int y=0;
	printf("Nhap gia tri can them vao:");
	scanf("%d",&y);
	InsertNode(tree.root,y);
	LNR(tree.root);
	
	//cau g
	printf("\n");
	printf("Nhap gia tri can xoa:");
	scanf("%d",&y);
	DeleteNode(tree.root,y);
	LNR(tree.root);
	
	//cau h
	printf("\n");
	printf("Tong cac nut co trong cay la : %d",CreateNode(tree.root));
	
	//cau i
	printf("\n");
	printf("\nDem tong cac nut co trong cay la: %d",tinhTongCacNut(tree.root));
	
	//cau j
	printf("\n");
	KTSoNguyenTo(n);
	printf("Dem so nut chua so nguyen to trong cay: %d",CountNodeSoNguyenTo(tree.root));
	
	//cau k
	/*int t,z;
	printf("\n Nhap gia tri nut 1:");
	scanf("%d",&t);
	printf("\n Nhap gia tri nut 2:");
	scanf("%d",&z);
	while(z == t)
	{
		printf("Nhap lai so z khac %d:",t);
		scanf("%d",&z);
	}
	if(SearchNode(tree.root, t) == 0 || SearchNode(tree.root, z) == 0)
	{
		if(SearchNode(tree.root, t) == 0)
			printf("\nPhan tu %d khong ton tai!", t);
		if(SearchNode(tree.root, z) == 0)
			printf("\nPhan tu %d khong ton tai!", z);
	}
	else 
	{
		if (t > z)
		{
			int temp = z;
			z = t;
			t = temp;
		}
		printf("\nDo dai duong di la tu %d den %d: %d", t, z, CountDuongDi2Node(tree.root, t, z));
	}*/
}
	

