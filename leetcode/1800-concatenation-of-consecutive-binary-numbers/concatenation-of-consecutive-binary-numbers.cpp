class Solution {
public:
    const long long mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        int val = 0;
        stack<int> reserve;
        for(int i = 1; i <= n; ++i) {
            int cur_num = 0;
            int loc = 1;
            for(int j = 0; j < 32 && cur_num < i; ++j) {
                reserve.push(((i >> j) & 1));
                cur_num += (loc * ((i >> j) & 1));
                loc *= 2;
            }
            while(!reserve.empty()) {
                val <<= 1;
                val |= (reserve.top());
                val = (val % mod);
                reserve.pop();
            }
        }
        return val;
    }
};