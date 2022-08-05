#include <stdio.h>

typedef struct SINHVIEN
{
    char maSo[10];
    char hoTen[30];
    float diem1,diem2,diem3,diemTB;
}sv;

sv sinhVien[100];

void nhapDanhSach(sv sinhVien[], int n)
{
    char ch;
    for(int i=0;i<n;i++)
    {
        while((ch = getchar()) != '\n')
        {
            printf("Nhap ma so sinh vien thu %d: ", i);
            gets_s(sinhVien[i].maSo);
            printf("Nhap ho ten sinh vien: %d ", i);
            gets_s(sinhVien[i].hoTen);
            printf("Nhap diem 1: ");
            scanf_s("%f",&sinhVien[i].diem1);
            printf("Nhap diem 2: ");
            scanf_s("%f",&sinhVien[i].diem2);
            printf("Nhap diem 3: ");
            scanf("%f",&sinhVien[i].diem3);

            sinhVien[i].diemTB =(float)(sinhVien[i].diem1 + sinhVien[i].diem2 + sinhVien[i].diem3)/3;
        }
    }
}

void xuatDS(sv sinhVien[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("sinh vien %d %s; %s; %.2f; %.2f; %.2f; %.2f\n",i,sinhVien[i].maSo,sinhVien[i].hoTen,sinhVien[i].diem1,sinhVien[i].diem2,sinhVien[i].diem3,sinhVien[i].diemTB);
    }
}
int main()
{
    int n = 3;
    nhapDanhSach(sinhVien,n);
    xuatDS(sinhVien,n);
}

