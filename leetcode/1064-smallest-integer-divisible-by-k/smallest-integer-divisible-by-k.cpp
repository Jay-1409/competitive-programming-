class Solution {
public:
    const long long MOD = 1e9 + 7;
    int smallestRepunitDivByK(int k) {
        vector<long long> values;
        long long val = 0;
        for(int i = 0; i <= k; ++i) {
            val = (val * 10 + 1) % k;
            if(val % k == 0)
                return i + 1;
            values.push_back(val);
        }
        return -1;
    }
};