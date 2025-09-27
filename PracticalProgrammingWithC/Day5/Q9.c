#include <stdio.h>

int main()
{
    int sum[3][3];
    int ar1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int ar2[3][3] = {{1, 4, 3}, {5, 9, 8}, {2, 6, 7}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum[i][j]=ar1[i][j]+ar2[i][j];
        }
    }
    printf("Sum of both matrices: \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
