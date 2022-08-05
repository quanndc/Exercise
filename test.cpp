#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "MinhQuan";
    char b[20];

    strcpy(b,a);

    printf("%s",a);
    printf("%s", b);

}