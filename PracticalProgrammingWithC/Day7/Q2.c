#include <stdio.h>
int main()
{
    char c='G';
    for(int i=7;i>=1;i--)
    {
        for(int d=0;d<i;d++)
        {
            printf("%c",c-d);
        }
        c--;
        printf("\n");
    }
}