#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> mp;
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ans = 1;
    for(int i = 0 ; i < n; i++){
        if(ans < v[i]){
            cout << ans << endl;
            return;
        }

        ans += v[i];
    }
    cout << ans << endl;    
}
#undef int
int main(){
int t = 1;

while(t--)solve();
return 0;
}