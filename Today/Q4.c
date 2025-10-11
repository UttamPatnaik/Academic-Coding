#include <stdio.h>

int main() {
    char name[5][50];
    int i;

    
    printf("Enter 5 names:\n");
    for(i = 0; i < 5; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", name[i]);
    }
    printf("\nThe names are:\n");
    for(i = 0; i < 5; i++) {
        printf("Name %d: %s\n", i + 1, name[i]);
    }

    return 0;
}