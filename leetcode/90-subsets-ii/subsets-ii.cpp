class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        auto dfs = [&](int loc, vector<int> &run, auto && self) -> void {
            if(loc == (int)nums.size()) {
                sort(run.begin(), run.end());
                st.insert(run);
                return;
            }
            run.push_back(nums[loc]);
            self(loc + 1, run, self);
            run.pop_back();
            self(loc + 1, run, self);
        };
        vector<int> t;
        dfs(0, t, dfs);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};