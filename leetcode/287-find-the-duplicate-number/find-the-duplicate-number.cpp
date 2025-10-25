class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1);
        vector<int> dirty(n + 1);
        for(auto&I : nums) {
            if(dirty[I] != 0) {
                dirty[I] = 0;
                v[I] = 0;
            }
            v[I]++;
            if(v[I] == 2)
                return I;
        }
        return -1;
    }
};