#include <stdio.h>
#include <stdlib.h>

void revArray(int *n, int size)
{
    for(int i=0;i<size/2;i++)
    {
        int tmp = n[i];
        n[i] = n[size-i-1];
        n[size-i-1] = tmp;

    }
}

void xuatMang(int *n, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ", *(n+i));
    }
}

int main()
{
    int a[9] ={1,2,3,4,5,6,7,8,9};
    
    printf("Mang truoc khi dao nguoc: ");
    xuatMang(a,9);
    printf("\n");
    printf("Mang sau khi dao nguoc: ");
    revArray(a,9);
    xuatMang(a,9);
}