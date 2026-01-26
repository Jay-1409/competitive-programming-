class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> dp((1 << 16), -1);
        auto f = [&](int mask, int op, auto && self) -> int {
            if(__builtin_popcount(mask) == (int)nums.size()) 
                return 0;
            if(dp[mask] != -1) {
                return dp[mask];
            }
            int sub_score = 0;
            for(int i = 0; i < (int)nums.size(); ++i) {
                for(int j = 0; j < i; ++j) {
                    if(!((mask >> i) & 1) && !((mask >> j) & 1)) {
                        sub_score = max(sub_score, op * (__gcd(nums[i], nums[j])) + self((mask | (1 << i) | (1 << j)), op + 1, self));
                    }
                }
            }
            return dp[mask] = sub_score;
        };
        return f(0, 1, f);
    }
};