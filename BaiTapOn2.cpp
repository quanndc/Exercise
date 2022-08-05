#include <stdio.h>
#include <stdlib.h>

typedef struct Bnode
{
    int info;
    Bnode *left;
    Bnode *right;
}Bnode;

template <typename T>
class Node
{
public:
	// attributes
	Node<T> *next;
	Node<T> *prev;
	T data;
public:
	// methods
	Node(T value, Node<T> *next, Node<T> *prev) 
	{
        this->data = value;
		this->next = next;
		this->prev = prev;
	}

	void setData(T data)
	{
		this->data = data;
	}

	T getData()
	{
		return data;
	}

	void setNext(Node<T> *next)
	{
		this->next = next;
	}

	Node<T> *getNext()
	{
		return next;
	}

	void setPrev(Node<T> *prev)
	{
		this->prev = prev;
	}

	Node<T> *getPrev()
	{
		return prev;
	}

	void print(char *format)
	{
		printf(format, getData());
	}
};


template <typename T>
class Queue
{
private:
	Node<T> *head;
	Node<T> *tail;
	int length;

public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		length = 0;
	}

	void setHead(Node<T> *head)
	{
		this->head = head;
	}

	void setTail(Node<T> *tail)
	{
		this->tail = tail;
	}

	int getSize()
	{
		return length;
	}

	void duyetQueue(char *format)
	{
		Node<T> *newNode = head;
		while (newNode != NULL)
		{
			newNode->print(format);
			newNode = newNode->getNext();
		}
	}

	void enqueue(T value)
	{
		Node<T> *newNode = new Node<T>(value, NULL, NULL);
		if (head == NULL)
		{
			head = tail = newNode;
			length++;
		}
		else
		{
			tail->setNext(newNode);
			setTail(newNode);
			length++;
		}
	}

	T dequeue()
	{
		Node<T> *result = head;
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			head = head->next;
			length--;
		}
		return result->getData();
	}

	T front()
	{
		return head->getData();
	}
};


typedef struct Btree
{
    Bnode *root;
}Btree;


Bnode *createBnode(int data)
{
    Bnode *newBnode = new Bnode;
    if(newBnode!=NULL)
    {
        newBnode->info = data;
        newBnode->left = NULL;
        newBnode->right = NULL;
    }

    return newBnode;
}

void initialize(Btree *&tree)
{
    tree->root=NULL;
}

int insertBnode(Bnode *&p, int data)
{
    if(p!=NULL)
    {
        if(p->info == data)
        {
            return 0;
        }
        else if(p->info > data)
        {
            return insertBnode(p->left,data);
        }
        else if(p->info < data)
        {
            return insertBnode(p->right,data);
        }
    }
    else
    {
        p = createBnode(data);
        if(p==NULL)
        {
            return -1;
        }
        return 1;
    }
}

void createBsTree(Bnode *&p, FILE *f)
{
    while(true)
    {
        int x = 0;
        fscanf(f,"%d",&x);
        if(x == -1)
        {
            break;
        }
        insertBnode(p,x);
    }
}

void LNR(Bnode *&p)
{
    if(p==NULL)
    {
        return;
    }
    LNR(p->left);
    printf("%d\t",p->info);
    LNR(p->right);
}

void NLR(Bnode *&p)
{
    if(p==NULL)
    {
        return;
    }
    printf("%d\t",p->info);
    NLR(p->left);
    NLR(p->right);
}

void LRN(Bnode *&p)
{
    if(p==NULL)
    {
        return;
    }
    LRN(p->left);
    LRN(p->right);
    printf("%d\t",p->info);
    
}

int nhapXcanTim()
{
    int x = 0;
    printf("Hay nhap x: ");
    scanf("%d", &x);

    return x;
}

void timKiemGiaTriX(Bnode *&p, int x)
{
    if(p==NULL)
    {
        return;
    }
    timKiemGiaTriX(p->left,x);
    if(p->info == x)
    {
        printf("Ton tai X trong cay!");
        return;
    }
    timKiemGiaTriX(p->right,x);
}

int demNut(Bnode *&p)
{
    if(p == NULL)
    {
        return 0;
    }
    int a = demNut(p->left);
    int b = demNut(p->right);
    return (a+b+1);
}

int demLa(Bnode *&p)
{
    if(p == NULL)
    {
        return 0;
    }
    int a = demLa(p->left);
    int b = demLa(p->right);
    if(p->left == NULL && p->right == NULL)
    {
        return (a+b+1);
    }
    else
    {
        return (a+b);
    }
}

int demNutTrungGian(Bnode *&p)
{
    int tongNut = demNut(p);
    int tongLa = demLa(p);
    
    return (tongNut - tongLa - 1);
}

void tongDuongDiTrong(Bnode *&p, int &sum, int count)
{
    if(p==NULL)
    {
        return;
    }
    sum += count;
    tongDuongDiTrong(p->left,sum,count+1);
    tongDuongDiTrong(p->right,sum,count+1);
}

void tongDuongDiNgoai(Bnode *&p, int &sum, int count)
{
    if(p==NULL)
    {
        sum += count;
        return;
    }
    tongDuongDiNgoai(p->left,sum,count+1);
    tongDuongDiNgoai(p->right,sum,count+1);
}

