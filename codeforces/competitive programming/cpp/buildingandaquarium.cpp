#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int lo = 0;
    // int hi = max(x + 1,*max_element(v.begin(),v.end())+1);
    int hi = x + *max_element(v.begin(),v.end());
    int mid;
    int ans= 0;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        int water = 0;
        for(int i = 0 ; i < n; i++){
            if(mid - v[i] > 0){
                water += (mid - v[i]);
            }
        }
        // cout << water << endl;
        if(water > x){
            hi = mid - 1;
        }else{
            ans = max(mid,ans);
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}
#undef int
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}