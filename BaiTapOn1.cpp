#include <stdio.h>
#include <stdlib.h>

typedef struct XeHoi
{
	char *hangXe;
	char *mauSac;
	int soChonGoi;
	float giaTien;
}XeHoi;

typedef struct Node
{
	XeHoi info;
	Node *next;
}Node;

typedef struct LinkedList
{
	Node *head;
    Node *sortedHead;
}LinkedList;

Node *createNode(XeHoi data)
{
	Node *newNode = new Node;
	if(newNode != NULL)
	{
		newNode->info = data;
		newNode->next = NULL;
	}
	return newNode;
}

LinkedList *createList()
{
	LinkedList *list = new LinkedList;
	list->head = NULL;
	
	return list;
}

void addHead(LinkedList *list, XeHoi data)
{
	Node *newNode = createNode(data);
	if(list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		newNode->next = list->head;
		list->head = newNode;
	}
}

void addTail(LinkedList *list, XeHoi data)
{
	Node *newNode = createNode(data);
	if(list->head == NULL)
	{
		list->head = newNode;
	}
	else
    {
        Node *p = list->head;
	    while(p->next!=NULL)
	    {
		    p=p->next;
	    }
	p->next = newNode;
    }
}

XeHoi docThongTinXe(FILE *f)
{
    XeHoi xe;
    xe.hangXe = new char[30];
	fscanf(f,"%s",xe.hangXe);
	xe.mauSac = new char[30];
	fscanf(f,"%s",xe.mauSac);
    fscanf(f,"%d",&xe.soChonGoi);
	fscanf(f,"%f",&xe.giaTien);

    return xe;
}

void docFile(FILE *f, char *fname,LinkedList *list)
{
	f = fopen(fname,"r");
	if(f != NULL)
	{
        while(!feof(f))
		{
            XeHoi car = docThongTinXe(f);
			addTail(list,car);
		}
	}
    fclose(f);
}

void xuatThongTin(LinkedList *list)
{
	for(Node* p = list->head; p!=NULL; p=p->next)
	{
		printf("%s\t",p->info.hangXe);
		printf("%s\t",p->info.mauSac);
		printf("%d\t",p->info.soChonGoi);
		printf("%.2f\t",p->info.giaTien);
        printf("\n");	
	}
}

void xuatThongTinXeCoGiaThap(LinkedList *list)
{
    float tien;
    printf("Nhap gia tien: ");
    scanf("%f",&tien);
    printf("Cac loai xe co gia tien thap hon gia tien nhap vao la: \n");
    for(Node *p = list->head; p!=NULL; p=p->next)
    {
        if(tien > p->info.giaTien)
        {
            printf("%s\t",p->info.hangXe);
            printf("%s\t",p->info.mauSac);
            printf("%d\t",p->info.soChonGoi);
            printf("%.2f\t",p->info.giaTien);
            printf("\n");	
        }
    }
}


void sortedInsert(LinkedList* list, Node *newNode)
{
    if(list->sortedHead == NULL || list->sortedHead->info.giaTien >= newNode->info.giaTien)
    {
        newNode->next = list->sortedHead;
        list->sortedHead = newNode;
    }
    else
    {
        Node *p = list->sortedHead;
        while(p->next != NULL && p->next->info.giaTien < newNode->info.giaTien)
        {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
}

void insertionSort(LinkedList *list,Node *headRef)
{
    list->sortedHead = NULL;
    Node *current = headRef;
    while(current != NULL)
    {
        Node *currentNext = current->next;
        sortedInsert(list,current);
        current = currentNext;
    }
    list->head = list->sortedHead;
}

int main()
{
	FILE *f = NULL;
	LinkedList *list = createList();
	docFile(f,"input1.txt",list);
	xuatThongTin(list);
    insertionSort(list,list->head);
    printf("================================\n");
    xuatThongTin(list);
    //xuatThongTinXeCoGiaThap(list);
	
	
}