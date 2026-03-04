#include<iostream>
using namespace std;
int main(){
    int a=10;
    int *ptr=&a;
    // cout  << ptr;
    // cout << *ptr;\

    //PRINTING ARRAY WITH POINTER~~!!
    // int arr[]={1,2,3,4};
    // int *aptr=arr;
    // for(int i=0;i<4;i++){
    //     cout << *aptr << endl;
    //     aptr++;
    // }

    //POINTER TO POINTER 
    int n=10;
    int *p=&n;
    int **q=&p;
    cout << *q << endl;// reffered only once so it prints the address
    cout << **q << endl;// reffered twice so it prints the value
    



}