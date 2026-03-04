#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int x,k;
    cin>>x>>k;
    if(x%2==0){
        if(k%2!=0){
            cout<<1<<endl;
            cout<<x<<endl;return;
        }
    } else {
        if(k%2==0){
            cout<<1<<endl;
            cout<<x<<endl;return;
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i%k!=0 && j%k!=0){
                if(i+j==x){
                    cout<<2<<endl;
                    cout<<i<<" "<<j<<endl;return;
                }
            }
        }
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