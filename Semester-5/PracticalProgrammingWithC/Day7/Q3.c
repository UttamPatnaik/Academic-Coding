#include <stdio.h>
int main()
{
    char c='A';
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7-i;j++)
        {
            printf("%c",c+j);
        }
        for(int k = 0; k<i*2-1;k++){
            printf(" ");
        }

        if(i==0){
        for(int k=7-i-2;k>=0;k--)
        {
            printf("%c",c+k);
        }}

      else{
        for(int k=7-i-1;k>=0;k--)
        {
            printf("%c",c+k);
        }}




        printf("\n");

    }
}
