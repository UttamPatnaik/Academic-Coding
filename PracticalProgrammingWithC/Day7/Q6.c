#include <stdio.h>

int main() {
    char names[5][50];
    int i, j;
    printf("Enter 5 names:\n");
    for(i = 0; i < 5; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", names[i]);
    }
    printf("\nThe names in uppercase are:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; names[i][j] != '\0'; j++) {
            if(names[i][j] >= 'a' && names[i][j] <= 'z') {
                names[i][j] = names[i][j] - 32;
            }
        }
        printf("Name %d: %s\n", i + 1, names[i]);
    }
    return 0;
}