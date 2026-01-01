// Function that finds the number of words in a sentence entered by the user.
#include <stdio.h>
#include <ctype.h> // to use ispunct() function

void wordCounter(char paragraph[])
{
    int i=0,count=0;
    int inWord=0;

    while (paragraph[i]!='\0')
    {
        // ispuntc() : checks for punctuation
        if(paragraph[i]!=' ' && paragraph[i]!='\n' && paragraph[i]!='\t' && !ispunct(paragraph[i]) && inWord==0)
        {
            count++;
            inWord=1;
        }

        else if(paragraph[i]==' ' || paragraph[i]=='\n' || paragraph[i]=='\t')
        {
            inWord=0;
        }
        i++;
    }

    if(count==1){
      printf("There is %d word in your sentence.",count);
    }
    else{
        printf("There are %d words in your sentence.",count);
    }
}


int main()
{
    char paragraph[1000];
    printf("Please enter a message:");
    fgets(paragraph,1000,stdin);

    wordCounter(paragraph);
}
