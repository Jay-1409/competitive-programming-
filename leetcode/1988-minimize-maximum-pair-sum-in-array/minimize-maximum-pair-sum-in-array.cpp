class Solution {
public:
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int l = 0;
       int r = (nums.size() - 1);
       int sum = 0;
       while(l < r) {
        sum = max(sum, nums[r--] + nums[l++]);
       }
       return sum;
    }
};