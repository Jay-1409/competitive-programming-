#include <stdio.h>
#include <math.h>
double squareRoot (double num);
int main()
{
double num;
double sqrt;

scanf("%le", &num);

sqrt = squareRoot (num);
printf("%f", sqrt);

return 0;
}

double squareRoot (double num)
{
double n= pow(num,0.5);
return n;
}