class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1,-1));
        auto dfs = [&](int p1, int p2, int p3, auto && self) -> bool {
            if(p3 == (int)s3.size()) {
                return (p1 == n && p2 == m);
            } 
            if(dp[p1][p2] != -1) {
                return dp[p1][p2];
            }
            if(p1 < n && p2 < m) {
                return dp[p1][p2] = (s1[p1] == s3[p3] ? self(p1 + 1, p2, p3 + 1, self) : false) || (s2[p2] == s3[p3] ? self(p1, p2 + 1, p3 + 1, self) : false);
            } else if(p1 < n) {
                return dp[p1][p2] = (s1[p1] == s3[p3] ? self(p1 + 1, p2, p3 + 1, self): false);
            } else if(p2 < m) {
                return dp[p1][p2] = (s2[p2] == s3[p3] ? self(p1, p2 + 1, p3 + 1, self): false);
            } else
                return dp[p1][p2] = false;
        };
        return dfs(0, 0, 0, dfs);
    }
};