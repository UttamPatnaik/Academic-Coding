//to swap 2 numbers using 2 variables
#include <stdio.h>
int main(){
    int a,b;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("Swapped numbers: 1st number: %d \t 2nd number: %d",a,b);
    return 0;
}