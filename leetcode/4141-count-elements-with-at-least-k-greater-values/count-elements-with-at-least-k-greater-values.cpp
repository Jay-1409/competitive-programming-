class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            auto it = upper_bound(nums.begin() + i, nums.end(), nums[i]);
            if(it != nums.end()) {
                int id = (it - nums.begin());
                id = (n) - id;
                if(id >= k) {
                    cnt++;
                }
            } else if(k == 0){
                cnt++;
            }
        }
        return cnt;
    }
};