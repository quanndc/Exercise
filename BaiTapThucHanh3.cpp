#include <stdio.h>
#include <stdlib.h>

int tongMang(int *n)
{
    int sum = 0; 
    for(int i=0;i<9;i++)
    {
        sum+=*(n+i);
    }
    return sum;
}

int main()
{
    int a[9] ={1,2,3,4,5,6,7,8,9};
    
    printf("Tong cua mang la: %d",tongMang(a));
}