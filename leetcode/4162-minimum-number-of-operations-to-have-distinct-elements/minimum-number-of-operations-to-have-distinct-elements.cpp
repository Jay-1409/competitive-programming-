class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int nearest = -1;
        for(int i = (int)nums.size() - 1; i >= 0; --i) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) {
                nearest = max(i, nearest);
            }
        }
        if(nearest == -1){
            return 0;
        }
        int len = nearest + 1;
        return (len + 2) / 3;
    }
};