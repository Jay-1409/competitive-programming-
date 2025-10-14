class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        stack<int> stk; int prev = 0;
        for(auto &i : nums) {
            if(stk.empty()) {
                stk.push(i);
            } else {
                if(i > stk.top()) 
                    stk.push(i);
                else {
                    prev = stk.size();
                    stk = {};
                    stk.push(i);
                }
                if(stk.size() >= k && prev >= k)
                    return true;
                else if(stk.size() >= 2 * k || prev >= 2 * k)
                    return true;
            }
        }
        return false;    
    }
};
