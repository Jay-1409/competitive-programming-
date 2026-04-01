class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(1e4 + 1, 0);
        vector<int> dp(1e4 + 1, 0);
        for(auto &I : nums) {
            cnt[I]++;
        }
        dp[0] = cnt[0] * 0;
        dp[1] = max(dp[0], cnt[1] * 1);
        for(int i = 2; i < 1e4 + 1; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        }
        return dp[1e4];
    }
};

/**
7 8 9 10. -> 8, 7/9  -> 9, 8/10 
dp[i] = max(dp[i - 1], dp[i - 2] + [i]*frq[[i]]);
**/