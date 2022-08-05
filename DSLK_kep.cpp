#include <stdio.h>
#include <string.h>

typedef struct SinhVien
{
	int MSSV;
	float toan,ly,hoa,TB;
	char Ho[30];
	char Ten[20];
} SV;

struct Node
{
	SV info;
	Node* next;
    Node* prev;
};

struct LinkedList
{
	Node* head;
    Node* tail;
	int length;
};

Node* khoiTaoMotNodeMoi(SV newInfo)
{
	Node *newNode; 
	newNode = new Node(); 
	newNode -> next = NULL;
    newNode -> prev = NULL;
	newNode -> info = newInfo;
	
	return newNode; // Tra ve gia tri cua Node vua tao
}


LinkedList* khoiTaoLinkedList()
{
	LinkedList *list = new LinkedList();
	list -> head = NULL;
    list -> tail = NULL;
	return list;
}


void themNodeVaoDauLinkedList(LinkedList* list, SV info)
{
	Node* newNode = khoiTaoMotNodeMoi(info);
	if(list -> head == NULL)
	{
        list -> head = newNode;
        list -> tail = newNode;
	}
	else
	{
		list -> head -> prev = newNode;
        newNode -> next = list -> head;
		list -> head = newNode;
	}
	list->length++;	
}

void themNodeVaoCuoiLinkedList(LinkedList* list, SV info)
{
	Node* newNode;
	newNode = khoiTaoMotNodeMoi(info);
	if(list -> head == NULL) 
	{
		list -> head = newNode;
        list -> tail = newNode;
	}
	else
	{
		list -> tail -> next = newNode;
		newNode -> prev = list -> tail;
        list -> tail = newNode;
    }
    list->length++;
}


void xoaNodeDauList(LinkedList* list)
{
	if(list -> head == NULL)
	{
		return;
	}
	else
	{
		list -> head = list -> head -> next;
		list -> head -> prev = NULL;
	}
	list -> length--;
}


void duyetList(LinkedList* list)
{
	for(Node* p=list->head;p!=NULL;p=p->next)
	{
        printf("%d  ", p->info.MSSV);
        printf("%.2f  ", p->info.toan);
        printf("%.2f  ", p->info.ly);
        printf("%.2f  ", p->info.hoa);
       	printf("%s  ", p->info.Ho);
        printf("%s  ",p->info.Ten);
		printf("\n");
    }
}

void docThongTinMotSV(FILE* f,char* fname, SV &sv)
{
	fscanf(f,"%d",&sv.MSSV);
	fscanf(f,"%f",&sv.toan);
	fscanf(f,"%f",&sv.ly);
	fscanf(f,"%f",&sv.hoa);
	fscanf(f,"%s",sv.Ho);
	fscanf(f,"%s",sv.Ten);
	sv.TB = (sv.toan+sv.ly+sv.hoa)/3.0;
}

void readFile(FILE *f,char* fname,LinkedList* list)
{
	int ch;
    f = fopen(fname,"r");
    if(f!=NULL)
	{
		fscanf(f,"%d",&ch);
		for(int i=0;i<ch;i++)
		{
			SV sv;
			docThongTinMotSV(f,fname,sv);
			themNodeVaoCuoiLinkedList(list,sv);		
		}
	}
	fclose(f);
}

void timSVcoDiemToanBeHon8(LinkedList *list)
{
	for(Node* p=list->head;p!=NULL;p=p->next)
	{
		if(p->info.toan < 8)
		{
			printf("%d  ", p->info.MSSV);
	        printf("%.2f  ", p->info.toan);
	        printf("%.2f  ", p->info.ly);
	        printf("%.2f  ", p->info.hoa);
	       	printf("%s  ", p->info.Ho);
	        printf("%s  ",p->info.Ten);
			printf("\n");
		}
	}
}

void xuatDanhSachSVcoDiemTB(LinkedList *list)
{
	for(Node* p=list->head;p!=NULL;p=p->next)
	{
        printf("%d  ", p->info.MSSV);
        printf("%.2f  ", p->info.toan);
        printf("%.2f  ", p->info.ly);
        printf("%.2f  ", p->info.hoa);
        printf("%.2f  ",p->info.TB);
       	printf("%s  ", p->info.Ho);
        printf("%s  ",p->info.Ten);
		printf("\n");
    }
}

