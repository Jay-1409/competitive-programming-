class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> st;
        auto f = [&](int loc, vector<int> &a, auto && self) -> void {
            if(loc >= (int)nums.size()) {
                st.insert(a);
            } else {
                a.push_back(nums[loc]);
                self(loc + 1, a, self);
                a.pop_back();
                self(loc + 1, a, self);
            }
        };
        vector<int> a;
        f(0, a, f);
        vector<vector<int>> ans (st.begin(), st.end());
        return ans;
    }
};