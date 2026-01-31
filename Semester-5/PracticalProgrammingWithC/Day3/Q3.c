#include <stdio.h>
int main() {
    int n,s=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    int a=n;
    printf("The digits in the number, starting from the rightmost one is: ");
    while(a>0)
    {
        int d=a%10;
        printf("%d \t",d);
        s=s+d;
        a=a/10;
    }
    if(s%9==0)
    {
        printf("The number is divisble by 9");
    }
    else
    {
        printf("The number is not divisble by 9");
    }
    return 0;
}
