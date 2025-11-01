class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combs;
        auto f = [&](int loc, int &cursum, vector<int> &nums, auto && self) -> void {
            if(cursum == target) {
                combs.push_back(nums);
                return;
            }
            if(loc >= (int)candidates.size() || cursum > target) {
                return;
            }
            for(int i = loc; i < (int)candidates.size(); ++i) {
                if (i > loc && candidates[i] == candidates[i - 1]) 
                    continue;
                nums.push_back(candidates[i]);
                cursum += candidates[i];
                self(i + 1, cursum, nums, self);
                nums.pop_back();
                cursum -= candidates[i];
            }
            return;
        };
        int sum = 0;
        vector<int> dum;
        sort(candidates.begin(), candidates.end());
        f(0, sum, dum, f);
        // vector<vector<int>> ans(combs.begin(), combs.end());
        return combs;
    }
};