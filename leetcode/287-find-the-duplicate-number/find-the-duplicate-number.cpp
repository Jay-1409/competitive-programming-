class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(100001, 0);
        for(auto&I : nums) {
            v[I]++;
            if(v[I] == 2)
                return I;
        }
        return -1;
    }
};