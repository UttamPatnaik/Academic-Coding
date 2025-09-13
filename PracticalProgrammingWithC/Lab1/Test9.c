//Write a program to find the grade of the student
#include <stdio.h>
int main(){
    float s1,s2,s3,s4,s5,total,per;
    scanf("%f%f%f%f%f",&s1,&s2,&s3,&s4,&s5);
    total=s1+s2+s3+s4+s5;
    per=(total/500)*100;
    printf("Total Marks: %.2f \t", total);
    printf("Percentage: %.2f \t", per);
    if(per>90)
    {
        printf("Grade: O");
    }
    else if(per>80 && per<=90)
    {
        printf("Grade: A");
    }
    else if(per>70 && per<=80)
    {
        printf("Grade: B");
    }
    else if(per>60 && per<=70)
    {
        printf("Grade: C");
    }
    else if(per>50 && per<=60)
    {
        printf("Grade: D");
    }
    else
    {
        printf("Grade: F");
    }
    return 0;
}