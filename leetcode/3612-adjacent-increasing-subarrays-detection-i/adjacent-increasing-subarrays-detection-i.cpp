class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1) return true; 
        int n = nums.size();
        auto inc = [&](int start) {
            for (int i = start; i < start + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = 0; i <= n - 2 * k; ++i) {
            if (inc(i) && inc(i + k)) {
                return true;
            }
        }
        
        return false;
    }
};
