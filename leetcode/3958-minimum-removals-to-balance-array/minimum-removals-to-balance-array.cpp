class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max_len = 0;
        for(int i = 0; i < (int)nums.size(); ++i) {
            int it = upper_bound(nums.begin(), nums.end(), 1LL * nums[i] * k) - nums.begin();
            it--;
            // cout << nums[i] << " " << it << " " << it - i + 1 << endl;
            max_len = max(max_len, it - i + 1);
        }
        return (int)nums.size() - max_len;
    }
};