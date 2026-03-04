#include<iostream>
using namespace std;
long long int fact(int x){
    long long int fact=1;
    for(int i=1;i<=x;i++){
        fact=fact*i;
    }
    return fact;
}
int main(){
    int t;
    cin >> t;
    for(int test=0;test<t;test++){
    int k;
    cin >> k;
    long int max=0;
    int temp=0;
    for(int x=1;x<k;x++){
        long long int ans=fact(x)+fact(x-1);
        // cout << ans << endl;
        if(ans%k==0){
            if(ans>max){
                max=ans;
                temp=x;
            }
        }
    }
    cout << temp << endl;
    }


}