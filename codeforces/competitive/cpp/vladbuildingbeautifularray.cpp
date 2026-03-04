#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;cin>>n;
    vector<int> arr(n); int ce=0,co=0; int min;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2==0){
            ce++;
        }else{
            co++;
        }
    }
    min=arr[0];
    for(int i=0;i<n;i++){
                if(arr[i]<min){
            min=arr[i];
        }
    }
    // cout<<co<<" "<<ce<<endl;
    if(ce==0 || co==0){
        cout<<"YES"<<endl;
    } else if(min%2==1){
        cout<<"YES"<<endl;
    } 
    else cout<<"NO"<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}