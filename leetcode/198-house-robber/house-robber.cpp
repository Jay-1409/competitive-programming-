class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2) 
            return max(nums[0], nums[1]);
        int oneback = max(nums[0], nums[1]);
        int twoback = nums[0];
        for(int i = 2; i < n; ++i) {
            int temp = oneback;
            oneback = max(twoback + nums[i], oneback);
            twoback = temp;
        }
        return max(oneback, twoback);
    }
};