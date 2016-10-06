#include <stdio.h>
#include <malloc.h>

void mul(int **mas1, int **mas2, int x1, int y1, int y2)
{
    int **mas3;
    int i,j,k;
    mas3=(int **)malloc(sizeof(int *)*y2);
    for(i=0; i<y2; i++)
        mas3[i] = (int*)malloc(sizeof(int)*x1);

    for(i=0; i < x1; i++)
        for(j=0; j < y2; j++)
            mas3[i][j]=0;

    for (i=0; i < x1; i++)
        for (j=0; j < y2; j++)
            for (k=0;k < y1; k++)
                mas3[i][j]+=mas1[i][k]*mas2[k][j];

    printf("Произведение матриц = \n\n\n");

    for(i=0; i < x1; i++)
    {
        for(j=0; j < y2; j++)
        {
            printf("%d ",mas3[i][j]);

        }
        printf("\n");
    }
    free(mas3);
}

int main()

{
    int i,j,x1,x2,y1,y2;
    int **mas1;
    int **mas2;
    printf("Количество строк матрицы A: ");
    scanf("%d",&x1);
    printf("Количество столбцов матрицы A: ");
    scanf("%d",&y1);
    printf("Количество строк матрицы B: ");
    scanf("%d",&x2);
    printf("Количество столбцов матрицы B: ");
    scanf("%d",&y2);

    if(y1 != x2)
    {
        printf("Не совпадают размерности\n");
        return -1;
    }
    mas1=(int **)malloc(sizeof(int*)*y1);
    for(i=0; i < x1; i++)
        mas1[i]=(int*)malloc(sizeof(int)*x1);

    for(i=0; i < x1; i++)
    {
        for(j=0; j < y1; j++)
        {
            printf("A[%d][%d]=", i+1, j+1);
            scanf("%d",&mas1[i][j]);
        }
    }
    mas2=(int **)malloc(sizeof(int*)*y2);
    for(i=0; i < x2; i++)
        mas2[i]=(int*)malloc(sizeof(int)*x2);

    for(i=0; i < x2; i++)
    {
        for(j=0; j <y2; j++)
        {
            printf("B[%d][%d]=", i+1, j+1);
            scanf("%d",&mas2[i][j]);
        }
    }

    mul(mas1, mas2, x1, y1, y2);

    free(mas1);
    free(mas2);
}