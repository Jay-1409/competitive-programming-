class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cnt = 1;
        int prevcnt = 0;
        int ans = 0;
        for(int i = 0; i < (int)nums.size() - 1; ++i) {
            if(nums[i + 1] > nums[i]) {
                cnt++;
                ans = max(ans, cnt / 2);
            } else {
                prevcnt = cnt;
                cnt = 1 ;
            }
            if(prevcnt >= cnt) {
                // can form a inc seq one form the prev sequence since that length is greater than cnt 
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};