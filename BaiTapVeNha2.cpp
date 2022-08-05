#include <stdio.h>
#include <ctype.h>
#include <string.h>

int demSoTu(char *c)
{
    int count = 0;
    for(int i=0;i<=strlen(c);i++)
    {
        if(*(c+i) == ' ')
        {
            count++;
        }
    }
    return count+1;
}

int main()
{
    char arr[] = "Tran Minh Quan";
    printf("So tu trong chuoi la: %d",demSoTu(arr));
}