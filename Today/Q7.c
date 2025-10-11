#include <stdio.h>

int main() {
    char names[5][50], search[50];
    int i, j, found = 0;
    printf("Enter 5 names:\n");
    for(i = 0; i < 5; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", names[i]);
    }
    printf("\nEnter name to search: ");
    scanf("%s", search);
    for(i = 0; i < 5; i++) {
        int match = 1;
        for(j = 0; names[i][j] != '\0' || search[j] != '\0'; j++) {
            if(names[i][j] != search[j]) {
                match = 0;
                break;
            }
        }
        if(match && names[i][j] == '\0' && search[j] == '\0') {
            found = 1;
            break;
        }
    }
    if(found) {
        printf("\n%s was found in the list.\n", search);
    } else {
        printf("\n%s was not found in the list.\n", search);
    }
    return 0;
}