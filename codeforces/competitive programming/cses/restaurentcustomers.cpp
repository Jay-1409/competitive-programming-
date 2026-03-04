#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    map<int,int> mp;
    while(n--){
        int x,y;
        cin >> x >> y;
        while(x <= y){
            mp[x]++;
            x++;
        }
    }
    int mx = 0;
    for(auto i : mp){
        mx = max(mx,i.second);
    }
    cout << mx << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}