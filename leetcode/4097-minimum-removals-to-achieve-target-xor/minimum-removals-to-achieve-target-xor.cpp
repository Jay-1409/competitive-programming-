class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        map<pair<int,int>, long long> dp;
        auto dfs = [&](int loc, int cur_xor, auto && self) -> long long {
            if(loc >= (int)nums.size()) {
                if(cur_xor == target)
                    return 0;
                return INT_MAX;
            } 
            if(dp.find(make_pair(loc, cur_xor)) != dp.end())
                return dp[make_pair(loc, cur_xor)];
            long long take = self(loc + 1, cur_xor ^ nums[loc], self);
            long long not_take = min(1LL * INT_MAX, 1 + self(loc + 1, cur_xor, self));
            return dp[make_pair(loc, cur_xor)] = min(take, not_take);
        };  
        return (dfs(0, 0, dfs) == INT_MAX ? -1 : dp[make_pair(0, 0)]);
    }
};