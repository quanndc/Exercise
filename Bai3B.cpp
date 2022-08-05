#include <stdio.h>
#include <stdlib.h>


//CÂU 3A
void inputLowerAndUpper (int &lower, int &upper)
{
    printf("input lower: ");
    scanf("%d", &lower);
    printf("input upper: ");
    scanf("%d", &upper);
}

int inDayCacChuSo(int lower, int upper)
{
    if(lower > upper)
    {
        return 0;
    }
    if(lower <= upper)
    {
        printf("%d ", lower);
    }
    inDayCacChuSo(lower+1,upper);
}


int main()
{
    int lower, upper;
    inputLowerAndUpper (lower,upper);
    inDayCacChuSo(lower,upper);
    
}