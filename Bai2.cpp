#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
typedef struct SinhVien{
	int MSSV;
	char hoten[50];
	float diemTB;
}SV;
SV ttinSV[100];

void hoanVi(SV &a, SV &b)
{
	SV temp = a;
	a = b;
	b = temp;
}

void write(FILE* f, int &n)
{
	for(int i=0;i<n;i++)
	{
		fprintf(f,"%d;%s;%.2f\n",ttinSV[i].MSSV, ttinSV[i].hoten, ttinSV[i].diemTB);
		//printf("%d;%s;%.2f\n",ttinSV[i].MSSV, ttinSV[i].hoten, ttinSV[i].diemTB);
	}
}

void input(int &n)
{
	int ch;
    // printf("Nhap so luong sinh vien: ");
    // scanf_s("%d",&n);
	// for(int i=0;i<n;i++)
        printf_s("Nhap ma sinh vien: ");
        scanf_s("%d",&ttinSV[n].MSSV);
        printf_s("Nhap ho ten sv: ");
        while((ch = getchar() != '\n')); 
        gets_s(ttinSV[n].hoten);
        printf_s("Nhap diem TB: ");
        scanf_s("%f", &ttinSV[n].diemTB);
        n++;

}

void read(char*fname, SV a[], int &n)
{
	char* tokens;
	char k[256];  
	FILE* f=NULL;
	f=fopen(fname,"r");
	int i=0;
	while(fgets(k,256,f)!=NULL)
	{
		tokens=strtok(k,";");
		ttinSV[i].MSSV = atoi(tokens);		
		tokens=strtok(NULL,";");			
		strcpy_s(ttinSV[i].hoten,tokens);
		tokens=strtok(NULL,";");
		ttinSV[i].diemTB = atof(tokens);

		i++;
	}	
	n=i;
	fclose(f);
}

void output(char*fname, SV a[], int &n)
{
	FILE* f=fopen(fname,"r");
	for(int i=0;i<n;i++)
	{
		printf_s("MSSV: %d	Ho ten: %s			Diem TB: %.2f\n",ttinSV[i].MSSV, ttinSV[i].hoten, ttinSV[i].diemTB);
	}	
}

void sortStudentTheoHoTen(char* fname, int &n)
{
	FILE* f=fopen(fname,"w");
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(strcmp(ttinSV[j].hoten,ttinSV[j-1].hoten)<0)
			{
				hoanVi(ttinSV[j], ttinSV[j-1]);
			}
		}
	}
	write(f,n);

	fclose(f);
}

void sortStudentTheoDiemTB(char* fname, int &n)
{
	FILE* f=fopen(fname,"w");
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(ttinSV[j].diemTB > ttinSV[j-1].diemTB)
			{
				hoanVi(ttinSV[j], ttinSV[j-1]);
			}
		}
	}
	write(f,n);

	fclose(f);
}

void timSvTheoMSSV(FILE *f, char* fname, int &n)
{
	f = fopen(fname,"w");
    int maSoSV;
    int flag = 0;
	printf_s("Nhap MSSV can tim: \n");
	scanf_s("%d",&maSoSV);
	for(int i=0;i<n;i++)
	{
		if(maSoSV == ttinSV[i].MSSV)
		{
			flag = 1;
			fprintf_s(f,"%d;%s;%.2f\n",ttinSV[i].MSSV, ttinSV[i].hoten, ttinSV[i].diemTB);
			printf_s("MSSV: %d	Ho ten: %s		Diem TB: %.2f\n",ttinSV[i].MSSV, ttinSV[i].hoten, ttinSV[i].diemTB);
		}
	}
	if(flag == 1)
	{
		printf_s("Da luu sinh vien tim theo MSSV");
	}
	else
	{
		printf_s("Khong tim thay sinh vien");
	}
}

