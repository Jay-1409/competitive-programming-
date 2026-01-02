class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size() / 2;
        for(auto &i : nums) {
            mp[i]++;
            if(mp[i] == n) {
                return i;
            }
        }
        return -1;
    }
};