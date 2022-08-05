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

int timSoLe(int lower, int upper)
{
    if(lower > upper)
    {
        return 0;
    }
    if(lower%2!=0)
    {
        printf("%d ", lower);
    }
    timSoLe(lower+1,upper);
}

int timSoChan(int lower, int upper)
{
    if(lower > upper)
    {
        return 0;
    }
    if(lower%2==0)
    {
        printf("%d ", lower);
    }
    timSoChan(lower+1,upper);
}


int main()
{
    int lower, upper;
    inputLowerAndUpper (lower,upper);
    timSoLe(lower,upper);
    printf("\n");
    timSoChan(lower,upper);
}