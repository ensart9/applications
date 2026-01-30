#include <stdio.h>
#include <stdlib.h>

// Bubble Sort Implementation
void bubbleSort(int* arr, int n)
{
    // n = number of array elements
    for (int i = 0; i < n - 1; i++) { //the last element doesn't need to be compared to itself.(i<n-1)
        int swap = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }

        if (swap == 0) break;
    }
}

void getArrayValues(int* arr, int n)
{
    char enter[100];
    int value;
    char extra;

    for (int i = 0; i < n; i++)
    {
        while (1) {

            printf("Element %d: ", i + 1);

            fgets(enter, 100, stdin);

            if (sscanf(enter, "%d %c", &value, &extra) == 1) {
                arr[i] = value;
                break;
            }
            else {
                printf("Invalid input! Please enter a valid value.\n");
            }
        }
    }
}

int main()
{
    // define the array
    int n;
    while (1) {
        printf("Enter the size of array:");

        if (scanf("%d", &n) == 1 && n > 0) {
            break;
        }
        else {
            printf("Invalid input! Please enter a positive number.\n");

            // input buffer
            while (getchar() != '\n');
        }
    }

    while (getchar() != '\n');

    int* array = (int*)(malloc(n * sizeof(int)));
    // NULL control
    if (array == NULL) {
        printf("Memory Allocation failed\n");
        return 1;       
    }

    // call the function to get values
    getArrayValues(array, n);

    // call the sorting function
    bubbleSort(array, n);

    // free the memory
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    free(array);
}