#include <stdio.h>

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int ar1[3][3];
    int s = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ar1[i][j]=arr[j][i];
        }
    }
    printf("\nTranspose of Matrix is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ar1[i][j]);
        }
        printf("\n");
    }
}
