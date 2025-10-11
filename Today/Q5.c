#include <stdio.h>

int main() {
    char names[5][50];
    int i, j, length;
    printf("Enter 5 names:\n");
    for(i = 0; i < 5; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", names[i]);
    }
    printf("\nThe names and their lengths are:\n");
    for(i = 0; i < 5; i++) {
        length = 0;
        for(j = 0; names[i][j] != '\0'; j++) {
            length++;
        }
        printf("Name %d: %s, Length: %d\n", i + 1, names[i], length);
    }
    return 0;
}