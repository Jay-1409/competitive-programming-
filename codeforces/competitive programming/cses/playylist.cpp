#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++)
    {cin >> v[i];}
    set<int> st(v.begin(),v.end());

    cout << st.size() << endl;
    // int cnt = 0;
    // int maxcnt = 0;
    // for(int i = 1; i < n; i++){
    //     if(v[i] == v[i - 1]){
    //         cnt = 0;
    //     }else{
    //         map<int,bool> mp;
    //         i--;
    //         while(i < n){
    //             if(!mp[v[i]]){
    //                 cnt++;
    //                 mp[v[i]] = true;
    //                 i++;
    //             }else break;
    //         }
    //         maxcnt = max(maxcnt,cnt);
    //         cnt = 0;
    //     }
    // }
    // cout << max(maxcnt,1) << endl;

}
int main(){
int t = 1;
while(t--)solve();
return 0;
}