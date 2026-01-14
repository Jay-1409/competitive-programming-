class Solution {
public:
    int countDigitOne(int n) {
        int dp[11][11][2];
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        auto dfs = [&](auto&& self, int ind, int cnt, int tight) -> int {
            if(ind == s.size()) return cnt;               
            if(dp[ind][cnt][tight] != -1) return dp[ind][cnt][tight];
            int limit = tight ? s[ind] - '0' : 9;
            int ans = 0;
            for(int i = 0; i <= limit; i++) {
                int ncnt = (i == 1) ? cnt + 1 : cnt;
                int ntight = (tight && i == limit) ? 1 : 0;
                ans += self(self, ind + 1, ncnt, ntight); 
            }
            return dp[ind][cnt][tight] = ans;
        };
        return dfs(dfs, 0, 0, 1);
    }
};
