class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        auto f = [&](const vector<int>& a) -> vector<int> {
            vector<int> dp(n, 0);
            dp[0] = 1;
            dp[1] = 2;
            for (int i = 2; i < n; ++i) {
                if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
                    dp[i] = dp[i - 1] + 1;
                } else {
                    dp[i] = 2;
                }
            }
            return dp;
        };
        vector<int> x = f(nums);
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());
        vector<int> y = f(rev);
        reverse(y.begin(), y.end());
        int best_ans = 2;
        best_ans = max(best_ans, y[1] + 1);
        best_ans = max(best_ans, x[n - 2] + 1);
        for (int i = 1; i < n - 1; ++i) {
            best_ans = max(best_ans, x[i - 1] + 1);
            best_ans = max(best_ans, y[i + 1] + 1);
            long long gap = 1LL * nums[i + 1] - nums[i - 1];
            if (gap % 2 == 0) {
                long long d = gap / 2;
                int left = 1;
                int right = 1;
                if (i >= 2 && 1LL * nums[i - 1] - nums[i - 2] == d) {
                    left = x[i - 1];
                }
                if (i + 2 < n && 1LL * nums[i + 2] - nums[i + 1] == d) {
                    right = y[i + 1];
                }
                best_ans = max(best_ans, left + right + 1);
            }
        }
        return min(best_ans, n);
    }
};