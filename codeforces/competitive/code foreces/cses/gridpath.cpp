#include<bits/stdc++.h>
using namespace std;
char arr[1000][1000];
int dp[1000][1000];
const long long mod = 1e9 + 7;
int cnt = 0;
int level(int a,int b,int n,int step){
    if(a>=n || b >=n || arr[a][b] == '*'){
        return 0;
    }
    if(a == n-1 && b == n-1){
        return 1;
    }
    if(dp[a][b] != -1){
        return dp[a][b];
    }
    dp[a][b] = 0;
    if(a + 1 < n){
        dp[a][b] += level(a+1,b,n,step+1);
        dp[a][b] %= mod;
    }
    if(b + 1 < n){
        dp[a][b] += level(a,b+1,n,step+1);
        dp[a][b] %= mod;
    }
    return dp[a][b];
}
int main(){
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    cout << level(0,0,n,0) << endl;
}