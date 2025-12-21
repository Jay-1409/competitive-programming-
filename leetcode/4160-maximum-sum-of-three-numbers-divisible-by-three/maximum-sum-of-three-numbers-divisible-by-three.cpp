class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(auto &I : nums) {
            mp[I % 3].push_back(I);
        }
        vector<int> possibilities;
        if(mp[1].size() >= 3) {
            sort(mp[1].rbegin(), mp[1].rend());
            possibilities.push_back(mp[1][0] + mp[1][1] + mp[1][2]);
        }
        if(mp[2].size() >= 3) {
            sort(mp[2].rbegin(), mp[2].rend());
            possibilities.push_back(mp[2][0] + mp[2][1] + mp[2][2]);
        }
        if(mp[2].size() >= 1 && mp[1].size() >= 1 && mp[0].size() >= 1) {
            sort(mp[2].rbegin(), mp[2].rend());
            sort(mp[1].rbegin(), mp[1].rend());
            sort(mp[0].rbegin(), mp[0].rend());  
            possibilities.push_back(mp[2][0] + mp[1][0] + mp[0][0]);
        }
        if(mp[0].size() >= 3) {
            sort(mp[0].rbegin(), mp[0].rend());  
            possibilities.push_back(mp[0][0] + mp[0][1] + mp[0][2]); 
        }
        if(possibilities.empty()) {
            return 0;
        }
        return *max_element(possibilities.begin(), possibilities.end());
    }
};