class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pfx(n, 0);
        // int prevmin = INT_MAX;
        map<int,long long> prevmin;
        prevmin[1] = nums[0];
        if(k == 1) {
            prevmin[0] = nums[0];
        }
        pfx[0] = nums[0];
        long long overall_max = (k == 1 ? nums[0] : LLONG_MIN);
        for(int i = 2; i <= n; ++i) {
            int j = i - 1;
            pfx[j] = pfx[j - 1] + nums[j];
            if((i - k >= 0 && (prevmin.find(i % k) != prevmin.end())) || i % k == 0) {
                overall_max = max({overall_max, pfx[j] - prevmin[i % k], (i % k == 0 ? pfx[j] : LLONG_MIN)});
                // cout << overall_max << " " << i << " " << pfx[j] << " " << prevmin[i % k] << endl;
            }
            if(prevmin.find(i % k) == prevmin.end()) {
                prevmin[i % k] = 1LL * pfx[j];
            } else
                prevmin[i % k] = min(1LL * pfx[j], 1LL * prevmin[i % k]);
            // cout << i << " " << prevmin[i % k] << endl;
        }
        return overall_max;
    }
};