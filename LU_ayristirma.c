#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int i,j,k,l,m,n,size;
    double l1,lxu;
    double A[100][100] = {0}, L[100][100] = {0};
    printf("Matrisin boyutunu giriniz mxm: ");
    fflush(stdout);
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("%d. satiri girin\n", i + 1);
        fflush(stdout);
        for (j = 0; j < size; j++) scanf("%lf", &A[i][j]);
    }
    printf("A matrix:\n");
    for (i = 0; i < size; i++)
    {
        for (j =0; j < size; j++) printf("%12lf", A[i][j]);
        printf("\n");
    }
    for (i = 0; i < size - 1; i++)
    {
        L[i][i] = 1;
                  for (k = i + 1; k < size; k++)
        {
            if (A[i][i] == 0)
            {
                printf("LU ayrisimi gerceklestirilemiyor!\n");
                getch();
                return EXIT_FAILURE;
            }
            l1 = -A[k][i]/A[i][i];
            for (l = 0; l < size; l++)  A[k][l] = l1*A[i][l] + A[k][l];
            L[k][i] = -l1;
        }
    }
    L[size - 1][size - 1] = 1;
    printf("U matrix:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++) printf("%12lf", A[i][j]);
        printf("\n");
    }
    printf("L matrix:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++) printf("%12lf", L[i][j]);
        printf("\n");
    }
    printf("L*U=A\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            lxu = 0;
            for( k = 0; k < size; k++) lxu += (L[i][k]*A[k][j]);
            printf("%12lf", lxu);
        }
        printf("\n");
    }
    getch();
    return EXIT_SUCCESS;
}

