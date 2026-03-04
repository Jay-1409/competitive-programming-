#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> v;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int i=0;
    int k=1;
    int j=n-2;
    int l=n-1;
    cout<<abs(v[i]-v[j])+abs(v[j]-v[k])+abs(v[k]-v[l])+abs(v[l]-v[i])<<endl;
    
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}