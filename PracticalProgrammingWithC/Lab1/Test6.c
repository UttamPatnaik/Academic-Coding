//Write a program to check whether the input number is even/odd
#include <stdio.h>
int main(){
    int inp;
    printf("Enter a number: ");
    scanf("%d",&inp);
    if(inp % 2 ==0)
    {
        printf("It is an even number");
    }
    else
    {
        printf("It is an odd number");
    }
    return 0;
}