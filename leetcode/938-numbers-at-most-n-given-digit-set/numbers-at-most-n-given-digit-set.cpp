class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // pos, tight
        string maxv = to_string(n);
        int m = (int)maxv.size();
        int dp[10][2];
        for(int i = 0; i < 10; ++i) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        auto dfs = [&](int pos, bool tight, auto && self) -> int {
            if(pos >= m) {
                return 1;
            }
            if(dp[pos][tight] != -1) 
                return dp[pos][tight];
            int ans = 0;
            for(int i = 0; i < digits.size(); ++i) {
                if(tight && ((digits[i][0] - '0') > (maxv[pos] - '0')))
                    break;
                bool next_tight = (tight && (digits[i][0] == maxv[pos]));
                ans = (ans + self(pos + 1, next_tight, self));
            }
            return dp[pos][tight] = ans;
        };
        int ans = 0;
        int p = 1;
        int poss = digits.size();
        for(int i = 1; i < maxv.size(); i++) {
            p *= poss;
            ans += p;
        }
        return dfs(0, 1, dfs) + ans;
    }
};