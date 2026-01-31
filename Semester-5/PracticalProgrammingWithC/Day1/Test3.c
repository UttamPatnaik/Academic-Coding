//Write a program to find the area of circle
#include <stdio.h>
#define Area_Of_Circle 3.16
int main(){
    double radius,area;
    printf("Enter the distance in miles:");
    scanf("%lf",&radius);
    area=Area_Of_Circle*radius*radius;
    printf("The area of the circle is %.2f", area);
    return 0;
}
