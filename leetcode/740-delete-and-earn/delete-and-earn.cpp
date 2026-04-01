class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> a(st.begin(), st.end());
        map<int,int> mp;
        int n = a.size();
        vector<int> dp(1e4 + 1, 0);
        for(auto &I : nums) {
            mp[I]++;
        }
        dp[0] = mp[0] * 0;
        dp[1] = max(dp[0], mp[1] * 1);
        auto Calc = [&](int pos) -> int {
            if(mp.find(pos) == mp.end())
                return 0;
            return mp[pos] * pos;
        };
        for(int i = 2; i < 1e4 + 1; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + Calc(i));
        }
        // for(auto &i : dp) {
        //     cout << i << " ";
        // }
        return dp[1e4];
    }
};

/**
7 8 9 10. -> 8, 7/9  -> 9, 8/10 
dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]*frq[nums[i]]);
**/