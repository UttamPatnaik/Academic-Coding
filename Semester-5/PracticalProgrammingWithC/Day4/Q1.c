/* Write a program that calculates the user's body mass index using its height(inch) and weight(pounds) and categories it as underweight, normal, overweight, or obese.
formula for BMI=(703*wt)/ht */
#include <stdio.h>
int main(){
    double ht,wt,bmi;
    printf("Enter your weight in pounds: ");
    scanf("%lf",&wt);
    printf("Enter your height in inches: ");
    scanf("%lf",&ht);
    bmi=(703*wt)/(ht*ht);
    printf("Your BMI is:  %.2f \t",bmi);
    if(bmi<18.5)
    {
        printf("Your BMI shows that you are underweight.");
    }
    else if(bmi>=18.5 && bmi<=24.9)
    {
        printf("Your BMI shows that you are normal weight.");
    }
    else if(bmi>=25 && bmi<=29.9)
    {
        printf("Your BMI shows that you are overweight.");
    }
    else if(bmi>=30)
    {
       printf("Your BMI shows that you are obese.");
    }
    else
    {
        printf("Invalid Input");
    }
    return 0;
}
