class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> st;
        auto f = [&](vector<int> &v,int sum, int loc, int num, auto && self) -> void {
            if(num > 9)
                return;
            if(sum > n) {
                return;
            }
            if(loc >= k) {
                 if(sum == n)
                    st.insert(v);
                return;
            }
            // take
            if(v.empty()) {
                v.push_back(num);
                self(v, sum + num, loc + 1, num, self);
                v.pop_back();
            } else if(v.back() != num) {
                v.push_back(num);
                self(v, sum + num, loc + 1, num, self);
                v.pop_back();
            }
            // if(used.find(num) == used.end()) {
            //     used.insert(num);
            //     v.push_back(num);
            //     self(used, v, sum + num, loc + 1, num, self);
            //     used.erase(num);
            //     v.pop_back();
            // }
            // not take 
            self(v, sum, loc, num + 1, self);
        };
        vector<int> v;
        f(v, 0, 0, 1, f);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};