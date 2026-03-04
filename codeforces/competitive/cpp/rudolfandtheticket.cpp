#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> b;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        b.push_back(x);
    }
    vector<int> c;
    for(int i=0;i<m;i++){
        cin>>x;
        c.push_back(x);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((b[i]+c[j])<=k){
                // cout<<b[i]<<" "<<c[i]<<endl;
                count++;
            }
        }
    }
    cout<<count<<endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}