/*A function that takes two matrices from the user, retrieves the number of rows and columns of each matrix and their values,
 and displays their sum.
*/
#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int r, int c)
{
    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }
    return matrix;
}

void getMatrix(int** matrix, int r, int c)
{
    for (int i = 0; i < r; i++)    // r=row, c=column
    {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
}

int** sumMatrix(int** matrix1, int** matrix2, int r, int c)
{
    int** sum = createMatrix(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return sum;
}

void freeMatrix(int** matrix, int r)
{
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int r, c;
    int** matrix1, ** matrix2;
    printf("Please enter your row and column numbers:");
    scanf("%d%d", &r, &c);

    if (r <= 0 || c <= 0) {
        printf("Invalid size!\n");
        return 1;
    }

    matrix1 = createMatrix(r, c);
    matrix2 = createMatrix(r, c);

    printf("Enter the values for your first matrix\n");
    getMatrix(matrix1, r, c);

    printf("Enter the values for your second matrix\n");
    getMatrix(matrix2, r, c);

    int** resultMatrix = sumMatrix(matrix1, matrix2, r, c);
    printf("Result Matrix\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }
    // Free the memory
    freeMatrix(matrix1, r);
    freeMatrix(matrix2, r);
    freeMatrix(resultMatrix, r);
}