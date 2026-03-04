#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    vector<int> ans;
    int x;
    cin >> x;
    v.push_back(x);
    ans.push_back(max(abs(v[0] - 0),abs(v[0] - n)));
    for(int i = 1 ; i < k; i++){
        cin >> x;
        v.push_back(x);
        sort(v.begin(),v.end());
        int mx = v.front();
        for(int i = 1 ; i < v.size(); i++){
            mx = max(abs(v[i] - v[i - 1]),mx);
        }
        mx = max(n - v.back(), mx);
        ans.push_back(mx);
    }   
    for(auto i : ans){
        cout << i << " " ;
    }
    cout << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}