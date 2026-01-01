#include <stdio.h>
#include <stdlib.h>

void getMatrices(int **arr,int r,int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            printf("matrix[%d][%d]:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void multiplyMatrices(int **arr1,int **arr2,int **result,int r1,int c1,int r2,int c2) 
{
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++){
            result[i][j]=0;
        }
    }

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            for(int k=0;k<c1;k++){
                result[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
}

void displayingResult(int **result,int r,int c)
{
     for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            printf("%d  ",result[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int r1, c1, r2, c2;
    printf("Enter rows and column for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and column for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    while (c1 != r2) {
        printf("Error! Enter rows and columns again.\n");
        printf("Enter rows and columns for the first matrix: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and columns for the second matrix: ");
        scanf("%d%d", &r2, &c2);
    }

    // matrix1
    int **matris1=(int**)malloc(r1*sizeof(int*));

    for(int i=0;i<r1;i++){
        matris1[i]=(int*)malloc(c1*sizeof(int));
    }
    // matrix2
    int **matris2=(int**)malloc(r2*sizeof(int*));

    for(int i=0;i<r2;i++){
        matris2[i]=(int*)malloc(c2*sizeof(int));
    }

    // result
    int **result=(int**)malloc(r1*sizeof(int*));

    for(int i=0;i<r1;i++){
        result[i]=(int*)malloc(c2*sizeof(int));
    }

    // calling first and second matrices
    printf("First matrix\n");
    getMatrices(matris1,r1,c1);

    printf("Second matrix\n");
    getMatrices(matris2, r2, c2);

    // multiply matrices
    multiplyMatrices(matris1, matris2, result, r1, c1, r2, c2);

    // display matrices
    displayingResult(result, r1, c2);

    return 0;
}
