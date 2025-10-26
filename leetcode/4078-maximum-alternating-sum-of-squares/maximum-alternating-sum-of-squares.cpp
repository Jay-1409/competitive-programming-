class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &i : nums)
            i = abs(i);
        sort(nums.begin(), nums.end());
        int l =0;
        int r = (int)nums.size() - 1;
        long long sum = 0;
        while(l < r) {
            sum -= (1LL * nums[l] * nums[l]);
            sum += (1LL * nums[r] * nums[r]);
            l++;
            r--;
        }
        if((int)nums.size() & 1) {
            // cout << nums[l] << " " << nums[r] << endl;
            sum += (1LL * nums[l] * nums[l]);
        }
        return sum;
    }
};