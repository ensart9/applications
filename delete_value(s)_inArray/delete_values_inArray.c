#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 100

// print the array
void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// delete the array elements
int* deleteElement(int* arr, int* n, int value)
{
	// Stores the index of the value if found (-1 means value was not found)
	int isFound = -1;

	// Search for the value in the array entered by the user
	for (int i = 0; i < *n; i++)
	{
		if (arr[i] == value) {
			isFound = i;
			break;
		}
	}

	// If the value does not exist in the array
	if (isFound == -1) {
		printf("%d was not found\n", value);
		return arr;
	}

	// shift elements to the left
	for (int i = isFound; i < (*n) - 1; i++) {
		arr[i] = arr[i + 1];
	}

	(*n)--;

	// Resize the array
	int* temp =(int*)realloc(arr, (*n) * sizeof(int));
	if (temp == NULL && *n > 0) {
		printf("Reallocation failed\n");
		return arr;
	}

	return temp;
}


int main()
{
	// get size of array from user
	int n;

	while (1)
	{
		printf("How many numbers do you wanna generate:");

		if (scanf("%d", &n) == 1 && n > 0) {
			break;
		}
		else {
			printf("Please enter a valid positive number!\n");
		}

		// clear the input buffer 
		while (getchar() != '\n');
	}

	// define the array
	int* randomNumbers = (int*)malloc(n * sizeof(int));

	if (randomNumbers == NULL) {
		printf("Memory Allocation failed!\n");
		return 1;
	}

	// run the srand function number=(rand()%(max-min+1))+min
	srand((unsigned int)time(NULL)); // U can use in VS code like this: srand(time(NULL));

	for (int i = 0; i < n; i++) {
		randomNumbers[i] = rand() % (MAX - MIN + 1) + MIN;
	}

	// print the array of random numbers after creation
	printf("Original array\n");
	printArray(randomNumbers, n);

	printf("\nEnter values to delete (enter a letter to stop):\n");

	while (1)
	{
		int value;
		printf("Delete value: ");

		if (scanf("%d", &value) != 1) {
			break;
		}

		randomNumbers = deleteElement(randomNumbers, &n, value);
	}

	printf("Current Array\n");
	printArray(randomNumbers, n);

	free(randomNumbers);
}