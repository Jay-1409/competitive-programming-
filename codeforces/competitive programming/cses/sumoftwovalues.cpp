#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin >> n >> k;
    vector<pair<int, int>> v(n); 
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }    
    sort(v.begin(),v.end());
    int l = 0;
    int r =  n - 1;
    bool flg = true;
    while(l < r){
        if(v[l].first + v[r].first == k && l != r){
            cout << v[r].second + 1 << " " << v[l].second + 1 << endl;
            return;
        }else if(v[l].first + v[r].first < k){
            l++;
        }else{
            r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
#undef int
int main(){
int t = 1;
while(t--)solve();
return 0;
}