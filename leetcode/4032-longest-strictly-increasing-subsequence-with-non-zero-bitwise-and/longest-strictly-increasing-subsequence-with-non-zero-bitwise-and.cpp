class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto compute_lis = [&](vector<int> &v) -> int {
            vector<int> b;
            b.push_back(v[0]);
            for(auto &i : v) {
                if(i > b.back()) {
                    b.push_back(i);
                } else {
                    int it = lower_bound(b.begin(), b.end(), i) - b.begin();
                    b[it] = i;
                }
            }
            return (int)b.size();
        };
        int ans = 0;
        for(int i = 0; i < 32; ++i) {
            vector<int> temp;
            for(auto &j : nums) {
                if((j >> i) & 1) {
                    temp.push_back(j);
                }
            }
            if(!temp.empty())
                ans = max(ans, compute_lis(temp));
        }
        return ans;
    }
};