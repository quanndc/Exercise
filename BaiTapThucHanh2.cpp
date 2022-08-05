#include <stdio.h>
#include <stdlib.h>

void xuatMang(int *n)
{
    for(int i=0;i<9;i++)
    {
        printf("%d ", *(n+i));
    }
}

int main()
{
    int a[9] ={1,2,4,5,2,7,8,3,5};
    
    xuatMang(a);
}