#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
#include<set>
using namespace std;
int median(vector<int> v){
    sort(v.begin(),v.end());
    return v[ceil((v.size()-1)/2)];
}
void solve() {
    int n;cin>>n;
    vector<int> v;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int p=(n+1)/2-1;
    int res=count(v.begin()+p,v.end(),v[p]);
    cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}