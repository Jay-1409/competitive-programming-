class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int loc = 0;
        int n = nums.size();
        int cnt = 0;
        for(loc; loc < n - 1; ++loc) {
            if(nums[loc] >= nums[loc + 1]) {
                if(cnt > 0)
                    goto firstphase;
                else
                    return false;
            } 
            cnt++;
        }
        return false;
        firstphase:;
        cnt = 0;
        for(loc; loc < n - 1; ++loc) {
            if(nums[loc] <= nums[loc + 1]) {
               if(cnt > 0)
                    goto secondphase;
                else
                    return false;
            }
            cnt++;
        }
        return false;
        secondphase:;
        if(loc == n - 1) {
            return false;
        }
        for(loc; loc < n - 1; ++loc) {
            if(nums[loc] >= nums[loc + 1]) {
                return false;
            }
        }
        return true;
    }
};