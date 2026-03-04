#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    vector<long long int> vp;
    vector<long long int> vn;
    int x; 
    if(n==2){
        vector<long long int> v;
        while(n--){cin>>x;v.push_back(x);}
        cout<<v[0]*v[1]<<endl;return;
    }
    while(n--){
        cin>>x;
        if(x<0)vn.push_back(abs(x));
        else vp.push_back(x);
    }
    long long int m1 = 0, m2 = 0;
    if (vn.size()>=2) {
        sort(vn.begin(), vn.end());
        m1 = vn[vn.size() - 1] * vn[vn.size() - 2];
    }
    if (!vp.empty()&&vp.size()>=1) {
        sort(vp.begin(), vp.end());
        if(vp.size()==1){
            m2=0;
        }else m2 = vp[vp.size() - 1] * vp[vp.size() - 2];
    }
    long long int ans=max(m1,m2);
    if(vp.size()==1){
        ans=ans;
    }
    cout<<ans<<endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}