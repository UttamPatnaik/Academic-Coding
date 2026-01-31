#include <stdio.h>

int main()
{
    int mark;
    int arr[5][3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter the pixels of Row %d:\n", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("Column %d: ", j + 1);
            scanf("%d", &mark);
            arr[i][j] = mark;
        }
    }

    printf("\nPicture Created is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); // new line after each student
    }

    return 0;
}
