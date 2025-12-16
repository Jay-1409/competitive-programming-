class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int r = 0, l = 0; r < nums.size(); ++r)
            ans = (r >= k - 1 ? min(ans, nums[r] - nums[l++]) : INT_MAX);
        return ans;
    }
};