class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;
        for(auto &I : nums) {
            if(I > 0) {
                mp[I % value]++;
            }
            else {
                mp[(value - (abs(I) % value)) % value]++;
            }
        }
        int mex = 0;
        while(true) {
            if(mp[mex % value] > 0) {
                mp[mex % value]--;
            } else
                return mex;
            mex++;
        }
        return -1;
    }
};