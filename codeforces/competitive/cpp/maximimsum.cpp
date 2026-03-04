#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
void solve() {
    int n,k; cin>>n>>k;
    long long int tn=1000000007;
    vector<int> arr(n); int ans=0; int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    int st=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            st=i;break;
        }
    }
    if(st==-1){
        ans=sum;
    }else if(st==0){
        int tsum=sum;
        for(int i=1;i<=k+1;i++){
            ans+=tsum;
            tsum=ans;    
        }
    } else{
        int tsum=0;
        for(int i=st;i<arr.size();i++){
            tsum+=arr[i];
        }
            for(int i=1;i<=k+1;i++){
            ans+=tsum;
            tsum=ans;    
        }
    }
    cout<<ans<<endl;
    // if(ans%tn<0){
    //     cout<<tn+(ans%tn)<<endl;
    // }else{
    //     cout<<ans%tn<<endl;
    // }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}