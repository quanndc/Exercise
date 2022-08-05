#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct SinhVien
{
    int MSSV;
    float diemToan,diemLy,diemHoa,diemTB;
    char firstName[30];
    char lastName[30];
}SV;

typedef struct
{
    int n;
    SV sv[MAX];
}CLIST;

void khoiTaoDanhSach(CLIST &list)
{
    list.n = 0;
}

bool isEmpty(CLIST &list)
{
    if(list.n == 0)
    {
        return true;
    }
    return false;
}

bool isFull(CLIST &list)
{
    if(list.n == MAX)
    {
        return true;
    }
    return false;
}


void read(FILE *f,char *fname,int &n, CLIST &list)
{
    f = fopen(fname,"r");
    if (f != NULL)
    {
        for(int i=0;i<n;i++)
        {
            fscanf(f,"%d    ",&list.sv[i].MSSV);                                
            fscanf(f,"%f    ",&list.sv[i].diemToan);
            fscanf(f,"%f    ",&list.sv[i].diemLy);
            fscanf(f,"%f    ",&list.sv[i].diemHoa);
            fscanf(f,"%s    ",list.sv[i].firstName);
            fscanf(f,"%s    ",list.sv[i].lastName);
        }
        fclose(f);
    }
}

void output(CLIST &list, int &n)
{
	for(int i=0;i<n;i++)
	{
		printf_s("%d    ",list.sv[i].MSSV);
        printf_s("%.2f  ",list.sv[i].diemToan);
        printf_s("%.2f  ",list.sv[i].diemLy);
        printf_s("%.2f  ",list.sv[i].diemHoa);
        printf_s("%s    ",list.sv[i].firstName);
        printf_s("%s    ",list.sv[i].lastName);
        printf_s("\n");

	}	
}


void timThongTinSvCoDiemToanNhoHon8(CLIST &list,int &n) 
{
    printf("Nhung sinh vien co diem toan < 8 la: \n");
    int flag = 0;
    for (int i=0;i<n;i++)
    {
        if (list.sv[i].diemToan < 8)
        {
            flag = 1;
            printf_s("%d    ",list.sv[i].MSSV);
            printf_s("%.2f  ",list.sv[i].diemToan);
            printf_s("%.2f  ",list.sv[i].diemLy);
            printf_s("%.2f  ",list.sv[i].diemHoa);
            printf_s("%s    ",list.sv[i].firstName);
            printf_s("%s    ",list.sv[i].lastName);
            printf_s("\n");
        }
    }
    if(flag == 0)
    {
        printf("Khong tim thay sinh vien");
    }
}

void tinhDiemTB(CLIST &list, int &n)
{
    for(int i=0;i<n;i++)
    {
        list.sv[i].diemTB = (list.sv[i].diemToan+list.sv[i].diemLy+list.sv[i].diemHoa)/3.0;
    }
}

int demSvCoDiemTBlonHon7(CLIST &list, int &n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(list.sv[i].diemTB > 7)
        {
            count++;
        }
    }
    return count;
}

void xuatThongTinSvCoDiemLyCaoNhat(CLIST &list,int &n)
{
    float maxLy = list.sv[0].diemLy;
    for(int i=1;i<n;i++)
    {
        list.sv[i].diemLy > maxLy ? maxLy = list.sv[i].diemLy : maxLy;
    }
    for(int j=0;j<n;j++)
    {
        if(list.sv[j].diemLy == maxLy)
        {
            printf_s("%d    ",list.sv[j].MSSV);
            printf_s("%.2f  ",list.sv[j].diemToan);
            printf_s("%.2f  ",list.sv[j].diemLy);
            printf_s("%.2f  ",list.sv[j].diemHoa);
            printf_s("%s    ",list.sv[j].firstName);
            printf_s("%s    ",list.sv[j].lastName);
            printf_s("\n");
        }
    }
}

void nhapMSSVcanXoa(int &x)
{
    printf("Nhap MSSV: ");
    scanf("%d",&x);
}
void xoaThongTinSVtheoMSSV(CLIST &list, int &n,int &x)
{
    nhapMSSVcanXoa(x);
    for (int i=0;i<n;i++)
    {
        if(list.sv[i].MSSV == x)
        {
            for(int j=i;j<n-1;j++)
            {
                list.sv[j] = list.sv[j+1];  
            }
        } 
    }
    n--;
}

