#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
        vector<int> v;
    while(n--){
        cin >> s;
        int cnt=0;
        for(auto i:s){
            cnt++;
            if(i == '#'){
                v.push_back(cnt);
            }
        }
    }
    reverse(v.begin(),v.end());
    for(auto i : v){
        cout << i << " " ;
    }cout << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}