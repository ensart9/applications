#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h> // for using tolower() function 
#include <locale.h> // for using setlocale() function 

#define WORD_LEN 50 // maximum length of each word entered

int getArray(char ***arr)
{
    int wordCounter = 0; 
    char **temp = NULL; // a temporary variable for realloc

    while (1)
    {
        printf("Word %d (press 0 to stop): ", wordCounter + 1);

        // enlarge array
        temp = (char **)realloc(*arr, (wordCounter + 1) * sizeof(char *));
            // control
        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            return wordCounter;
        }
        *arr = temp;

        // allocate memory for each word
        (*arr)[wordCounter] = (char *)malloc(WORD_LEN * sizeof(char));
            // control
        if ((*arr)[wordCounter] == NULL)
        {
            printf("Memory allocation failed!\n");
            return wordCounter;
        }
        
        if (scanf("%s", (*arr)[wordCounter]) != 1)
        {
            free((*arr)[wordCounter]);
            break;
        }

        // quit control
        if ((*arr)[wordCounter][0] == '0' && (*arr)[wordCounter][1] == '\0')
        {
            free((*arr)[wordCounter]);
            break;
        }

        wordCounter++;
    }

    return wordCounter;
}

void toLowerString(char *word, char *copy)
{
    int i = 0;
    while (word[i] != '\0')
    {
        copy[i] = tolower((unsigned char)word[i]);
        i++;
    }
    copy[i] = '\0';
}


void sortingArray(char **arr, int n) // n=word count
{
    char *temp;
    int swapped;

    char lower1[WORD_LEN];
    char lower2[WORD_LEN];

    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            toLowerString(arr[j], lower1);
            toLowerString(arr[j + 1], lower2);

            if (strcoll(lower1,lower2) > 0) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

int main()
{
    setlocale(LC_ALL, "tr_TR.UTF-8"); // for turkish alphabetical order

    char **arr = NULL;

    // get words from user
    int m = getArray(&arr);

    if (m == 0)
    {
        printf("There is no word entered by user\n");
        return 0;
    }

    // calling sorting function
    sortingArray(arr, m);

    printf("\nAlphabetical Order (Turkish supported):\n");
    for (int i = 0; i < m; i++)
    {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }

    free(arr);
    return 0;
}