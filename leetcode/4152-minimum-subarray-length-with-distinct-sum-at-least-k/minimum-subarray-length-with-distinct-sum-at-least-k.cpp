class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int min_len = INT_MAX;
        map<int,int> mp;
        set<int> st;
        int l = 0;
        int cur_sum = 0;
        for(int r = 0; r < (int)nums.size(); ++r) {
            mp[nums[r]]++;
            if(st.find(nums[r]) == st.end()) {
                cur_sum += nums[r];
                st.insert(nums[r]);
            }
            while(cur_sum >= k) {
                min_len = min(min_len, r - l + 1);
                if(mp[nums[l]] == 1) {
                    cur_sum -= nums[l];
                    st.erase(nums[l]);
                }
                mp[nums[l++]]--;
            }
        }
        return (min_len == INT_MAX ? -1 : min_len);
    }
};