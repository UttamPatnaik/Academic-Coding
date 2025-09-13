//to swap 2 numbers using 3 variables
#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&a,&b);
    c=a+b;
    b=c-b;
    a=c-a;
    printf("Swapped numbers: 1st number: %d \t 2nd number: %d",a,b);
    return 0;
}