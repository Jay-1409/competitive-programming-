class Solution {
public:
    unordered_map<int, int> dp;
    int f(long long n) {
        if (n == 1) return 0;
        if (dp.find(n) != dp.end()) return dp[n];
        int result;
        if (n % 2 == 0) {
            result = 1 + f(n / 2);
        } else {
            result = 1 + min(f(n - 1), f((n + 1) / 2) + 1);
        }
        dp[n] = result;
        return result;
    }
    int integerReplacement(int n) {
        return f(n);
    }
};
