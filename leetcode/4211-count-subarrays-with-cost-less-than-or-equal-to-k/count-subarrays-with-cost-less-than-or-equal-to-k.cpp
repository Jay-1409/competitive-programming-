class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        map<int,int> mp;
        set<int> st;
        int n = nums.size();
        int l = 0;
        long long cnt = 0;
        for(int r = 0; r < n; ++r) {
            mp[nums[r]]++;
            if(mp[nums[r]] == 1) {
                st.insert(nums[r]);
            }
            auto condition = [&]() -> bool {
                long long maxe = *st.rbegin();
                long long mine = *st.begin();
                long long ans = (maxe - mine) * (r - l + 1);
                if(ans > k) 
                    return true;
                return false;
            };
            while(l < r && condition()) {
                if(mp[nums[l]] == 1) {
                    st.erase(nums[l]);
                }
                mp[nums[l++]]--;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};