int demSVcoDiemTBlonHon7(LinkedList *list)
{
	int count = 0;
	for(Node* p=list->head;p!=NULL;p=p->next)
	{
		if(p->info.TB > 7)
		{
			count++;
		}
	}
	return count;
}

Node* timSinhVienCoDiemLyCaoNhat(LinkedList *list)
{
	float max = 0;
	Node* p = list->head;
	while(p!=NULL)
	{
		if(p->info.ly > max)
		{
			max = p->info.ly;
		}
		p=p->next;
	}
	if(p!=NULL)
	{
		return p;
	}
}

void xuatTTsinhVienCoDiemLyCaoNhat(LinkedList *list)
{
	Node* sv = timSinhVienCoDiemLyCaoNhat(list);
	for(Node* p=list->head;p!=NULL;p=p->next)
	{
		if(p->info.ly == sv->info.ly)
		{
			printf("%d  ", p->info.MSSV);
			printf("%.2f  ", p->info.toan);
			printf("%.2f  ", p->info.ly);
			printf("%.2f  ", p->info.hoa);
			printf("%.2f  ",p->info.TB);
			printf("%s  ", p->info.Ho);
			printf("%s  ",p->info.Ten);
			printf("\n");
		}
	}
}

Node* timSinhVienCoDiemHoaThapNhat(LinkedList *list)
{
	float min = 10;
	Node* p = list->head;
	while(p!=NULL)
	{
		if(p->info.hoa < min)
		{
			min = p->info.hoa;
		}
		p=p->next;
	}
	if(p!=NULL)
	{
		return p;
	}
}

void xuatTTsinhVienCoDiemHoaThapNhat(LinkedList *list)
{
	Node* sv = timSinhVienCoDiemHoaThapNhat(list);
	for(Node* p=list->head;p!=NULL;p=p->next)
	{
		if(p->info.hoa == sv->info.hoa)
		{
			printf("%d  ", p->info.MSSV);
			printf("%.2f  ", p->info.toan);
			printf("%.2f  ", p->info.ly);
			printf("%.2f  ", p->info.hoa);
			printf("%.2f  ", p->info.TB);
			printf("%s  ", p->info.Ho);
			printf("%s  ", p->info.Ten);
			printf("\n");
		}
	}
}

void hoanVi(SV &a, SV &b)
{
	SV temp  = a;
	a = b;
	b = temp;
}

void write(FILE* f, char* fname, LinkedList *list)
{
	f=fopen(fname,"w");
	for(Node* p=list->head;p!=NULL;p=p->next)
	{
		fprintf(f,"%d  ", p->info.MSSV);
        fprintf(f,"%.2f  ", p->info.toan);
        fprintf(f,"%.2f  ", p->info.ly);
        fprintf(f,"%.2f  ", p->info.hoa);
        fprintf(f,"%.2f  ",p->info.TB);
       	fprintf(f,"%s  ", p->info.Ho);
        fprintf(f,"%s  ",p->info.Ten);
		fprintf(f,"\n");
	}
	fclose(f);
}


