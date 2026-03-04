#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<n;j++){
            // cout<<i<<j<<endl;
            if(((i/2)+j)%2==0){
                // cout<<i<<endl;
                cout<<"##";
            }else{
                cout<<"..";
            }
        }cout<<endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}