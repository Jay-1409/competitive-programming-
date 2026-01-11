class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        const long long mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        auto dfs = [&](int loc, int people, int prof, auto && self) -> int {
            if (people > n)
                return 0;
            if (loc == m)
                return (prof >= minProfit);
            if (dp[loc][people][prof] != -1)
                return  dp[loc][people][prof];
            long long ans = 0;
            ans = self(loc + 1, people, prof, self);
            int next_ppl = people + group[loc];
            int next_profit = min(minProfit, prof + profit[loc]);
            if (next_ppl <= n) {
                ans = (ans + self(loc + 1, next_ppl, next_profit, self)) % mod;
            }
            return dp[loc][people][prof] = ans;
        };
        return dfs(0, 0, 0, dfs);
    }
};