void sortTheoMSSV(LinkedList *list)
{
	for(Node* ptr1=list->head;ptr1!=NULL;ptr1=ptr1->next)
	{
		for(Node* ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
		{
			if(ptr1->info.MSSV > ptr2->info.MSSV)
			{
				hoanVi(ptr1->info,ptr2->info);
			}
		}
	}
}

void sortTheoTenvaXuatRaFile(FILE* f, char *fname, LinkedList *list)
{
	for(Node* ptr1=list->head;ptr1!=NULL;ptr1=ptr1->next)
	{
		for(Node* ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
		{
			if(strcmp(ptr1->info.Ten,ptr2->info.Ten) > 0)
			{
				hoanVi(ptr1->info,ptr2->info);
			}
		}
	}
	write(f,fname,list);
}

void xoaSinhVienTheoMSSV(LinkedList *list)
{
	int maSo;
	printf("Nhap MSSV can xoa: ");
	scanf("%d",&maSo);
	Node* p=list->head;
	Node *q = NULL;
	while(p!=NULL)
	{
		if(p->info.MSSV == maSo)
		{
			break;
		}
		q = p;
		p=p->next;
	}
	if(q!=NULL)
	{
	 	if(p!=NULL)
	 	{
			q -> next = p -> next;
			p -> prev = q;
		}
		list->length--;
	}
	else
	{
	 	xoaNodeDauList(list);
	}
}

int timMSSVlonNhat(LinkedList *list)
{
	int max = 0;
	for(Node*p=list->head;p!=NULL;p=p->next)
	{
		if(p->info.MSSV > max)
		{
			max = p->info.MSSV;
		}
	}
	return max;
}

void nhapThongTinSVcanThem(SV &sv)
{
	printf("Nhap MSSV: ");
	scanf("%d",&sv.MSSV);
	printf("Nhap diem Toan: ");
	scanf("%f",&sv.toan);
	printf("Nhap diem Ly: ");
	scanf("%f",&sv.ly);
	printf("Nhap diem Hoa: ");
	scanf("%f",&sv.hoa);
	printf("Nhap ho: ");
	scanf("%s", sv.Ho);
	printf("Nhap ten: ");
	scanf("%s", sv.Ten);
	sv.TB = (sv.toan+sv.ly+sv.hoa)/3.0;
}


void themSinhVien(FILE *f, char* fname, LinkedList *list)
{
	SV newStudent;
	nhapThongTinSVcanThem(newStudent);
	Node* p = list -> head;
	while(p!=NULL)
	{
		if(newStudent.MSSV < list->head->info.MSSV)
		{
			themNodeVaoDauLinkedList(list,newStudent);
			break;
		}
		else if(newStudent.MSSV > timMSSVlonNhat(list))
		{
			themNodeVaoCuoiLinkedList(list,newStudent);
			break;
		}
		else
		{
			themNodeVaoDauLinkedList(list,newStudent);
			sortTheoMSSV(list);
			break;
		}
	}
	write(f,fname,list);
}

void timSVtheoTen(FILE *f, char* fname, LinkedList *list)
{
	f=fopen(fname,"w");
	char *ten;
	
	printf("Nhap ten sv can tim: ");
	scanf("%s", ten = new char());
	for(Node*p=list->head;p!=NULL;p=p->next)
	{
		if(strcmp(ten,p->info.Ten)==0)
		{
			printf("%d  ", p->info.MSSV);
			printf("%.2f  ", p->info.toan);
			printf("%.2f  ", p->info.ly);
			printf("%.2f  ", p->info.hoa);
			printf("%.2f  ",p->info.TB);
			printf("%s  ", p->info.Ho);
			printf("%s  ",p->info.Ten);
			printf("\n");

			fprintf(f,"%d  ", p->info.MSSV);
			fprintf(f,"%.2f  ", p->info.toan);
			fprintf(f,"%.2f  ", p->info.ly);
			fprintf(f,"%.2f  ", p->info.hoa);
			fprintf(f,"%.2f  ",p->info.TB);
			fprintf(f,"%s  ", p->info.Ho);
			fprintf(f,"%s  ",p->info.Ten);
			fprintf(f,"\n");
		}
	}
	fclose(f);
}


int main()
{
	int maSo;
    FILE *f = NULL;
	LinkedList *list = khoiTaoLinkedList();
	readFile(f,"DSLK.txt",list);
	duyetList(list);
	printf("\n");
	// timSVcoDiemToanBeHon8(list);
	// xuatDanhSachSVcoDiemTB(list);
	// printf("So luong sinh vien co DTB > 7 la: %d", demSVcoDiemTBlonHon7(list));
	//timSinhVienCoDiemLyCaoNhat(list);
	//xuatTTsinhVienCoDiemLyCaoNhat(list);
	// timSinhVienCoDiemHoaThapNhat(list);
	// xuatTTsinhVienCoDiemHoaThapNhat(list);
	// sortTheoMSSV(list);
	// sortTheoMSSV(list);
	// write(f,"output1.txt",list);
	// sortTheoTenvaXuatRaFile(f,"output2.txt",list);
	xoaSinhVienTheoMSSV(list);
	//themSinhVien(f,"output3.txt",list);
	// timSVtheoTen(f,"sinhvien.txt",list);
	duyetList(list);
	return 0;
}
