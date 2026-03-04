#include <stdio.h>

int main(){
    int b;
    int h;
    printf("Enter base (b):\n");
    scanf("%d", &b);
    printf("Enter height (h):\n");
    scanf("%d", &h);
    printf("Area of parallelogram with base %d and height %d is %d\n", b, h, b*h);

    return 0;
}