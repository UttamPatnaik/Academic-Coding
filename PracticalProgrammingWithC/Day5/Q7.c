#include <stdio.h>

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int s = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            s = s + arr[i][j];
        }
    }

    printf("Sum of all the elements in the matrix: %d\n", s);
    return 0;
}
