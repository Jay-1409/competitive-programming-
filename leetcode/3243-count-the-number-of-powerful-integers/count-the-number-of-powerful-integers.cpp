class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long dp[20][2];
        string f;
        int len;
        auto dfs = [&](int pos, int tight, auto && self) -> long long {
            if(pos >= len) {
                if(!tight) return 1;
                for(int i = 0; i < (int)s.size(); ++i) {
                    char sc = s[i];
                    char fc = f[len + i];
                    if(sc < fc) return 1;
                    if(sc > fc) return 0;
                }
                return 1;
            }
            if(dp[pos][tight] != -1) {
                return dp[pos][tight];
            }
            long long sub_cnt = 0;
            int max_v = min(limit, (tight ? f[pos] - '0' : limit));
            for(int i = 0; i <= max_v; ++i) {
                sub_cnt += self(pos + 1, tight && (i == (f[pos] - '0')), self);
            }
            return dp[pos][tight] = sub_cnt;
        };
        auto count = [&](long long x) -> long long {
            f = to_string(x);
            len = f.size() - s.size();
            if(len < 0) return 0;
            for(int i = 0; i < 20; ++i) {
                for(int j = 0; j < 2; ++j)
                    dp[i][j] = -1;
            }
            for(char c : s)
                if(c - '0' > limit) return 0;
            return dfs(0, 1, dfs);
        };
        return count(finish) - count(start - 1);
    }
};