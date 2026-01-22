class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt= 0;
        while(true) {
            if(is_sorted(nums.begin(), nums.end()))
                break;
            int idx = -1;
            cnt++;
            int min_sum = INT_MAX;
            for(int i = 0; i < (int)nums.size() - 1; ++i) {
                if((nums[i] + nums[i + 1]) < min_sum) {
                    min_sum = nums[i] + nums[i + 1];
                    idx = i;
                }
            }
            vector<int> next_nums;
            for(int i = 0; i < (int)nums.size(); ++i) {
                if(i == idx) {
                    next_nums.push_back(nums[i] + nums[i + 1]);
                    i++;
                } else {
                    next_nums.push_back(nums[i]);
                }
            }
            nums = next_nums;
        }
        return cnt;
    }
};