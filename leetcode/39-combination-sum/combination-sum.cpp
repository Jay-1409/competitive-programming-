class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> st;
        auto dfs = [&](vector<int> &cur, int &sum, int loc, auto && self) -> void {
            if(sum > target) {
                return;
            }
            if(sum == target) {
                st.insert(cur);
                return;
            }
            if(loc == (int)candidates.size()) {
                return;
            }
            cur.push_back(candidates[loc]);
            sum += candidates[loc];
            self(cur, sum, loc, self);
            self(cur, sum, loc + 1, self);
            cur.pop_back();
            sum -= candidates[loc];
            self(cur, sum, loc + 1, self);
        };
        vector<int> t; int summ =0;
        dfs(t, summ, 0, dfs);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};