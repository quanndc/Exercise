#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien
{
	int MSSV;
	char hoTen[50];
	float diemTB;	
}sv;

sv A[50];

void nhapMangSV(int &n, sv A[])
{
	int ch;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap ten SV thu %d", (i+1));
		//A[i].hoTen = new char[20];
		while((ch = getchar() != '\n')); 
		gets_s(A[i].hoTen);
		printf("Nhap MSSV thu %d", (i+1));
		scanf("%d",&A[i].MSSV);
		printf("Nhap diem TB cua sinh vien thu %d", (i+1));
		scanf("%f", &A[i].diemTB);
	}	
}

void xuatMangSV(int &n, sv A[])
{
	for(int i=0;i<n;i++)
	{
		printf("%s   %d   %.2f\n", A[i].hoTen, A[i].MSSV, A[i].diemTB);
	}
}

void timSinhVienTheoMSSV(int &n, sv A[], int &find)
{
	int flag = 0;
	printf("Nhap MSSV can tim: ");
	scanf("%d", &find);
	for(int i=0;i<n;i++)
	{
		if(find == A[i].MSSV)
		{
			flag = 1;
			printf("%s   %d   %.2f\n", A[i].hoTen, A[i].MSSV, A[i].diemTB);
		}
	}
	if(flag == 0)
	{
		printf("Khong tim thay sinh vien");
	}
}

void timSinhVienTheoTen(int &n, sv A[])
{
	char tenSV[50];
	int ch,flag = 0;
	printf("Nhap ten sinh vien can tim: ");
	while((ch = getchar() != '\n'));
	gets_s(tenSV);
	for(int i=0;i<n;i++)
	{
		if(strcmp(A[i].hoTen,tenSV) == 0)
		{
			flag = 1;
			printf("%s   %d   %.2f\n", A[i].hoTen, A[i].MSSV, A[i].diemTB);
		}
	}
	if(flag == 0)
	{
		printf("Khong tim thay sinh vien");
	}
}

void hoanVi1(sv &a, sv &b)
{
	sv temp = a;
	a = b;
	b = temp;
}


void sortSinhVienTheoTen(sv A[], int left, int right)
{
	char* x;
	int i = left, j = right;
	x = new char[30];
	strcpy(x,A[(left+right)/2].hoTen);
	while(i<j)
	{
		while(strcmp(A[i].hoTen,x) < 0)
		{
			i++;
		}
		while(strcmp(A[j].hoTen,x) > 0)
		{
			j--;
		}
		if(i<=j)
		{
			hoanVi1(A[i],A[j]);
			i++;
			j--;
		}
	}
	if(left < j)
	{
		sortSinhVienTheoTen(A,left,j);
	}
	if(right > i)
	{
		sortSinhVienTheoTen(A,i,right);
	}
}

void sortSinhVienTheoDiemTB(sv A[], int left, int right)
{
	int i = left, j = right;
	float x;
	x = A[(left+right)/2].diemTB;
	while(i<j)
	{
		while(A[i].diemTB > x)
		{
			i++;
		}
		while(A[j].diemTB < x)
		{
			j--;
		}
		if(i<=j)
		{
			hoanVi1(A[i],A[j]);
			i++;
			j--;
		}
	}
	if(left < j)
	{
		sortSinhVienTheoDiemTB(A,left,j);
	}
	if(right > i)
	{
		sortSinhVienTheoDiemTB(A,i,right);
	}
}


void nhapDiemTB(sv A[],float &diemTB)
{
	printf("Nhap diem can tim: ");
	scanf("%f",&diemTB);
}

int binarySearch(sv A[], float item, int left, int right)
{
	int mid = (left + right) / 2;
	if (left > right) 
	{
		return -1;
	}

	if (item == A[mid].diemTB) 
	{
		return mid;
	}
	if (item < A[mid].diemTB)
	{
		return binarySearch(A,item,mid+1,right);
	}
	if (item > A[mid].diemTB)
	{
		return binarySearch(A,item,left,mid-1);
	}

}

int timKiemSinhVienTheoDiemTB(sv A[],int &n, float diemTB)
{
	int i = binarySearch(A,diemTB,0,n-1);
	int start = i, end = i+1;
	if(binarySearch(A,diemTB,0,n-1) == -1)
	{
		printf("Khong tim thay sinh vien");
		return 0;
	}
	while(true)
	{
		if(A[start].diemTB == A[i].diemTB)
		{
			start--;
		}
		if(A[end].diemTB == A[i].diemTB)
		{
			end++;
		}
		if(start <= 0 || end > n-1)
		{
			break;
		}
		if(A[start].diemTB != A[i].diemTB && A[end].diemTB != A[i].diemTB)
		{
			break;
		}
	}
	for(int j=start;j<end;j++)
	{
		printf("%s   %d   %.2f\n", A[j].hoTen, A[j].MSSV, A[j].diemTB);
	}
}

int main()
{
	int n,find;
	float diemTB;
	char tenSV[50];
	nhapMangSV(n,A);
	xuatMangSV(n,A);
	//timSinhVienTheoMSSV(n,A,find);
	//timSinhVienTheoTen(n,A);
	//printf("Mang sinh vien sau khi sort theo diem la: \n");
	//sortSinhVienTheoTen(A,0,n-1);
	printf("-----------------------------\n");
	sortSinhVienTheoDiemTB(A,0,n-1);
	xuatMangSV(n,A);
	nhapDiemTB(A,diemTB);
	printf("----------------------------------\n");
	timKiemSinhVienTheoDiemTB(A,n,diemTB);
	
}