#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= k;j++){
            if(j - a[i] >=0){
                dp[j] += dp[j - a[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[k] << endl;
}