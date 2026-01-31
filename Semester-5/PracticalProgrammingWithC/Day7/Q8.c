#include <stdio.h>

int main() {
    char names[5][50];
    int i, j, k, length, is_palindrome;
    printf("Enter 5 names:\n");
    for(i = 0; i < 5; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", names[i]);
        while(getchar() != '\n');
    }
    printf("\nPalindrome check for each name:\n");
    for(i = 0; i < 5; i++) {
        length = 0;
        for(j = 0; names[i][j] != '\0'; j++) {
            length++;
        }
        is_palindrome = 1;
        for(j = 0, k = length - 1; j < k; j++, k--) {
            if(names[i][j] != names[i][k]) {
                is_palindrome = 0;
                break;
            }
        }
        printf("Name %d: %s is ", i + 1, names[i]);
        if(is_palindrome) {
            printf("a palindrome\n");
        } else {
            printf("not a palindrome\n");
        }
    }
    return 0;
}