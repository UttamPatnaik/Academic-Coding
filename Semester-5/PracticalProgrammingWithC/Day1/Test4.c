//Write a program to print the area and perimeter of the rectangle
#include <stdio.h>
int main(){
    double length,breadth,area,perimeter;
    printf("Enter the length and breadth of the rectangle:");
    scanf("%lf%lf",&length,&breadth);
    area=length*breadth;
    perimeter=2*(length+breadth);
    printf("The area of the rectangle is %.2f \t", area);
    printf("The perimeter of the rectangle is %.2f", perimeter);
    return 0;
}
