#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int sum = 0;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> v[i];
    }
    for(int i = 0 ; i < n ; i ++){
        if(i & 1){
            sum -= v[i];
        }else{
            sum += v[i];
        }
    }
    cout << sum << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}