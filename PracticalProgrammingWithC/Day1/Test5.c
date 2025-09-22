//Write a program to calculate total and percentage of the marks of a student. Marks are given for 5 subjects
#include <stdio.h>
int main(){
    float s1,s2,s3,s4,s5,total,per;
    scanf("%f%f%f%f%f",&s1,&s2,&s3,&s4,&s5);
    total=s1+s2+s3+s4+s5;
    per=(total/500)*100;
    printf("Total Marks: %.2f \t", total);
    printf("Percentage: %.2f", per);
    return 0;
}
