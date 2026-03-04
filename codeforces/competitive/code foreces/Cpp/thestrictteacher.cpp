#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> teach;
    while(m--){
        int x;
        cin >> x;
        teach.push_back(x);
    }
    sort(teach.begin(),teach.end());
    while(q--){
        int st;
        cin >> st;
        auto it_lower = lower_bound(teach.begin(), teach.end(), st);
        auto it_upper = upper_bound(teach.begin(), teach.end(), st);
        int b = (it_lower == teach.begin()) ? n : *(it_lower - 1);
        int f = (it_lower == teach.end()) ? 1 : *it_lower;
        int ans;
        if(st > f){
            ans = n - b;
        }else if(st < b){
            ans = f - 1;
        }else{
            int mid = (f + b) / 2;
            ans = min(abs(f - mid), abs(b - mid));
        }
        cout << ans << endl;
    }
}
#undef int
int main(){
int t;
cin >> t;
while(t--)solve();
return 0;
}