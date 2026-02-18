class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        for(int i = 0; i <= n; ++i) {
            vector<int> bits(n, 0);
            for(int j = 0; j < i; ++j) {
                bits[j] = 1;
            }
            reverse(bits.begin(), bits.end());
            do {
                vector<int> temp;
                for(int i = 0; i < n; ++i) {
                    if(bits[i]) {
                        temp.push_back(nums[i]);
                    }
                }
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            } while(next_permutation(bits.begin(), bits.end()));
        }
        vector<vector<int>> fans(ans.begin(), ans.end());
        return fans;
    }
};