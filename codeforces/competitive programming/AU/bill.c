#include<stdio.h>
int main(){
    float a,b,c;
    printf("Input the price");
    scanf("%f",&a);
    printf("input the quantity");
    scanf("%f",&b);
    printf("input the discount percentage");
    scanf("%f",&c);
    float bill=a*b-((a*b)*c)/100;
    printf("%f",bill);

}