#include<stdio.h>
void Route(int a,int b);
int main(){
    printf("WELCOME \n");
    printf("BUS MANAGEMENT SYSTEM \n");
    printf("SELECT YOUR LOCATION: \n");
        printf("1) RAJKOT \n");
        printf("2) MITHAPUR \n");
        printf("3) AHEMDABAD \n");
        printf("4) JAMNAGAR \n");
        printf("5) SURAT \n");
        printf("6) JUNAGADH \n");
        int a;
        scanf("%d",&a);
    printf("SELECT YOUR DESTINATION: \n");
        printf("1) RAJKOT \n");
        printf("2) MITHAPUR \n");
        printf("3) AHEMDABAD \n");
        printf("4) JAMNAGAR \n");
        printf("5) SURAT \n");
        printf("6) JUNAGADH \n");
        int b;
        scanf("%d",&b);
        route(a,b);
}
void route(int a, int b){
    void slot();

    if(a==3&&b==4){
        printf("AHD-JNG \n");
        slot();
        }
    if(a==3&&b==1){
        printf("AHD-RAJ \n");
        slot();
        }

}
void slot(){
    printf("Choose the timming for your bus \n");
    printf("1) 9:00\n2)11:00\n3)16:00\n4)19:00");
    int c;
    scanf("%d",&c);
    switch (c)
    {
    case 1:
     printf("booked 9:00");
    break;
    case 2:
    printf("booked 11:00");
    break;
    case 3:
    printf("booked 16:00");
    break;
    case 4:
    printf("booked 19:00");
    break;
    default: printf("please enter a valid slot time!!");
    break;
    }

}

