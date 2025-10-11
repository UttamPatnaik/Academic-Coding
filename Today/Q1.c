#include <stdio.h>
int main()
{
    char c='A';
    for(int i=1;i<=7;i++)
    {
        for(int d=0;d<i;d++)
        {
            printf("%c",c+d);
        }
        printf("\n");
    }
}