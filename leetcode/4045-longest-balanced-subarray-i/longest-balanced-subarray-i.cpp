class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; ++i){ 
            st.clear();
            int odds = 0;
            int evs = 0;
            for(int j = i; j < n; ++j) {
                if(st.find(nums[j]) == st.end()) {
                    if(nums[j] & 1)
                        odds++;
                    else
                        evs++;
                    st.insert(nums[j]);
                }
                if(odds == evs) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};