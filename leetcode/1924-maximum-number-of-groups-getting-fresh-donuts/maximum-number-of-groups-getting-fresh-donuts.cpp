class Solution {
public:
    int maxHappyGroups(int bz, vector<int>& groups) {
        vector<int> cnt(bz);
        int res = 0;
        for (auto group : groups) {
            if (group % bz == 0)
                ++res;
            else if (cnt[bz - group % bz]) {
                --cnt[bz - group % bz];
                ++res;
            }
            else 
                ++cnt[group % bz];
        }
        map<vector<int>, int> dp;
        auto dfs = [&](auto&& self, vector<int>& cnt, int left) -> int {
            if (auto it = dp.find(cnt); it != dp.end()) return it->second;
            int best = 0;
            for (int j = 1; j < bz; ++j) {
                if (--cnt[j] >= 0) {
                    best = max(best, ( (left ) % bz == 0 ? 1 : 0 ) + self(self, cnt, (left + j) % bz));
                }
                ++cnt[j]; 
            }
            return dp[cnt] = best;
        };
        return res + dfs(dfs, cnt, 0);
    }

};