#include <stdio.h>

int main() {
    int ch;
    printf("In which range does the Richter scale number fall?\n"
           "1. < 5.0\n"
           "2. >= 5.0 and < 5.5\n"
           "3. >= 5.5 and < 6.5\n"
           "4. >= 6.5 and < 7.5\n"
           "5. >= 7.5: ");

    scanf("%d", &ch);

    switch (ch) {
        case 1:
            printf("It indicates: Little or no damage\n");
            break;
        case 2:
            printf("It indicates: Some damage\n");
            break;
        case 3:
            printf("It indicates: Serious Damage, walls may crack or fall\n");
            break;
        case 4:
            printf("It indicates: Disastrous effect, Houses and Buildings may collapse\n");
            break;
        case 5:
            printf("It indicates: Catastrophic effect, Most Buildings Destroyed\n");
            break;
        default:
            printf("Invalid Input\n");
    }

    return 0;
}
/*Floating-point (double) issue:
The switch statement in C only accepts integral types like int or char as its controlling expression. Since the Richter scale number is a double (floating-point), it cannot be used directly in a switch.

Range comparison limitation:
switch works by matching exact constant values (case labels). It cannot compare ranges or inequalities (like < 5.0 or >= 5.0 and < 5.5), which are necessary for categorizing the Richter scale number based on intervals.*/
