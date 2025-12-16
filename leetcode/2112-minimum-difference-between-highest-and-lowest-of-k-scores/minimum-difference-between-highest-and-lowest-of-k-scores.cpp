class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int l = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int r = 0; r < n; ++r) {
            if(r >= k - 1) {
                ans = min(ans, nums[r] - nums[l]);
                l++;
            }
        }
        return ans;
    }
};