void nhapViTriCanThem(int &k)
{
    printf("Nhap vi tri can them: ");
    scanf_s("%d",&k);
}
void themThongTinSV(CLIST &list, int &k, int &n)
{
    int ch;
    if((!isFull(list) && (0 <= k && k <= n))) 
    {
        
        for(int i=n;i>k;i--)
        {
            list.sv[i] = list.sv[i-1];              
        }                                          
        printf("Nhap MSSV: ");
        scanf("%d",&list.sv[k].MSSV);
        printf("Nhap diem Toan: ");
        scanf("%f",&list.sv[k].diemToan);
        printf("Nhap diem Ly: ");
        scanf("%f",&list.sv[k].diemLy);
        printf("Nhap diem Hoa: ");
        scanf("%f",&list.sv[k].diemHoa);
        printf("Nhap ho sinh vien: ");
        while((ch = getchar() != '\n')); 
        gets_s(list.sv[k].firstName);
        printf("Nhap ten sinh vien: ");
        gets_s(list.sv[k].lastName);
        n++;
    }
}


void xoaThongTinSVcoDiemHoaNhoHon6(CLIST &list, int &n)
{
    //if(!isEmpty(list))
    {
        for (int i=0;i<n;i++)
        {
            if(list.sv[i].diemHoa < 6)
            {
                for(int j=i;j<n;j++)
                {
                    list.sv[j] = list.sv[j+1];  
                }
                n--;
            }  
        }   
    }   
}


void timThongTinSinhVienTheoTen(FILE *f, char* fname, CLIST &list, int &n)
{
    f = fopen(fname,"w");
    char tenSV[20];
    printf("Nhap ten sv can tim: ");
    gets_s(tenSV);
    for(int i=0;i<n;i++)
    {
        if(strcmp(tenSV,list.sv[i].lastName) == 0)
        {
            fprintf(f,"%d    ",list.sv[i].MSSV);
            fprintf(f,"%.2f    ",list.sv[i].diemToan);
            fprintf(f,"%.2f    ",list.sv[i].diemLy);
            fprintf(f,"%.2f    ",list.sv[i].diemHoa);
            fprintf(f,"%.2f    ",list.sv[i].diemTB);
            fprintf(f,"%s    ",list.sv[i].firstName);
            fprintf(f,"%s    ",list.sv[i].lastName);
            fprintf(f,"\n");
            
            printf_s("%d    ",list.sv[i].MSSV);
            printf_s("%.2f    ",list.sv[i].diemToan);
            printf_s("%.2f    ",list.sv[i].diemLy);
            printf_s("%.2f    ",list.sv[i].diemHoa);
            printf("%.2f    ",list.sv[i].diemTB);
            printf_s("%s    ",list.sv[i].firstName);
            printf_s("%s    ",list.sv[i].lastName);
            printf_s("\n");
        }    
    }  
    fclose(f); 
}


int main()
{
    CLIST list;
    FILE* f=NULL;
    khoiTaoDanhSach(list);
    int n = 10;
    int k,x;
    // f=fopen("input.txt","w");
	// input(n,list);
	// write(f, n,list);
	// fclose(f);
    read(f,"input.txt",n,list);
    //tinhDiemTB(list,n);
    //timThongTinSvCoDiemToanNhoHon8(list,n);
    // printf("So luong sinh vien co DTB > 7 la: ");
    // printf("%d",demSvCoDiemTBlonHon7(list,n));
    // printf("\n");
    //xuatThongTinSvCoDiemLyCaoNhat(list,n);
    nhapViTriCanThem(k);
    themThongTinSV(list,k,n);
    output(list,n);
    // xoaThongTinSVtheoMSSV(list,n,x);
    // output(list,n);
    //output(list,n);
    //printf("\n");
    // xoaThongTinSVcoDiemHoaNhoHon6(list,n);
    //output(list,n);
    //timThongTinSinhVienTheoTen(f,"sinhvien.txt",list,n);
    
}