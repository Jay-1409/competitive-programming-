class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> options;
        for(auto I : strs) {
            int cnt1 = 0;
            int cnt0 = 0;
            for(auto &j : I) {
                if(j == '1'){
                    cnt1++;
                } else {
                    cnt0++;
                }
            }
            options.push_back({cnt0, cnt1});
        }
        auto uq = [&](int a, int b, int c) -> int {
            long long base = 1000003;
            long long state = (a * base * base) + (b * base) + c;
            return (int)(state % 2147483647);
        };
        unordered_map<int, int> cache;
        auto dfs = [&](int loc, int taken0, int taken1, auto && self) -> int {
            int key = uq(loc, taken0, taken1);
            if(loc >= (int)options.size()) {
                return 0;
            }
            if(cache.count(key)) {
                return cache[key];
            }
            int new0 = taken0 + options[loc].first;
            int new1 = taken1 + options[loc].second;
            int maxlen = 0;
            if(new0 <= m && new1 <= n) {
                // can take 
                maxlen = 1 + max(maxlen, self(loc + 1, new0, new1, self));
            }
            // dont take
            maxlen = max(maxlen, self(loc + 1, taken0, taken1, self));
            return cache[key] = maxlen;
        };
        return dfs(0, 0, 0, dfs);
    }
};
/**
- we can cache on the number of 0's we can take and number of 1's we can take standing at any position as the cache state [pos][o's][1's]

**/