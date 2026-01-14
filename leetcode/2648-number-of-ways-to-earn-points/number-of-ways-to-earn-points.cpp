class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const long long MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(51, vector<vector<int>> (1001, vector<int>(51, -1)));
        auto dfs = [&](int pos, int score, int Q, auto &&self) -> int {
            if(score == target) {
                return 1;
            }
            if(score > target)
                return 0;
            if(pos >= types.size()) {
                return 0;
            }
            if(dp[pos][score][Q] != -1) 
                return dp[pos][score][Q];
            int skip = self(pos + 1, score, 0, self);
            int take = (Q < types[pos][0] ? (self(pos, score + types[pos][1], Q + 1, self)) : 0);
            return dp[pos][score][Q] = (skip + take) % MOD;
        };
        return dfs(0, 0, 0, dfs);
    }
};