void timSvTheoHoTen(FILE* f, char*fname, int &n)
{
	f = fopen(fname,"w");
    char hoTenSV[30], flag = 0, ch;
	printf_s("Nhap ten SV can tim: \n");
    while((ch = getchar() != '\n'));
	gets_s(hoTenSV);
	for(int i=0;i<n;i++)
	{
		if(strcmp(hoTenSV,ttinSV[i].hoten) == 0)
		{
			flag = 1;
			fprintf(f,"%d;%s;%.2f\n",ttinSV[i].MSSV, ttinSV[i].hoten, ttinSV[i].diemTB);
			printf_s("MSSV: %d	Ho ten: %s			Diem TB: %.2f\n",ttinSV[i].MSSV, ttinSV[i].hoten, ttinSV[i].diemTB);
		}
	}
	if(flag == 1)
	{
		printf_s("Da luu sinh vien tim theo ho ten");
	}
	else if(flag == 0)
	{
		printf_s("Khong tim thay sinh vien");
	}
}

void nhapDiemTBcanTim(float &diemTB)
{
	printf_s("Nhap diem can tim: ");
	scanf_s("%f",&diemTB);
}

int binarySearch( SV ttinSV[], float item, int left, int right)
{
	int mid = (left + right) / 2;
	if (left > right) 
	{
		return -1;
	}

	if (item == ttinSV[mid].diemTB) 
	{
		return mid;
	}
	if (item < ttinSV[mid].diemTB)
	{
		return binarySearch(ttinSV,item,mid+1,right);
	}
	if (item > ttinSV[mid].diemTB)
	{
		return binarySearch(ttinSV,item,left,mid-1);
	}

}

int timKiemSinhVienTheoDiemTBbinarySearch(SV ttinSV[],int &n, float diemTB)
{
	int i = binarySearch(ttinSV,diemTB,0,n-1);
	int start = i, end = i+1;
	if(binarySearch(ttinSV,diemTB,0,n-1) == -1)
	{
		printf_s("Khong tim thay sinh vien");
		return 0;
	}
	while(true)
	{
		if(ttinSV[start].diemTB == ttinSV[i].diemTB)
		{
			start--;
		}
		if(ttinSV[end].diemTB == ttinSV[i].diemTB)
		{
			end++;
		}
		if(start < 0 || end > n-1)
		{
			break;
		}
		if(ttinSV[start].diemTB != ttinSV[i].diemTB && ttinSV[end].diemTB != ttinSV[i].diemTB)
		{
			break;
		}
	}
	for(int j=start+1;j<end;j++)
	{
		printf_s("%d   %s   %.2f\n", ttinSV[j].MSSV, ttinSV[j].hoten, ttinSV[j].diemTB);
	}
}


int main()
{
	int n = 0, maSoSV;
	int choice;
    float diemTB;
	FILE* f=NULL;
	do
	{
		system("cls");
		printf_s("Menu\n");
		printf_s("1.Nhap thong tin sv xuong file\n");
		printf_s("2.Doc thong tin tu sv file\n");
		printf_s("3.Xuat mang thong tin tu file\n");
		printf_s("4.Tim kiem thong tin SV theo MSSV (Linear Search) \n");
		printf_s("5.Tim kiem thong tin SV theo ho ten (Linear Search)\n");
		printf_s("6.Sap xep sinh vien tang dan theo ho ten\n");
        printf_s("7.Sap xep sinh vien giam dan theo diem TB\n");
        printf_s("8.Tim kiem thong tin SV theo diemTB (Binary Search) \n");
		printf_s("9.Thoat\n");
		printf_s("Chon chuc nang");
		scanf_s("%d", &choice);
		
		switch(choice)
		{
			case 1:
				f=fopen("ThongTinSV.txt","w");
				input(n);
				write(f, n);
				fclose(f);
				break;
			case 2:
				read("ThongTinSV.txt",ttinSV,n);
				break;
			case 3:
				output("ThongTinSV.txt",ttinSV,n);
				break;
			case 4:
				timSvTheoMSSV(f,"timTheoMSSV.txt",n);
				break;
			case 5:
				timSvTheoHoTen(f,"timTheoHoTen.txt",n);
				break;
			case 6:
				sortStudentTheoHoTen("SSSVsapXepTheoHoTen.txt",n);
				break;
            case 7:
                sortStudentTheoDiemTB("DSSVsapXepTheodiemTB.txt",n);
                break;
            case 8:
                nhapDiemTBcanTim(diemTB);
                binarySearch(ttinSV,diemTB,0,n-1);
                timKiemSinhVienTheoDiemTBbinarySearch(ttinSV,n,diemTB);
                break;
			case 9:	
				break;		
		}
		getch();
	} while (choice!=9);	
}