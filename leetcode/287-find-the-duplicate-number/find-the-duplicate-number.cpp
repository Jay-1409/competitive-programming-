class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(100001);
        vector<int> dirty(100001);
        for(auto&I : nums) {
            v[I]++;
            if(dirty[I] != 0) {
                dirty[I] = 0;
                v[I] = 0;
            }
            if(v[I] == 2)
                return I;
        }
        return -1;
    }
};