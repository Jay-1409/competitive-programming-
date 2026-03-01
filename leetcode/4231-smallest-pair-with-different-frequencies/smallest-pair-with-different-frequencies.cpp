class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> mp;
        for(auto &I : nums) {
            mp[I]++;
        }
        sort(nums.begin(), nums.end());
        for(int j = 0; j < (int)nums.size(); ++j) {
            for(int i = 0; i < (int)nums.size(); ++i) {
                if((nums[j] != nums[i]) && (mp[nums[j]] != mp[nums[i]])) {
                    return {nums[j], nums[i]};
                }
            }
        }
        return {-1, -1};
    }
};