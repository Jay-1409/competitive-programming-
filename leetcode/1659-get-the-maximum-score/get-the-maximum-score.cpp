class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        long long dp1 = 0, dp2 = 0;
        for(int i = 0, j = 0; i < n || j < m;) {
            if(i < n && j < m && nums1[i] == nums2[j]) {
                long long best_val = max(dp1, dp2) + nums1[i];
                dp1 = best_val;
                dp2 = best_val;
                i++;
                j++;
            } else if(i < n && ((j < m && nums1[i] < nums2[j]) || j == m)) {
                dp1 += nums1[i++];
            } else 
                dp2 += nums2[j++];
        }
        const long long mod = 1e9 + 7;
        return max(dp1, dp2) % mod;
    }
};