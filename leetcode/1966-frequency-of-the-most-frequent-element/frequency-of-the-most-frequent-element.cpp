class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];
        auto verify = [&](int size) -> bool {
            for (int r = size - 1; r < n; r++) {
                int l = r - size + 1;
                long long sum = pref[r + 1] - pref[l];
                long long cost = (long long)nums[r] * size - sum;
                if (cost <= k) return true;
            }
            return false;
        };
        int lo = 1, hi = n, ans = 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (verify(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
