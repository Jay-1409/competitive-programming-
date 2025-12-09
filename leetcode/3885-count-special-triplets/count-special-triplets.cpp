class Solution {
public:
  int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        map<int, int> mpl, mpr;
        int n = nums.size();
        vector<long long> a(n, 0), b(n, 0);
        for(int i = 0; i < n; i++) {
            int target = nums[i] * 2;
            if(mpl.find(target) != mpl.end()) {
                // the target has appeared before, so we have atleast one valid i, for the current j
                a[i] = mpl[target];
            }
            mpl[nums[i]]++;
        }
        for(int i = n - 1; i >= 0; --i) {
            int target = nums[i] * 2;
            if(mpr.find(target) != mpr.end()) {
                // the target has appeared before, so we have atleast one valid i, for the current j
                b[i] = mpr[target];
            }
            mpr[nums[i]]++;
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] != 0 && b[i] != 0) {
                int temp = (a[i] * b[i]) % MOD;
                cnt = (cnt + temp) % MOD;
            }
        }
        return cnt;
    }
};