/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
bool respond(int i, int j, vector<vector<char>> &arr, vector<vector<bool>> &vis) {
    int n = arr.size();
    int m = arr[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m) {
        return true;  // escape
    }
    if(dp[i][j] != -1)return dp[i][j];
    if (vis[i][j]) {
        return false;  
    }
    vis[i][j] = true;
    bool escape = false;
    if (arr[i][j] == '?') {
        escape = respond(i + 1, j, arr, vis) || respond(i, j + 1, arr, vis);
    } else if (arr[i][j] == 'U') {
        escape = respond(i - 1, j, arr, vis);
    } else if (arr[i][j] == 'D') {
        escape = respond(i + 1, j, arr, vis);
    } else if (arr[i][j] == 'L') {
        escape = respond(i, j - 1, arr, vis);
    } else if (arr[i][j] == 'R') {
        escape = respond(i, j + 1, arr, vis);
    }
    vis[i][j] = false;
    if(escape = false)dp[i][j] = false;
    else dp[i][j] = true;
    return escape;  
}

void solve(){
    int n , m;
    int cnt = 0;
    cin >> n >> m;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<char>> arr(n, vector<char>(m, 0));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j ++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j ++){
            if(!respond(i,j,arr,vis)){cnt++;}
        }
    }
    cout << cnt << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        solve();
    }
    return 0;
}