#include<iostream>
using namespace std;
int main(){
    int k2,k3,k5,k6;
    cin >>k2>>k3>>k5>>k6;
    int sum=0;
    while(k2&&k5&&k6){
        sum=sum+256;
        k2--;
        k5--;
        k6--;
    }
    while(k2&&k3){
        sum=sum+32;
        k2--;
        k3--;
    }
    cout << sum << endl;
    return 0;
}