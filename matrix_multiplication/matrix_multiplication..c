#include <stdio.h>
#include <stdlib.h>

int** defineMatrix(int r, int c)
{
    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }
    return matrix;
}

// r=row,c=column
void getMatrices(int** arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            printf("matrix[%d][%d]:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void multiplyMatrices(int** arr1, int** arr2, int** result, int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void displayingResult(int** result, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            printf("%d  ", result[i][j]);
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

    while (c1 !=r2 || r1<=0 || r2<=0 || c1<=0 || c2<=0) 
    {
        printf("Error!\n");

        if (r1 <= 0 || r2 <= 0 || c1 <= 0 || c2 <= 0)
            printf("Rows and columns must be positive numbers\n");

        if(c1!=r2)
            printf("c1 must equal r2\n");

        printf("\nEnter rows and columns for the first matrix: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and columns for the second matrix: ");
        scanf("%d%d", &r2, &c2);
    }

    int** matrix1;
    matrix1 = defineMatrix(r1, c1);
    int** matrix2;
    matrix2 = defineMatrix(r2, c2);
    int** result;
    result = defineMatrix(r1, c2);


    // calling first and second matrices
    printf("First matrix\n");
    getMatrices(matrix1, r1, c1); printf("\n");

    printf("Second matrix\n");
    getMatrices(matrix2, r2, c2);

    // multiply matrices
    multiplyMatrices(matrix1, matrix2, result, r1, c1, r2, c2);

    // display matrices
    printf("\nResult Matrix\n");
    displayingResult(result, r1, c2);

    return 0;
}