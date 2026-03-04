#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<long long> v(n);
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int q;
    cin >> q;
    int t0t = 0;
    for(int i = 0 ; i < q; i++){
        long long x;
        cin >> x;
        int cnt = upper_bound(v.begin(),v.end(),x) - v.begin();
        cout << cnt << endl;
    }
}
int main(){
int t = 1;

while(t--)solve();
return 0;
}