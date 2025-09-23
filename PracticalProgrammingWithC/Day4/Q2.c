#include <stdio.h>
int main() {
    char ch;
    printf("What is the color of the cylinder?\n"
           "O/o. Orange\n"
           "Y/y. Yellow\n"
           "B/b. Brown\n"
           "G/g. Green\n");

    scanf(" %c", &ch);  // Note the space before %c

    char ch_lower = tolower(ch);

    switch (ch_lower) {
        case 'y':
            printf("The cylinder contains Oxygen\n");
            break;
        case 'o':
            printf("The cylinder contains Carbon Monoxide\n");
            break;
        case 'b':
            printf("The cylinder contains Hydrogen\n");
            break;
        case 'g':
            printf("The cylinder contains Oxygen\n");
            break;
        default:
            printf("Invalid Input\n");
    }

    return 0;
}
/*We may avoid using switch statement because its possible that maybe the user meant black and he gave b, which actually means brown,
so using if else would be better*/
