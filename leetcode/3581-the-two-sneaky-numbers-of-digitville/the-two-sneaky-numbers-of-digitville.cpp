class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> mp;
        for(auto &I:nums) {
            mp[I]++;
        }
        vector<int> v;
        for(auto &i : mp) {
            if(i.second == 2) {
                v.push_back(i.first);
            }
        }
        return v;
    }
};