#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ;i++) cin >> v[i];
    if(false){
        cout << max(v[0],v[1]) - min(v[0],v[1]) << endl;
    }else{
        int sus = v[n-2];
        for(int i = 0; i < n - 2;i++){
            sus -= v[i];
        }
        cout << v.back() - sus << endl;
    }
    return;
}
#undef int
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}