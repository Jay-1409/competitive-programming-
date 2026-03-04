#include<iostream>
using namespace std;
int main(){
    int a=0;
    cout << a++;//b=a++, after printing b will become 1 but a at the original location remains 0
    cout << ++a;//b=++a, after printing b will be 1 and also a will be changed at its original location to 1
}
