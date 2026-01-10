class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        auto dfs = [&](int p1, int p2, auto && self) -> int {
            if (p1 == n) {
                int sum = 0;
                for (int i = p2; i < m; i++) 
                    sum += s2[i];
                return sum;
            }
            if (p2 == m) {
                int sum = 0;
                for (int i = p1; i < n; i++) 
                    sum += s1[i];
                return sum;
            }
            if(dp[p1][p2] != -1) 
                return dp[p1][p2];
            int cost = INT_MAX;
            if(s1[p1] == s2[p2]) {
                cost = min(cost, self(p1 + 1, p2 + 1, self));
            } else {
                cost = min({cost, (int)(s1[p1]) + self(p1 + 1, p2, self), (int)(s2[p2]) + self(p1, p2 + 1, self)});
            }
            return dp[p1][p2] = cost;
        };
        return dfs(0, 0, dfs);
    }
};