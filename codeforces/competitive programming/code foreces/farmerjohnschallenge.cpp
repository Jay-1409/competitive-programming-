#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n,k; cin>>n>>k;
    int arr[n];
    int res=1;
    if(k==1||k==n){
    for(int i=1;i<=n;i++){
        arr[i]=res;
        // cout<<res<<" "<<i<<endl;
        if(i%k==0){
            res++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    }else{
        cout<<-1<<endl;
    }

}

int main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}