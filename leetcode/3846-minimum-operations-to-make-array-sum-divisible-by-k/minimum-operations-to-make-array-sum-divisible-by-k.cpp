class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(sum % k == 0) {
            return 0;
        } 
        int distright = sum % k;
        int distleft = (sum + k) % k;
        return min(distright, distleft);
    }
};