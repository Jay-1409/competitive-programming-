class Solution {
public:
    int numWays(int steps, int arrLen) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, unordered_map<int,int>> cache;
        auto f = [&](int pos, int step, auto && self) -> int {
            if(step == 0 && pos == 0)
                return 1;
            else if(step == 0)
                return 0;
            if(cache.count(step) && cache[step].count(pos))
                return cache[step][pos];
            long long go_left = 0, go_right = 0, stay_;
            if(pos - 1 >= 0) {
                go_left = self(pos - 1, step - 1, self);
            }
            if(pos + 1 < arrLen) {
                go_right = self(pos + 1, step - 1, self);
            }
            stay_ = self(pos, step - 1, self);
            return 
                cache[step][pos] = (go_left + go_right + stay_) % MOD;
        };
        return f(0, steps, f);
    }
};

/**
NOTES

- one can easily solve this using normal recurssion 
- It can be optimized using meomoization with two states [stepsleft][location]
- since steps are 500 the above approch might be feasible 500 * 501 (position in aray * step)

**/