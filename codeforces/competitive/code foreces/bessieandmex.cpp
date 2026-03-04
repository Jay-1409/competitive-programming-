#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t; cin>>t;
while(t--){
        int n; cin>>n;
        ll e = 0;
        ll p[n];
        ll mex = n;
        int arr[n]; for(int i=0;i<n;i++){cin>>arr[i];};
        for(long long int i = n-1;i >= 0;i--){
            if(arr[i] > 0){
                p[i] = (mex-arr[i]);
                mex=p[i];
            }
            else{
                p[i]=(mex+abs(arr[i]));
            }
        }
        for(int i=0;i<n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
}