#include <stdio.h>
#include <math.h>

float calculate(float m,char operator,float n)
{
    switch(operator)
    {
        case '+':  return m+n;
        case '-':  return m-n;
        case '*': return m*n;

        case '/':
            if(m==0 && n==0){
                printf("Indeterminate!");
            }
            else if(n==0){
                printf("Undefined!");
            }
        return m/n;
            
        case '^':
            if(m==0 && n==0)
            {
                printf("Undefined!");
                return 0;
            }
        return pow(m,n);
    } 
}


int main()
{
    float x,y;
    char operation;

    while(1){
        printf("Please enter your operation: ");

        if(scanf("%f %c %f",&x,&operation,&y)==3)
        {
                if(operation=='+' || operation=='-' || operation=='*' || operation=='/' || operation=='^'){
                    calculate(x,operation,y);
                    break;
            }
                else{
                printf("Invalid operation! Please try again.\n");
                }
        }

        else
        {
            printf("Invalid number input! Please enter again.\n");
            while(getchar()!='\n');
        }
    }

    float result=calculate(x,operation,y);
    printf("%.2f",result);

}

