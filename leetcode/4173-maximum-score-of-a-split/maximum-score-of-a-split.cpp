class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pfxsum(n, 0), sfxmin(n, INT_MAX);
        pfxsum[0] = nums[0];
        sfxmin[n - 1] = nums[n - 1];
        for(int i = 1; i < n; ++i) {
            pfxsum[i] = pfxsum[i - 1] + nums[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            sfxmin[i] = min(sfxmin[i + 1], 1LL*nums[i]);
        }
        long long maxe = LLONG_MIN;
        for(int i = 0; i < n - 1; ++i) {
            //cout << pfxsum[i] << " " << sfxmin[i + 1] << endl;
            maxe = max(maxe, pfxsum[i] - sfxmin[i + 1]);
        }
        return maxe;
    }
};