#include<iostream>
#include<cmath>
using namespace std;
void solve(){
    long long int n;
    long long int k;
    cin>> n >> k;
    int diag=0;
    if(k%2==0 && (4*n-2)!=k){
        diag=k/2;
    } else{
    diag=k/2+1; 
    }
    cout << diag << endl;
}
int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}