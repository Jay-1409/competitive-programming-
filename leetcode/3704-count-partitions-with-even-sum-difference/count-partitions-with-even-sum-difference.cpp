class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pfx(n + 1, 0);
        pfx[1] = nums[0];
        for(int i = 1; i < n; ++i) {
            pfx[i + 1] = pfx[i] + nums[i];
        }
        int cnt = 0;
        for(int i = 1; i < n; ++i) {
            int sum_right = pfx[i];
            int sum_left = pfx[n] - pfx[i];
            int diff = abs(sum_right - sum_left);
            if(diff % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};