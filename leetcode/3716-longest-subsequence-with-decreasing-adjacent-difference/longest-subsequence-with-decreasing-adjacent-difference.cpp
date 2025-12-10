class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        static int f[301][301];
        static int suf[302][301];
        memset(f, 0, sizeof(f));
        memset(suf, 0, sizeof(suf));
        int ans = 1;
        for (int x : nums) {
            static int new_f[301];
            memset(new_f, 0, sizeof(new_f));
            for (int v = 1; v <= 300; v++) {
                int d = abs(x - v);
                int best_prev = suf[d][v];
                new_f[d] = max(new_f[d], (best_prev > 0 ? best_prev + 1 : 1));
            }
            for (int d = 0; d <= 300; d++) {
                f[d][x] = max(f[d][x], new_f[d]);
                ans = max(ans, f[d][x]);
            }
            suf[300 + 1][x] = 0;
            for (int d = 300; d >= 0; d--) {
                suf[d][x] = max(f[d][x], suf[d + 1][x]);
            }
        }

        return ans;
    }
};
