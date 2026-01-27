class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int dp[201][201][201];
        for(int i = 0; i < 201; ++i) {
            for(int j = 0 ; j < 201; ++j) {
                for(int k = 0; k < 201; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        auto mod_add = [&](int a, int b) -> int {
            const long long MOD = 1e9 + 7;
            return (a + b) % MOD;
        };
        auto f = [&](int loc, int gcd_s1, int gcd_s2, bool seq1, bool seq2, auto && self) -> int {
            if(loc >= nums.size()) {
                return ((seq1 & seq2) && gcd_s1 == gcd_s2);
            }
            if(dp[loc][gcd_s1][gcd_s2] != -1)
                return dp[loc][gcd_s1][gcd_s2];
            int add_to_s1 = self(loc + 1, __gcd(gcd_s1, nums[loc]), gcd_s2, true, seq2, self);
            int add_to_s2 = self(loc + 1, gcd_s1, __gcd(gcd_s2, nums[loc]), seq1, true, self);
            int do_not_add = self(loc + 1, gcd_s1, gcd_s2, seq1, seq2, self);
            return dp[loc][gcd_s1][gcd_s2] = mod_add(do_not_add, mod_add(add_to_s1, add_to_s2));
        };  
        return f(0, 0, 0, false, false, f);
    }
};