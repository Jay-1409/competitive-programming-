class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 6;
        dp[0][1] = 6;
        for(int i = 1; i < n; ++i) {
            dp[i][0] = ( (1LL * dp[i - 1][0] * 2) % MOD + (1LL * dp[i - 1][1] * 2) % MOD) % MOD;
            dp[i][1] = ( (1LL * dp[i - 1][0] * 2) % MOD + (1LL * dp[i - 1][1] * 3) % MOD ) % MOD;
        }
        return (dp[n - 1][0] + dp[n - 1][1]) % MOD;
    }
};