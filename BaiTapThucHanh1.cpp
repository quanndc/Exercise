#include <stdio.h>

void hoanVi(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 9;
    int b = 7;
    printf("a va b truoc khi hoan vi la: %d %d\n", a,b);
    hoanVi(&a,&b);
    printf("a va b sau khi hoan vi la: %d %d", a,b);
}