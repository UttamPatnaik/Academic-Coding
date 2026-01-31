#include <stdio.h>

int main()
{
    int mul[3][3];
    int ar1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int ar2[3][3] = {{1, 4, 3}, {5, 9, 8}, {2, 6, 7}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                mul[i][j] += ar1[i][k] * ar2[k][j];
            }
        }
    }

    printf("Multiplication of both matrices: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}
