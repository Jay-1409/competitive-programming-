#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)cin>>i;
    long long sum =0,indx=0;
    for(int i=0;i<n;i++){
        indx+=i;
        sum+=v[i];
        if(sum<indx){
            cout<<"NO"<<endl;
            return;
        }
    } cout<<"YES"<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}