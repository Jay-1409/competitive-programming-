class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < (int)nums.size(); ++i) {
            for(int j = 0; j <= 1000; ++j) {
                if((j | (j + 1)) == nums[i]) {
                    ans.push_back(j);
                    goto done;
                }
            }
            ans.push_back(-1);
            done:;
        }
        return ans;
    }
};