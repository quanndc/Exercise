#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapMaTran(int A[][20], int &N, int &M)
{
	printf("Nhap mang: \n");
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++){
			printf("A[%d][%d]:",i,j);
			scanf_s("%d",&A[i][j]);
		}
		
	}
}

void xuatMaTran(int A[][20], int &N, int &M)
{
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
			printf("%4d ", A[i][j]);
			printf("\n");
	}
}

int tinhTongMotDong(int A[][20], int&N, int&M, int k)
{
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        if(k==i)
        {
            for(int j=0;j<M;j++)
            {
                sum = sum + A[k][j];
            }
        }
    }
    return sum; 
}

int main()
{
    int A[20][20],N,M;
    int k;
    printf("Input Row: ");
	scanf_s("%d", &N);
	printf("Input Col: ");
	scanf_s("%d", &M);
    nhapMaTran(A,N,M);
    xuatMaTran(A,N,M);
    printf("Nhap dong muon tinh tong: ");
    scanf_s("%d", &k);
    printf("%d",tinhTongMotDong(A,N,M,k));

    return 0;
}