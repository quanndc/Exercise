#include <stdio.h>

int tinhHamMu(int x, int y)
{
    if(y==0)
    {
        return 1;
    }
    if(y>0)
    {
        return x*tinhHamMu(x,y-1);
    }
}

int main()
{
    printf("%d", tinhHamMu(2,4));
}