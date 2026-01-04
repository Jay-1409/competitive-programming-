class Solution {
public:
    int minOperations(int n) {
        unordered_map<int,int> dp;
        auto f = [&](int n, auto && self) -> int {
            if(dp.count(n)) {
                return dp[n];
            } 
            if (n == 0)
                return 0;
            if (dp.count(n)) 
                return dp[n];
            if((n & (n - 1)) == 0) 
                return 1;
            int p = 1 << (31 - __builtin_clz(n));
            return dp[n] = 1 + min(self((p << 1) - n, self), self(n - p, self));         
        };
        return f(n, f);
    }
};