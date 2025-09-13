//Write a program to convert distance in miles to kilometres
#include <stdio.h>
#define KMS_To_Miles 1.609
int main(){
    double kms,miles;
    printf("Enter the distance in miles:");
    scanf("%lf",&miles);
    kms=KMS_To_Miles *miles;
    printf("The distance in km is %.2f", kms);
    return 0;
}