class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,map<int,int>> mp;
        map<int,int> len;
        for(int i = 0 ; i < n; ++i) {
            mp[i % k][nums[i]]++;
            len[i % k]++;
        }
        vector<int> dp(1025, INT_MAX); 
        dp[0] = 0;
        for(int i = 0; i < k; ++i) {
            vector<int> _dp(1025, INT_MAX);
            for(int l = 0; l < 1024; ++l) {
                if(dp[l] == INT_MAX)
                    continue;
                for(auto &j : mp[i]) {
                    _dp[l ^ j.first] = min(_dp[l ^ j.first],  dp[l] + (len[i] - j.second));
                }
            }
            int val = *min_element(dp.begin(), dp.end());
            for(int l = 0; l < 1024; ++l) {
                _dp[l] = min(_dp[l], val + len[i]);
            }
            dp = _dp;
        }
        return dp[0];
    }
};