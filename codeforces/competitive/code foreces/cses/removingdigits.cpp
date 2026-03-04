#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> dp(n + 1,1e9);
    dp[0] = 0;
    for(int i = 1;i <= n; i++ ){
        int temp = i;
        while(temp){
            int dif = temp % 10;
            dp[i] = min(dp[i],1 + dp[i-dif]);
            temp/=10;
        }
    }
    cout << dp[n] << endl; 
}