#include<iostream>
#include "plib.h"
using namespace std;
using namespace mylib;

int main(){
    int arr[]={42, 17, 8, 91, 64, 23, 55, 37, 19, 78, 3, 92, 46, 29, 11, 67, 84, 5, 73, 50};
    // cout << arrSize(arr);
    // arrOut(arr);
    int x=sizeof(arr)/sizeof(int);
    cout << x << endl;
     cout << arrMax(arr,x) << endl;
     cout << arrMin(arr,x) << endl;
     arrSort(arr,x);
     arrOut(arr,x);cout<< endl;

}