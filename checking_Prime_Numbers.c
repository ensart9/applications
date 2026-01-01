//A function to check if a number from the user is prime.
#include <stdio.h>

void isPrimeNumber(int x)
{
    int prime=1;

    if(x<2){
        prime=0;
    }
    else{
        for(int i=2;i*i<x;i++)
        {
            if(x%i==0)
            {
                prime=0;
                break;
            }
        }
    }

    if(prime==1){
     printf("%d is a prime number.",x);
    }
    else{
     printf("%d is not a prime number.",x);
    }
}

int main()
{
    int n;
    printf("Please enter a number:");
    scanf("%d",&n);

    isPrimeNumber(n);
    return 0;
}
