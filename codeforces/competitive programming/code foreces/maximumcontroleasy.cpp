#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<int> mp(n+1,0);
    for(int i = 0 ;i < n - 1 ; i ++){
        int x,y;
        cin >> x >> y;
        mp[y]++;
        mp[x]++;
    }
    int cnt = 0 ;
    // mp[1] -- ;
    // mp[n] --;
    for(int i = 0;i < n;i++){
        // cout << i + 1 << mp[i+1] << endl;
        if(mp[i + 1] == 1)cnt++;
    }
    cout << cnt ;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}