void themSoNguyenDuong(Bnode *&p)
{
    int n;
    do
    {
        printf("Hay nhap n: ");
        scanf("%d", &n);
    }
    while(n<0);

    insertBnode(p,n);
}

void tongGiaTriCacNut(Bnode *&p, int &sum)
{
    if(p==NULL)
    {
        return ;
    }
    sum += p->info;
    tongGiaTriCacNut(p->left,sum);
    tongGiaTriCacNut(p->right,sum);
}

bool kiemTraSoNguyenTo(int &n)
{
    if(n<2)
    {
        return false;
    }
    for(int i=2;i<(n-1); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int demSoNguyenTo(Bnode *&p, int &count)
{
    if(p==NULL)
    {
        return 0;
    }
    demSoNguyenTo(p->left,count);
    demSoNguyenTo(p->right,count);
    if(kiemTraSoNguyenTo(p->info))
    {
        count++;
    }
    return count;
}

void searchStandForLeft(Bnode *&p, Bnode *&sf)
{
    if(sf->left != NULL)
    {
        searchStandForLeft(p,sf->left);
    }
    else
    {
        p->info = sf->info;
        p = sf;
        sf = sf->right;
    }
}

void searchStandForRight(Bnode *&p, Bnode *&sf)
{
    if(sf->right != NULL)
    {
        searchStandForRight(p,sf->right);
    }
    else
    {
        p->info = sf->info;
        p = sf;
        sf = sf->left;
    }
}


int nhapPhanTuCanXoa()
{
    int x;
    printf("Hay nhap phan tu muon xoa: ");
    scanf("%d",&x);

    return x;
}
bool deleteNode(Bnode *&p, int x)
{
    if(p==NULL)
    {
        return false;
    }
    if(p->info > x)
    {
        return deleteNode(p->left,x);
    }
    if(p->info < x)
    {
        return deleteNode(p->right,x);
    }
    if(p->info == x)
    {
        Bnode *q = p;
        if(p->left == NULL && p->right == NULL)
        {
            p = NULL;
        }
        else if(p->left == NULL)
        {
            p = p->right;
        }
        else if(p->right == NULL)
        {
            p = p->left;
        }
        else
        {
            searchStandForLeft(q,p->right);
        }
        delete q;
        return true;
    }
}

void timDuongDiGiua2Nut(Bnode *&p, int a,int b)
{
    Queue<Bnode*> *queue = new Queue<Bnode*>();
    queue->enqueue(p);
    Bnode *start = NULL;
    Bnode *end = new Bnode();

    while(queue->getSize() != 0)
    {
        Bnode *current = queue->dequeue();
        if(current == NULL)
        {
            continue;
        }
        if(current->info == a)
        {
            start = current;
            end->info = b;
            break;
        }
        else if(current->info == b)
        {
            start = current;
            end->info = a;
            break;
        }
        queue->enqueue(current->left);
        queue->enqueue(current->right);
    }
    if(start == NULL)
    {
        return;
    }
    Bnode *current = start;
    int i = 0;
    int path[100];

    while(current != NULL)
    {
        if(current->info == end->info)
        {
            for(int j=0; j<i; j++)
            {
                printf("%d -> ", path[j]);
            }
            printf("%d", current->info);
            return;
        }
        if(current->info < end->info)
        {
            path[i++] = current->info;
            current = current->right;
        }
        else
        {
            path[i++] = current->info;
            current = current->left;
        }
    }
    printf("Khong co duong di giua 2 nut!");
}


void nhap2NutBatKi(Bnode *&p)
{
    int a=0,b=0;
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    insertBnode(p,a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);
    insertBnode(p,b);

    timDuongDiGiua2Nut(p,a,b);
}


int main()
{
    FILE *f = NULL;
    Btree *tree  = new Btree;
    initialize(tree);
    f = fopen("input2.txt","r");
    if(f!=NULL)
    {
        createBsTree(tree->root,f);
    }
    fclose(f);
    printf("LNR: ");
    LNR(tree->root);
    printf("\n");
    // printf("NLR: ");
    // NLR(tree->root);
    // printf("\n");
    // printf("LRN: ");
    // LRN(tree->root);
    //int x = nhapXcanTim();
    //timKiemGiaTriX(tree->root,x);
    //printf("So nut goc la : %d", demNut(tree->root));
    // printf("So nut trung gian la: %d", demNutTrungGian(tree->root));
    //int count = 0;
    //printf("So luong so nguyen to la: %d", demSoNguyenTo(tree->root,count));
    // themSoNguyenDuong(tree->root);
    // printf("\n");
    // LNR(tree->root);
    int sum1 = 0;
    tongDuongDiTrong(tree->root,sum1,0);
    printf("Tong duong di trong la: %d", sum1);
    //int sum2 = 0;
    // int sum3 = 0;
    // tongDuongDiNgoai(tree->root,sum3,0);
    // printf("Tong duong di ngoai la: %d", sum3);
    // tongGiaTriCacNut(tree->root,sum2);
    // printf("Tong gia tri cac nut la: %d", sum2);
    //nhap2NutBatKi(tree->root);
    // int n = nhapPhanTuCanXoa();
    // deleteNode(tree->root,n);
    // LNR(tree->root);
}