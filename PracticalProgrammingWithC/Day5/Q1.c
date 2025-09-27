#include <stdio.h>

int main()
{
    int mark;
    int arr[5][3];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the marks of student %d:\n", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("For subject %d: ", j + 1);
            scanf("%d", &mark);
            arr[i][j] = mark;
        }
    }

    printf("\nTable Created is:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); // new line after each student
    }

    return 0;
}
