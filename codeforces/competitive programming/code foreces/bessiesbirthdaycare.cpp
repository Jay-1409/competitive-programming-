#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n,x,y; cin>>n>>x>>y;
    int temp; for(int i=0;i<x;i++){
        cin>>temp;
        }
    int curr=x+y;
    if(x+y==2){
        cout<<2<<endl;return;
    }
    // cout<<x<<endl;cout<<y<<endl;
    cout<<(x+y)-2<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}