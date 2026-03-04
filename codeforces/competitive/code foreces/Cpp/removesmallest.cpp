#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin >> n;
    vector<int> v(n);
    for(int i =0 ; i < n;i++){
        cin >> v[i];
    }
    int cnt = 0;
    sort(v.begin(),v.end());
    for(int i = 1 ;i < n ; i++){
        if(v[i] - v[i-1] <= 1){
            cnt++;
        }
    }
    if(cnt == n - 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl; 
    }
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}