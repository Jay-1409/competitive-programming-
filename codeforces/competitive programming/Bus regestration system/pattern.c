#include<stdio.h>
#include<conio.h>
void pattern(char *n,int count);
void pattern_n(char *n,int count);
void main()
{
    int x;
    printf("enter a number: ");
    scanf("%d",&x);
    int z=x-1;
 
    char symbol[20]="*";
    pattern (symbol,z);
    printf("*");
}
void pattern(char *n,int count)

{

    if(count>0)
    {
        
        pattern_n(n,count);
        printf("%s\n",n);
        count--;
        pattern(n,count);
       
    }
 
}
void pattern_n(char *n,int count)
{
    if(count>0)
    {
        printf("%s",n);
        count--;
        pattern_n(n,count);
    }
}